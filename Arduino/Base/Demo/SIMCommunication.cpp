#include <stdarg.h>
#include "Arduino.h"
#include "SIMCommunication.h"
#include <SoftwareSerial.h>

extern SoftwareSerial SIM900;

/*
    Constructor
*/
SIMCommunication::SIMCommunication(unsigned long baud, uint8_t powerPin)
{
    _powerPin = powerPin;
    _baud = baud;
    
    pinMode(_powerPin, OUTPUT);
    digitalWrite(_powerPin, LOW);
    
    SIM900.begin(_baud);
}

/*
    Toggles the power of SIM900 module.
    Holds PWR pin high for 2 seconds.
    Does not use AT+CPOWD
*/
void SIMCommunication::togglePower() {
    DEBUG_PRINT(F("Toggling Power..."));
    
    digitalWrite(_powerPin, HIGH);
    delay(2000);
    digitalWrite(_powerPin, LOW);
    delay(2000);
    DEBUG_PRINTLN(F("Done"));
}

/*
    Restarts the SIM900 module. Turns it on if it's off.
*/
void SIMCommunication::resetModule() {
    if (isOn()) {
        togglePower();
    }
    
    togglePower();
}

/*
    Checks if SIM900 module is powered on.
    
    Returns true if its on. False otherwise.
*/
bool SIMCommunication::isOn() {
    /*
        Sends the AT command to the module.
        If it's on, it'll respond with OK.
        If it's off, it won't respond.
    */
    String response = sendCommand("AT", 500);
    
    return response.indexOf("OK") >= 0;
}


/*
    Sends AT commands to SIM900 module.
    
    Parameter   Description
    command     String containing the AT command to send to the module
    timeout     A timeout, in milliseconds, to wait for the response
    
    Returns a string containing the response. Returns NULL on timeout.
    
*/
String SIMCommunication::sendCommand(String command, int timeout) {
    // Clear read buffer before sending new command
    while(SIM900.available()) { SIM900.read(); }
    
    SIM900.println(command);
    
    if (responseTimedOut(timeout)) {
        DEBUG_PRINT("sendCommand Timed Out: ");DEBUG_PRINTLN(command);
        return NULL;
    }
    
    String response = "";
    
    while(SIM900.available()) {
        response.concat((char)SIM900.read());
        delayMicroseconds(500);
    }
    
    return response;
}

/*
    Sends the necessary commands to connect to the network.
*/
bool SIMCommunication::connectToNetwork() {
    if (!fancySend("AT+CREG=1", 10, 1000, 1, "OK")) goto error;
    if (!fancySend("AT+CREG?", 10, 1000, 2, ",1", ",5")) goto error;
    if (!fancySend("AT+CGATT=1", 5, 1000, 1, "OK")) goto error;
    if (!fancySend("AT+CGATT?", 1, 1000, 1, ": 1")) goto error;
    if (!fancySend("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"", 5, 1000, 1, "OK")) goto error;
    // TODO: Determine APN automatically. Use "phone" for ATT LTE. "wap.cingular" for other ATT
    if (!fancySend("AT+SAPBR=3,1,\"APN\",\"wap.cingular\"", 5, 1000, 1, "OK")) goto error;
    // if bearer is not connected, connect it.
    if (sendCommand("AT+SAPBR=2,1", 2500).indexOf("1,3") >= 0) {
        if (!fancySend("AT+SAPBR=1,1", 5, 2000, 1, "OK")) goto error;
    }
    // Check that we have an IP address
    if (!fancySend("AT+SAPBR=2,1", 5, 2000, 1, "1,1")) goto error;
    
    return true;
    
    error:
        DEBUG_PRINTLN(F("Network Connection Failed."));
        return false;
}

int freeRam () 
{
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

String SIMCommunication::HTTPRequest(uint8_t type, String url, String parameters) {
    /*
        Setup HTTP
    */
    sendCommand("AT+HTTPINIT", 1000);
    
    // if (!fancySend("AT+HTTPINIT", 1, 1000, 1, "OK")) {
        // DEBUG_PRINTLN("INIT fail");
    // }
    
    sendCommand("AT+HTTPPARA=\"CID\",\"1\"", 2000);
    sendCommand("AT+HTTPPARA=\"URL\",\"" + url + "\"", 1000);
    sendCommand("AT+HTTPPARA=\"REDIR\",\"1\"", 1000);
    
    switch (type) {
        case 0:
            sendCommand("AT+HTTPACTION=0", 1000);
            break;
        case 1: {
            // if (!fancySend("AT+HTTPPARA=\"CONTENT\",\"application/x-www-form-urlencoded\"", 1, 1000, 1, "OK")) {
                // DEBUG_PRINTLN("CONTENT fail");
            // }
            // if (!fancySend("AT+HTTPPARA=\"TIMEOUT\",\"45\"", 1, 1000, 1, "OK")) {
                // DEBUG_PRINTLN("TIMEOUT fail");
            // }
            sendCommand("AT+HTTPPARA=\"CONTENT\",\"application/x-www-form-urlencoded\"", 1000);
            sendCommand("AT+HTTPPARA=\"TIMEOUT\",\"45\"", 1000);
            
            int dataLen = parameters.length();
            sendCommand("AT+HTTPDATA="+(String)dataLen+",5000", 5000);
            // DEBUG_PRINTLN("AT+HTTPDATA="+(String)dataLen+",5000");
            // if (!fancySend("AT+HTTPDATA="+(String)dataLen+",5000", 1, 10000, 1, "DOWNLOAD")) {
                // DEBUG_PRINTLN("httpdata fail");
            // }

            sendCommand(parameters, 1000);
            
            sendCommand("AT+HTTPACTION=1", 1000);
            
            break;
        } default:
            DEBUG_PRINTLN(F("Invalid type in HTTP Request"));
            break;
    }
    
    // After HTTPACTION we have to wait for a HTTP Status Code.
    if (responseTimedOut(10000)) {
        DEBUG_PRINTLN(F("Didn't get HTTP Status Code"));
        return NULL;
    }
    delay(1000);
    while (SIM900.available()) { SIM900.read(); }
    
    delay(1000);
    String response = "";
    
    SIM900.println("AT+HTTPREAD");
    if (responseTimedOut(10000)) {
        DEBUG_PRINTLN(F("Didn't get HTTP data"));
    }
    
    // Capture only data between braces (JSON)
    bool begin = false;
    while (SIM900.available()) {
        
        char in = SIM900.read();
        if (in == '{') {
            begin = true;
        }
        
        if (begin) response += (in);
        
        if (in == '}') {
            break;
        }
        
        delay(1);
    }
    
    delay(1000);
    
    sendCommand("AT+HTTPTERM", 1000);
    // if (!fancySend("AT+HTTPTERM", 1, 5000, 1, "OK")) {
        // DEBUG_PRINTLN("TERM fail");
    // }
    
    return response;
}

/*
    Sends a command to SIM900 and waits for one of the acceptable responses.
    
    Parameter       Description
    command         String containing the AT command to send to the module
    attempts        Number of times to re-send <command> if nothing in <OKResponses> matches response
    timeout         A timeout, in milliseconds, to wait for the response from SIM900 per <attempt>
    num             Number of acceptable responses
    ...             Strings of substrings of the acceptable responses.
                    The function will look for each of these substrings in the response.
                    It should be specific enough to determine success.
    
    Returns true if something in <OKResponses> matched response from SIM900. False otherwise.
*/
bool SIMCommunication::fancySend(String command, uint8_t attempts, int timeout, uint8_t num, ...) {
    va_list arguments;
    
    //DEBUG_PRINT("Fancy Sending: ");DEBUG_PRINTLN(command);
    
    String response;
    bool done = false;
    
    for (uint8_t i = 0; i < attempts; i++) {
        response = sendCommand(command, timeout);
        if (command.indexOf("TERM") >= 0) {
            DEBUG_PRINTLN(command);
            DEBUG_PRINTLN(response);
        }
        va_start(arguments, num);
        for (uint8_t j = 0; j < num; j++) {
            String comp = va_arg(arguments, char*);
            if (response.indexOf(comp) >= 0) {
               done = true;
               break;
            }
        }
        va_end(arguments);
        
        if (done) break;
        delay(500);
    }
    
    return done;
}

/*
    Waits for a response from SIM900 for <ms> milliseconds
    
    Returns true if timed out without response. False otherwise.
*/
bool SIMCommunication::responseTimedOut(int ms) {
    int counter = 0;
    while(!SIM900.available() && counter < ms) {
        counter++;
        delay(1);
    }
    
    // Timed out, return null
    if (counter >= ms) {
        return true;
    }
    counter = 0;
    return false;
}