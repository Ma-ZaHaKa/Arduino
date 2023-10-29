#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int a=1;
LiquidCrystal_I2C lcd(0x27,16,2);  // Устанавливаем дисплей
void setup()
{Serial.begin(9600);
  lcd.init();                     
  lcd.backlight();


}
void loop()
{
 
   
    lcd.setCursor(0, 1);
  
  lcd.print("10000000kek00001");
  

}
