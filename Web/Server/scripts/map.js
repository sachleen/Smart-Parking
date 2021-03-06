var map;

$(function() {
    google.maps.event.addDomListener(window,'load',initialize);    
});


/*
    Initialize the Google map and handles event handlers
*/
function initialize() {
    /*
        Full list of map options:
        https://developers.google.com/maps/documentation/javascript/reference#MapOptions
    */
    var properties = {
        // Default center location in case geolocation isn't supported
        center: new google.maps.LatLng(38.56080772372703,-121.42170578241348),
        zoom:20,
        mapTypeId:google.maps.MapTypeId.ROADMAP
    };
    
    map = new google.maps.Map(document.getElementById("map-canvas"), properties);
    
    google.maps.event.addListener(map, 'dragend', centerChanged);
    google.maps.event.addListener(map, 'zoom_changed', centerChanged);
    
    centerMap();
    
    /*
        Allows user to click anywhere on the map to add a new node
    */
    addMarkerListener = google.maps.event.addListener(map, 'click', function(event) {
        addNode(event.latLng);
    });
}

/*
    Centers the map on the user's current position.
    Requires geolocation. If geolocation is not available, nothing will happen.
*/
function centerMap() {
    if (navigator.geolocation) {
        navigator.geolocation.getCurrentPosition(function (position) {
            initialLocation = new google.maps.LatLng(position.coords.latitude, position.coords.longitude);
            map.setCenter(initialLocation);
            loadAllNodes(position.coords.latitude, position.coords.longitude, SEARCH_RADIUS);
        });
    }
}

/*
    Fires whenever the center of the map has changed.
    Triggers an update of the nodes displayed on the map.
*/
function centerChanged() {
    var center = map.getBounds().getCenter();
    loadAllNodes(center.lat(), center.lng(), SEARCH_RADIUS);
}

/*
    Adds a marker to the map to represent a node
    
    Parameter   Description
    Node        WirelessNode object
*/
function addMarker(Node) {
    // Marker properties
    var marker = new google.maps.Marker({
        position: Node.latLng,
        map: map,
        animation: google.maps.Animation.DROP,
        icon: 'images/default.png',
    });

    // Information window for when marker is clicked
    var nodeInfoTemplate = $("#nodeInfoTemplate").html().format(Node.id, Node.spots);
    
    var infoWindow = new google.maps.InfoWindow({
        content: nodeInfoTemplate
    });
    
    Node.mapMarker = marker;
    Node.infoWindow = infoWindow;
    Node.attachMapEvents();
}