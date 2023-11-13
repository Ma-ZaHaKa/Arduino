void setup() {
  int buzzer = 4;
  tone(buzzer, 50000);
  delay(500);
  noTone(buzzer);
  
  Serial.begin(9600);  
  Serial.setTimeout(5);
  pinMode(LED_BUILTIN, OUTPUT);
  //pinMode(LED_R, OUTPUT);
  //pinMode(LED_G, OUTPUT);
}

void loop() {
  //analogRead(A0);
  //analogWrite(LED_B,b);
  if(Serial.available())
  {
    char str[30];
    int amount = Serial.readBytesUntil(';', str, 30);
    str[amount] = NULL;

    int data[5];
    int count = 0;
    char* offset = str;
    while (true)
    {
      data[count++] = atoi(offset);
      offset = strchr(offset, ',');
      if(offset) offset++;
      else break;
    }    
    switch(data[0])
    {
             case 1://выкл смены цвета
              digitalWrite(LED_BUILTIN, HIGH);
             break;
             case 2://выкл смены цвета
              digitalWrite(LED_BUILTIN, LOW);
             break;
    }
    Serial.println(data[0]);
    delay(200);
  }
    /*digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);*/ 
}
