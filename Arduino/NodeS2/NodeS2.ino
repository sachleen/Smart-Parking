#include <RS485.h>
#include <SoftwareSerial.h>
SoftwareSerial xbee(5, 6); // RX, TX

#define MAX_SENSORS 32
String nodeId = "test1";

int  numSensors = 99; // Starts off at 99 so that the base recognizes first message as startup message. SET TO 3 FOR TESTING
int retryCount = 0;//retry count for adding messages to queue
int check = 0;//checks for success of adding to queue
String messageFromBase = "";


char sensorStatus[MAX_SENSORS]; // keeps track of status of each sensor
bool dataChanged = false; // Set to true if any sensor's status has changed. XBee only sends if this is true.

/*
    Setup block
    Initializes communication protocols and initiates other setup related tasks.
*/
void setup()
{
    Serial.begin(9600);
    Serial.println("New System Startup - Sender");

    RS485_Begin(4800);
    xbee.begin(9600);
    
    // Wait for sensors to power up and calibrate
    delay(2000);
	
    String powerOnMessage = nodeId + ',' + String(numSensors) + ',' + String(0);//numSensors should be 99 at startup so the base knows its asking for number of sensors
    Serial.println(numSensors); delay(2000);
    while(numSensors == 99 || numSensors == 0){
        numSensors = sendMessageBase(powerOnMessage);
    }
}

void loop()
{
    /*
        Loops through all the sensors asking for a status.
        Records the responses or time outs in sensorStatus[]
    */
    RS485_Listen();//Should be replaced by getSendMessageSensor() function call

    for (int sensorNum = 1; sensorNum <= numSensors; sensorNum++) {
        
        Serial.print("Querying Sensor ");
        Serial.println(sensorNum);
        
        
       //The message is composed of a sensor ID and command.
      
        char sendBuff[maxMsgLen+1];
        sendBuff[0] = getSensorIdFromIndex(sensorNum);//get sensorIdFromIndex
        sendBuff[1] = 'C';
        sendBuff[2] = '\0';
        
        if(sendMessageSensor(sendBuff))
        //if(RS485_SendMessage(sendBuff,fWrite,ENABLE_PIN))
        {
            //Serial.print("Sending:");
            Serial.println(sendBuff);
            
            // Listen for response
            char recBuff[maxMsgLen+3+1];//what are the 3 and 1?
            timeout_init(2000);
            bool gotResponse = false;
            while (!timeout_timedout()) {
                if (getMessageSensor(recBuff)){
				//if (RS485_ReadMessage(fAvailable,fRead, recBuff)) {//NEEDS TO BE REPLACED WITH GET MESSAGE FROM SENSOR FUNCTION
                    Serial.print("Got:");
                    Serial.println(recBuff);
                    
                    /*
                        If the response is from the same sensor we responded data from, parse it.
                    */
                    if (recBuff[0] == getSensorIdFromIndex(sensorNum)) {
                        switch (recBuff[1]) {
                            case 'T': // Car present
                                Serial.println("CAR PRESENT");
                                if (sensorStatus[sensorNum-1] != 'T'){
                                    sensorStatus[sensorNum-1] = 'T';
                                    dataChanged = true;
                                }
                                break;
                            case 'A': // Car NOT present
                                Serial.println("CAR NOT PRESENT");
                                if (sensorStatus[sensorNum-1] != 'A'){
                                    sensorStatus[sensorNum-1] = 'A';
                                    dataChanged = true;
                                }
                                break;
                            default:
                                Serial.println("Invalid Response");
                                sensorStatus[sensorNum-1] = 'I';
                        }
                    } else {
                        // Wrong sensor ID
                        Serial.println("Wrong sensor responded to request...wtf");
                        sensorStatus[sensorNum-1] = 'W';
                    }
                    
                    gotResponse = true;
                    break;
                }
                delay(100);
            }
            
            if (!gotResponse) {
                Serial.println("Timed out!");
                sensorStatus[sensorNum-1] = 'L';
            }
        }
		else {
            Serial.println("Send Failed");
        }
        Serial.println();
        delay(100);
    }
    
    
    /*
        Print stuff out to serial
    */
    Serial.println("==============================");
    Serial.print("Sensor: ");
    for (int i = 1; i <= numSensors; i++) {
        Serial.print(i);
        Serial.print(" ");
    }
    Serial.print("\nStatus: ");
    for (int i = 1; i <= numSensors; i++) {
        Serial.print(sensorStatus[i-1]);
        Serial.print((i < 10) ? " " : "  ");
    }
    Serial.println();
    
    Serial.println(dataChanged ? "Data changed, sending..." : "Not sending. no change");
    
    if (dataChanged) {
        /*
            Send data to base station using XBee
        */
        // Get count of available spots
        uint8_t countAvailable = 0;
        for (int i = 1; i <= numSensors; i++) {
            if (sensorStatus[i-1] == 'A') {
                countAvailable++;
            }
        }
        
        /*
            Prepare XBee message packet:
            [Node ID],[Total Spots],[Available Spots]
        */
        String updateMessage = nodeId + ',' + String(numSensors) + ',' + String(countAvailable);
        /*
		xbee.listen();
        Serial.println(updateMessage);
        xbee.println(updateMessage);
		*/
		
		check = sendMessageBase(updateMessage);
		if(check < 0){
			Serial.println("sendMessageBase() failed");
		}
		
    }
    
    Serial.println("==============================\n");
    
    dataChanged = false;
}

bool sendMessageSensor(char message[]){
	RS485_Listen();//Activates sensor channel
	return (RS485_SendMessage(message,fWrite,ENABLE_PIN));
}

bool getMessageSensor(char data[]){
	//RS485_Listen();//Activates sensor channel
	return RS485_ReadMessage(fAvailable,fRead, data);
}

/*
int sendMessageBase(String message){
	//sends message to base
	//wait for response from base
	Serial.println(F("Sending message to base and getting response..."));
	Serial.println("Message sent: " + message);
        xbee.listen();
        xbee.println(message);
        Serial.println(getBaseMessage());
        return 3;//returns 3 for testing
}
*/

int sendMessageBase(String message){
	//sends message to base
	//wait for response from base!!!!!!!!!!!!!!!!
	xbee.listen();
	
	//To check
	int responseCount = 0;
	String baseResponse;
	while(responseCount < 5){
		xbee.println(message);
		baseResponse = getBaseMessage();
		if(baseResponse != NULL){
			break;
		}
		delay(10);
		responseCount++;
	}
	
	uint8_t total = -1;
	
	if(responseCount >= 5){
		Serial.println(F("getBaseMessage() timed out!"));
		//total = -1;
	}
	else{
		if(baseResponse != NULL){
			uint8_t start = 0;
			uint8_t end = baseResponse.indexOf(',');
			String target = baseResponse.substring(start, end);
			
			start = end + 1;
			end = baseResponse.indexOf(',', start);
			total = baseResponse.substring(start, end).toInt();
			
			Serial.println("Target Node:  " + String(target));
			Serial.println("Number: " + String(total));
		}
		else{
			Serial.println("Base Response = NULL");
		}
	}
    //Serial.print("This is what sendMessageBase returns: ");
    //Serial.println(total);
    //delay(2000);
    return total;
}


String getBaseMessage() {

  xbee.listen();
  String xResponse = xbeeResponse();
  uint8_t start = 0;
  uint8_t end = xResponse.indexOf(',');
  String targetNode = xResponse.substring(start, end);
  if(targetNode.equals(nodeId)){
	return xResponse;
  }
  else{
	return NULL;
  }
}

char getSensorIdFromIndex(uint8_t index) {
    // Returns a byte from 0x40 of the ascii table. Starting at @ A B C ...
    // Have to do this because if we start from 0 1 2... the control characters at the beginning mess up transmissions
    // Since sensor 0 is master, it will be @, the slaves will start from A
    return (char)(index + 64);
}

String xbeeResponse() {
    String content = "";
    int counter = 0;
    while(!xbee.available() && counter < 250) {
        counter++;
        delay(10);
    }
    
    if (counter >= 2500) {
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
    Software Reset Functions
*/
#include <avr/wdt.h>
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
