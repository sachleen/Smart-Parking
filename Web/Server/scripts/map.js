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
    
    centerMap();
    
    /*
        Allows user to click anywhere on the map to add a new node
    */
    addMarkerListener = google.maps.event.addListener(map, 'click', function(event) {
        addNode(event.latLng);
    });
    
    // for easy testing
    var Node1 = new WirelessNode('ABCDE55555', new google.maps.LatLng(38.56080772372703,-121.42170578241348), '23');
    addMarker(Node1);
    
    getLatLngListener = google.maps.event.addListener(map, 'click', function(event) {
        console.log(event.latLng);
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
        });
    }
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
        icon: 'images/'+~~(Math.random() * 6)+'.png',
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