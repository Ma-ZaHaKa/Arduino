#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2);
int d;
int b;
int v;
double T;
double c = 0.003968;
int a;
double P = 0.39;  //сопротивление 2х проводов датчика
double RP;
int AC_LOAD = 3;
int dimming = 127;
int analogPin= 1;
int raw= 0;
int Vin= 4.53;
float Vout= 0;
float R1= 147.83;
float R= 0;
float buffer= 0;


void setup()
{
  Serial.begin(9600);
  lcd.init();                     
  lcd.backlight();
  pinMode(AC_LOAD, OUTPUT);
  pinMode(A2, INPUT);
  attachInterrupt(0, zero_crosss_int, RISING);
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop()
{
  /*считывание крутилки*/
  a = analogRead(A2);
  a = map(a, 0, 1020, -50, 100);
constrain(a, -30, 70);
  Serial.println(a);
  /*конец считывания крутилки*/

  
raw= analogRead(analogPin);
if(raw) 
{
buffer= raw * Vin;
Vout= (buffer)/1024.0;
buffer= (Vin/Vout) -1;
R= R1 * buffer;
RP= R - P;
Serial.println(RP);
}


T = (-1+(RP/100))/c;  //temp

d = T + a;
b = T + a;

d = map(d, 0, 150, 6, 127);
constrain(d, 6, 127);

v = map(d, 6, 127, 223, 4);
constrain(d, 223, 4);
dimming = d;



lcd.setCursor(0, 0);
 lcd.print("TH ");
 lcd.print(T);
 
lcd.setCursor(0, 1);  //резистор
  lcd.print("K");
  lcd.print(a);
  
  lcd.setCursor(10, 0);
 lcd.print("TK ");
 lcd.print(b);

 lcd.setCursor(5, 1);
 lcd.print("D ");
 lcd.print(d);
  lcd.setCursor(11, 1);
 lcd.print("V ");
 lcd.print(v);
 
 
  delay(150);
lcd.clear();


}
void zero_crosss_int()  //function to be fired at the zero crossing to dim the light

{

  // Firing angle calculation : 1 full 50Hz wave =1/50=20ms

  // Every zerocrossing thus: (50Hz)-> 10ms (1/2 Cycle)

  // For 60Hz => 8.33ms (10.000/120)

  // 10ms=10000us

  // (10000us - 10us) / 128 = 75 (Approx) For 60Hz =>65

 

  int dimtime = (75*dimming);    // For 60Hz =>65   

  delayMicroseconds(dimtime);    // Wait till firing the TRIAC

  digitalWrite(AC_LOAD, HIGH);   // Fire the TRIAC

  delayMicroseconds(10);         // triac On propogation delay (for 60Hz use 8.33)

  digitalWrite(AC_LOAD, LOW);    // No longer trigger the TRIAC (the next zero crossing will swith it off) TRIAC

}
