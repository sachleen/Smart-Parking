#include "Arduino.h"
#include "XBeeCommunication.h"
#include <RS485.h>

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
        DEBUG_PRINT("Returning: ");
        DEBUG_PRINTLN(xResponse.substring(end));
        return xResponse.substring(end);
    } else {
        DEBUG_PRINTLN("Returning NULL");
        return NULL;
    }
}

/*
    Broadcast a message to other XBees
    
    Parameter   Description
    nodeIdTo    String containing the id of the receiving node.
    message     String containing message to broadcast
    
    Returns true if the message was broadcast successfully. False otherwise.
*/
bool XBeeCommunication::sendMessage(String nodeIdTo, String message) {
    xbee.listen();
    
    // Message format: <NodeTo>,<NodeFrom>,<Message>
    message = nodeIdTo + ',' + _nodeId + ',' + message;
    xbee.println(message);
    
    DEBUG_PRINT("sent: ");DEBUG_PRINTLN(message);
    
    String response = getMessage();
    
    DEBUG_PRINT("got back: ");DEBUG_PRINTLN(response);
    
    if (response == NULL || response != "OK") {
        return false;
    }
    
    return true;
}

/*
    Reads data from XBee's input serial buffer until '\n'
    Returns a '\n' terminated string.
    Returns null upon timeout after ~2.5s
*/
String XBeeCommunication::xbeeResponse() {
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
    
    // Clear rest of input buffer
    while (xbee.available()) {
        xbee.read();
    }
    
    return content;
}