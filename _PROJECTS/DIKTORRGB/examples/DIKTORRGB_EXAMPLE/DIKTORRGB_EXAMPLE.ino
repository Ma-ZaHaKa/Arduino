#include "DIKTORRGB.h"

#define redPin 11
#define greenPin 6
#define bluePin 5

DIKTORRGB rgb(redPin, greenPin, bluePin); // экономия памяти через define

void setup()
{
  Serial.begin(9600);
  rgb.InitFullAnimation(10, 1000); // полный спектр
  rgb.InitFadeAnimation(10, 1000); // полный спектр
  rgb.InitRCAnimation(1000); // полный спектр
}

void loop()
{
  rgb.OnAnimation();
  //rgb.SetColor(255, 0, 0);
}

