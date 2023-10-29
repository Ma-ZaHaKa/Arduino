int a;
int b = 100;
int c;
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // Устанавливаем дисплей
void setup()
{Serial.begin(9600);
  lcd.init();                     
  lcd.backlight();


}
void loop()
{
 a = analogRead(A0);
a = map(a, 0, 1015, 0, 1);
constrain(a, 1, 2);
   
    lcd.setCursor(0, a);
  
  lcd.print("10000000kek00001");
  delay(100);
  lcd.clear();
  Serial.println(a);

}
