RS485-Arduino-Library
=====================
Arduino Library for use with RS485 devices. It creates a software-serial on pins D2(RX) and D3(TX) that is connected to a RS485 chip. 

Original library: https://github.com/Protoneer/RS485-Arduino-Library

Added the following methods to enable switching between multiple modules that use SoftwareSerial
    void RS485_End()
    void RS485_Listen()
    