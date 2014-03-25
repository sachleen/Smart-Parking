#include "globals.h"
#include "SIMCommunication.h"

#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8);
SIMCommunication simcomm(4800, 9);

void setup()
{
    DEBUG_INIT(9600);
    
    DEBUG_PRINTLN("Starting");
    
    while (!simcomm.isOn()) {
        simcomm.togglePower();
    }
    DEBUG_PRINT("Power Status:");DEBUG_PRINTLN(simcomm.isOn() ? "ON" : "OFF");
    
    if (simcomm.connectToNetwork()) {
        DEBUG_PRINTLN(F("Connected!"));
    } else {
        DEBUG_PRINTLN(F("Network Connection Failed."));
    }
    
    String response;
    
    DEBUG_PRINTLN(F("Making HTTP GET Request"));
    response = simcomm.HTTPRequest(0, "http://sachleen.com/sachleen/parking/API/nodes/test1", "");
    DEBUG_PRINTLN(response);
    
    DEBUG_PRINTLN(F("Making HTTP POST Request"));
    response = simcomm.HTTPRequest(1, "http://sachleen.com/sachleen/parking/API/nodes/save", "id=test1&available=0&api_key=8ce367853467bbfe56a51d9eac208318");
    DEBUG_PRINTLN(response);
    
    DEBUG_PRINTLN("DONE WITH SETUP");
    
    response = NULL; // free up some memory
}

void loop()
{
  if (SIM900.available())
    Serial.write(SIM900.read());
  if (Serial.available())
    SIM900.write(Serial.read());  
}

int freeRam () 
{
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}