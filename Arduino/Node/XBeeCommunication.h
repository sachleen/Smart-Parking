#ifndef XBeeCommunication_h
#define XBeeCommunication_h

#include "Arduino.h"
#include "globals.h"

class XBeeCommunication
{
  public:
    XBeeCommunication(String);
    String getMessage();
    void sendMessage(String, String);
  private:
    String xbeeResponse();
    String _nodeId;
};

#endif