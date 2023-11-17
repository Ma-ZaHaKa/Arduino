#include "EmptyArduinoLib.h"
#include <Arduino.h>

EmptyArduinoLib::EmptyArduinoLib(uint8_t _pin1, uint8_t _pin2)
{
	pin1 = _pin1;
	pin2 = _pin2;
}

void TestSerialPrint()
{
	Serial.println("22313213-" + String(123));
}