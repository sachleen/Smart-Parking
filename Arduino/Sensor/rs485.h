/*
    Function Prototypes
*/
bool getMessage(char*);
bool sendMessage(char*);

/*
    Variables
*/

/*
    Functions
*/

/*
    Reads a message from the RS485 bus.
    
    Parameter   Description
    buff        Pointer to a char array to which the message will be written to
    
    Returns true if there was a message and it was written to buff. False otherwise.
*/
bool getMessage(char* buff) {
    if (RS485_ReadMessage(fAvailable, fRead, buff)) {
        return true;
    }
    
    return false;
}

/*
    Sends a message on the RS485 bus.
    
    Parameter   Description
    buff        Pointer to a char array containing the message
    
    Returns true if the message was written to the bus successfully. False otherwise.
*/
bool sendMessage(char* buff) {
    if (RS485_SendMessage(buff, fWrite, ENABLE_PIN)) {
        return true;
    }
    
    return false;
}