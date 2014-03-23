#ifndef GLOBALS_H
#define GLOBALS_H

/*
    Debug functions
*/
#define DEBUG_ENABLED
#ifdef DEBUG_ENABLED
    #define DEBUG_INIT(baud)  Serial.begin(baud)
    #define DEBUG_PRINT(x)  Serial.print (x)
    #define DEBUG_PRINTLN(x)  Serial.println (x)
#else
    #define DEBUG_INIT(baud)
    #define DEBUG_PRINT(x)
    #define DEBUG_PRINTLN(x)
#endif

#include "Arduino.h"

#endif