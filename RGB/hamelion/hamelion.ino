/*
    Использование RGB светодиода, эффект хамелеона
 */
// Для управления цветом светодиода используем 3 ШИМ порта
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
 
void setup(){
  // Инициализируем выходы для нашего RGB светодиода
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
 
void loop(){  
  // Вызываем функцию установки цвета и в качестве параметров передаем номер пина. 
  // Используем вызов 3 раза со сменой пинов, для перетекания из одного цвета в другой.
  setFadeColor(redPin,greenPin,bluePin);
  setFadeColor(greenPin,bluePin,redPin);
  setFadeColor(bluePin,redPin,greenPin);
}
 
// Функция, которая устанавливает для каждого пина(RGB канала) 
// свой алгоритм изменения цвета
void setFadeColor(int cPin1,int cPin2,int cPin3){
  for(int i=0;i<=255;i++){
    analogWrite(cPin1, i);
    analogWrite(cPin2, 255-i);
    analogWrite(cPin3, 255);
    delay(5);
  }
}
