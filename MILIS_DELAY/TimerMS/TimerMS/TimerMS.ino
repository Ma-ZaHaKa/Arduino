#include <TimerMs.h>

TimerMs tmr(500);


void setup()
{
  Serial.begin(9600);
  tmr.start();
  tmr.attach(OnTimer);
}

void OnTimer()
{
  Serial.println("!!!");
}

void loop()
{
  tmr.tick();
  //TASK(1000);
}

void TASK(int delay)
{
  static uint32_t tmr;
  if(millis() - tmr >= delay)
  {
    tmr = millis();
    Serial.println("!!!");
  }
}

bool _DKSleep(float deltaTime, float waitTime, float& sleepBuffer)
{
  sleepBuffer += deltaTime;
  if (sleepBuffer >= waitTime) {
    sleepBuffer = 0.0f;
    return true;
  }
  return false;
}