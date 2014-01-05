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
}

WirelessNode.prototype.attachMapEvents = function() {
    var that = this;
    console.log(that);
    
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
        
        console.log("CLOSECLICK");
        // Need to save the new data
        if (that.dirty) {
            console.log ("Save node to database!");
        }
    });
}

