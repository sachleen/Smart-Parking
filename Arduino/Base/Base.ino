#include <avr/wdt.h> // for watchdog timer
#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8);

#define SIM900_BAUD 2400
#define XBEE_BAUD 9600

SoftwareSerial xbee(2, 3);

String response = ""; // Holds the response from SIM900
String responseXBee = "";
bool pass = false; // Keeps track of various phases of the connection. Must be set to true during each phase for success



/*
    Setup block
    Initializes communication protocols and initiates other setup related tasks.
*/
void setup() {
    Serial.begin(9600);
    
    SIM900.begin(SIM900_BAUD);
    powerSIM900();
    connectToNetwork();
    
    xbee.begin(XBEE_BAUD);
}

/*
    Loop block
    Recieves a message from a wireless node and relays it to the web server
*/
void loop() {
    /*
        Listen for a message from a wireless node
    */
    xbee.listen();
    responseXBee = xbeeResponse();
    
    // If we have a message
    if (responseXBee != NULL) {
        uint8_t start = 0;
        uint8_t end = responseXBee.indexOf(',');
        String nodeId = responseXBee.substring(start, end);
        
        start = end + 1;
        end = responseXBee.indexOf(',', start);
        uint8_t total = responseXBee.substring(start, end).toInt();
        
        start = end + 1;
        end = responseXBee.indexOf(',', start);;
        uint8_t available = responseXBee.substring(start, end).toInt();
        
        Serial.println("Node:  " + String(nodeId));
        Serial.println("Total: " + String(total));
        Serial.println("Avail: " + String(available));
        sendUpdate(nodeId, total, available);
    }
    
    
    Serial.println("====================");
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
            
            SIM900.println(F("AT+SAPBR=3,1,\"APN\",\"wap.cingular\""));
            
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

/*
    Sends a HTTP request to the web server with the status of a parking spot.
    Right now it only works with one hard-coded spot but in the near future it will be generic
*/
bool sendUpdate(String nodeId, uint8_t total, uint8_t available) {
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
    
    SIM900.println("AT+HTTPPARA=\"URL\",\"http://sachleen.com/sachleen/parking/app/api/sensor/status/" + String(nodeId) + "/" + String(total) + "/" + String(available) + "\"");
        
    response = sim900Response();
    
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
        
        if (response.indexOf("Success") >= 0) {
            Serial.println(F("Request complete!"));
        } else {
            Serial.println("Request did NOT return Success");
            Serial.println(response);
        }
    }
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

    if (counter >= 5000) {
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
    
    if (counter >= 2500) {
        Serial.println(F("XBEE Timed Out"));
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
    
    xbee.flush();
    return content;
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