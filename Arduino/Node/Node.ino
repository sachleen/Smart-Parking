#include <RS485.h>
#include <SoftwareSerial.h>
SoftwareSerial xbee(5, 6); // RX, TX

#define NUM_SENSORS 3
String nodeId = "ABCDE";

char sensorStatus[NUM_SENSORS];
bool dataChanged = false; // Set to true if any sensor's status has changed. XBee only sends if this is true.

/*
    Setup block
    Initializes communication protocols and initiates other setup related tasks.
*/
void setup()
{
    Serial.begin(9600);
    Serial.println("System Startup - Sender");

    RS485_Begin(4800);
    xbee.begin(9600);
    
    // Wait for sensors to power up and calibrate
    delay(2000);
}

void loop()
{
    RS485_Listen();
    
    /*
        Loops through all the sensors asking for a status.
        Records the responses or time outs in sensorStatus[]
    */
    for (int sensorNum = 1; sensorNum <= NUM_SENSORS; sensorNum++) {
        
        Serial.print("Querying Sensor ");Serial.println(sensorNum);
        
        /*
            The message is composed of a sensor ID and command.
        */
        char sendBuff[maxMsgLen+1];
        sendBuff[0] = getSensorIdFromIndex(sensorNum);
        sendBuff[1] = 'C';
        sendBuff[2] = '\0';
        
        if(RS485_SendMessage(sendBuff,fWrite,ENABLE_PIN))
        {
            //Serial.print("Sending:");
            Serial.println(sendBuff);
            
            // Listen for response
            char recBuff[maxMsgLen+3+1];
            timeout_init(2000);
            bool gotResponse = false;
            while (!timeout_timedout()) {
                if (RS485_ReadMessage(fAvailable,fRead, recBuff)) {
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
        } else {
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
    for (int i = 1; i <= NUM_SENSORS; i++) {
        Serial.print(i);
        Serial.print(" ");
    }
    Serial.print("\nStatus: ");
    for (int i = 1; i <= NUM_SENSORS; i++) {
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
        for (int i = 1; i <= NUM_SENSORS; i++) {
            if (sensorStatus[i-1] == 'A') {
                countAvailable++;
            }
        }
        
        /*
            Prepare XBee message packet:
            [Node ID],[Total Spots],[Available Spots]
        */
        String xbeeMessage = nodeId + ',' + String(NUM_SENSORS) + ',' + String(countAvailable);
        
        xbee.listen();

        Serial.println(xbeeMessage);
        xbee.println(xbeeMessage);
    }
    
    Serial.println("==============================\n");
    
    dataChanged = false;
    delay(2000);
}

char getSensorIdFromIndex(uint8_t index) {
    // Returns a byte from 0x40 of the ascii table. Starting at @ A B C ...
    // Have to do this because if we start from 0 1 2... the control characters at the beginning mess up transmissions
    // Since sensor 0 is master, it will be @, the slaves will start from A
    return (char)(index + 64);
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