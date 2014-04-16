#define DEBUG_ENABLED
#include <RS485.h>
#include <SoftwareSerial.h>

#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/wdt.h>

#include "globals.h"
#include "WiredCommunication.h"
#include "XBeeCommunication.h"

#define XBEE_SLEEP 7	//Set Sleep pin to D7

#define MAX_SENSORS 32
#define SENSOR_MAX 10
String baseId = "00000";

volatile int f_wdt=1;//used for wdt interrupt
volatile int sleep_count = 0;

SoftwareSerial xbee(5, 6); // RX, TX
//SoftwareSerial xbee(2, 3); //Testing with Xbee only

WiredCommunication wiredbus;
XBeeCommunication xcomm("TEST2");//Change here for different nodes


int  numSensors = -1; // Starts off at -1 to show the Node has yet to be intialized
int retryCount = 0;//retry count for adding messages to queue
int check = 0;//checks for success of adding to queue
String messageFromBase = "";


char sensorStatus[MAX_SENSORS]; // keeps track of status of each sensor
bool dataChanged = false; // Set to true if any sensor's status has changed. XBee only sends if this is true.
bool sendOk = false;
bool sensorSuccess = false;
int sendCount;

int sensorCount = 0;

/*
    Setup block
    Initializes communication protocols and initiates other setup related tasks.
*/
void setup()
{
  DEBUG_INIT(9600);
  DEBUG_PRINTLN("New System Startup - Sender");

  xbee.begin(9600);
  power_adc_disable();
  power_spi_disable();
  //power_timer0_disable(); need timer 0 for delay()
  power_timer1_disable();
  power_timer2_disable();
  power_twi_disable();
  wdtSetup();
  // Wait for sensors to power up and calibrate
  delay(2000);
  
  DEBUG_PRINTLN(numSensors); delay(2000);
  String response = "";
  pinMode(XBEE_SLEEP, OUTPUT);   // sleep control
  digitalWrite(XBEE_SLEEP, LOW);   // deassert 
  
  // Need this delay for XBee to "warm up" ... messages aren't being received faster than this.
  for (int i = 0; i < 10; i++) {
   DEBUG_PRINT(".");
   delay(1000);
  }
  setXbeeSleep();
  
  /**
   * The node will stay in this loop until it receives it's number of sensors from the Base station
   * Commented out for testing purposes
   */
   
  while(numSensors < 0){
    xbee.println("Sending...");
    xcomm.sendMessage(baseId, "N");//"N" indicates that the Node is requesting its number of Sensors
    response = xcomm.getMessage();

    if(response != NULL){
      uint8_t start = 0;
      uint8_t end = response.indexOf(',');
    
      start = end + 1;
      end = response.indexOf(',', start);
      String numberResponse = response.substring(start, end);
  
      numberResponse.trim();
      numSensors = numberResponse.toInt();
      DEBUG_PRINTLN(numSensors);
    }
  }
  
    
  //numSensors = 3;//used when we don't get numSensors from Base Station
  
  /**
   * This while loop will run until the number of nodes the sensor has assigned a new ID matches numSensors
   * The loop keeps track of how many assignment statements reached the sensors successfully
   */
   
  while(!sensorSuccess){  
    for(int i=1; i <= SENSOR_MAX; i++){
      char sendBuff[maxMsgLen+2];
      sendBuff[0] = getSensorIdFromIndex(i);//get sensorIdFromIndex
      sendBuff[1] = 'P';
      sendBuff[2] = getSensorIdFromIndex(sensorCount+1);
      sendBuff[3] = '\0';
      wiredbus.sendMessage("wakeup");//to wake up sensors
      if(wiredbus.sendMessage(sendBuff)){
        DEBUG_PRINTLN(sendBuff);
        // Listen for response
        char recBuff[maxMsgLen+3+1];
        timeout_init(2000);
        bool gotResponse = false;
        while (!timeout_timedout()) {
          if (wiredbus.getMessage(recBuff)){
            DEBUG_PRINT("Got:");
            DEBUG_PRINTLN(recBuff);
            if (recBuff[0] == getSensorIdFromIndex(i)) {
              if(recBuff[1] == 'X'){
                sensorCount++;
                DEBUG_PRINT("Sensor Assigned: ");
                DEBUG_PRINTLN(sensorCount);//Sensor count
              }
            }
	    else {
              // Wrong sensor ID
              DEBUG_PRINTLN("Wrong sensor responded to assignment...");
            }
            gotResponse = true;
            break;
          }
          delay(100);
        }
        if (!gotResponse) {
          DEBUG_PRINTLN("Timed out!");
        }
      }
      else {
        DEBUG_PRINTLN("Assignment Failed");
      }
      if((sensorCount) == numSensors)
        break;
      delay(500);
    }
    if((sensorCount) < numSensors){
      sensorSuccess = false;
      DEBUG_PRINTLN("Sensors intialization failed");
      sensorCount = 0;
      resetSensors();//This tells sensors to randomize to a new SensorID
    }
    else{
      sensorSuccess = true;
      DEBUG_PRINTLN("Sensors initialized");
      delay(3000);
    }
  }
  
}

void loop()
{
    if(f_wdt == 1){
      Serial.println("Awake");//Check to see if Arduino woke back up
    }
	
    /*
        Loops through all the sensors asking for a status.
        Records the responses or time outs in sensorStatus[]
    */
    for (int sensorNum = 1; sensorNum <= numSensors; sensorNum++) {
        
        DEBUG_PRINT("Querying Sensor ");DEBUG_PRINTLN(sensorNum);
        
        // Send some data to the sensors to wake them up. Doesn't matter what it is.
        //wiredbus.sendMessage("wakeup");
        
        //The message is composed of a sensor ID and command.
        char sendBuff[maxMsgLen+1];
        sendBuff[0] = getSensorIdFromIndex(sensorNum);//get sensorIdFromIndex
        sendBuff[1] = 'C';
        sendBuff[2] = '\0';
        
        wiredbus.sendMessage("wakeup");
        if(wiredbus.sendMessage(sendBuff))
        {
            DEBUG_PRINTLN(sendBuff);
            
            // Listen for response
            char recBuff[maxMsgLen+3+1];
            timeout_init(2000);
            bool gotResponse = false;
            while (!timeout_timedout()) {
              
                if (wiredbus.getMessage(recBuff)){
                    
                    DEBUG_PRINT("Got:");
                    DEBUG_PRINTLN(recBuff);
                    
                    /*
                        If the response is from the same sensor we responded data from, parse it.
                    */
                    if (recBuff[0] == getSensorIdFromIndex(sensorNum)) {
                        switch (recBuff[1]) {
                            case 'T': // Car present
                                DEBUG_PRINTLN("CAR PRESENT");
                                if (sensorStatus[sensorNum-1] != 'T'){
                                    sensorStatus[sensorNum-1] = 'T';
                                    dataChanged = true;
                                }
                                break;
                            case 'A': // Car NOT present
                                DEBUG_PRINTLN("CAR NOT PRESENT");
                                if (sensorStatus[sensorNum-1] != 'A'){
                                    sensorStatus[sensorNum-1] = 'A';
                                    dataChanged = true;
                                }
                                break;
                            default:
                                DEBUG_PRINTLN("Invalid Response");
                                sensorStatus[sensorNum-1] = 'I';
                        }
                    } else {
                        // Wrong sensor ID
                        DEBUG_PRINTLN("Wrong sensor responded to request...");
                        sensorStatus[sensorNum-1] = 'W';
                    }
                    
                    gotResponse = true;
                    break;
                }
                delay(100);
            }
            
            if (!gotResponse) {
                DEBUG_PRINTLN("Timed out!");
                sensorStatus[sensorNum-1] = 'L';
            }
        }
	else {
            DEBUG_PRINTLN("Send Failed");
        }
        DEBUG_PRINTLN();
        delay(500);
    }
    
    
    /*
        Print stuff out to serial
    */
    DEBUG_PRINTLN("==============================");
    DEBUG_PRINT("Sensor: ");
    for (int i = 1; i <= numSensors; i++) {
        DEBUG_PRINT(i);
        DEBUG_PRINT(" ");
    }
    DEBUG_PRINT("\nStatus: ");
    for (int i = 1; i <= numSensors; i++) {
        DEBUG_PRINT(sensorStatus[i-1]);
        DEBUG_PRINT((i < 10) ? " " : "  ");
    }
    DEBUG_PRINTLN();
    
    DEBUG_PRINTLN(dataChanged ? "Data changed, sending..." : "Not sending. no change");
    //dataChanged = true;//This line will force the XBee to send a message. (Used for testing)
    if (dataChanged) {
        digitalWrite(XBEE_SLEEP, LOW);
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
            [Message Identifier],[Available Spots]
        */
		String updateMessage = "U," + String(countAvailable);//The identifier "U" means that this is an update meant for the server
                xcomm.sendMessage(baseId, updateMessage);
		String response = xcomm.getMessage();
		sendCount = 0;
		while (response == NULL && sendCount < 2){
			xcomm.sendMessage(baseId, updateMessage);
			response = xcomm.getMessage();
			sendCount++;
		}
		if(response!=NULL){
			uint8_t start = 0;
			uint8_t end = response.indexOf(',');
			
			String baseCheck = response.substring(end+1);
			if (baseCheck.indexOf("OK") < 0){
				DEBUG_PRINTLN("Didn't receive correct message from base");
			}
			else{
				DEBUG_PRINTLN("Update Successful");
			}
		}
		else{
			DEBUG_PRINTLN("Update Failed");
		}
    }
    
    DEBUG_PRINTLN("==============================\n");
    
    
	digitalWrite(XBEE_SLEEP, HIGH);//Set XBee to sleep
    
    dataChanged = false;//reset dataChanged flag
    
    /**
    *This block of code will cause the arduino to sleep for a given number of minutes
    *It is commented out for demonstration purposes where we want a quick response
    */
	 
    /*
    Serial.println("Going to sleep");
    delay(100);
    
    int cyclesSlept = 0;
    int sleepMinutes = 1;//Minutes we want arduino to sleep
    int sleepCycles = (sleepMinutes * 60)/8;//This tells us how many sleep cycles of 8 seconds to perform
    
    
    while(cyclesSlept < sleepCycles){
      f_wdt = 0;
      wdt_reset();//Resets the watchdog timer for the sleep cycle
      enterSleep();
      cyclesSlept++;
    }
    */
}

char getSensorIdFromIndex(uint8_t index) {
    // Returns a byte from 0x40 of the ascii table. Starting at @ a b c ...
    // Have to do this because if we start from 0 1 2... the control characters at the beginning mess up transmissions
    // Since sensor 0 is master, it will be @, the slaves will start from a
    return (char)(index + 96);
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

/**
 * This method issues the AT command SM1 to the XBee
 * This sets the XBee Sleep Mode to 1 which allows us to control the sleep state of the XBee by asserting a its DTR pin
 */
void setXbeeSleep(){
	String ok_response = "OK\r"; // the response we expect.
	xbee.print("+++");
	xbee.listen();
	//xbee.print("+++");
	String content = "";
	int counter = 0;
	while(!xbee.available() && counter < 500) {
		counter++;
		delay(10);
	}

	if (counter >= 500) {
		Serial.println(F("XBEE Timed Out"));
	}

	while (xbee.available()) {
		char input = xbee.read();
		content.concat(input);
		if (input == '\n') {
			break;
		}
		delay(1);
	}
	//Serial.print("Content: ");

	//Serial.println(content);

	if (content.equals(ok_response)) {
		xbee.println("ATSM 1");
	delay(500);
		xbee.println("ATCN");     // back to data mode
		Serial.println(F("Set to pin sleep"));
	}
}

void wdtSetup(){
	/* Clear the reset flag. */
	MCUSR &= ~(1<<WDRF);

	/* In order to change WDE or the prescaler, we need to
	* set WDCE (This will allow updates for 4 clock cycles).
	*/
	WDTCSR |= (1<<WDCE) | (1<<WDE);

	/* set new watchdog timeout prescaler value */
	WDTCSR = 1<<WDP0 | 1<<WDP3; /* 8.0 seconds */

	/* Enable the WD interrupt (note no reset). */
	WDTCSR |= _BV(WDIE);

	Serial.println("Initialisation complete.");
	delay(100); //Allow for serial print to complete.
}

ISR(WDT_vect)
{
  if(f_wdt == 0)
  {
    f_wdt=1;
  }
  else
  {
    //Serial.println("WDT Overrun!!!");
  }
}

void enterSleep(void)
{
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);   /* EDIT: could also use SLEEP_MODE_PWR_DOWN for lowest power consumption. */
  sleep_enable();
  
  /* Now enter sleep mode. */
  sleep_mode();
  
  /* The program will continue from here after the WDT timeout*/
  sleep_disable(); /* First thing to do is disable sleep. */
  
  /* Re-enable the peripherals. */
  //power_all_enable();
}

void initializeSensors(){//Will add initializing code here once I'm sure it works after another test
  
}

/**
 *This method sends a message to all attached sensors letting them know to randomize their SensorIDs
 */
void resetSensors(){
  for(int i=1; i <= SENSOR_MAX; i++){
    char sendBuff[maxMsgLen+1];
    if(i == 5)
      sendBuff[0] = 'e';
    else
    sendBuff[0] = getSensorIdFromIndex(i);//get sensorIdFromIndex
    sendBuff[1] = 'R';
    sendBuff[2] = '\0';
    wiredbus.sendMessage("wakeup");//to wake up sensors
    if(wiredbus.sendMessage(sendBuff)){
      DEBUG_PRINTLN(sendBuff);
      // Listen for response
      char recBuff[maxMsgLen+3+1];
      timeout_init(2000);
      bool gotResponse = false;
      while (!timeout_timedout()) {
        if (wiredbus.getMessage(recBuff)){
          DEBUG_PRINT("Got:");
          DEBUG_PRINTLN(recBuff);
          if (recBuff[0] == getSensorIdFromIndex(i)) {
            if(recBuff[1] == 'Y'){
              DEBUG_PRINT("Sensor Randomized: ");
              DEBUG_PRINTLN(i);//Sensor count
            }
          } else {
            // Wrong sensor ID
            DEBUG_PRINTLN("Wrong sensor responded to assignment...");
          }
          gotResponse = true;
          break;
        }
        delay(100);
      }
        if (!gotResponse) {
          DEBUG_PRINTLN("Timed out!");
        }
    }
  	else {
  		DEBUG_PRINTLN("Randomize Failed");
  	}
  	delay(500);
  }
    
}
