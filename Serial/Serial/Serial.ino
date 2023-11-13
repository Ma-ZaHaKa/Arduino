void setup()
{
    Serial.begin(9600);
}

void loop()
{
  /*if (Serial.available() > 0)
  {
    char receivedChar = Serial.read();
    Serial.print("Received character: ");
    Serial.println(receivedChar);
  }*/

  if (Serial.available())
  {
    String inputString = Serial.readStringUntil('\n');
    Serial.print("Received: ");
    Serial.println(inputString);
  }
}
