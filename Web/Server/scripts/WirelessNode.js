function WirelessNode(id, latLng, spots) {
    this.id = id;
    this.latLng = latLng;
    this.spots = spots;
    this.mapMarker = null;
    this.infoWindow = null;
    
    this.dirty = false;
    
    WirelessNodes.push(this);
    
    this.save();
}

WirelessNode.prototype.save = function() {
    console.log("Saving Node");
    console.log(this.id, this.latLng, this.spots);
    
    // Make API call here
}

WirelessNode.prototype.delete = function() {
    console.log("Deleting Node");
    console.log(this.id, this.latLng, this.spots);
    
    // Make API call here
    
    // Remove the marker and infoWindow from map
    this.infoWindow.setMap(null);
    this.mapMarker.setMap(null);
    
    // Remove node from WirelessNodes array
    var index = jQuery.inArray(this, WirelessNodes);
    WirelessNodes.splice(index, 1);
}

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