#ifndef XBeeCommunication_h
#define XBeeCommunication_h

#include "Arduino.h"

class XBeeCommunication
{
  public:
    XBeeCommunication(String);
    String getMessage();
    bool sendMessage(String);
  private:
    String xbeeResponse();
    String _nodeId;
};


#endif