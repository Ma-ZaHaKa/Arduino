#include <ArduinoJson.h>
#include <EEPROM.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <LCD_1602_RUS.h>
#include "GyverTM1637.h"


LiquidCrystal_I2C lcd(0x27,16,2);  // Устанавливаем дисплей
LCD_1602_RUS lcd_ru(0x27,16,2); // присваиваем имя LCD для дисплея


// Define the pins for TM1637 (CLK, DIO)
GyverTM1637 disp(2, 4);
//GyverTM1637 disp(7, 8);


void setup()
{
  Serial.begin(9600);
  lcd_ru.init();                     
  lcd_ru.noBacklight();

  disp.clear();        // очистить
  disp.brightness(0);  // яркость 0-7
  //disp.displayByte(_H, _E, _L, _L);  // вывести текст
  //delay(2000);
  //disp.displayInt(1234);      // вывести чисел
  
  //delay(2000);
  //disp.displayClock(16, 37);  // вывести часы и минуты
  //delay(2000);
  //displayStringOnTM1637("ABCDS");
  //uint8_t segments[] = {B01111110, B00000100, B10110110, B10011110}; // Пример значений для сегментов
  //disp.displayByte(segments);
    //uint8_t segments[] = {1, 1, 1, 1, 0, 1, 1, 0};
    //disp.display(segments, sizeof(segments) / sizeof(segments[0]));
    //byte values[] = {3, 5, 9, 0}; 
    //disp.display(values);

    //byte values[] = {7, 7}; 
    //disp.display(0, 0);
    /*for (int i = -100; i < 101; ++i)
    {
      //disp.display(0, i);
      disp.displayInt(i);
      delay(500);
    }*/
    /*for (int i = 0; i < 255; ++i)
    {
      disp.displayByte(i);
      delay(50);
    }*/

    //disp.display(0, 'A');
    //disp.display("AAAA");
    //displayStringOnTM1637("ABCDEF");
    //uint8_t segments[] = {B00000001, 0, 0, 0}; // Пример значений для сегментов
    //disp.displayByte(_H, _empty, _empty, _empty);
    //disp.displayByte(0x77, _empty, _empty, _empty);
    //disp.displayByte(0x57, _empty, _empty, _empty);
    //disp.displayByte(0x57, _empty, _empty, _empty);
    //int segments_[] = {1, 2, 3, 4, 5};
    //int combinedValue = CombineSegments(segments_);
    //disp.displayByte(combinedValue, 0, 0, 0);
    //digitalWrite(5, HIGH);

    //displayStringOnTM1637("ABCD");
    //delay(5000);
}
void loop() {
  // мигаем двоеточием дисплея
  /*disp.point(0);
  delay(500);
  disp.point(1);
  delay(500);*/
  //runningText();
  String AlphaKeyU = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  String AlphaKeyL = "abcdefghijklmnopqrstuvwxyz";
  String Other = "0123456789-_= ";
  String _out = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_= ";

  //disp.displayByte(CombineSegments("a"), 0, 0, 0);
  //disp.displayByte(getDisplayChar('A'), 0, 0, 0);
  //disp.displayByte(getDisplayChar(AlphaKeyU[0]), 0, 0, 0);
  //disp.displayByte(getDisplayChar('~'), 0, 0, 0);

  /*int sz = _out.length();
  for (int i = 0; i < sz; i++)
  {
    int tmp = getDisplayChar(_out[i]);
    disp.displayByte(tmp, 0, 0, 0);
    delay(1000);
  }*/
  _out = "hello  enjoy 1637 display";
  runningTextDK(_out, 500);
}





//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~7SEGMENT~~~~~~~~~BY~DIKTOR~~~~~~
// Функция, возвращающая значение для включения сегмента по указанному номеру
int GetInt(int segmentNumber)
{
    /*
     _a_
   f|   |b
    |_g_|
   e|   |c
    |_d_|
  */
  // mask B ~ G F E D C B A  // 0 disabled 1 enabled

  // В зависимости от номера сегмента возвращаем соответствующее значение
  switch (segmentNumber) {
    case 1:
      return B00000001; // A
    case 2:
      return B00000010; // B
    case 3:
      return B00000100; // C
    case 4:
      return B00001000; // D
    case 5:
      return B00010000; // E
    case 6:
      return B00100000; // F
    case 7:
      return B01000000; // G
    default:
      return 0; // Возвращаем 0 для выключения всех сегментов
  }
}

int GetInt(char segmentChar)
{
  char lowercaseChar = tolower(segmentChar);
  switch (lowercaseChar) {
    case 'a':
      return B00000001; // A
    case 'b':
      return B00000010; // B
    case 'c':
      return B00000100; // C
    case 'd':
      return B00001000; // D
    case 'e':
      return B00010000; // E
    case 'f':
      return B00100000; // F
    case 'g':
      return B01000000; // G
    default:
      return 0;
  }
}

int CombineSegments(const String& segmentString) // "abcdefg"
{
  int result = 0;
  for (char segmentChar : segmentString) {
    result |= GetInt(segmentChar);
  }
  return result;
}

//size_t seg_sz = sizeof(segments) / sizeof(segments[0]);
int CombineSegments(const int segments[], size_t seg_sz)
{
  int result = 0;
  for (size_t i = 0; i < seg_sz; ++i) {
    result |= GetInt(segments[i]);
  }
  return result;
}

//uint8_t getDisplayChar(char c)
int getDisplayChar(char c)
{
  /*
     _a_
   f|   |b
    |_g_|
   e|   |c
    |_d_|
  */
  // mask B ~ G F E D C B A  // 0 disabled 1 enabled

  // GetInt(char segmentChar)
  // int CombineSegments(String segmentString) // "abcdefg"
  c = tolower(c);
  switch (c)
  {
    /*case 'A': return CombineSegments("abcefg");
    case 'B': return CombineSegments("cdefg");
    case 'C': return CombineSegments("adef");
    case 'D': return CombineSegments("bcdeg");
    case 'E': return CombineSegments("adefg");
    case 'F': return CombineSegments("aefg");
    case 'G': return CombineSegments("abcdfg");
    case 'H': return CombineSegments("cefg");
    case 'I': return CombineSegments("c");
    case 'J': return CombineSegments("bcde");
    case 'K': return CombineSegments("bcefg");
    case 'L': return CombineSegments("def");
    case 'M': return CombineSegments("ace");
    case 'N': return CombineSegments("ceg");
    case 'O': return CombineSegments("cdeg");
    case 'P': return CombineSegments("abefg");
    case 'Q': return CombineSegments("abcfg");
    case 'R': return CombineSegments("eg");
    case 'S': return CombineSegments("acdfg");
    case 'T': return CombineSegments("defg");
    case 'U': return CombineSegments("bcdef");
    case 'V': return CombineSegments("cde");
    case 'W': return CombineSegments("bdf");
    case 'X': return CombineSegments("bcefg");
    case 'Y': return CombineSegments("bcdfg");
    case 'Z': return CombineSegments("abdeg");*/

    case 'a': return CombineSegments("abcefg");
    case 'b': return CombineSegments("cdefg");
    case 'c': return CombineSegments("adef");
    case 'd': return CombineSegments("bcdeg");
    case 'e': return CombineSegments("adefg");
    case 'f': return CombineSegments("aefg");
    case 'g': return CombineSegments("abcdfg");
    case 'h': return CombineSegments("cefg");
    //case 'i': return CombineSegments("c");
    case 'i': return CombineSegments("ef");
    case 'j': return CombineSegments("bcde");
    case 'k': return CombineSegments("bcefg");
    case 'l': return CombineSegments("def");
    case 'm': return CombineSegments("ace");
    case 'n': return CombineSegments("ceg");
    case 'o': return CombineSegments("cdeg");
    case 'p': return CombineSegments("abefg");
    case 'q': return CombineSegments("abcfg");
    case 'r': return CombineSegments("eg");
    case 's': return CombineSegments("acdfg");
    case 't': return CombineSegments("defg");
    case 'u': return CombineSegments("bcdef");
    case 'v': return CombineSegments("cde");
    case 'w': return CombineSegments("bdf");
    case 'x': return CombineSegments("bcefg");
    case 'y': return CombineSegments("bcdfg");
    case 'z': return CombineSegments("abdeg");

    case '0': return CombineSegments("abcdef");
    case '1': return CombineSegments("bc");
    case '2': return CombineSegments("abdeg");
    case '3': return CombineSegments("abcdg");
    case '4': return CombineSegments("bcfg");
    case '5': return CombineSegments("acdfg");
    case '6': return CombineSegments("acdefg");
    case '7': return CombineSegments("abc");
    case '8': return CombineSegments("abcdefg");
    case '9': return CombineSegments("abcdfg");

    case '-': return CombineSegments("g");
    case '_': return CombineSegments("d");
    case '=': return CombineSegments("dg");
    case ' ': return CombineSegments("");
    default: return CombineSegments(""); // Значение по умолчанию (пустой символ)
  }
}

byte* GetDisplayByteArray(String str)
{
  if (str == NULL || str.length() == 0) { return NULL; }
  //str = str.substring(0, min(str.length(), 4));
  //while (str.length() < 4) { str += " "; }

  byte* byteArray = new byte[str.length()];
  for (int i = 0; i < str.length(); i++) { byteArray[i] = getDisplayChar(str[i]); }
  return byteArray; // !! delete[] byteArray;
}
void runningTextDK(const String& str, int _delay)
{
  byte* bytes = GetDisplayByteArray(str);
  disp.runningString(bytes, str.length(), _delay);
  //disp.runningString(bytes, sizeof(bytes), 200);
  delete[] bytes;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




/*void GyverTM1637::runningString(uint8_t DispData[], byte amount, int delayMs) {
    uint8_t segm_data[amount + 8];    // оставляем место для 4х пустых слотов в начале и в конце
    for (byte i = 0; i < 4; i++) {  // делаем первые 4 символа пустыми
        segm_data[i] = 0x00;
    }
    for (byte i = 0; i < amount; i++) {  // далее забиваем тем что на входе (сам текст строки)
        segm_data[i + 4] = DispData[i];
    }
    for (byte i = amount + 4; i < amount + 8; i++) {  // и последние 4 тоже забиваем пустыми символами
        segm_data[i] = 0x00;
    }
    for (byte i = 0; i <= amount + 4; i++) {   // выводим
        displayByte(segm_data[i], segm_data[i + 1], segm_data[i + 2], segm_data[i + 3]);
        delay(delayMs);
    }
}*/

void runningText() {
  byte welcome_banner[] = {_H, _E, _L, _L, _O, _empty, _empty,
                           _e, _n, _j, _o, _y, _empty, _empty,
                           _1, _6, _3, _7, _empty, _d, _i, _S, _P, _l, _a, _y
                          };
  disp.runningString(welcome_banner, sizeof(welcome_banner), 200);  // 200 это время в миллисекундах!
}

