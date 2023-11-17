#ifndef _EmptyArduinoLib_h
#define _EmptyArduinoLib_h
#include <inttypes.h>
#include <Arduino.h>
class EmptyArduinoLib {
public:
    
    EmptyArduinoLib(uint8_t _pin1, uint8_t _pin2);
    
    void PrintData();

private:
    int pin1 = 0;
    int pin2 = 0;
    int data = 0;

};

void TestSerialPrint();


#endif