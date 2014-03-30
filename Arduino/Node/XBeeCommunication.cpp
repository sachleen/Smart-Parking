#include "Arduino.h"
#include "XBeeCommunication.h"
#include <SoftwareSerial.h>

extern SoftwareSerial xbee;

/*
    Constructor
*/
XBeeCommunication::XBeeCommunication(String nodeId)
{
    // TODO: INITIATE XBEE SOFTWARE SERIAL
    
    _nodeId = nodeId;
}

/*
    Reads a message from the XBee.
    
    Returns a String containing the message iff it was addressed to this node.
    Returns Null otherwise.
*/
String XBeeCommunication::getMessage() {
    xbee.listen();
    String xResponse = xbeeResponse();
    
    uint8_t start = 0;
    uint8_t end = xResponse.indexOf(',');
    
    String targetNode = xResponse.substring(start, end);
    
    if(targetNode.equals(_nodeId)) {
        return xResponse.substring(end+1);
    } else {
        DEBUG_PRINTLN("getMessage: node ID not match, return NULL");
        return NULL;
    }
}

/*
    Broadcast a message to other XBees
    
    Parameter   Description
    nodeIdTo    String containing the id of the receiving node.
    message     String containing message to broadcast
*/
void XBeeCommunication::sendMessage(String nodeIdTo, String message) {
    xbee.listen();
    
    // Message format: <NodeTo>,<NodeFrom>,<Message>
    message = nodeIdTo + ',' + _nodeId + ',' + message;
    xbee.println(message);
}

/*
    Reads data from XBee's input serial buffer until '\n'
    Returns a '\n' terminated string.
    Returns null upon timeout after ~2.5s
*/
String XBeeCommunication::xbeeResponse() {
    xbee.listen();
    String content = "";
    int counter = 0;
    while(!xbee.available() && counter < 250) {
        counter++;
        delay(10);
    }
    
    if (counter >= 2500) {
        DEBUG_PRINTLN(F("XBEE Timed Out"));
        return NULL;
    }
    
    while (xbee.available()) {
        char input = xbee.read();
        content.concat(input);
        if (input == '\n') {
            break;
        }
        delay(1);
    }
    
    return content;
}