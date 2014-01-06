WirelessNodes = [];

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
    
    loadAllNodes();
});

/*
    Loads all nodes from database on to the map
*/
function loadAllNodes() {
    $.get("/API/nodes/all", function(response) {
        var items = [];
        response = $.parseJSON(response);
        $.each(response, function(key, val) {
            var latLng = new google.maps.LatLng(val['lat'], val['lng']);
            var node = new WirelessNode(val['id'], latLng, val['total']);
            addMarker(node);
        });
    }).fail(function() {
        alert("Error communicating with server.");
    });
}

/*
    Add Node event handler
    Gets the node ID and number of sensors connected to it and adds it to the map
*/
function addNode(latLng) {
    var id = prompt("Enter 5 character Node ID");
    
    if (id.length != 5) {
        alert("Invalid ID");
    } else {
        var spots = prompt("Enter number of spots");

        if (parseInt(spots) > 0 && parseInt(spots) <= 32) {
            var node = new WirelessNode(id, latLng, spots);
            addMarker(node);
            
            node.save();
        } else if(spots) {
            alert("Invalid number");
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