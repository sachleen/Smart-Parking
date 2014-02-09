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
        zoom:19,
        mapTypeId:google.maps.MapTypeId.ROADMAP
    };
    
    map = new google.maps.Map(document.getElementById("map-canvas"), properties);
    
    google.maps.event.addListener(map, 'dragend', centerChanged);
    google.maps.event.addListener(map, 'zoom_changed', centerChanged);
    
    centerMap();
    
    var locationMarker = new google.maps.Marker({
        position: new google.maps.LatLng(38.56080772372703,-121.42170578241348),
        map: map,
        animation: google.maps.Animation.DROP,
        icon: 'images/bluedot.png',
        zIndex: 100 // make sure the user's location is above all other markers
    });
    
    var watchID = navigator.geolocation.watchPosition(function(position) {
        locationMarker.setPosition(new google.maps.LatLng(position.coords.latitude, position.coords.longitude));
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
            loadAllNodes(position.coords.latitude, position.coords.longitude);
        });
    }
}

/*
    Fires whenever the center of the map has changed.
    Triggers an update of the nodes displayed on the map.
*/
function centerChanged() {
    var center = map.getBounds().getCenter();
    loadAllNodes(center.lat(), center.lng());
}

/*
    Adds a marker to the map to represent a node
    
    Parameter   Description
    Node        WirelessNode object
*/
function addMarker(Node) {
    // Marker properties
    var icon = Node.available > 5 ? 5 : Node.available;
    var zidx = parseInt(Node.available > 5 ? 5 : Node.available);
    
    var marker = new google.maps.Marker({
        position: Node.latLng,
        map: map,
        animation: google.maps.Animation.DROP,
        icon: 'images/'+icon+'.png',
        zIndex: zidx
    });

    Node.mapMarker = marker;
    Node.attachMapEvents();
}

/*
    Updates the available count of an existing marker on the map
    Does not update any other properties! Marker position won't change.
    Parameter   Description
    Node        WirelessNode object
*/
function updateMarker(Node) {
    var icon = Node.available > 5 ? 5 : Node.available;
    var zIndex = parseInt(Node.available > 5 ? 5 : Node.available);
    
    Node.mapMarker.setIcon('images/'+icon+'.png');
    Node.mapMarker.setZIndex(zIndex);
}