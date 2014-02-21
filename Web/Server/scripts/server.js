WirelessNodes = [];
var lastQuery = 0;
var lastPosition = {};
var timeout = 10000;

$(function() {
    /*
        Event handler for deleteNode button
        Did it this way to ensure elements added in the future would get this handler too
    */
    $("body").on("click", '.deleteNode', deleteNode);
    $("#addNode").click(addNode);
    
    for (i = 1; i <= 32; i++) {
        $("#spots").append("<option value="+i+">"+i+"</option>");
    }
    
    //loadAllNodes();
});


/*
    Loads all nodes within the boundaries from database on to the map
*/
function loadAllNodes(lat, lng) {
    var time = new Date().getTime();
    
    // Calculate the distance moved since last update
    var distance = 3959 * Math.acos (
            Math.cos( lat * (Math.PI/180) )
          * Math.cos( lastPosition.lat * (Math.PI/180) )
          * Math.cos( lastPosition.lng * (Math.PI/180) - lng * (Math.PI/180) )
          + Math.sin( lat * (Math.PI/180) )
          * Math.sin( lastPosition.lat * (Math.PI/180))
        );
    
    // Only query server if data is older than timeout OR if map has moved too much
    if ((time - lastQuery > timeout) || distance > 0.5) {
        $.get(BASE_URL + "nodes/{0}/{1}/1.0".format(lat,lng), function(response) {
            var items = [];
            response = $.parseJSON(response);
            
            $.each(response, function(key, val) {
                var node = WirelessNode.findById(val['id']);
                if (!node) {
                    var latLng = new google.maps.LatLng(val['lat'], val['lng']);
                    node = new WirelessNode(val['id'], latLng, val['total']);
                    addMarker(node);
                }
            });
            
            lastQuery = new Date().getTime();
            lastPosition.lat = lat
            lastPosition.lng = lng;
        }).fail(function() {
            showMessage("error", "Error communicating with server.");
        });
    }
}

/*
    Add Node event handler
    Gets the node ID and number of sensors connected to it and adds it to the map
*/
function addNode(latLng) {
    var id = prompt("Enter 5 character Node ID");
    
    if (id.length != 5) {
        showMessage("error", "Invalid ID");
    } else {
        var spots = prompt("Enter number of spots");

        if (parseInt(spots) > 0 && parseInt(spots) <= 32) {
            var node = new WirelessNode(id, latLng, spots);
            addMarker(node);
            
            node.save();
        } else if(spots) {
            showMessage("error", "Invalid number");
        }
    }
}

/*
    Delete Node event handler
    Finds the right node in WirelessNodes and calls its delete function
*/
function deleteNode() {
    var id = $(this).data('nodeid');
    
    var Node = WirelessNode.findById(id);
    
    Node.delete();
}