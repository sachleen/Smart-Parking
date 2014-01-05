WirelessNodes = [];

$(function() {
    /*
        Event handler for deleteNode button
        Did it this way to ensure elements added in the future would get this handler too
    */
    $("body").on("click", '.deleteNode', deleteNode);
    $("#addNode").click(addNode);
});

/*
    Add Node event handler
    Gets the node ID and number of sensors connected to it and adds it to the map
*/
function addNode() {
    if (typeof addMarkerListener !== 'undefined') {
        google.maps.event.removeListener(addMarkerListener);
    }
    
    addMarkerListener = google.maps.event.addListener(map, 'click', function(event) {
        
        var id = prompt("Enter the 10 character Node ID");
        var spots = prompt("Enter number of sensor connected to this node");
        
        var node = new WirelessNode(id, event.latLng, spots);
        
        addMarker(node);
        
        google.maps.event.removeListener(addMarkerListener);
    });
}

/*
    Delete Node event handler
    Finds the right node in WirelessNodes and calls its delete function
*/
function deleteNode() {
    var id = $(this).data('nodeid');
    
    var Node = WirelessNodes.filter(function(Node) {
        return Node.id == id;
    });
    
    Node[0].delete();
}