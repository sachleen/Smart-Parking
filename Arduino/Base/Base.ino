#define DEBUG_ENABLED

#include <avr/wdt.h> // for watchdog timer
#include <SoftwareSerial.h>
#include <RS485.h>
#include "globals.h"
#include "XbeeCommunication.h"
#include "SIMCommunication.h"

#define XBEE_BAUD 9600
#define QMAX 5

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
                DEBUG_PRINTLN(response);
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
  
    if (response != NULL) {
        DEBUG_PRINT(F("Message From Node: "));DEBUG_PRINTLN(response);
        
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

        delay(2000);
    }
	loopCount = loopCount + 1;
}