int inByte = 0;
byte RU = 3;
byte EN = 5;
byte BASE = 6;
byte LED_G = 9;
byte LED_R = 10;
byte LED_B = 11;

short POT = 255;

short RRU = 0;
short GRU = 0;
short BRU = 255;
short REN = 255;
short GEN = 0;
short BEN = 0;

bool change = true;
bool lan = false;
void(* resetFunc) (void) = 0;
void dis(bool b)
{
  if(b)
  {
    analogWrite(BASE, 170);
    analogWrite(EN, 0);
    analogWrite(RU, 255);
  }
  else
  {
    analogWrite(BASE, 255);
    analogWrite(RU, 0);
    analogWrite(EN, 255);
  }

  
}
void setup() {
  Serial.begin(9600);  
  Serial.setTimeout(5);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(RU, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(BASE, OUTPUT);
  pinMode(A0, INPUT);
  digitalWrite(BASE, LOW);
  digitalWrite(RU, LOW);
  digitalWrite(EN, LOW);
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_B, LOW);
  for(int i = 0;i<3;i++){
  digitalWrite(BASE, HIGH);
  delay(500);
  digitalWrite(BASE, LOW);
  delay(500);
  }
  analogWrite(LED_G, map(POT, 0, 1023,0, 255));
}
void setRGB(int r,int g,int b,int s)
 {
 analogWrite(LED_R,r);
 analogWrite(LED_G,g);
 analogWrite(LED_B,b);
 delay(s);
 }
void loop() { 
  if(change){
   POT = analogRead(A0);
  }
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
             case 0://выкл смены цвета
                change = !change;
             break;
             case 1://EN
                lan = false;
                dis(lan);
                if(change){
                analogWrite(LED_R, map(POT, 0, 1023,0, REN));
                analogWrite(LED_G, map(POT, 0, 1023,0, GEN));
                analogWrite(LED_B, map(POT, 0, 1023,0, BEN));
                }
              break;
             case 2://RU
              lan = true;
              dis(lan);
              if(change){
              analogWrite(LED_R, map(POT, 0, 1023,0, RRU));
              analogWrite(LED_G, map(POT, 0, 1023,0, GRU));
              analogWrite(LED_B, map(POT, 0, 1023,0, BRU));
              }
             break;
            case 3://замена общего
            if(count == 5)
            {
              analogWrite(LED_R, map(data[4], 0, 1023,0, data[1]));
              analogWrite(LED_G, map(data[4], 0, 1023,0, data[2]));
              analogWrite(LED_B, map(data[4], 0, 1023,0, data[3]));
              }
             else if(count == 4)
             {
                analogWrite(LED_R, map(POT, 0, 1023,0,  data[1]));
                analogWrite(LED_G, map(POT, 0, 1023,0,  data[2]));
                analogWrite(LED_B, map(POT, 0, 1023,0,  data[3]));
             }
        break;
            case 4://rus замена цвета
                RRU = data[1];
                GRU = data[2];
                BRU = data[3];
                if(lan && change)
                {
               analogWrite(LED_R, map(POT, 0, 1023,0, RRU));
              analogWrite(LED_G, map(POT, 0, 1023,0, GRU));
              analogWrite(LED_B, map(POT, 0, 1023,0, BRU));
                }
        break;
            case 5://en замена цвета
                REN = data[1];
                GEN = data[2];
                BEN = data[3];
                if(!lan && change)
                {
                analogWrite(LED_R, map(POT, 0, 1023,0, REN));
                analogWrite(LED_G, map(POT, 0, 1023,0, GEN));
                analogWrite(LED_B, map(POT, 0, 1023,0, BEN));
                }
        break;
        case 6://def
                RRU = 0;
                GRU = 0;
                BRU = 255;
                REN = 255;
                GEN = 0;
                BEN = 0;
                if(lan)
                {
              analogWrite(LED_R, map(POT, 0, 1023,0, RRU));
              analogWrite(LED_G, map(POT, 0, 1023,0, GRU));
              analogWrite(LED_B, map(POT, 0, 1023,0, BRU));
                }
               else
               {
                analogWrite(LED_R, map(POT, 0, 1023,0, REN));
                analogWrite(LED_G, map(POT, 0, 1023,0, GEN));
                analogWrite(LED_B, map(POT, 0, 1023,0, BEN));
                }
        break;
                case 7://res
                resetFunc();
        break;
                case 8://anim
                int red=0, green=0, blue=0;
                while(1)
                {
                 if(Serial.available() && change)
                  {
                    break;
                  }

 red=255;green=0;blue=0;
 for(green=0;green<=255 && !(Serial.available() && change);green++)
 {
  setRGB(red,green,blue,data[1]);  
 }
 red=255;green=255;blue=0; 
 for(red=255;red>=0 && !(Serial.available() && change);red--) 
 {
  setRGB(red,green,blue,data[1]); 
 }
 red=0;green=255;blue=0;
 for(blue=0;blue<=255 && !(Serial.available() && change);blue++) 
 {
  setRGB(red,green,blue,data[1]);   
 }
 red=0;green=255;blue=255; 
 for(green=255;green>=0 && !(Serial.available() && change);green--) 
 {
  setRGB(red,green,blue,data[1]); 
 }
 red=0;green=0;blue=255;
 for(red=0;red<=255 && !(Serial.available() && change);red++) 
 {
  setRGB(red,green,blue,data[1]);  
 }
 red=255;green=0;blue=255; 
 for(blue=255;blue>=0 && !(Serial.available() && change);blue--)  
 {
  setRGB(red,green,blue,data[1]); 
 }
 }
        break;
    }
  }
}
