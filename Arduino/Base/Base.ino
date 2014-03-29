#include <avr/wdt.h> // for watchdog timer
#include <SoftwareSerial.h>
#include <RS485.h>
#include "globals.h"
#include "XbeeCommunication.h"
#include "SIMCommunication.h"

#define XBEE_BAUD 9600
#define QMAX 10

SoftwareSerial xbee(2, 3);
//SoftwareSerial xbee(5, 6);//For Testing on Node board
SoftwareSerial SIM900(7, 8);

XBeeCommunication xcomm("00000");//Change here for different bases
SIMCommunication simcomm(4800, 9);


String response = ""; // Holds the response from SIM900
String messageFromNode = "";
String apiKey = "8ce367853467bbfe56a51d9eac208318";
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
  /*This starts the network connection*/
  while (!simcomm.isOn()) {
    simcomm.togglePower();
  }
  DEBUG_PRINT("Power Status:");DEBUG_PRINTLN(simcomm.isOn() ? "ON" : "OFF");

  if (simcomm.connectToNetwork()) {
    DEBUG_PRINTLN(F("Connected!"));
  } else {
    DEBUG_PRINTLN(F("Network Connection Failed."));
  }
  
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
      for(int i = 0; i < qCount; i++){
		DEBUG_PRINTLN(F("Making HTTP POST Request"));
		simcomm.HTTPRequest(1, "http://sachleen.com/sachleen/parking/API/nodes/save", "id=" + nodeIds[i] + "&" + "available=" + spacesAvail[i] + "&api_key=" + apiKey);
        //sendResponse = sendRequestServer(nodeIds[i], 'U', spacesAvail[i], totalSpaces[i]);//Sends a message to the server to update the status of the node
		DEBUG_PRINTLN(response);//Idk what the response is supposed to be yet...
		if (response.indexOf("TRUE") < 0) {
			DEBUG_PRINTLN("Update " + (String)i + " Failed");
		}
		else{
			DEBUG_PRINTLN("Update " + (String)i + " Succeeded");
		}
      }
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
		DEBUG_PRINTLN(nodeId);
		//DEBUG_PRINTLN(identifier.length());
		identifier.trim();
		if(identifier=="N"){
			DEBUG_PRINTLN("Number of sensors request from " + nodeId);
			DEBUG_PRINTLN(F("Making HTTP GET Request"));
			response = simcomm.HTTPRequest(0, "http://sachleen.com/sachleen/parking/API/nodes/" + nodeId, "");
			DEBUG_PRINTLN(response);
			response.trim();//might not need(?)
			//JSON Parsing
			uint8_t responseStart = response.indexOf("id\":\"") + 5;
			uint8_t responseEnd = responseStart + 5;
			String nodeId = response.substring(responseStart, responseEnd);//for testing
			//nodeId = response.substring(start, end);
			
			responseStart = response.indexOf("total\":\"") + 8;
			responseEnd = responseStart + 1;
			
			String total;

			uint8_t quoteStart = responseEnd;
			uint8_t quoteEnd = responseStart + 2;
			String quoteCheck = response.substring(quoteStart, quoteEnd);
			
			
			if(quoteCheck.equals("\"")){
				total = response.substring(responseStart, responseEnd);
			}
			else{
				total = response.substring(responseStart, responseEnd + 1);
			}
			
            xcomm.sendMessage(nodeId, total);//Sends reponse from server back to node
		}
		else if(identifier.equals("U")){
			xcomm.sendMessage(nodeId, "OK");
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
			
			DEBUG_PRINTLN("Storing in queue...");
		}
        delay(2000);
    }
    DEBUG_PRINTLN("====================End of Void Loop====================");
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

