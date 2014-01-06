/*
    Creates a new Wireless Node
    Parameter   Description
    id          ID of the Node
    latLng      Position to place the marker on the map
    spots       Number of parking spaces connected to this node
*/
function WirelessNode(id, latLng, spots) {
    this.id = id;
    this.latLng = latLng;
    this.spots = spots;
    this.mapMarker = null;
    this.infoWindow = null;
    
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
    Saves Node information to database
*/
WirelessNode.prototype.save = function() {
    console.log("Saving Node");
    console.log(this.id, this.latLng, this.spots);
    
    $.post("/API/nodes/save", {
        id: this.id,
        lat: this.latLng.lat(),
        lng: this.latLng.lng(),
        total: this.spots
    }, function(response) {
        parseResponse(response, "Node Saved!");
    }).fail(function() {
        alert("Error communicating with server.");
    });
}

/*
    Deletes Node from map and database
*/
WirelessNode.prototype.delete = function() {
    $.post("/API/nodes/delete", { id: this.id }, function(response) {
        parseResponse(response, "Node Deleted!");
    }).fail(function() {
        alert("Error communicating with server.");
    });
    
    // Remove the marker and infoWindow from map
    this.infoWindow.setMap(null);
    this.mapMarker.setMap(null);
    
    // Remove node from WirelessNodes array
    var index = jQuery.inArray(this, WirelessNodes);
    WirelessNodes.splice(index, 1);
}

/*
    Attaches click and drag handlers to node marker and infoWindow
*/
WirelessNode.prototype.attachMapEvents = function() {
    var that = this;
    
    // Show the info window when marker is clicked and allow it to be dragged
    google.maps.event.addListener(this.mapMarker, "click", function (e) {
        that.infoWindow.open(map, this);
        this.setDraggable(true);
    });
    
    // If marker has been moved, we need to save the new location
    google.maps.event.addListener(this.mapMarker, 'dragend', function() 
    {
        that.latLng = this.position
        that.dirty = true;
    });
    
    // Disable the marker from being draggable on window close
    google.maps.event.addListener(this.infoWindow,'closeclick',function(){
        that.mapMarker.setDraggable(false);
        
        // Need to save the new data
        if (that.dirty) {
            that.save();
        }
    });
}