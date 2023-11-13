#include "GyverTM1637.h"

int GetInt(int segmentNumber);
int GetInt(char segmentChar);
int CombineSegments(const String& segmentString);
int CombineSegments(const int segments[], size_t seg_sz);
int getDisplayChar(char c);
bool IsModifyedStr(const String& str);
String ModString(const String& str);
byte* GetDisplayByteArray(String str);
void runningTextDK(const String& str, int _delay);

class TM1637Animation
{
  public:
    MyClass() {}

    void InitAnimation(const String& str, int _delay, GyverTM1637* disp)
    {
        if (message != NULL) { delete[] message; message = NULL; }
        String Mstr = ModString(str);
        last_millis = millis();
        message = GetDisplayByteArray(Mstr);
        MSGSZ = Mstr.length();
        delay = _delay;
        display = disp;
    }

    void OnAnimation()
    {
      unsigned long currentMillis = millis();
      if (currentMillis - last_millis >= delay) {
        last_millis = currentMillis;
        display->displayByte(message);
        shiftMessage();
      }
    }

    void StopAnimation()
    {
      display->clear();
    }

    void shiftMessage()
    {
      byte temp = message[0];
      for (int i = 1; i < MSGSZ; i++) {
        message[i - 1] = message[i];
      }
      message[MSGSZ - 1] = temp;
    }

  //private:
    unsigned long last_millis = 0;
    GyverTM1637* display = NULL;
    byte* message = NULL; 
    int MSGSZ = 0;
    int delay = 0;
};

  GyverTM1637 disp1(2, 4);
  TM1637Animation disp1anim;


void setup()
{
  disp1.clear();        // очистить
  disp1.brightness(0);  // яркость 0-7

  String _out = "hello  enjoy 1637 display";
  int delay = 500;
  //runningTextDK(_out, 500);
  //disp1anim = TM1637Animation();
  disp1anim.InitAnimation(_out, delay, &disp1);
}

void loop()
{
    //disp1anim.OnAnimation();
    //disp1anim.StopAnimation();
    String _out = "hello  enjoy 1637 display";
    runningTextDK(_out, 500);
    //delay(100);
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~7SEGMENT~~~~~~~~~BY~DIKTOR~~~~~~
//int GetInt(int segmentNumber);
//int GetInt(char segmentChar);
//int CombineSegments(const String& segmentString);
//int CombineSegments(const int segments[], size_t seg_sz);
//int getDisplayChar(char c);
//bool IsModifyedStr(const String& str);
//String ModString(const String& str);
//byte* GetDisplayByteArray(String str);
//void runningTextDK(const String& str, int _delay);
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
    default: return CombineSegments("");
  }
}

/*bool IsModifyedStr(const String& str)
{
  if(str.length() > 8)
  { return ((str[0]==' ') && (str[1]==' ') && (str[2]==' ') && (str[3]==' ') && (str[str.length()-4]==' ') && (str[str.length()-3]==' ') && (str[str.length()-2]==' ') && (str[str.length()-1]==' ')); }
  return false;
}*/
String ModString(const String& str) { return ("    " + str + " " ); }
String GyverModString(const String& str) { return ("    " + str + "   " ); }

byte* GetDisplayByteArray(String str)
{
  if (str == NULL || str.length() == 0) { return NULL; }
  //if(!IsModifyedStr(str)) { str = ModString(str); }
  //str = str.substring(0, min(str.length(), 4));
  //while (str.length() < 4) { str += " "; }

  byte* byteArray = new byte[str.length()];
  for (int i = 0; i < str.length(); i++) { byteArray[i] = getDisplayChar(str[i]); }
  //byte* byteArray = new byte[str.length()+8]; // ____TEXT____
  //for (int i = 0; i < 4; i++) { byteArray[i] = CombineSegments(""); }
  //for (int i = 4; i < str.length(); i++) { byteArray[i] = getDisplayChar(str[i]); }
  //for (int i = str.length(); i < 4; i++) { byteArray[i] = CombineSegments(""); }
  return byteArray; // !! delete[] byteArray;
}
void runningTextDK(const String& str, int _delay)
{
  String Mstr = ModString(str);
  byte* bytes = GetDisplayByteArray(Mstr);
  int STRSZ = Mstr.length();
  runningString(bytes, STRSZ, _delay);
  //disp.runningString(bytes, sizeof(bytes), 200);
  delete[] bytes;
}
void runningString(uint8_t DispData[], byte amount, int delayMs)
 {
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
        disp1.displayByte(segm_data[i], segm_data[i + 1], segm_data[i + 2], segm_data[i + 3]);
        delay(delayMs);
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~





