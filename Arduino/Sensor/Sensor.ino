#include <RS485.h>
#include <SoftwareSerial.h>
#include <Wire.h>

#include "globals.h"
#include "WiredCommunication.h"

#define Addr 0x1E               // 7-bit address of HMC5883 compass
#define SENSOR_ID 3

WiredCommunication wiredbus;

/*
    Setup block
    Initializes communication protocols and initiates other setup related tasks.
*/
void setup()
{
    DEBUG_INIT(9600);
    DEBUG_PRINTLN("System Startup - Receiver");

    Wire.begin();
    Wire.beginTransmission(Addr); 
    Wire.write(byte(0x02));
    Wire.write(byte(0x00));
    Wire.endTransmission();
    
    // Calibrate compass on startup
    isCarPresent();
}

void loop()
{
    char recBuff[maxMsgLen+3+1];
    
    if(wiredbus.getMessage(recBuff))
    {
        DEBUG_PRINT("Receiving:");
        DEBUG_PRINTLN(recBuff);
        
        // Check if the request is for this sensor
        if (recBuff[0] == getSensorIdFromIndex(SENSOR_ID)) {
            // Prepare response message
            char sendBuff[maxMsgLen+1];
            sendBuff[0] = getSensorIdFromIndex(SENSOR_ID);
            
            switch (recBuff[1]) {
                case 'C': // Report compass status
                    DEBUG_PRINTLN("Reporting Compass Status");
                    sendBuff[1] = isCarPresent() ? 'T' : 'A';
                    break;
                default:
                    DEBUG_PRINTLN("Don't understand the request :(");
                    sendBuff[1] = '?';
            }
            
            // Finish message with null
            sendBuff[2] = '\0';
            
            // Send response
            if(wiredbus.sendMessage(sendBuff))
            {
                DEBUG_PRINT("Sent:");
                DEBUG_PRINTLN(sendBuff);
            }
        } else {
            // The request was NOT for this sensor
            DEBUG_PRINTLN("Not me");
        }
        
        DEBUG_PRINTLN();
    }
}

int calZ; // Holds the reference value for compass Z axis
boolean needsCalibration = true;
uint8_t deltaErrorCount = 0; // Every time the read value is off by a certain amount from the reference, this increments. Once this is high enough, compass recalibrates.

/*
    Determines if a car is present above the sensor or not.
*/
bool isCarPresent() {
    int x, y, z;
    
    getCompassData(x, y, z);
    
    DEBUG_PRINT("Z: ");DEBUG_PRINTLN(z);
    
    /*
        Recalibrate the compass reference value.
        Samples the compass and gets an average value.
        This should only be run when the parking space is EMPTY.
        
        This block executes on power on and when deltaErrorCount is above a certain amount.
        deltaErrorCount increments when the read value is off by a small amount from the reference
        but not enough to change the car present/not present status. This allows the system to keep
        up with small changes in the compass reading and always have a "good" reference value.
    */
    if (needsCalibration || deltaErrorCount >= 5) {
        DEBUG_PRINT("Calibrating Compass");
        calZ = z;
        for (int i = 0; i < 10; i++) {
            getCompassData(x, y, z);
            calZ = (calZ + z) / 2;
            DEBUG_PRINT(" .");
            delay(100);
        }
        needsCalibration = false;
        deltaErrorCount = 0;
        DEBUG_PRINTLN(" Done!");
    }
    
    int delta = abs(calZ - z);
    if (delta > 150) {
        deltaErrorCount = 0;
        return true;
    } else if (delta > 10 && delta < 50) {
        deltaErrorCount++;
    }
    
    return false;
}

/*
    Returns the X, Y, and Z values from the compass module.
*/
void getCompassData(int& x, int& y, int& z) {
    // Initiate communications with compass
    Wire.beginTransmission(Addr);
    Wire.write(byte(0x03));       // Send request to X MSB register
    Wire.endTransmission();

    Wire.requestFrom(Addr, 6);    // Request 6 bytes; 2 bytes per axis
    if(Wire.available() <=6) {    // If 6 bytes available
        x = Wire.read() << 8 | Wire.read();
        z = Wire.read() << 8 | Wire.read();
        y = Wire.read() << 8 | Wire.read();
    }
}
/*
    Returns a byte from 0x40 of the ascii table. Starting at @ A B C ...
    Have to do this because if we start from 0 1 2... the control characters at the beginning mess up transmissions
*/
char getSensorIdFromIndex(uint8_t index) {
    return (char)(index + 64);
}