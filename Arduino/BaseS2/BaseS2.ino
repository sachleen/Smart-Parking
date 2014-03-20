#include <avr/wdt.h> // for watchdog timer
#include <SoftwareSerial.h>

#define SIM900_BAUD 2400
#define XBEE_BAUD 9600
#define QMAX 10

SoftwareSerial SIM900(7, 8);
SoftwareSerial xbee(2, 3);
//SoftwareSerial xbee(5, 6);//For Testing on Node board


String response = ""; // Holds the response from SIM900
String messageFromNode = "";
String apiKey = "e1d1b85eef174d89121da2407f7bb15b";
bool pass = false; // Keeps track of various phases of the connection. Must be set to true during each phase for success

//These values were used for testing

int val1 = 0;
int val2 = 0;
int button = 0;
String test = "1";
String amountToSend = "";

//Keeps track of the number of messages to be sent to the server
int qCount = 0;

//These arrays are what hold the different parts of the messages to be sent to the server
String nodeIds[QMAX];
int spacesAvail[QMAX];
int totalSpaces[QMAX];

int sendResponse;//this holds the response from the sendRequestServer()


void setup()
{
  Serial.begin(9600);
  SIM900.begin(SIM900_BAUD);// Communicates with Server
  powerSIM900();
  connectToNetwork();
  xbee.begin(XBEE_BAUD); // Communicates with node
  timeout_init(5000);//Starts timer for updates to be sent to server
}

void loop(){
  Serial.println(F("====================Beginning of Void Loop===================="));
  
  /*
  This limits the sending of updates to the server by sending a maximum of 10 once every minute
  or once the array of requests reaches its maximum
  */
  if(timeout_timedout() || qCount == QMAX){
    if(qCount > 0){//will only send if q isn't empty
      Serial.print(F("Made it to server update. Number of messages: "));
      Serial.println(qCount);
      delay(1000);
      for(int i = 0; i < qCount; i++){
        sendResponse = sendRequestServer(nodeIds[i], 'U', spacesAvail[i], totalSpaces[i]);//Sends a message to the server to update the status of the node
		if(sendResponse == 1){
			Serial.println("Update " + (String)i + " Succeeded");
		}
		else{
			Serial.println("Update " + (String)i + " Failed");
		}
      }
      qCount = 0;
    }
    timeout_init(5000);
  }
  
  //TODO - Replace with getNodeMessage()
  messageFromNode = getNodeMessage();
  /*
  xbee.listen();
  messageFromNode = xbeeResponse();
  Serial.println("Message From Node: "+ messageFromNode);
  */
  
  if (messageFromNode != NULL) {
        uint8_t start = 0;
        uint8_t end = messageFromNode.indexOf(',');
        String nodeId = messageFromNode.substring(start, end);
        
        start = end + 1;
        end = messageFromNode.indexOf(',', start);
        uint8_t total = messageFromNode.substring(start, end).toInt();
        
        start = end + 1;
        end = messageFromNode.indexOf(',', start);
        uint8_t available = messageFromNode.substring(start, end).toInt();
        
        Serial.println("Node:  " + String(nodeId));
        Serial.println("Total: " + String(total));
        Serial.println("Avail: " + String(available));
        delay(2000);
        /*
		Can use other numbers above 32 for different cases
		At power-on, Node will have 99 set as number of sensors so that it knows to ask server for number
		*/
        if(total == 99){
			int numSensors = sendRequestServer(nodeId, 'N', 0, 0);
			//sendMessageNode(nodeId, 3);//Using this for testing
                        sendMessageNode(nodeId, numSensors);
        }
        else{
          //We add the NodeId, Total, and available to their respective arrays to send later
          nodeIds[qCount] = nodeId;
          totalSpaces[qCount] = total;
          spacesAvail[qCount] = available;
          qCount++;
        }
    }
    Serial.println(F("====================End of Void Loop===================="));
    Serial.print("Free Ram after loop: ");Serial.println(freeRam());
}

/*
    Power on sequence
    Holds pin 9 (power button) high for 2 seconds to toggle device power.
    NOTE: this toggles the power and works under the assumption that the module is initially OFF.
*/
void powerSIM900() {
    Serial.println(F("Toggling Power"));
    pinMode(9, OUTPUT);
    digitalWrite(9,LOW);
    delay(1000);
    digitalWrite(9,HIGH);
    delay(2000);
    digitalWrite(9,LOW);
    delay(1000);
    Serial.println(F("Done"));
}

int sendRequestServer(String nodeId, char identifierC, int amount, int total){
		int nodeNumber = -1;
                
                uint8_t responseStart;
                uint8_t responseEnd;
                uint8_t quoteStart;
                uint8_t quoteEnd;
                
                String responseTotal;
                String quoteCheck;
                
		switch(identifierC){
			case 'N':
                                /*
				Serial.print("Sending Number of Sensors Request from : ");
				Serial.println(nodeId);
				nodeNumber = 3;//Will be replaced with response from server
				break;
                                */
				
				Serial.print("Sending Number of Sensors Request from : ");
				Serial.println(nodeId);
				//Sending update to server
				SIM900.listen();
				// Set the bearer profile identifier to 1 (see bearer initialization in connectToNetwork() phase 4)
				SIM900.println(F("AT+HTTPPARA=\"CID\",\"1\""));
				response = sim900Response();
				if (response.indexOf("OK") < 0) {
					Serial.println(F("Error setting CID"));
					Serial.println(response);
				}
				
				// Set the URL
				Serial.println(F("Setting URL"));
				
				SIM900.println("AT+HTTPPARA=\"URL\",\"http://sachleen.com/sachleen/parking/API/nodes/" + String(nodeId) + "\"");
				response = sim900Response();
				Serial.println("HTTP RESPONSE IS: " + response);

				
				if (response.indexOf("OK") >= 0) {
					Serial.println(F("Set URL"));
					pass = true;
				}
				
				if (pass) {
					pass = false;
					
					// Set the action to GET
					Serial.println(F("Making HTTP Request"));
					
					SIM900.println(F("AT+HTTPACTION=0"));
					response = sim900Response();
						
					// Check for not only an OK but also a 200 status code.
					if (response.indexOf("OK") >= 0) {
						Serial.println(F("Made request!"));
						pass = true;
					} else {
						response = sim900Response();
						Serial.println(response);
					}
				}
				
				if (pass) {
					// Read response from server. By not providing any parameters, it reads all data.
					Serial.println(F("Reading HTTP response data"));
					
					SIM900.println(F("AT+HTTPREAD"));

					response = sim900Response();
					Serial.println(response);
					//response = "Success";
					if (response.indexOf("Success") >= 0) {
						Serial.println(F("Request complete!"));
					} else {
						Serial.println("Request did NOT return Success");
						Serial.println(response);
					}
					responseStart = response.indexOf("total\":\"") + 8;
					responseEnd = responseStart + 1;
					
					quoteStart = responseEnd;
					quoteEnd = responseStart + 2;
					quoteCheck = response.substring(quoteStart, quoteEnd);
					
					
					if(quoteCheck.equals("\"")){
						responseTotal = response.substring(responseStart, responseEnd);
					}
					else{
						responseTotal = response.substring(responseStart, responseEnd + 1);
					}
					nodeNumber = responseTotal.toInt();
				}
				//response = responseFromServer;
				//This case (of char 'N') should return the number of sensors at the node
				//Needs parsing of string
				//nodeNumber = responseFromServer;
				break;
				
			case 'U':
				Serial.print("Sending Update Message to Server: ");
				Serial.println(nodeId + ',' + amount + ',' + total);
				nodeNumber = 1;
				break;
			default:
				Serial.println("ERROR: Unrecognized Request");
		}
		//waits for a request form the server
		return nodeNumber;
}

void sendMessageNode(String targetId,int sensorCount){
		
	/*
	Serial.print(F("Sending message to node:"));
	Serial.println(targetId + ',' + sensorCount);
	*/

	String messageToNode = targetId + "," + (String)sensorCount;
	xbee.listen();
	xbee.println(messageToNode);
		
}


String getNodeMessage() {

	//This will get any message being sent from a node
	xbee.listen();
	String incomingNodeMessage = xbeeResponse();
	Serial.println(F("Message From Node"));
	Serial.println(incomingNodeMessage);

	uint8_t start = 0;
	uint8_t end = incomingNodeMessage.indexOf(',');
	String targetNode = incomingNodeMessage.substring(start, end);
	
	sendMessageNode(targetNode, 0);//number sent is arbitrary. Lets the node know it received the message
	
	return incomingNodeMessage;
}

/*
    Returns a string with the response from the SIM900 module.
    NOTE: This is a blocking function.
          It will wait until it gets a response or times out after 2.5s and returns NULL.
          If it gets a response it will keep reading until an OK or ERROR (or Call Ready for initial power on) is received.
          If it does not receive an OK or ERROR within 5 seconds, it will time out and return NULL.
*/
String sim900Response() {
    String content = "";
    int counter = 0;
    while(!SIM900.available() && counter < 2500) {
        counter++;
        delay(1);
    }
    
    // Timed out, return null
    if (counter >= 2500) {
        return NULL;
    }
    counter = 0;
    
    // Keep reading until we get an OK or ERROR or call ready for initial power on signifying the end of the response.
    while (content.indexOf("OK") < 0 && content.indexOf("ERROR") < 0 && content.indexOf("Call Ready") <= 0 && counter < 5000) {
        while(SIM900.available()) {
            char input = SIM900.read();
            content.concat(input);
            delay(1); // allows the buffer to keep filling as we read it.
            counter = 0; // reset the timeout because we just got data.
        }
        counter++;
    }

    if (counter >= 9000) {
        return NULL;
    }
    counter = 0;
    
    /*
        HTTPACTION returns some useful data after OK so we have to keep reading...
        
        Example response:
        AT+HTTPACTION=0
        OK
        +HTTPACTION:0,200,7
    */
    if (content.indexOf("HTTPACTION") >= 0) {

        while(!SIM900.available() && counter < 2500) {
            counter++;
            delay(1);
        }
        
        if (counter >= 2500) {
            return NULL;
        }
        counter = 0;
        
        while(SIM900.available()) {
            char input = SIM900.read();
            content.concat(input);
            delay(1); // allows the buffer to keep filling as we read it.
        }
    }
    
    return content;
}

/*
    Returns a string with the data from the XBee module up until the first new line.
    NOTE: This is a blocking function. It will wait until it gets data or times out after 2.5s
*/
String xbeeResponse() {
    String content = "";
    int counter = 0;
    while(!xbee.available() && counter < 250) {
        counter++;
        delay(10);
    }
    
    if (counter >= 250) {
        Serial.println(F("XBEE Timed Out"));
        return NULL;
    }
    
    while (xbee.available()) {
        char input = xbee.read();
        //Serial.println("Xbee response: " + input);
        content.concat(input);
        if (input == '\n') {
            break;
        }
        delay(1);
    }
    
    xbee.flush();
    return content;
}

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

/*
    Connects to the cellular network and sets up for HTTP.
    Read the comments before each phase of the connection for details.
*/
/*
void connectToNetwork() {
    Serial.println(F("connectToNetwork() function call"));
	delay(2000);
}
*/


void connectToNetwork() {
    SIM900.listen();
    /*
        Phase 1
        After power on, device will try to connect to network.
        This can take a bit, timeout is about 10 seconds, but usually takes 3-4 seconds.
        
        Expected response:
        RDY
        +CFUN: 1
        +CPIN: READY
        +PACSP: 0
        Call Ready      This is what we're looking for.
    */
    Serial.println(F("\nPhase 1 - connect to network"));
    for (int i = 0; i < 10; i++) {
        Serial.println("Waiting... " + String(i+1) + " of 10");
        
        // Read input from SIM900
        response = sim900Response();
        
        // Check against what we want
        if (response.indexOf("Call Ready") >= 0) {
            Serial.println(F("Connected to network!"));
            pass = true;
            break;
        }
    }
    
    delay(1000);
    
    /*
        Phase 2
        Check GPRS attach status with AT+CREG
        
        Possible responses from AT+CREG:
        AT+CREG:0,0    Trying to attach.
        AT+CREG:0,1    Attached.
        AT+CREG:0,2    Failed and stopped.
        AT+CREG:0,3    Banned Networks.
        AT+CREG:0,5    Logged in and roaming.
        
        The first value in the response is the network technology and the second is the connection status.
        We only care that the device is registered, so only look for a "1" in the second number.
    */
    if (pass) {
        pass = false;
        
        Serial.println(F("\nPhase 2 - Check GPRS Status"));
        
        for (int i = 0; i < 5; i++) {
            Serial.println("Waiting... " + String(i+1) + " of 5");
            
            SIM900.println(F("AT+CREG?"));
            response = sim900Response();
            
            // Look for that 1 in the second value of the response
            if (response.indexOf(",1") >= 0 || response.indexOf(",5") >= 0) {
                // registered (1) OR registered and roaming. (5) - both should work, I think.
                Serial.println(F("Attached to network!"));
                pass = true;
                break;
            } else if (response.indexOf(",2") >= 0) {
                // Not registered but searching
                delay(1000);
                i = 0;
            } else {
                // Failed and stopped OR Banned Networks OR some other thing that probably won't work
                Serial.println(F("Failed to attach."));
                Serial.println(response);
                break;
            }
        }
        
        delay(1000);
    }
    
    /*
        Phase 3
        Attach SIM900 to packet domain service with AT+CGATT=1
        
        Possible responses:
        OK
        ERROR
        
        Timeout is about 5 seconds
    */
    if (pass) {
        pass = false;
        
        Serial.println(F("\nPhase 3 - Attach SIM900 to packet domain service"));
        
        SIM900.println(F("AT+CGATT=1"));
        response = sim900Response();
        
        if (response == NULL) response = sim900Response();
        
        Serial.println(response);
        
        if (response.indexOf("OK") >= 0) {
            Serial.println(F("Attached to packet domain service!"));
            pass = true;
        } else if (response.indexOf("ERROR") >= 0) {
            Serial.println(F("Got Error. Trying one more time."));
            SIM900.println(F("AT+CGATT=1"));
        }
        
        delay(1000);
    }
    
    /*
        Phase 4
        Configure the bearer settings
        Sets the connection type to GPRS, APN to wap.cingular, and opens the bearer.
        
        Documentation for this too big to include here, see SIM900 AT Commands manual
    */
    if (pass) {
        pass = false;
        Serial.println(F("\nPhase 4 - configure bearer settings"));
        
        SIM900.println(F("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\""));
        response = sim900Response();
        if (response.indexOf("OK") >= 0) {
            // Successfully set connection type, now set APN
            Serial.println(F("Successfully set connection type!"));
            
            SIM900.println(F("AT+SAPBR=3,1,\"APN\",\"phone\"")); //for ATT LTE, use "phone", for older simcard, use "wap.cingular"
			//hard coding the APN setting right now until we figure out how to get the APN with any given simcard
            
            response = sim900Response();
            if (response.indexOf("OK") >= 0) {
                // Successfully set APN, now check if its closed and if it is open it.
                Serial.println(F("Successfully set APN!"));
                
                for (int i = 0; i < 5; i++) {
                    Serial.println("Waiting... " + String(i+1) + " of 5");
                    
                    SIM900.println(F("AT+SAPBR=2,1"));
                    response = sim900Response();
                    
                    if (response.indexOf("1,0") >= 0) {
                        // bearer is connecting. Give it a second...
                        delay(1000);
                        i = 0;
                    } else if (response.indexOf("1,1") >= 0) {
                        // bearer is connected. good
                        Serial.println(F("Bearer is connected!"));
                        pass = true;
                        break;
                    } else {
                        // bearer is closing or is closed. open it.
                        Serial.println(F("Not connected... connecting..."));
                        SIM900.println(F("AT+SAPBR=1,1"));
                        
                        response = sim900Response();
                    }
                }
            }
        }
        
        delay(1000);
    }
    
    /*
        Phase 5
        Initialize HTTP Service
    */
    if (pass) {
        pass = false;
        Serial.println(F("\nPhase 5 - Initialize HTTP Service"));
        
        SIM900.println(F("AT+HTTPINIT"));
        response = sim900Response();
        if (response.indexOf("OK") >= 0) {
            pass = true;
            Serial.println("HTTP Serial Initialized");
        } else {
            Serial.println(F("Error initializing HTTP service"));
            Serial.println(response);
        }
    }
    
    /*
        All phases successfully passed. Module is connected and ready!
    */
    if (pass) {
        Serial.println(F("\nInitialization Complete!"));
        Serial.println(F("Signal level:"));
        SIM900.println(F("AT+CSQ"));
        Serial.println(sim900Response());
    } else {
        Serial.println(F("Could not connect to network for some reason! Restarting. (5s)"));
        powerSIM900();
        delay(5000);
        soft_reset();
    }
}