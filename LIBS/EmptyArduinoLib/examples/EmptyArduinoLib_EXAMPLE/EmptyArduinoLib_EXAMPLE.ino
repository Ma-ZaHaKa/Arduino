#include "EmptyArduinoLib.h"

#define pin1 2
#define pin2 4

//EmptyArduinoLib obj(pin1, pin2); // экономия памяти через define
void test();

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  test();
}

// the loop function runs over and over again forever
void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}

void test()
{
  TestSerialPrint();
}