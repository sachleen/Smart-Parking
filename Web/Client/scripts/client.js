WirelessNodes = [];

$(function() {
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
        showMessage("error", "Error communicating with server.");
    });
}