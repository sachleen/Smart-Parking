#ifndef WiredCommunication_h
#define WiredCommunication_h

#include "Arduino.h"
#include "globals.h"

class WiredCommunication
{
  public:
    WiredCommunication();
    bool getMessage(char*);
    bool sendMessage(char*);
};


#endif