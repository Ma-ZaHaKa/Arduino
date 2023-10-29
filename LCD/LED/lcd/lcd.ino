#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 11, 5, 4, 3, 12);

void setup()
{
  pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
digitalWrite(7, HIGH);
analogWrite(6, 150);

 // lcd.begin(16,1);
  lcd.setCursor(3, 0);
  lcd.print("hello, world!");
}

void loop() {}
