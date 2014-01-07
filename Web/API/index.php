<?php
require 'vendor/autoload.php';

$app = new \Slim\Slim();

if ($_SERVER['REMOTE_ADDR'] == '127.0.0.1')
    $app->config('mode', 'development');
else
    $app->config('mode', 'production');

$app->config('debug', false);

// Only invoked if mode is "production"
$app->configureMode('production', function () use ($app) {
    ORM::configure(array(
        'connection_string' => 'mysql:host=localhost;dbname=sacramh7_parking',
        'username' => 'sacramh7_parking',
        'password' => '20=1=c9)xWSJ'
    ));
});

// Only invoked if mode is "development"
$app->configureMode('development', function () use ($app) {
    ORM::configure(array(
        'connection_string' => 'mysql:host=localhost;dbname=parking',
        'username' => 'root',
        'password' => 'admin'
    ));
});

/*
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

$app->get('/nodes/:lat/:lng/:distance', function ($lat, $lng, $distance) {
    
    $nodes = ORM::for_table('nodes')->raw_query("
    SELECT
      id, lat, lng, total, available, (
        3959 * acos (
          cos ( radians($lat) )
          * cos( radians( lat ) )
          * cos( radians( lng ) - radians($lng) )
          + sin ( radians($lat) )
          * sin( radians( lat ) )
        )
      ) AS distance
    FROM nodes
    HAVING distance < $distance
    ORDER BY distance
    ")->find_many();
    
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
    
    // Some validation
    if (strlen($id) != 5) {
        sendResponse(false, "Invalid Node ID");
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

    sendResponse(true, '');
});

$app->post('/nodes/delete', function () use($app) {
    $id = $app->request->post('id');
    
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