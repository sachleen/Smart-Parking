<?php

require 'vendor/autoload.php';
require 'config.php';

$app = new \Slim\Slim();

$app->config('debug', getenv('APP_MODE') == "development" ? TRUE : FALSE);

ORM::configure($connectionSettings);


/*
    Sends a JSON encoded response in the format of:
    {"success":"TRUE","error_message":""}
    {"success":"FALSE","error_message":"Error message here"}
    
    Parameter       Description
    succss          Boolean value. True if query was successful.
    error_message   A message explaining the error. Will be ignored if success is true
*/
function sendResponse($success, $error_message) {
    
    $response = array(
        "success" => $success ? "TRUE" : "FALSE",
        "error_message" => $success ? "" : $error_message
    );
    
    echo json_encode($response);
}

/*
    Validates API key
    
    Parameter       Description
    key             API Key
    action          The action the app is trying to perform:
                        update_available_count
                        create_or_update
                        delete
*/
function authAPI($key, $action) {
    $checkKey = ORM::for_table('api_keys')->where('key', $key)->find_one();
    
    if ($checkKey == null) {
        return 0;
    }
    
    /*
        Bit 0 (LSB) - update_available_count
        Bit 1       - create_or_update
        Bit 2       - delete
    */
    $actions = $checkKey->actions;
    
    switch($action) {
        case 'update_available_count':
            return $actions & 1;
        case 'create_or_update':
            return $actions & 2;
        case 'delete':
            return $actions & 4;
        default:
            return 0;
    }
}


$app->get('/nodes/:lat/:lng/:distance', function ($lat, $lng, $distance) {
    
    $nodes = ORM::for_table('nodes')->select('id')
                                    ->select('lat')
                                    ->select('lng')
                                    ->select('total')
                                    ->select('available')
                                    ->select_expr("calcDistance($lat, $lng, lat, lng)", 'distance')
                                    ->having_lt('distance', $distance)
                                    ->find_many();
    
    $nodes_arr = array();
    foreach ($nodes as $n) {
        array_push($nodes_arr,
            array("id"        => $n->id,
                  "lat"       => $n->lat,
                  "lng"       => $n->lng,
                  "total"     => $n->total,
                  "available" => $n->available,
                  "distance"  => $n->distance
            )
        );
    }
    echo json_encode($nodes_arr);
})->conditions(array(
    'lat' => '-?\d+\.?\d*',
    'lng' => '-?\d+\.?\d*',
    'distance' => '\d+\.?\d*',
));

$app->get('/nodes/all', function () {
    $nodes = ORM::for_table('nodes')->select('id')
                                     ->select('lat')
                                     ->select('lng')
                                     ->select('total')
                                     ->select('available')
                                     ->find_many();
    $nodes_arr = array();
    foreach ($nodes as $n) {
        array_push($nodes_arr,
            array("id"        => $n->id,
                  "lat"       => $n->lat,
                  "lng"       => $n->lng,
                  "total"     => $n->total,
                  "available" => $n->available
            )
        );
    }
    echo json_encode($nodes_arr);
});

$app->post('/nodes/save', function () use($app) {
    $id = $app->request->post('id');
    $lat = $app->request->post('lat');
    $lng = $app->request->post('lng');
    $total = $app->request->post('total');
    $available = $app->request->post('available');
    $apiKey = $app->request->post('api_key');
    
    // Some validation
    if (strlen($id) != 5) {
        sendResponse(false, "Invalid Node ID");
        return;
    }
    
    /*
        If lat, lng, and total are all set there are two possibilities:
            Create a new node
            Update the position or number of sensors of a node
        If only available is set, the node must already exist and we're just updating the available count
    */
    if ($lat != null && $lng != null && $total != null) {
        
        if (!authAPI($apiKey, 'create_or_update')) {
            sendResponse(false, "API Key Fail");
            return;
        }
    
        // If node doesn't exist, create it.
        $node = ORM::for_table('nodes')->find_one($id);
        if (!$node) {
            $node = ORM::for_table('nodes')->create();
        }
        
        $node->id = $id;
        $node->lat = $lat;
        $node->lng = $lng;
        $node->total = $total;
        
        $node->save();
    } else if ($available != null) {
        
        if (!authAPI($apiKey, 'update_available_count')) {
            sendResponse(false, "API Key Fail");
            return;
        }
    
        $node = ORM::for_table('nodes')->find_one($id);
        if (!$node) {
            sendResponse(false, "Node does not exist");
            return;
        }
        
        if ($node->total < $available) {
            sendResponse(false, "Available spots cannot be more than total spots!");
            return;
        }
        
        $node->available = $available;
        $node->save();
        
        sendResponse(true, '');
    } else {
        sendResponse(false, "Invalid parameters.");
    }
});

$app->post('/nodes/delete', function () use($app) {
    $id = $app->request->post('id');
    $apiKey = $app->request->post('api_key');
    
    if (!authAPI($apiKey, 'delete')) {
        sendResponse(false, "API Key Fail");
        return;
    }
    
    $node = ORM::for_table('nodes')->find_one($id);
    
    if ($node) {
        $node->delete();
        sendResponse(true, '');
    } else {
        sendResponse(false, "Node not found!");
    }
});

$app->run();

?>