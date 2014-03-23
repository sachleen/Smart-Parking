#include <avr/wdt.h> // for watchdog timer
#include <SoftwareSerial.h>
#include <RS485.h>
#include "globals.h"
#include "XbeeCommunication.h"

#define XBEE_BAUD 9600
#define QMAX 10

SoftwareSerial xbee(2, 3);
//SoftwareSerial xbee(5, 6);//For Testing on Node board
XBeeCommunication xcomm("00000");//Change here for different bases


String response = ""; // Holds the response from SIM900
String messageFromNode = "";
String apiKey = "e1d1b85eef174d89121da2407f7bb15b";
bool pass = false; // Keeps track of various phases of the connection. Must be set to true during each phase for success

//Keeps track of the number of messages to be sent to the server
int qCount = 0;

//These arrays are what hold the different parts of the messages to be sent to the server
String nodeIds[QMAX];
int spacesAvail[QMAX];
int totalSpaces[QMAX];

int sendResponse;//this holds the response from the sendRequestServer()


void setup()
{
  DEBUG_INIT(9600);
  xbee.begin(XBEE_BAUD); // Communicates with node
  timeout_init(5000);//Starts timer for updates to be sent to server
}

void loop(){
  DEBUG_PRINTLN("====================Beginning of Void Loop====================");
  
  /*
  This limits the sending of updates to the server by sending a maximum of 10 once every minute
  or once the array of requests reaches its maximum
  */
  if(timeout_timedout() || qCount == QMAX){
    if(qCount > 0){//will only send if q isn't empty
      DEBUG_PRINT("Made it to server update. Number of messages: ");
      DEBUG_PRINTLN(qCount);
      delay(1000);
      // for(int i = 0; i < qCount; i++){
        // sendResponse = sendRequestServer(nodeIds[i], 'U', spacesAvail[i], totalSpaces[i]);//Sends a message to the server to update the status of the node
		// if(sendResponse == 1){
			// DEBUG_PRINTLN("Update " + (String)i + " Succeeded");
		// }
		// else{
			// DEBUG_PRINTLN("Update " + (String)i + " Failed");
		// }
      // }
      qCount = 0;
    }
    timeout_init(5000);
  }
  
  messageFromNode = xcomm.getMessage();
  DEBUG_PRINTLN("Message From Node: "+ messageFromNode);
  
  if (messageFromNode != NULL) {
        uint8_t start = 0;
        uint8_t end = messageFromNode.indexOf(',');
        String nodeId = messageFromNode.substring(start, end);
		
		start = end + 1;
		end = messageFromNode.indexOf(',', start);
		String identifier = messageFromNode.substring(start, end);
		//identifier = identifier.trim();
		DEBUG_PRINTLN(nodeId);
		DEBUG_PRINTLN(identifier.length());
		identifier.trim();
		if(identifier=="N"){
			DEBUG_PRINTLN("Number of sensors request from " + nodeId);
            xcomm.sendMessage(nodeId, "2");
		}
		else if(identifier.equals("U")){
			start = end + 1;
			end = messageFromNode.indexOf(',', start);
			uint8_t total = messageFromNode.substring(start, end).toInt();
			
			start = end + 1;
			end = messageFromNode.indexOf(',', start);
			uint8_t available = messageFromNode.substring(start, end).toInt();
			
			DEBUG_PRINTLN("Node:  " + String(nodeId));
			DEBUG_PRINTLN("Total: " + String(total));
			DEBUG_PRINTLN("Avail: " + String(available));
			
			nodeIds[qCount] = nodeId;
			totalSpaces[qCount] = total;
			spacesAvail[qCount] = available;
			qCount++;
			
			DEBUG_PRINTLN("Sending update to server...");
		}
        delay(2000);
    }
    DEBUG_PRINTLN("====================End of Void Loop====================");
    DEBUG_PRINT("Free Ram after loop: ");DEBUG_PRINTLN(freeRam());
}

// int sendRequestServer(String nodeId, char identifierC, int amount, int total){
		// int nodeNumber = -1;
                
                // uint8_t responseStart;
                // uint8_t responseEnd;
                // uint8_t quoteStart;
                // uint8_t quoteEnd;
                
                // String responseTotal;
                // String quoteCheck;
                
		// switch(identifierC){
			// case 'N':
                                // /*
				// DEBUG_PRINT("Sending Number of Sensors Request from : ");
				// DEBUG_PRINTLN(nodeId);
				// nodeNumber = 3;//Will be replaced with response from server
				// break;
                                // */
				
				// DEBUG_PRINT("Sending Number of Sensors Request from : ");
				// DEBUG_PRINTLN(nodeId);
				// //Sending update to server
				// SIM900.listen();
				// // Set the bearer profile identifier to 1 (see bearer initialization in connectToNetwork() phase 4)
				// SIM900.println(F("AT+HTTPPARA=\"CID\",\"1\""));
				// response = sim900Response();
				// if (response.indexOf("OK") < 0) {
					// DEBUG_PRINTLN(F("Error setting CID"));
					// DEBUG_PRINTLN(response);
				// }
				
				// // Set the URL
				// DEBUG_PRINTLN(F("Setting URL"));
				
				// SIM900.println("AT+HTTPPARA=\"URL\",\"http://sachleen.com/sachleen/parking/API/nodes/" + String(nodeId) + "\"");
				// response = sim900Response();
				// DEBUG_PRINTLN("HTTP RESPONSE IS: " + response);

				
				// if (response.indexOf("OK") >= 0) {
					// DEBUG_PRINTLN(F("Set URL"));
					// pass = true;
				// }
				
				// if (pass) {
					// pass = false;
					
					// // Set the action to GET
					// DEBUG_PRINTLN(F("Making HTTP Request"));
					
					// SIM900.println(F("AT+HTTPACTION=0"));
					// response = sim900Response();
						
					// // Check for not only an OK but also a 200 status code.
					// if (response.indexOf("OK") >= 0) {
						// DEBUG_PRINTLN(F("Made request!"));
						// pass = true;
					// } else {
						// response = sim900Response();
						// DEBUG_PRINTLN(response);
					// }
				// }
				
				// if (pass) {
					// // Read response from server. By not providing any parameters, it reads all data.
					// DEBUG_PRINTLN(F("Reading HTTP response data"));
					
					// SIM900.println(F("AT+HTTPREAD"));

					// response = sim900Response();
					// DEBUG_PRINTLN(response);
					// //response = "Success";
					// if (response.indexOf("Success") >= 0) {
						// DEBUG_PRINTLN(F("Request complete!"));
					// } else {
						// DEBUG_PRINTLN("Request did NOT return Success");
						// DEBUG_PRINTLN(response);
					// }
					// responseStart = response.indexOf("total\":\"") + 8;
					// responseEnd = responseStart + 1;
					
					// quoteStart = responseEnd;
					// quoteEnd = responseStart + 2;
					// quoteCheck = response.substring(quoteStart, quoteEnd);
					
					
					// if(quoteCheck.equals("\"")){
						// responseTotal = response.substring(responseStart, responseEnd);
					// }
					// else{
						// responseTotal = response.substring(responseStart, responseEnd + 1);
					// }
					// nodeNumber = responseTotal.toInt();
				// }
				// //response = responseFromServer;
				// //This case (of char 'N') should return the number of sensors at the node
				// //Needs parsing of string
				// //nodeNumber = responseFromServer;
				// break;
				
			// case 'U':
				// DEBUG_PRINT("Sending Update Message to Server: ");
				// DEBUG_PRINTLN(nodeId + ',' + amount + ',' + total);
				// nodeNumber = 1;
				// break;
			// default:
				// DEBUG_PRINTLN("ERROR: Unrecognized Request");
		// }
		// //waits for a request form the server
		// return nodeNumber;
// }

// void sendMessageNode(String targetId,int sensorCount){
		
	// /*
	// DEBUG_PRINT(F("Sending message to node:"));
	// DEBUG_PRINTLN(targetId + ',' + sensorCount);
	// */

	// String messageToNode = targetId + "," + (String)sensorCount;
	// xbee.listen();
	// xbee.println(messageToNode);
		
// }


// String getNodeMessage() {

	// //This will get any message being sent from a node
	// xbee.listen();
	// String incomingNodeMessage = xbeeResponse();
	// DEBUG_PRINTLN(F("Message From Node"));
	// DEBUG_PRINTLN(incomingNodeMessage);

	// uint8_t start = 0;
	// uint8_t end = incomingNodeMessage.indexOf(',');
	// String targetNode = incomingNodeMessage.substring(start, end);
	
	// sendMessageNode(targetNode, 0);//number sent is arbitrary. Lets the node know it received the message
	
	// return incomingNodeMessage;
// }

int freeRam () 
{
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

/*
    Software Reset Functions
*/

/*
    Enables the watchdog timer and starts an infinite loop so the uC restarts
*/
void soft_reset() {
   wdt_enable(WDTO_15MS);
   while(1) {};
}

/*
    Disabled the watchdog timer as soon as possible on startup (before bootloader) so it doesn't continually restart chip.
*/
void wdt_init(void) __attribute__((naked)) __attribute__((section(".init3")));
void wdt_init(void)
{
   MCUSR = 0;
   wdt_disable();

   return;
}

// Timeout Functions
// ========================================
unsigned long _timeout_end = 0;

void timeout_init(int timeoutms) {
    _timeout_end = millis() + timeoutms;
}
unsigned long timeout_remaining() {
    return _timeout_end-millis();
}
bool timeout_timedout() {
    return millis() > _timeout_end;
}

