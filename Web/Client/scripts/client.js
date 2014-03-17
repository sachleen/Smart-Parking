var WirelessNodes = [];
var lastQuery = 0;
var lastPosition = {};
var timeout = 2000;

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
                if (node) {
                    node.spots = val['total'];
                    node.available = val['available'];
                    updateMarker(node);
                } else {
                    var latLng = new google.maps.LatLng(val['lat'], val['lng']);
                    node = new WirelessNode(val['id'], latLng, val['total'], val['available']);
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