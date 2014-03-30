#include <avr/wdt.h> // for watchdog timer
#include <SoftwareSerial.h>
#include <RS485.h>
#include "globals.h"
#include "XbeeCommunication.h"
#include "SIMCommunication.h"

#define XBEE_BAUD 9600
#define QMAX 10

SoftwareSerial xbee(2, 3);
XBeeCommunication xcomm("00000");//Change here for different bases

SoftwareSerial SIM900(7, 8);
SIMCommunication simcomm(4800, 9);


String response = "";
String apiKey = "8ce367853467bbfe56a51d9eac208318";
bool pass = false; // Keeps track of various phases of the connection. Must be set to true during each phase for success

//Keeps track of the number of messages to be sent to the server
uint8_t qCount = 0;

uint8_t loopCount = 0;

//These arrays are what hold the different parts of the messages to be sent to the server
String nodeIds[QMAX];
uint8_t spacesAvail[QMAX];
//uint8_t totalSpaces[QMAX];

int freeRam () 
{
      extern int __heap_start, *__brkval; 
      int v; 
      return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

void setup()
{
    DEBUG_INIT(9600);
    xbee.begin(XBEE_BAUD); // Communicates with node
    //timeout_init(5000);//Starts timer for updates to be sent to server
    
    /*This starts the network connection*/
    while (!simcomm.isOn()) {
        simcomm.togglePower();
    }
    DEBUG_PRINT("Pwr ");DEBUG_PRINTLN(simcomm.isOn() ? "ON" : "OFF");

    if (!simcomm.connectToNetwork()) {
        DEBUG_PRINTLN(F("Network Connection Failed."));
    }
}

void loop() {
    DEBUG_PRINTLN(freeRam());
    
    /*
    This limits the sending of updates to the server by sending a maximum of 10 once every minute
    or once the array of requests reaches its maximum
    */
    if(loopCount > 9 || qCount == QMAX) {
        if(qCount > 0) {//will only send if q isn't empty
            DEBUG_PRINT(F("Made it to server update. Number of messages: "));
            DEBUG_PRINTLN(qCount);
            delay(1000);
            
            for(int i = 0; i < qCount; i++) {
                response = simcomm.POSTRequest("id=" + nodeIds[i] + "&" + "available=" + spacesAvail[i] + "&api_key=" + apiKey);
                if (response.indexOf("TRUE") < 0) {
                    DEBUG_PRINTLN("Update " + (String)i + " Failed");
                } else{
                    DEBUG_PRINTLN("Update " + (String)i + " Succeeded");
                }
            }
            qCount = 0;
        }
        //timeout_init(5000);
        loopCount = 0;
    }
  
    response = xcomm.getMessage();
    DEBUG_PRINT(F("Message From Node: "));DEBUG_PRINTLN(response);
  
    if (response != NULL) {
        uint8_t start = 0;
        uint8_t end = response.indexOf(',');
        String nodeId = response.substring(start, end);
		DEBUG_PRINTLN(nodeId);
        
        xcomm.sendMessage(nodeId, "OK");
        start = end + 1;
        end = response.indexOf(',', start);
        uint8_t available = response.substring(start, end).toInt();

        DEBUG_PRINTLN("Avail: " + String(available));

        nodeIds[qCount] = nodeId;
        spacesAvail[qCount] = available;
        qCount++;

        // DEBUG_PRINTLN(F("Storing in queue..."));

        
        // uint8_t start = 0;
        // uint8_t end = response.indexOf(',');
        // String nodeId = response.substring(start, end);
		// DEBUG_PRINTLN(nodeId);
        
        // start = end + 1;
		// end = response.indexOf(',', start);
        // String identifier = response.substring(start, end);
        
		// //DEBUG_PRINTLN(identifier.length());
		// identifier.trim();
		// if(identifier=="N"){
			// DEBUG_PRINT(F("num req frm "));DEBUG_PRINTLN(nodeId);
			// //DEBUG_PRINTLN(F("Making HTTP GET Request"));
			// response = simcomm.HTTPRequest(0, nodeId);
			// DEBUG_PRINTLN(response);
			// if(response != NULL){
				// response.trim();//might not need(?)
				// //JSON Parsing
				// start = response.indexOf("id\":\"") + 5;
				// end = start + 5;
				// //nodeId = response.substring(responseStart, responseEnd);//for testing
				// nodeId = response.substring(start, end);
				
				// start = response.indexOf("total\":\"") + 8;
				// end = start + 1;
				
				// String total;

				// uint8_t quoteStart = end;
				// uint8_t quoteEnd = start + 2;
				// String quoteCheck = response.substring(quoteStart, quoteEnd);
				
				
				// if(quoteCheck.equals("\"")){
					// total = response.substring(start, end);
				// }
				// else{
					// total = response.substring(start, end + 1);
				// }
				
				// xcomm.sendMessage(nodeId, total);//Sends reponse from server back to node
			// }
			// else{
				// DEBUG_PRINTLN(F("Get request returned NULL"));
			// }

		// }
		// else if(identifier.equals("U")){
            // xcomm.sendMessage(nodeId, "OK");
            // start = end + 1;
            // end = response.indexOf(',', start);
            // uint8_t total = response.substring(start, end).toInt();

            // start = end + 1;
            // end = response.indexOf(',', start);
            // uint8_t available = response.substring(start, end).toInt();

            // DEBUG_PRINTLN("Node:  " + String(nodeId));
            // DEBUG_PRINTLN("Total: " + String(total));
            // DEBUG_PRINTLN("Avail: " + String(available));

            // nodeIds[qCount] = nodeId;
            // totalSpaces[qCount] = total;
            // spacesAvail[qCount] = available;
            // qCount++;

            // DEBUG_PRINTLN(F("Storing in queue..."));
		// }
        delay(2000);
    }
	loopCount = loopCount + 1;
}

// /*
    // Software Reset Functions
// */

// /*
    // Enables the watchdog timer and starts an infinite loop so the uC restarts
// */
// void soft_reset() {
   // wdt_enable(WDTO_15MS);
   // while(1) {};
// }

// /*
    // Disabled the watchdog timer as soon as possible on startup (before bootloader) so it doesn't continually restart chip.
// */
// void wdt_init(void) __attribute__((naked)) __attribute__((section(".init3")));
// void wdt_init(void)
// {
   // MCUSR = 0;
   // wdt_disable();

   // return;
// }

// // Timeout Functions
// // ========================================
// unsigned long _timeout_end = 0;

// void timeout_init(int timeoutms) {
    // _timeout_end = millis() + timeoutms;
// }
// unsigned long timeout_remaining() {
    // return _timeout_end-millis();
// }
// bool timeout_timedout() {
    // return millis() > _timeout_end;
// }

