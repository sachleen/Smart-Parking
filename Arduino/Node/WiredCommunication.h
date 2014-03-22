#ifndef WiredCommunication_h
#define WiredCommunication_h

#include "Arduino.h"

class WiredCommunication
{
  public:
    WiredCommunication();
    bool getMessage(char*);
    bool sendMessage(char*);
};


#endif