/*
    Creates a new Wireless Node
    Parameter   Description
    id          ID of the Node
    latLng      Position to place the marker on the map
    spots       Number of parking spaces connected to this node
    avail       Number of parking spaces available or "empty"
*/
function WirelessNode(id, latLng, spots, avail) {
    this.id = id;
    this.latLng = latLng;
    this.spots = spots;
    this.avail = avail
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