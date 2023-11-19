#include <ArduinoJson.h>
#include "DIKTORRGB.h"

#define redPin 11
#define greenPin 6
#define bluePin 5

#define JSON_BUFFER_SIZE 128
#define PROJ_CODE "rgb_controller_diktor"

DIKTORRGB rgb(redPin, greenPin, bluePin); // экономия памяти через define

void(* resetFunc) (void) = 0;

bool CanIntParse(const String& str)
{
  //str.trim();
  return (str == String(str.toInt()));
}
bool IsPWMVal(int val) { return ((val >= 0) && (val <= 255)); }
bool IsPercentVal(int val) { return ((val >= 0) && (val <= 100)); }


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~JSON~~~~~~
const char e_[] = "error";
const char d_[] = "data";
const char v_[] = "value";

void PrintErrorJson(const String& error_msg)
{
   DynamicJsonDocument responseDoc(JSON_BUFFER_SIZE);
   responseDoc[e_] = error_msg;
   serializeJson(responseDoc, Serial);
   Serial.println();
   responseDoc.clear();
}

void PrintOkJson()
{
   DynamicJsonDocument responseDoc(JSON_BUFFER_SIZE);
   responseDoc[d_] = "OK";
   serializeJson(responseDoc, Serial);
   Serial.println();
   responseDoc.clear();
}

void PrintDataJson(const String& message)
{
   DynamicJsonDocument responseDoc(JSON_BUFFER_SIZE);
   responseDoc[d_] = message;
   serializeJson(responseDoc, Serial);
   Serial.println();
   responseDoc.clear();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~SETUP!!!!~~~~~~~~~~~~~
void setup()
{
  Serial.begin(9600);
  rgb.SetCtrMode(true); //ctr гамма
  // pinout PWM OUTPUT auto in DIKTORLIB
  //rgb.SetRandomColor();

  int L = 1;
  int R = 10;
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  analogWrite(9, map(L, 0, 100, 46, 255));
  analogWrite(10, map(R, 0, 100, 54, 255));
}

void loop()
{
  if (Serial.available()) // || SA() > 0
  {
      String inputString = Serial.readStringUntil('\n'); //!!!! {}\n

      // Попытка разобрать JSON
      DynamicJsonDocument jsonDoc(JSON_BUFFER_SIZE);
      DeserializationError error = deserializeJson(jsonDoc, inputString);

      if (!error)
      {
        if (jsonDoc.containsKey("mode"))
        {
          const String mode = jsonDoc["mode"].as<String>();




          // {"mode":"set_color", "r":"255", "g":"100", "b":"10"}
          // {"mode":"set_color", "r":"255", "g":"255", "b":"255"}    // white dbg
          if(mode == "set_color")
          {
            int r = -1;
            int g = -1;
            int b = -1;
            String temp_buffer = "";
            bool flag_any = false; // -1 val not change color on SetColor
            bool flag_parse_checker = false;


            //--DETECT--SET--COLOR
            // Red
            if(jsonDoc.containsKey("r")) { temp_buffer = jsonDoc["r"].as<String>(); flag_parse_checker = true; }
            if(!CanIntParse(temp_buffer) && flag_parse_checker) { PrintErrorJson("~err parse"); return; }
            else if(flag_parse_checker) { r = temp_buffer.toInt(); if(!IsPWMVal(r)) { PrintErrorJson("~err not pwm val"); return; } flag_any = true; }
            flag_parse_checker = false;

            // Green
            if(jsonDoc.containsKey("g")) { temp_buffer = jsonDoc["g"].as<String>(); flag_parse_checker = true; }
            if(!CanIntParse(temp_buffer) && flag_parse_checker) { PrintErrorJson("~err parse"); return; }
            else if(flag_parse_checker) { g = temp_buffer.toInt(); if(!IsPWMVal(g)) { PrintErrorJson("~err not pwm val"); return; } flag_any = true; }
            flag_parse_checker = false;

            // Blue
            if(jsonDoc.containsKey("b")) { temp_buffer = jsonDoc["b"].as<String>(); flag_parse_checker = true; }
            if(!CanIntParse(temp_buffer) && flag_parse_checker) { PrintErrorJson("~err parse"); return; }
            else if(flag_parse_checker) { b = temp_buffer.toInt(); if(!IsPWMVal(b)) { PrintErrorJson("~err not pwm val"); return; } flag_any = true; }
            flag_parse_checker = false;

            //DBG DIKTOR
            //Serial.println("R:"+String(r)+" G:"+String(g)+" B:"+String(b));

            if(flag_any) { rgb.SetColor(r, g, b); PrintOkJson(); return; }
            PrintErrorJson("~err not setted color");
          }






          // {"mode":"set_anim", "anim_num":"2", "delayanim":"10", "delaycolor":"1000"}    // ms   //!!anim_mode = 8 && delayanim any num EX 0 (da not used) || anim_mode = 1 da && dc 0 (zero) (not used)
          else if(mode == "set_anim" && jsonDoc.containsKey("anim_num") && jsonDoc.containsKey("delayanim") && jsonDoc.containsKey("delaycolor")) // full
          {
            const String _anim_num = jsonDoc["anim_num"].as<String>();
            const String _delayanim = jsonDoc["delayanim"].as<String>();
            const String _delaycolor = jsonDoc["delaycolor"].as<String>();

            if((!CanIntParse(_delayanim)) || (!CanIntParse(_delaycolor)) || (!CanIntParse(_anim_num))) { PrintErrorJson("~err parse"); return; }
            int delayanim = _delayanim.toInt();
            int delaycolor = _delaycolor.toInt();
            int anim_num = _anim_num.toInt();

            if(!rgb.IsAnimNumber(anim_num)) { PrintErrorJson("~err invalid anim num"); return; }
            PrintOkJson();


            //----anims
            if(anim_num == 0) { rgb.DisableAll(); }
            else if(anim_num == 1) { rgb.SetRandomColor(); } // static color
            else if(anim_num == 2) { rgb.InitFullAnimation(delayanim, delaycolor); } // full dual
            else if(anim_num == 3) { rgb.InitFadeAnimation(delayanim, delaycolor); } // fade dual

            else if(anim_num == 4) {  } // full offset
            else if(anim_num == 5) {  } // fade offset

            // {"mode":"set_anim", "anim_num":"7", "delayanim":"4", "delaycolor":"0"} 
            // {"mode":"set_anim", "anim_num":"7", "delayanim":"10", "delaycolor":"1000"} 
            // InitSmoothAnimation(bool all_colors_mode, int _DelayAnim, int _DelayColor, bool random_color) rc=false по кругу
            else if(anim_num == 6) {  rgb.InitSmoothAnimation(true, delayanim, delaycolor, true); } // 6 color smooth
            else if(anim_num == 7) { rgb.InitSmoothAnimation(false, delayanim, delaycolor, true); } // 3 color smooth

            else if(anim_num == 8) { rgb.InitRCAnimation(delaycolor);} // random color
          }



          else if (mode == "disable_color") { rgb.DisableAll(); }




          //else if (jsonDoc["mode"] == "hello") { PrintDataJson(PROJ_CODE); }
          else if (mode == "hello") { PrintDataJson(PROJ_CODE); }
          else if (mode == "reset") { resetFunc(); }
          else { PrintErrorJson("~errmode"); } // не найден нужный mode
        } // contains mode

        // parse but field mode not exists
        else { PrintErrorJson("errmodefield"); }
      } // !error

      else if (inputString == "hello") { PrintDataJson(PROJ_CODE); }
      //else { PrintErrorJson("Error Deserealization"); Serial.println(error.c_str()); }
      else { Serial.println(error.c_str()); }
  } // !Serial

  {
    // on animation tick
    rgb.OnAnimation();
  }

}

