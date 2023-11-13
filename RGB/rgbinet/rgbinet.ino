/*

Adafruit Arduino - RGB светодиод подробная инструкция на сайте:

arduino-diy.com

*/

int redPin = 11;

int greenPin = 10;

int bluePin = 9;

//уберите тег комментария со строки ниже, если вы используете светодиод с общим анодом

//#define COMMON_ANODE

void setup()

{

pinMode(redPin, OUTPUT);

pinMode(greenPin, OUTPUT);

pinMode(bluePin, OUTPUT);

}

void loop()

{

setColor(255, 0, 0); // красный

delay(1000);

setColor(0, 255, 0); // зеленый

delay(1000);

setColor(0, 0, 255); // синий

delay(1000);

setColor(255, 255, 0); // желтый

delay(1000);

setColor(80, 0, 80); // фиолетовый

delay(1000);

setColor(0, 255, 255); // аквамарин

delay(1000);

}

void setColor(int red, int green, int blue)

{

#ifdef COMMON_ANODE

red = 255 - red;

green = 255 - green;

blue = 255 - blue;

#endif

analogWrite(redPin, red);

analogWrite(greenPin, green);

analogWrite(bluePin, blue);

}

Попробуйте запустить этот скетч. Особенности скетча раскрыты ниже…

Скетч начинается с указания пинов, которые используются для каждого отдельного цвета:

int redPin = 11;

int greenPin = 10;

int bluePin = 9;

Следующий шаг – функция 'setup'. Эта функция отрабатывает один раз после запуска Arduino. В нашей программе в пределах этой функции мы инициализируем три пина, которые мы будем использовать в качестве выходов.

void setup()

{

pinMode(redPin, OUTPUT);

pinMode(greenPin, OUTPUT);

pinMode(bluePin, OUTPUT);

}

Перед тем как рассмотреть функцию 'loop', давайте рассмотрим последнюю функцию в скетче.

void setColor(int red, int green, int blue)

{

analogWrite(redPin, red);

analogWrite(greenPin, green);

analogWrite(bluePin, blue);

}
