#include <avr/wdt.h> // for watchdog timer
#include <SoftwareSerial.h>

#define SIM900_BAUD 2400
#define XBEE_BAUD 9600
#define QMAX 10

SoftwareSerial SIM900(7, 8);
//SoftwareSerial xbee(2, 3);
SoftwareSerial xbee(5, 6);//For Testing on Node board


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
			sendMessageNode(nodeId, 3);//Using this for testing
                        //sendMessageNode(nodeId, numSensors);
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

/*
    Connects to the cellular network and sets up for HTTP.
    Read the comments before each phase of the connection for details.
*/
void connectToNetwork() {
    Serial.println(F("connectToNetwork() function call"));
	delay(2000);
}
int sendRequestServer(String nodeId, char identifierC, int amount, int total){
		int nodeNumber = -1;
		switch(identifierC){
			case 'N':
				Serial.print("Sending Number of Sensors Request from : ");
				Serial.println(nodeId);
				nodeNumber = 3;//Will be replaced with response from server
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
	

        /*
        xbee.listen();
        String incMessage = xbeeResponse();
        Serial.println("Message From Node: "+ incMessage);
        delay(2000);
        return incMessage;
        */
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
