#include "DIKTORRGB.h"
#include <Arduino.h>


DIKTORRGB::DIKTORRGB(byte _R1Pin, byte _G1Pin, byte _B1Pin, byte _R2Pin = -1, byte _G2Pin = -1, byte _B2Pin = -1)
{
	R1_Pin = _R1Pin;
	G1_Pin = _G1Pin;
	B1_Pin = _B1Pin;

	R2_Pin = _R2Pin;
	G2_Pin = _G2Pin;
	B2_Pin = _B2Pin;

	IsDoubleChannel = (_R2Pin != -1);
	MaxBrightness = 255;

	pinMode(R1_Pin, OUTPUT);
	pinMode(G1_Pin, OUTPUT);
	pinMode(B1_Pin, OUTPUT);

	if (IsDoubleChannel)
	{
		pinMode(R2_Pin, OUTPUT);
		pinMode(G2_Pin, OUTPUT);
		pinMode(B2_Pin, OUTPUT);
	}
}


int _RandVUKL(int min, int max, bool set_seed) {
	// Инициализируем генератор случайных чисел с использованием аналогового входа A0
	if (set_seed) { randomSeed(analogRead(A0)); }

	// Генерируем случайное число в диапазоне [min, max - 1]
	return random(min, max);
}

int _RandVKL(int min, int max, bool set_seed) {
	// Инициализируем генератор случайных чисел с использованием аналогового входа A0
	if (set_seed) { randomSeed(analogRead(A0)); }

	// Генерируем случайное число в диапазоне [min, max]
	return random(min, max + 1);
}

byte getBrightCRT(byte val) { return (0.0003066 * pow(val, 2.46)); }

void DIKTORRGB::SetCtrMode(bool _CrtUse) { IsUseCRT = _CrtUse; }
bool DIKTORRGB::GetCrTuSE() { return IsUseCRT; }
void DIKTORRGB::SetMaxBrightness(int _max_brightness) { MaxBrightness = _max_brightness; }



//-----
void DIKTORRGB::SetColor(int _RPwm, int _GPwm, int _BPwm)
{
	if (anim_num != 1) { StopAnimation(); anim_num = 1; }
	_SetColor(_RPwm, _GPwm, _BPwm);
}
void DIKTORRGB::SetColorByNum(int _color, bool stop_anim) // ?? stop anim
{
	if (stop_anim)
	{
		if (_color == 0) { SetColor(0, 0, 0); } // none
		else if (_color == 1) { SetColor(MaxBrightness, 0, 0); } // red
		else if (_color == 2) { SetColor(0, MaxBrightness, 0); } // green
		else if (_color == 3) { SetColor(0, 0, MaxBrightness); } // blue (dark)
		else if (_color == 4) { SetColor(MaxBrightness, MaxBrightness, 0); } // yellow RG
		else if (_color == 5) { SetColor(0, MaxBrightness, MaxBrightness); } // blue (light) GB
		else if (_color == 6) { SetColor(MaxBrightness, 0, MaxBrightness); } // purple RB
		else if (_color == 7) { SetColor(MaxBrightness, MaxBrightness, MaxBrightness); } // white
	}
	else
	{
		if (_color == 0) { _SetColor(0, 0, 0); } // none
		else if (_color == 1) { _SetColor(MaxBrightness, 0, 0); } // red
		else if (_color == 2) { _SetColor(0, MaxBrightness, 0); } // green
		else if (_color == 3) { _SetColor(0, 0, MaxBrightness); } // blue (dark)
		else if (_color == 4) { _SetColor(MaxBrightness, MaxBrightness, 0); } // yellow RG
		else if (_color == 5) { _SetColor(0, MaxBrightness, MaxBrightness); } // blue (light) GB
		else if (_color == 6) { _SetColor(MaxBrightness, 0, MaxBrightness); } // purple RB
		else if (_color == 7) { _SetColor(MaxBrightness, MaxBrightness, MaxBrightness); } // white
	}
}
void DIKTORRGB::SetColorByNumPWM(int _color, int _pwm)
{

	if (_color == 0) { _SetColor(0, 0, 0); } // none
	else if (_color == 1) { _SetColor(_pwm, 0, 0); } // red
	else if (_color == 2) { _SetColor(0, _pwm, 0); } // green
	else if (_color == 3) { _SetColor(0, 0, _pwm); } // blue (dark)
	else if (_color == 4) { _SetColor(_pwm, _pwm, 0); } // yellow RG
	else if (_color == 5) { _SetColor(0, _pwm, _pwm); } // blue (light) GB
	else if (_color == 6) { _SetColor(_pwm, 0, _pwm); } // purple RB
	else if (_color == 7) { _SetColor(_pwm, _pwm, _pwm); } // white
}
void DIKTORRGB::_SetColor(int _RPwm, int _GPwm, int _BPwm) // -1 не трогаем pwm
{
	if (IsUseCRT)
	{
		if (_RPwm >= 0) { analogWrite(R1_Pin, getBrightCRT(_RPwm)); }
		if (_GPwm >= 0) { analogWrite(G1_Pin, getBrightCRT(_GPwm)); }
		if (_BPwm >= 0) { analogWrite(B1_Pin, getBrightCRT(_BPwm)); }

		if (IsDoubleChannel)
		{
			if (_RPwm >= 0) { analogWrite(R2_Pin, getBrightCRT(_RPwm)); }
			if (_GPwm >= 0) { analogWrite(G2_Pin, getBrightCRT(_GPwm)); }
			if (_BPwm >= 0) { analogWrite(B2_Pin, getBrightCRT(_BPwm)); }
		}
	}
	else
	{
		if (_RPwm >= 0) { analogWrite(R1_Pin, _RPwm); }
		if (_GPwm >= 0) { analogWrite(G1_Pin, _GPwm); }
		if (_BPwm >= 0) { analogWrite(B1_Pin, _BPwm); }

		if (IsDoubleChannel)
		{
			if (_RPwm >= 0) { analogWrite(R2_Pin, _RPwm); }
			if (_GPwm >= 0) { analogWrite(G2_Pin, _GPwm); }
			if (_BPwm >= 0) { analogWrite(B2_Pin, _BPwm); }
		}
	}
}
void DIKTORRGB::SetRandomColor()
{
	int _clr = _RandVKL(1, 7, false); // color
	SetColorByNum(_clr, true); // true reset anim
}





void DIKTORRGB::OnAnimation()
{
	if (anim_num == 2) { OnFullAnimation(); } // full
	else if (anim_num == 3) { OnFadeAnimation(); } // fade
	// 4 full dual
	// 5 fade dual
	else if (anim_num == 6) { OnSmoothAnimation(); } // smooth
	else if (anim_num == 7) { OnSmoothAnimation(); } // smooth
	else if (anim_num == 8) { OnRCAnimation(); } // rc
}
void DIKTORRGB::StopAnimation()
{
	//if (anim_num == 2) { StopFullAnimation(); }
	StopFullAnimation(); // 2
	StopFadeAnimation(); // 3
	OnSmoothAnimation(); // 6 7
	StopRCAnimation(); // 8
	anim_num = 0;
}
void DIKTORRGB::SwitchAnimation(int _anim_num)
{
	if (_anim_num == 2) { InitFullAnimation(DelayAnim, DelayColor); }
	else if (_anim_num == 3) { InitFadeAnimation(DelayAnim, DelayColor); }

	else if (_anim_num == 6) { InitSmoothAnimation(true, DelayAnim, DelayColor); }
	else if (_anim_num == 7) { InitSmoothAnimation(false, DelayAnim, DelayColor); }

	else if (_anim_num == 8) { InitRCAnimation(DelayColor); }
}

void DIKTORRGB::DisableLight(bool channel)
{
	if (channel) { digitalWrite(R1_Pin, LOW); digitalWrite(G1_Pin, LOW); digitalWrite(B1_Pin, LOW); }
	else { digitalWrite(R2_Pin, LOW); digitalWrite(G2_Pin, LOW); digitalWrite(B2_Pin, LOW); }
}
void DIKTORRGB::DisableAll()
{
	_SetColor(0, 0, 0);
	/*if (R1_Pin != -1)
	{
		digitalWrite(R1_Pin, LOW);
		digitalWrite(G1_Pin, LOW);
		digitalWrite(B1_Pin, LOW);
	}

	if (R2_Pin != -1)
	{
		digitalWrite(R2_Pin, LOW);
		digitalWrite(G2_Pin, LOW);
		digitalWrite(B2_Pin, LOW);
	}*/
}
bool DIKTORRGB::IsAnimNumber(int _num)
{
	return ((_num >= 0) && (_num <= 8)); // min max header
}







//--------------FULL---(2)
void DIKTORRGB::InitFullAnimation(int _DelayAnim, int _DelayColor)
{
	StopAnimation();
	//last_millis = millis();
	last_millis = 0;
	DelayAnim = _DelayAnim;
	DelayColor = _DelayColor;
	CurrDelay = DelayColor;
	anim_num = 2;
}



void DIKTORRGB::OnFullAnimation()
{
	unsigned long currentMillis = millis();

	/*if (mode == 0) {
	  analogWrite(RPin, Brightness);
	  CurrDelay = DelayAnim;
	  ++mode;
	}*/

	if (currentMillis - last_millis >= CurrDelay)
	{
		last_millis = currentMillis;
		switch (anim_mode)
		{
		case 0:
			//analogWrite(R1_Pin, MaxBrightness);
			_SetColor(MaxBrightness, -1, -1); // red
			colorStep = 0;
			anim_mode++;
			CurrDelay = DelayColor;
			break;


		case 1: // YELLOW
			if (CurrDelay != DelayAnim) { CurrDelay = DelayAnim; }

			/*if (IsUseCRT) { analogWrite(G1_Pin, getBrightCRT(colorStep)); }
			else { analogWrite(G1_Pin, colorStep); }*/
			_SetColor(-1, colorStep, -1); // green

			colorStep++;
			if (colorStep > MaxBrightness) {
				colorStep = 0;
				anim_mode++;
				CurrDelay = DelayColor;
			}
			break;


		case 2: // GREEN
			if (CurrDelay != DelayAnim) { CurrDelay = DelayAnim; }

			/*if (IsUseCRT) { analogWrite(R1_Pin, getBrightCRT(MaxBrightness - colorStep)); }
			else { analogWrite(R1_Pin, MaxBrightness - colorStep); }*/
			_SetColor((MaxBrightness - colorStep), -1, -1); // green

			colorStep++;
			if (colorStep > MaxBrightness) {
				colorStep = 0;
				anim_mode++;
				CurrDelay = DelayColor;
			}
			break;


		case 3: // BLUE (LIGHT)
			if (CurrDelay != DelayAnim) { CurrDelay = DelayAnim; }

			/*if (IsUseCRT) { analogWrite(B1_Pin, getBrightCRT(colorStep)); }
			else { analogWrite(B1_Pin, colorStep); }*/
			_SetColor(-1, -1, colorStep); // blue

			colorStep++;
			if (colorStep > MaxBrightness) {
				colorStep = 0;
				anim_mode++;
				CurrDelay = DelayColor;
			}
			break;


		case 4: // BLUE (DARK)
			if (CurrDelay != DelayAnim) { CurrDelay = DelayAnim; }

			/*if (IsUseCRT) { analogWrite(G1_Pin, getBrightCRT(MaxBrightness - colorStep)); }
			else { analogWrite(G1_Pin, MaxBrightness - colorStep); }*/
			_SetColor(-1, (MaxBrightness - colorStep), -1); // blue

			colorStep++;
			if (colorStep > MaxBrightness) {
				colorStep = 0;
				anim_mode++;
				CurrDelay = DelayColor;
			}
			break;


		case 5: // PURPLE
			if (CurrDelay != DelayAnim) { CurrDelay = DelayAnim; }

			/*if (IsUseCRT) { analogWrite(R1_Pin, getBrightCRT(colorStep)); }
			else { analogWrite(R1_Pin, colorStep); }*/
			_SetColor(colorStep, -1, -1); // red

			colorStep++;
			if (colorStep > MaxBrightness) {
				colorStep = 0;
				anim_mode++;
				CurrDelay = DelayColor;
			}
			break;


		case 6: // RED
			if (CurrDelay != DelayAnim) { CurrDelay = DelayAnim; }

			/*if (IsUseCRT) { analogWrite(B1_Pin, getBrightCRT(MaxBrightness - colorStep)); }
			else { analogWrite(B1_Pin, MaxBrightness - colorStep); }*/
			_SetColor(-1, -1, (MaxBrightness - colorStep)); // red

			colorStep++;
			if (colorStep > MaxBrightness) {
				colorStep = 0;
				anim_mode = 0; // Restart animation
				//CurrDelay = DelayColor;
			}
			break;

		}


	}
}

void DIKTORRGB::StopFullAnimation()
{
	CurrDelay = 0;
	last_millis = 0;
	anim_mode = 0;
	colorStep = 0;
	anim_num = 0;
	DisableAll();
}







//-----FADE---(3)
void DIKTORRGB::InitFadeAnimation(int _DelayAnim, int _DelayColor)
{
	StopAnimation();
	//last_millis = millis();
	last_millis = 0;
	DelayAnim = _DelayAnim;
	DelayColor = _DelayColor;
	CurrDelay = DelayColor;
	anim_num = 3;
	startM2 = false;
}



void DIKTORRGB::OnFadeAnimation()
{
	unsigned long currentMillis = millis();
	if (currentMillis - last_millis >= CurrDelay)
	{
		last_millis = currentMillis;
		switch (anim_mode)
		{
		case 0: // BLUE
			if (CurrDelay != DelayAnim) { CurrDelay = DelayAnim; }

			/*if (IsUseCRT) { analogWrite(R1_Pin, getBrightCRT(colorStep)); analogWrite(G1_Pin, getBrightCRT(MaxBrightness - colorStep)); }
			else { analogWrite(R1_Pin, colorStep); analogWrite(G1_Pin, MaxBrightness - colorStep); }
			analogWrite(B1_Pin, MaxBrightness);*/
			_SetColor(colorStep, (MaxBrightness - colorStep), MaxBrightness);

			if (!startM2) { startM2 = true; CurrDelay = DelayColor; } // залокать первый цвет
			colorStep++;
			if (colorStep > MaxBrightness)
			{
				colorStep = 0;
				++anim_mode;
				CurrDelay = DelayColor;
			}
			break;

		case 1: // PURPLE
			if (CurrDelay != DelayAnim) { CurrDelay = DelayAnim; }
			/*if (IsUseCRT) { analogWrite(G1_Pin, getBrightCRT(colorStep)); analogWrite(B1_Pin, getBrightCRT(MaxBrightness - colorStep)); }
			else { analogWrite(G1_Pin, colorStep); analogWrite(B1_Pin, MaxBrightness - colorStep); }
			analogWrite(R1_Pin, MaxBrightness);*/
			_SetColor(MaxBrightness, colorStep, (MaxBrightness - colorStep));

			colorStep++;
			if (colorStep > MaxBrightness)
			{
				colorStep = 0;
				++anim_mode;
				CurrDelay = DelayColor;
			}
			break;

		case 2: // YELLOW
			if (CurrDelay != DelayAnim) { CurrDelay = DelayAnim; }
			/*if (IsUseCRT) { analogWrite(B1_Pin, getBrightCRT(colorStep)); analogWrite(R1_Pin, getBrightCRT(MaxBrightness - colorStep)); }
			else { analogWrite(B1_Pin, colorStep); analogWrite(R1_Pin, MaxBrightness - colorStep); }
			analogWrite(G1_Pin, MaxBrightness);*/
			_SetColor((MaxBrightness - colorStep), MaxBrightness, colorStep);

			colorStep++;
			if (colorStep > MaxBrightness)
			{
				colorStep = 0;
				anim_mode = 0;
				CurrDelay = DelayColor;
			}
			break;
		}
	}
}

void DIKTORRGB::StopFadeAnimation()
{
	CurrDelay = 0;
	last_millis = 0;
	anim_mode = 0;
	colorStep = 0;
	anim_num = 0;
	startM2 = false;
	DisableAll();
}






//-----Color_SMOOTH---(6-7)
void DIKTORRGB::InitSmoothAnimation(bool all_colors_mode, int _DelayAnim, int _DelayColor, bool random_color)
{
	StopAnimation();
	//last_millis = millis();
	last_millis = 0;
	DelayAnim = _DelayAnim;
	DelayColor = _DelayColor;
	CurrDelay = DelayAnim; //!! // _DelayColor
	last_color_M56 = 0;
	color_counter_M56 = 0;
	ch_color_M56 = true; // по дефолту цвет 0 для генерации
	side_M56 = false;
	anim_num = all_colors_mode ? 6 : 7; // 6 seven, 7 three
	rand_colorM56 = random_color;
}
void DIKTORRGB::OnSmoothAnimation()
{
	unsigned long currentMillis = millis();
	if (currentMillis - last_millis >= CurrDelay)
	{
		last_millis = currentMillis;

		if (CurrDelay != DelayAnim) { CurrDelay = DelayAnim; }
		bool all_colors_mode = (anim_num == 6); // 6 seven, 7 three
		int last_color_num_by_mode = all_colors_mode ? 7 : 3;
		// rand_colorM56

		int _clr = 0;
		if (ch_color_M56)
		{
			//IsUseCRT = !IsUseCRT; // crt test
			//Serial.println(IsUseCRT);
			if (rand_colorM56) { while (true) { _clr = _RandVKL(1, last_color_num_by_mode, false); if (_clr != last_color_M56) { last_color_M56 = _clr; break; } } } // рандомный цвет
			else { ++color_counter_M56; if (color_counter_M56 > last_color_num_by_mode) { color_counter_M56 = 1; } _clr = color_counter_M56; last_color_M56 = _clr; }
			ch_color_M56 = false;
		}
		else { _clr = last_color_M56; }

		/*int _clr = 0; // баг на каждом fps новый цвет, еффект прикольный
		if (rand_colorM56) { while (true) { _clr = _RandVKL(1, last_color_num_by_mode, false); if (_clr != last_color_M56) { last_color_M56 = _clr; break; } } } // рандомный цвет
		else { ++color_counter_M56; if (color_counter_M56 > last_color_num_by_mode) { color_counter_M56 = 1; } _clr = color_counter_M56; }*/

		SetColorByNumPWM(_clr, colorStep);

		if (side_M56) { --colorStep; }
		else { ++colorStep; }

		if (colorStep > 255) { colorStep = 255; side_M56 = !side_M56; CurrDelay = DelayColor; }
		else if (colorStep < 0) { colorStep = 0; side_M56 = !side_M56; ch_color_M56 = true; }

		//Serial.println(colorStep);
		//SetColorByNum(_clr);
	}
}
void DIKTORRGB::StopSmoothAnimation()
{
	CurrDelay = 0;
	last_millis = 0;
	anim_mode = 0;
	colorStep = 0;
	side_M56 = false;
	anim_num = 0;
	last_color_M56 = 0;
	ch_color_M56 = false;
	color_counter_M56 = 0;
	rand_colorM56 = false;
	DisableAll();
}





//-----RC---(8)
void DIKTORRGB::InitRCAnimation(int _DelayColor)
{
	StopAnimation();
	//last_millis = millis();
	last_millis = 0;
	DelayAnim = 0; // not use
	DelayColor = _DelayColor;
	CurrDelay = DelayColor;
	anim_num = 8;
	last_colorM8 = 0;
}



void DIKTORRGB::OnRCAnimation()
{
	unsigned long currentMillis = millis();
	if (currentMillis - last_millis >= CurrDelay)
	{
		last_millis = currentMillis;
		int _clr = 0;
		while (true) { _clr = _RandVKL(1, 7, false); if (_clr != last_colorM8) { break; } }
		//Serial.println("OnRC!");
		last_colorM8 = _clr;
		SetColorByNum(_clr);
	}
}

void DIKTORRGB::StopRCAnimation()
{
	CurrDelay = 0;
	last_millis = 0;
	anim_mode = 0;
	colorStep = 0;
	anim_num = 0;
	last_colorM8 = 0;
	DisableAll();
}