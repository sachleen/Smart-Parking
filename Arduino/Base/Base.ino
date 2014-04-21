#define DEBUG_ENABLED

#include <avr/wdt.h> // for watchdog timer
#include <SoftwareSerial.h>
#include <RS485.h>
#include "globals.h"
#include "XbeeCommunication.h"
#include "SIMCommunication.h"

#define XBEE_BAUD 9600
#define QMAX 5
#define LOOP_MAX 14
#define SIM_RST 3

//SoftwareSerial xbee(2, 3);
SoftwareSerial xbee(5, 6);
XBeeCommunication xcomm("00000");//This gives the Base a TargetID of "00000"

//SoftwareSerial SIM900(7, 8);
SoftwareSerial SIM900(8, 7);
//SIMCommunication simcomm(4800, 9);
SIMCommunication simcomm(4800, 2);

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
    pinMode(SIM_RST, OUTPUT);
    digitalWrite(SIM_RST, LOW);
    /*Commented out for demo*/
    /*
    while (simcomm.isOn()) {
        simcomm.togglePower();
        DEBUG_PRINTLN(F("Toggling power"));
    }
    DEBUG_PRINT("Pwr ");DEBUG_PRINTLN(simcomm.isOn() ? "ON" : "OFF");
    */
    /*This starts the network connection*/
    /*Normally commented out, but we're avoiding an issue with network connectivity*/
    
    while (!simcomm.isOn()) {
        simcomm.togglePower();
    }
    DEBUG_PRINT("Pwr ");DEBUG_PRINTLN(simcomm.isOn() ? "ON" : "OFF");

    while (!simcomm.connectToNetwork()) {
        DEBUG_PRINTLN(F("Network Connection Failed."));
    }
    
}

void loop() {
    DEBUG_PRINTLN(freeRam());
    
    /*
    This limits the sending of updates to the server by sending a maximum of 10 once every time the loopCount reaches the max
    or once the array of requests reaches its maximum (Each loop is 2 seconds. Right now it is set to update the server every 30 seconds.)
    */
    //qCount = 1;//for testing
    //loopCount = 0;
    
    if(loopCount > LOOP_MAX || qCount == QMAX) {
        if(qCount > 0) {//will only send if q isn't empty
            DEBUG_PRINT(F("Made it to server update. Number of messages: "));
            DEBUG_PRINTLN(qCount);
            delay(1000);
            /*
            while (!simcomm.isOn()) {
		simcomm.togglePower();//Turn on SIM900
	    }
            while (!simcomm.connectToNetwork()) {//The loop will keep running until it is connected to the network
              DEBUG_PRINTLN(F("Network Connection Failed."));
            }
            */
            /*Following block commented out to keep SIM900 on to avoid connectivity issue*/
            /*
            bool netConnect = false;
            int connectCount = 0;
            while (!simcomm.isOn() || !netConnect) {
                connectCount = 0;
		DEBUG_PRINTLN(F("Resetting SIM and Network Connection"));
                while (!simcomm.isOn()) {
		  simcomm.togglePower();//Turn on SIM900
                  DEBUG_PRINTLN(F("Toggling Power"));
                  DEBUG_PRINT("Pwr ");DEBUG_PRINTLN(simcomm.isOn() ? "ON" : "OFF");
	        }
                while(connectCount < 3){
                  if (!simcomm.connectToNetwork()) {//The loop will keep running until it is connected to the network
                    DEBUG_PRINTLN(F("Network Connection Failed."));
                    netConnect = false;
                    connectCount++;
                  }
                  else {
                    netConnect = true;
                    break;
                  }
                }
                if(netConnect){
                  break;
                }
                else{
                  while (simcomm.isOn()) {
                    simcomm.togglePower();//Turn off SIM900
                    DEBUG_PRINTLN("Power cycling");
                    DEBUG_PRINT("Pwr ");DEBUG_PRINTLN(simcomm.isOn() ? "ON" : "OFF");
                  }
                }
	    }
            */
	    //DEBUG_PRINT("Pwr ");DEBUG_PRINTLN(simcomm.isOn() ? "ON" : "OFF");
            //DEBUG_PRINT("Network Connection Successful!");
            
            for(int i = 0; i < qCount; i++) {
                response = simcomm.POSTRequest("id=" + nodeIds[i] + "&" + "available=" + spacesAvail[i] + "&api_key=" + apiKey);
                DEBUG_PRINTLN(response);
                if (response.indexOf("TRUE") < 0) {
                    DEBUG_PRINTLN("Update " + (String)(i+1) + " Failed");
                } else{
                    DEBUG_PRINTLN("Update " + (String)(i+1) + " Succeeded");
                }
            }
            qCount = 0;
        }
        loopCount = 0;
        /*Commented out to avoid connectivity issue*/
        /*
        while (simcomm.isOn()) {
	    simcomm.togglePower();//Turn off SIM900
	}
	DEBUG_PRINT("Pwr ");DEBUG_PRINTLN(simcomm.isOn() ? "ON" : "OFF");
        */
    }
    
  
    response = xcomm.getMessage();
    /**
     * The message receive will be in the form [NodeId],[Identifier],[AvailableSpots]
     * The following block will parse the message and store the necessary values
     */
    if (response != NULL) {
        DEBUG_PRINT(F("Message From Node: "));DEBUG_PRINTLN(response);
        
        uint8_t start = 0;
        uint8_t end = response.indexOf(',');
        String nodeId = response.substring(start, end);
	DEBUG_PRINTLN(nodeId);
        
	start = end + 1;
	end = response.indexOf(',', start);
        String identifier = response.substring(start, end);
	identifier.trim();
	
        /**
         * This "N" case uses hardcoded values. We are able to get the values from the Server,
         * but our memory constraints do not currently allow us to implement that feature.
         * We do however have the code necessary to do this.
         */	
	if(identifier=="N"){
		int total = -1;
		if (nodeId == "TEST1")
			total = 2;
		else if(nodeId == "TEST2")
			total = 3;
		xcomm.sendMessage(nodeId, String(total));
	}
		
	if(identifier=="U"){
		xcomm.sendMessage(nodeId, "OK");
		start = end + 1;
		end = response.indexOf(',', start);
		uint8_t available = response.substring(start, end).toInt();

		DEBUG_PRINTLN("Avail: " + String(available));
                
                //Here we add the NodeId and the number of available spaces to their respective arrays to be sent to the server at update time
		nodeIds[qCount] = nodeId;
		spacesAvail[qCount] = available;
		qCount++;
	}

        delay(2000);
    }
    loopCount = loopCount + 1;
}
