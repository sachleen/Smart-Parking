/*
    Creates a new Wireless Node
    Parameter   Description
    id          ID of the Node
    latLng      Position to place the marker on the map
    spots       Number of parking spaces connected to this node
    available   Number of parking spaces available or "empty"
*/
function WirelessNode(id, latLng, spots, available) {
    this.id = id;
    this.latLng = latLng;
    this.spots = spots;
    this.available = available
    this.mapMarker = null;
    
    this.dirty = false;
    
    WirelessNodes.push(this);
}

/*
    Finds a node in WirelessNodes array given its ID
    Parameter   Description
    id          ID of Node to find
*/
WirelessNode.findById = function(id) {
    var Node = WirelessNodes.filter(function(Node) {
        return Node.id == id;
    });
    
    return Node[0];
}

/*
    Attaches event handlers to markers
*/
WirelessNode.prototype.attachMapEvents = function() {
    var that = this;
    
    // Open the device's Maps application with directions to this spot when a marker is clicked
    google.maps.event.addListener(this.mapMarker, "click", function (e) {
        var ios = "http://maps.apple.com/?daddr={0},{1}";
        var other = "http://maps.google.com/maps?daddr={0},{1}";
        
        var url = navigator.userAgent.match(/iPhone|iPad|iPod/i) ? ios : other;
        
        document.location.href = url.format(that.latLng.lat(), that.latLng.lng());
    });
}