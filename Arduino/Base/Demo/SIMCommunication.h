#ifndef SIMCommunication_h
#define SIMCommunication_h

#include "Arduino.h"
#include "globals.h"

class SIMCommunication
{
  public:
    SIMCommunication(unsigned long, uint8_t);
    
    // Power Functions
    void togglePower();
    void resetModule();
    bool isOn();
    
    String sendCommand(String, int);
    bool fancySend(String, uint8_t, int, uint8_t, ...);
    
    bool connectToNetwork();
    String HTTPRequest(uint8_t, String, String);
  private:
    uint8_t _powerPin;
    unsigned long _baud;
    
    bool responseTimedOut(int);
};

#endif