WirelessNodes = [];

$(function() {

});

/*
    Add a new Node
    Gets the node ID and number of sensors connected to it and places a marker on the map
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
        
        console.log("Added Node:");
        console.log(node);
        
        google.maps.event.removeListener(addMarkerListener);
    });
}