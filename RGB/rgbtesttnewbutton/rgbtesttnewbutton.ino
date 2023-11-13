int red; // переменная для хранения R-составляющей цвета
int green; // переменная для хранения G-составляющей цвета
int blue; // переменная для хранения B-составляющей цвета
int brightness = 0;    // уставливаем начально значение яркости
int fadeAmount = 3;    // шаг приращения/убывания яркости
int flag = 0;                  // флаг состояния
int flag1 = 0;
int regim = 0;                 // Переключалка


//КАНАЛ 2,4 = РГБ 3,5,6 ; КАНАЛ 7,8 = РГБ 9,10,11

//КАНАЛЫ
int V = 4; //ВИЛКА
int D = 2; //ДНО

int N = 7; //НИЗ
int S = 8; //СТОЙКА

//ЦВЕТА
//РГБ ДЛЯ 2 , 4
int VDR = 5;
int VDG = 3;
int VDB = 6;

 //РГБ ДЛЯ 7 , 8
 
int NSR = 10;
int NSG = 9;
int NSB = 11;


void setup() {
  Serial.begin(9600);
 pinMode(LED_BUILTIN, OUTPUT);
  
  //КАНАЛЫ
  pinMode(V, OUTPUT); //ВИЛКА
  pinMode(D, OUTPUT); //ДНО
  
  pinMode(N, OUTPUT); //НИЗ
  pinMode(S, OUTPUT); //СТОЙКА

//ЦВЕТА
//РГБ ДЛЯ 2 , 4
  pinMode(VDR, OUTPUT);
  pinMode(VDG, OUTPUT);
  pinMode(VDB, OUTPUT);

 //РГБ ДЛЯ 7 , 8
  pinMode(NSR, OUTPUT);
  pinMode(NSG, OUTPUT);
  pinMode(NSB, OUTPUT);

  digitalWrite(V, HIGH);//ВКЛ*****
  digitalWrite(D, HIGH);
  digitalWrite(N, HIGH);
  digitalWrite(S, HIGH);
  digitalWrite(VDR, HIGH);
  digitalWrite(NSR, HIGH);   
  delay(500);                      
  digitalWrite(VDR, LOW); 
  digitalWrite(NSR, LOW);   
   
                      
}
void press(){//**********************************ККККННННОООППКККА/////////////
  if(digitalRead(13) == HIGH && flag == 0)      
    {   Serial.println("NEXT");
   
      digitalWrite(VDR, LOW); 
      digitalWrite(VDG, LOW); 
      digitalWrite(VDB, LOW); 
      digitalWrite(NSR, LOW); 
      digitalWrite(NSG, LOW); 
      digitalWrite(NSB, LOW);
      digitalWrite(V, LOW);
      digitalWrite(D, LOW); 
      digitalWrite(N, LOW); 
      digitalWrite(S, LOW);                                          
      regim ++;
      flag = 1;
      
      if(regim > 24)                     // Если номер режима превышает требуемого
        {                               // то отсчет начинается с нуля
          regim = 0;
          
        }
        digitalWrite(LED_BUILTIN, HIGH);  
      delay(50);
      digitalWrite(LED_BUILTIN, LOW);
    }
  
  if(digitalRead(13) == LOW && flag == 1)
    {
      flag = 0;
    }
    if(digitalRead(12) == HIGH && flag1 == 0)      
    {
      Serial.println("BACK");
     
      digitalWrite(VDR, LOW); 
      digitalWrite(VDG, LOW); 
      digitalWrite(VDB, LOW); 
      digitalWrite(NSR, LOW); 
      digitalWrite(NSG, LOW); 
      digitalWrite(NSB, LOW);
      digitalWrite(V, LOW);
      digitalWrite(D, LOW); 
      digitalWrite(N, LOW); 
      digitalWrite(S, LOW);                                          
      regim --;
     flag1 = 1;
      
      if(regim < 0)                     
        {                              
          regim = 24;
         
        }
          digitalWrite(LED_BUILTIN, HIGH);
      delay(50);
      digitalWrite(LED_BUILTIN, LOW);
    }
  
  if(digitalRead(12) == LOW && flag1 == 1)
    {
      flag1 = 0;
    }}
void setRGB(int r,int g,int b)
 {
 analogWrite(VDR,r);
 analogWrite(VDG,g);
 analogWrite(VDB,b);
 analogWrite(NSR,r);
 analogWrite(NSG,g);
 analogWrite(NSB,b);
 delay(2);
 press();
 }

void loop() {
  press();             // обязательная функция отработки. Должна постоянно опрашиваться
 
  // всё переключение в итоге сводится к оператору switch
  switch (regim) {
    case 0: task_0();
      break;
    case 1: task_1();
      break;
    case 2: task_2();
      break;
    case 3: task_3();
      break;
    case 4: task_4();
      break;
      case 5: task_5();
      break;
      case 6: task_6();
      break;
      case 7: task_7();
      break;
      case 8: task_8();
      break;
      case 9: task_9();
      break;
      case 10: task_10();
      break;
      case 11: task_11();
      break;
      case 12: task_12();
      break;
      case 13: task_13();
      break;
      case 14: task_14();
      break;
      case 15: task_15();
      break;
      case 16: task_16();
      break;
      case 17: task_17();
      break;
      case 18: task_18();
      break;
      case 19: task_19();
      break;
      case 20: task_20();
      break;
      case 21: task_21();
      break;
      case 22: task_22();
      break;
      case 23: task_23();
      break;
      case 24: task_24();
      break;
  }
}
// наши задачи, внутри функций понятное дело может быть всё что угодно
void task_0() {
  Serial.println("Regim 0");
   digitalWrite(VDR, LOW); 
      digitalWrite(VDG, LOW); 
      digitalWrite(VDB, LOW); 
      digitalWrite(NSR, LOW); 
      digitalWrite(NSG, LOW); 
      digitalWrite(NSB, LOW);
      digitalWrite(V, LOW);
      digitalWrite(D, LOW); 
      digitalWrite(N, LOW); 
      digitalWrite(S, LOW);
       press();
}//0000000000000000




void task_1() {
  Serial.println("Regim 1");
   digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); 
      digitalWrite(S, HIGH);
      digitalWrite(VDR, HIGH); 
      digitalWrite(NSR, HIGH); 
       press();
}//11111111111111




void task_2() {
  Serial.println("Regim 2");
  digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); 
      digitalWrite(S, HIGH);
      digitalWrite(VDR, HIGH); 
      digitalWrite(NSR, HIGH); 
      digitalWrite(VDG, HIGH); 
      digitalWrite(NSG, HIGH); 
       press();
}//22222222222222




void task_3() {
  Serial.println("Regim 3");
   digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); 
      digitalWrite(S, HIGH);
      digitalWrite(VDG, HIGH); 
      digitalWrite(NSG, HIGH); 
       press();
}//333333333




void task_4() {
  Serial.println("Regim 4");
   digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); 
      digitalWrite(S, HIGH);
      digitalWrite(VDG, HIGH); 
      digitalWrite(NSG, HIGH); 
      digitalWrite(VDB, HIGH); 
      digitalWrite(NSB, HIGH); 
       press();
  }//4444444444


  
void task_5() {
  Serial.println("Regim 5");
   digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); 
      digitalWrite(S, HIGH);
      digitalWrite(VDB, HIGH); 
      digitalWrite(NSB, HIGH); 
       press();
}//5555555555



void task_6() {
  Serial.println("Regim 6");
   digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); 
      digitalWrite(S, HIGH);
      digitalWrite(VDB, HIGH); 
      digitalWrite(NSB, HIGH); 
      digitalWrite(VDR, HIGH); 
      digitalWrite(NSR, HIGH); 
       press();
}//6666666666




void task_7() {
  Serial.println("Regim 7");
  digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); 
      digitalWrite(S, HIGH);
      digitalWrite(VDB, HIGH); 
      digitalWrite(NSB, HIGH); 
      digitalWrite(VDG, HIGH); 
      digitalWrite(NSG, HIGH);
      digitalWrite(VDR, HIGH);
      digitalWrite(NSR, HIGH);
       press();
}//7777777



void task_8() {
  Serial.println("Regim 8");
   digitalWrite(V, HIGH); //2
      digitalWrite(D, HIGH);
      digitalWrite(N, HIGH);
      digitalWrite(S, HIGH);
      press();
      digitalWrite(VDB, HIGH);
      digitalWrite(NSB, HIGH);
      delay(100);
      press();
      digitalWrite(VDB, LOW);
      digitalWrite(NSB, LOW);
      delay(100);
      press();
      digitalWrite(VDB, HIGH);
      digitalWrite(NSB, HIGH);
      delay(100);
      press();
      digitalWrite(VDB, LOW);
      digitalWrite(NSB, LOW);
      delay(100);
      press();
      digitalWrite(VDB, HIGH);
      digitalWrite(NSB, HIGH);
      delay(100);
      press();
      digitalWrite(VDB, LOW);
      digitalWrite(NSB, LOW);
      delay(100);

       press();
      
      digitalWrite(VDR, HIGH);
      digitalWrite(NSR, HIGH);
      delay(100);
      press();
      digitalWrite(VDR, LOW);
      digitalWrite(NSR, LOW);
      delay(100);
      press();
      digitalWrite(VDR, HIGH);
      digitalWrite(NSR, HIGH);
      delay(100);
      press();
      digitalWrite(VDR, LOW);
      digitalWrite(NSR, LOW);
      delay(100);
      press();
      digitalWrite(VDR, HIGH);
      digitalWrite(NSR, HIGH);
      delay(100);
      press();
      digitalWrite(VDR, LOW);
      digitalWrite(NSR, LOW);
      delay(100);
        press();
}//8888888888



void task_9() {
  Serial.println("Regim 9");
    digitalWrite(VDR, HIGH);//RED
      digitalWrite(NSR, HIGH);
      digitalWrite(V, HIGH);
      delay(50);
      press();
      digitalWrite(V, LOW);
      digitalWrite(D, HIGH);
      delay(50);
      press();
      digitalWrite(D, LOW);
      digitalWrite(N, HIGH);
      delay(50);
      press();
      digitalWrite(N, LOW);
      digitalWrite(S, HIGH);
      delay(50);
      press();
      digitalWrite(S, LOW);
      press();//NORED
      digitalWrite(VDR, LOW);//RED
      digitalWrite(NSR, LOW);
      digitalWrite(VDG, HIGH);//GREEN
      digitalWrite(NSG, HIGH);
      digitalWrite(V, HIGH);
      delay(50);
      press();
      digitalWrite(V, LOW);
      digitalWrite(D, HIGH);
      delay(50);
      press();
      digitalWrite(D, LOW);
      digitalWrite(N, HIGH);
      delay(50);
      press();
      digitalWrite(N, LOW);
      digitalWrite(S, HIGH);
      delay(50);
      press();
      digitalWrite(S, LOW);
      press();//NOGREEN
      digitalWrite(VDG, LOW);//GREEN0
      digitalWrite(NSG, LOW);
      digitalWrite(VDB, HIGH);//BLUE
      digitalWrite(NSB, HIGH);
      digitalWrite(V, HIGH);
      delay(50);
      press();
      digitalWrite(V, LOW);
      digitalWrite(D, HIGH);
      delay(50);
      press();
      digitalWrite(D, LOW);
      digitalWrite(N, HIGH);
      delay(50);
      press();
      digitalWrite(N, LOW);
      digitalWrite(S, HIGH);
      delay(50);
      press();
      digitalWrite(S, LOW);
      press();//NOBLUE
      digitalWrite(VDR, HIGH);//RB
      digitalWrite(NSR, HIGH);
      digitalWrite(V, HIGH);
      delay(50);
      press();
      digitalWrite(V, LOW);
      digitalWrite(D, HIGH);
      delay(50);
      press();
      digitalWrite(D, LOW);
      digitalWrite(N, HIGH);
      delay(50);
      press();
      digitalWrite(N, LOW);
      digitalWrite(S, HIGH);
      delay(50);
      digitalWrite(S, LOW);
      press();
      digitalWrite(VDR, LOW); 
      digitalWrite(VDG, LOW); 
      digitalWrite(VDB, LOW); 
      digitalWrite(NSR, LOW); 
      digitalWrite(NSG, LOW); 
      digitalWrite(NSB, LOW);//NORB
      press();
}//999999999999



void task_10() {
  Serial.println("Regim 10");
   digitalWrite(VDR, HIGH);
      digitalWrite(NSR, HIGH);
      digitalWrite(V, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(N, HIGH);
      digitalWrite(S, HIGH);
      delay(100);
      press();
      digitalWrite(V, LOW);
      digitalWrite(D, LOW);
      digitalWrite(N, LOW);
      digitalWrite(S, LOW);
      delay(100);
      press();
      digitalWrite(V, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(N, HIGH);
      digitalWrite(S, HIGH);
      delay(100);
      press();
      digitalWrite(V, LOW);
      digitalWrite(D, LOW);
      digitalWrite(N, LOW);
      digitalWrite(S, LOW);
      digitalWrite(VDR, LOW);
      digitalWrite(NSR, LOW);
       delay(100);  
       press();

     digitalWrite(VDG, HIGH);
      digitalWrite(NSG, HIGH);
      digitalWrite(V, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(N, HIGH);
      digitalWrite(S, HIGH);
      delay(100);
      press();
      digitalWrite(V, LOW);
      digitalWrite(D, LOW);
      digitalWrite(N, LOW);
      digitalWrite(S, LOW);
      delay(100);
      press();
      digitalWrite(V, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(N, HIGH);
      digitalWrite(S, HIGH);
      delay(100);
      press();
      digitalWrite(V, LOW);
      digitalWrite(D, LOW);
      digitalWrite(N, LOW);
      digitalWrite(S, LOW);
      digitalWrite(VDG, LOW);
      digitalWrite(NSG, LOW);
       delay(100);  
       press();
       digitalWrite(VDB, HIGH);
      digitalWrite(NSB, HIGH);
      digitalWrite(V, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(N, HIGH);
      digitalWrite(S, HIGH);
      delay(100);
      press();
      digitalWrite(V, LOW);
      digitalWrite(D, LOW);
      digitalWrite(N, LOW);
      digitalWrite(S, LOW);
      delay(100);
      press();
      digitalWrite(V, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(N, HIGH);
      digitalWrite(S, HIGH);
      delay(100);
      press();
      digitalWrite(V, LOW);
      digitalWrite(D, LOW);
      digitalWrite(N, LOW);
      digitalWrite(S, LOW);
      
       delay(100);  
       press();
       digitalWrite(VDR, HIGH);
      digitalWrite(NSR, HIGH);
      digitalWrite(V, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(N, HIGH);
      digitalWrite(S, HIGH);
      delay(100);
      press();
      digitalWrite(V, LOW);
      digitalWrite(D, LOW);
      digitalWrite(N, LOW);
      digitalWrite(S, LOW);
      delay(100);
      press();
      digitalWrite(V, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(N, HIGH);
      digitalWrite(S, HIGH);
      delay(100);
      press();
      digitalWrite(V, LOW);
      digitalWrite(D, LOW);
      digitalWrite(N, LOW);
      digitalWrite(S, LOW);
      digitalWrite(VDR, LOW);
      digitalWrite(NSR, LOW);
      digitalWrite(VDB, LOW);
      digitalWrite(NSB, LOW);
       delay(100);  
       press();
}//1000100100000101010101010



void task_11() {
  Serial.println("Regim 11");
   digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); 
      digitalWrite(S, HIGH);
         press();

      // от красного к желтому
 Serial.println("red - yellow");
 red=255;green=0;blue=0;
 for(green=0;green<=255;green++) setRGB(red,green,blue);  
 press();
 // от желтому к зеленому 
 Serial.println("yellow - green");
 red=255;green=255;blue=0; 
 for(red=255;red>=0;red--)  setRGB(red,green,blue); 
 press();
 // от зеленого к голубому
 Serial.println("green - blue");
 red=0;green=255;blue=0;
 for(blue=0;blue<=255;blue++) setRGB(red,green,blue);   
 press();
 // от голубого к синему 
 Serial.println("blue - blue"); 
 red=0;green=255;blue=255; 
 for(green=255;green>=0;green--) setRGB(red,green,blue); 
 press();
 // от синего к фиолетовому
 Serial.println("blue - purple");
 red=0;green=0;blue=255;
 for(red=0;red<=255;red++) setRGB(red,green,blue);  
 press();
 // от фиолетового к красному
 Serial.println("purple - red");
 red=255;green=0;blue=255; 
 for(blue=255;blue>=0;blue--)  setRGB(red,green,blue); 
 press();
}//1111111111



void task_12() {
  Serial.println("Regim 12");
    digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); 
      digitalWrite(S, HIGH);
         press();

      // от красного к желтому
 Serial.println("red - yellow");
 red=255;green=0;blue=0;
 for(green=0;green<=255;green++) setRGB(red,green,blue);press();  delay(1000);
 press();
 // от желтому к зеленому 
 Serial.println("yellow - green");
 red=255;green=255;blue=0; 
 for(red=255;red>=0;red--)  setRGB(red,green,blue);press(); delay(1000);
 press();
 // от зеленого к голубому
 Serial.println("green - blue");
 red=0;green=255;blue=0;
 for(blue=0;blue<=255;blue++) setRGB(red,green,blue); press();  delay(1000);
 press();
 // от голубого к синему 
 Serial.println("blue - blue"); 
 red=0;green=255;blue=255; 
 for(green=255;green>=0;green--) setRGB(red,green,blue); press();delay(1000);
 press();
 // от синего к фиолетовому
 Serial.println("blue - purple");
 red=0;green=0;blue=255;
 for(red=0;red<=255;red++) setRGB(red,green,blue); press(); delay(1000);
 press();
 // от фиолетового к красному
 Serial.println("purple - red");
 red=255;green=0;blue=255; 
 for(blue=255;blue>=0;blue--)  setRGB(red,green,blue);press(); delay(1000);
 press();
}//1212121212



void task_13() {
  Serial.println("Regim 13");
   digitalWrite(VDR, LOW);
  digitalWrite(NSR, LOW);
    digitalWrite(VDG, HIGH);
    digitalWrite(NSG, HIGH);
    digitalWrite(V, HIGH);press();
       delay(300);
     digitalWrite(V, LOW); press();
     delay(100);
      digitalWrite(V, HIGH);press();
       delay(70);
     digitalWrite(V, LOW); press();
     delay(100);
     digitalWrite(V, HIGH);press();
       delay(50);
     digitalWrite(V, LOW); press();
     delay(200);
       digitalWrite(V, HIGH);press();
       delay(100);
     digitalWrite(V, LOW); press();
     delay(100);
     digitalWrite(V, HIGH);press();
     delay(500);
     

     digitalWrite(D, HIGH);press();
       delay(200);
     digitalWrite(D, LOW); press();
     delay(100);
      digitalWrite(D, HIGH);press();
       delay(70);
     digitalWrite(D, LOW); press();
     delay(100);
     digitalWrite(D, HIGH);press();
       delay(50);
     digitalWrite(D, LOW); press();
     delay(200);
       digitalWrite(D, HIGH);press();
       delay(100);
     digitalWrite(D, LOW); press();
     delay(100);
     digitalWrite(D, HIGH);press();
     delay(500);

     digitalWrite(N, HIGH);press();
     digitalWrite(S, HIGH);
       delay(100);
     digitalWrite(N, LOW); press();
     digitalWrite(S, LOW);
     delay(100);
      digitalWrite(N, HIGH);press();
      digitalWrite(S, HIGH);
       delay(70);
     digitalWrite(N, LOW); press();
     digitalWrite(S, LOW);
     delay(100);
     digitalWrite(N, HIGH);press();
     digitalWrite(S, HIGH);
       delay(50);
     digitalWrite(N, LOW); press();
     digitalWrite(S, LOW);
     delay(200);
       digitalWrite(N, HIGH);press();
       digitalWrite(S, HIGH);
       delay(100);
     digitalWrite(N, LOW); press();
     digitalWrite(S, LOW);
     delay(100);
     digitalWrite(N, HIGH);press();
     digitalWrite(S, HIGH);
     delay(2500);
     digitalWrite(V, LOW);press();
     digitalWrite(D, LOW);
     digitalWrite(N, LOW);
     digitalWrite(S, LOW);
     delay(300);
}//13131313131311313



void task_14() {
  Serial.println("Regim 14");
   digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); 
      digitalWrite(S, HIGH);
      digitalWrite(VDR, HIGH);
      digitalWrite(NSR, HIGH);
      delay(50);press();
      digitalWrite(VDR, LOW);
      digitalWrite(NSR, LOW);
      delay(65);
       press();
}//14141414141414141414




void task_15() {
  Serial.println("Regim 15");
  digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); 
      digitalWrite(S, HIGH);
      
       for(int i=0;i<=255;i++){
    analogWrite(VDR, i);
    analogWrite(NSR, i);
  press();
    delay(3);press();
  }
  
  //затухания светодиода
  for(int i=255;i>=0;i--){
    analogWrite(VDR, i);
    analogWrite(NSR, i);press();
    //Задержка для более плавного эффекта потухания
    delay(2);press(); }
 for(int i=0;i<=255;i++){
    analogWrite(VDG, i);
    analogWrite(NSG, i);
  press();
    delay(3);press();
  }
  
  //затухания светодиода
  for(int i=255;i>=0;i--){
    analogWrite(VDG, i);
    analogWrite(NSG, i);press();
    //Задержка для более плавного эффекта потухания
    delay(3);press(); }
    for(int i=0;i<=255;i++){
    analogWrite(VDB, i);
    analogWrite(NSB, i);
   press();
    delay(2);press();
  }
  
  //затухания светодиода
  for(int i=255;i>=0;i--){
    analogWrite(VDB, i);
    analogWrite(NSB, i);press();
    //Задержка для более плавного эффекта потухания
    delay(2);press();
 
  }
}//151515151515151515151




void task_16() {
  Serial.println("Regim 16");
   digitalWrite(VDR, HIGH);
      digitalWrite(NSR, HIGH);
      digitalWrite(V, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(N, HIGH);
      digitalWrite(S, HIGH);
      delay(100);
      press();
      digitalWrite(V, LOW);
      digitalWrite(D, LOW);
      digitalWrite(N, LOW);
      digitalWrite(S, LOW);
      
      press();
      
      digitalWrite(VDR, LOW);
      digitalWrite(NSR, LOW);
       delay(100);  
       press();

     digitalWrite(VDG, HIGH);
      digitalWrite(NSG, HIGH);
      digitalWrite(V, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(N, HIGH);
      digitalWrite(S, HIGH);
      delay(100);
      press();
      digitalWrite(V, LOW);
      digitalWrite(D, LOW);
      digitalWrite(N, LOW);
      digitalWrite(S, LOW);
      
      press();
      
      digitalWrite(VDG, LOW);
      digitalWrite(NSG, LOW);
       delay(100);  
       press();
       digitalWrite(VDB, HIGH);
      digitalWrite(NSB, HIGH);
      digitalWrite(V, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(N, HIGH);
      digitalWrite(S, HIGH);
      delay(100);
      press();
      digitalWrite(V, LOW);
      digitalWrite(D, LOW);
      digitalWrite(N, LOW);
      digitalWrite(S, LOW);
      
      press();
      
      digitalWrite(VDB, LOW);
      digitalWrite(NSB, LOW);
       delay(100);  
       press();
}//16161616161616161616161




void task_17() {
  Serial.println("Regim 17");
  digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH);
      digitalWrite(S, HIGH);
      press();
      digitalWrite(VDR, HIGH);
      digitalWrite(NSR, HIGH);press();
press();
 
  //затухания светодиода
  for(int i=255;i>=0;i--){ 
  press();
    analogWrite(VDR, i);
    analogWrite(NSR, i);press();

    //Задержка для более плавного эффекта потухания
    delay(1);press();
  }
}//417171717171717171717171




void task_18() {
  Serial.println("Regim 18");
     
      digitalWrite(VDR, HIGH);
      digitalWrite(NSG, HIGH); press();
      digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); press();
      digitalWrite(S, HIGH);
 press();

      
}//181818181818181818181



void task_19() {
  Serial.println("Regim 19");
   digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); press();
      digitalWrite(S, HIGH);
 press();
      
      digitalWrite(VDR, HIGH);
      digitalWrite(NSG, HIGH); 
      press();delay(50);
      
       digitalWrite(VDR, LOW);
       digitalWrite(NSG, LOW);
       digitalWrite(VDG, HIGH);
       digitalWrite(NSR, HIGH);
        press();delay(50);
}//1919191919191919191




void task_20() {
  Serial.println("Regim 20");
  
       digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); press();
      digitalWrite(S, HIGH);
 press();
      
      digitalWrite(VDR, HIGH);
      digitalWrite(NSG, HIGH); 
      press();delay(200);
      
       digitalWrite(VDR, LOW);
       digitalWrite(NSG, LOW); 
       
       digitalWrite(VDG, HIGH);
       digitalWrite(NSR, HIGH);
        press();delay(200);
        digitalWrite(VDG, LOW);
       digitalWrite(NSR, LOW); 
}//2020202020202020




void task_21() {
  Serial.println("Regim 21");
   digitalWrite(V, HIGH);
     digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH);
       digitalWrite(S, HIGH); 
       
       digitalWrite(VDR, HIGH);  
       digitalWrite(NSR, HIGH); 
       delay(200); press();
       digitalWrite(VDR, LOW); 
       digitalWrite(NSR, LOW); 
        digitalWrite(VDG, HIGH);  
       digitalWrite(NSG, HIGH); 
       delay(200); press();
       digitalWrite(VDG, LOW); 
       digitalWrite(NSG, LOW); 
        digitalWrite(VDB, HIGH);  
       digitalWrite(NSB, HIGH); 
        delay(200); press();
     
       digitalWrite(VDB, LOW); 
       digitalWrite(NSB, LOW); 


       
      press();
}//212121212121212112




void task_22() {
  Serial.println("Regim 22");
    digitalWrite(V, HIGH);press();
     digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH);
       digitalWrite(S, HIGH); 
      
       digitalWrite(VDR, HIGH);  press();
       digitalWrite(NSR, HIGH); 
       delay(800); press();
        digitalWrite(VDG, HIGH);  press();
       digitalWrite(NSG, HIGH); 
        delay(800); press();
       digitalWrite(VDR, LOW); press();
       digitalWrite(NSR, LOW); 
       delay(800); press();
       digitalWrite(VDB, HIGH);  
       digitalWrite(NSB, HIGH); 
       delay(800); press();
       digitalWrite(VDG, LOW); press();
       digitalWrite(NSG, LOW); 
       delay(800); press();
        digitalWrite(VDR, HIGH);  
       digitalWrite(NSR, HIGH); 
        delay(800); press();
       digitalWrite(VDB, LOW); 
       digitalWrite(NSB, LOW); 


       
      press();
}//222222222222



void task_23() {
  Serial.println("Regim 23");
   digitalWrite(VDR, LOW); press();
       digitalWrite(NSR, LOW); press();
      digitalWrite(VDB, HIGH);
      digitalWrite(NSB, HIGH); press();
      
       digitalWrite(V, HIGH);  press();
       digitalWrite(D, HIGH); press();
       delay(75); press();
      digitalWrite(V, LOW); press();
       digitalWrite(D, LOW); press();
       delay(75); press();
 digitalWrite(V, HIGH);  press();
       digitalWrite(D, HIGH); press();
       delay(75); press();
      digitalWrite(V, LOW); press();
       digitalWrite(D, LOW); press();
       delay(75); press();
        digitalWrite(V, HIGH);  press();
       digitalWrite(D, HIGH); press();
       delay(75); press();
      digitalWrite(V, LOW); press();
       digitalWrite(D, LOW); press();
       delay(75); press();

        digitalWrite(N, HIGH);  press();
       digitalWrite(S, HIGH); press();
       delay(75); press();
      digitalWrite(N, LOW); press();
       digitalWrite(S, LOW); press();
       delay(75); press();
        digitalWrite(N, HIGH);  press();
       digitalWrite(S, HIGH); press();
       delay(75); press();
      digitalWrite(N, LOW); press();
       digitalWrite(S, LOW); press();
       delay(75); press();
        digitalWrite(N, HIGH);  press();
       digitalWrite(S, HIGH); press();
       delay(75); press();
      digitalWrite(N, LOW); press();
       digitalWrite(S, LOW); press();
       delay(75); press();


        digitalWrite(V, HIGH);  press();
       digitalWrite(D, HIGH); press();
        digitalWrite(N, HIGH);  press();
       digitalWrite(S, HIGH); press();
       delay(75); press();
      digitalWrite(V, LOW); press();
       digitalWrite(D, LOW); press();
        digitalWrite(N, LOW);  press();
       digitalWrite(S, LOW); press();
       delay(75); press();
        digitalWrite(V, HIGH);  press();
       digitalWrite(D, HIGH); press();
        digitalWrite(N, HIGH);  press();
       digitalWrite(S, HIGH); press();
       delay(75); press();
      digitalWrite(V, LOW); press();
       digitalWrite(D, LOW); press();
       digitalWrite(N, LOW);  press();
       digitalWrite(S, LOW); press();
       delay(75); press();
        digitalWrite(V, HIGH);  press();
       digitalWrite(D, HIGH); press();
        digitalWrite(N, HIGH);  press();
       digitalWrite(S, HIGH); press();
       delay(75); press();
      digitalWrite(V, LOW); press();
       digitalWrite(D, LOW); press();
       digitalWrite(N, LOW);  press();
       digitalWrite(S, LOW); press();
       delay(300); press();
       

       
      press();
}//232323232323232232323232323223




void task_24() {
  Serial.println("Regim 24");
   digitalWrite(V, LOW);
     digitalWrite(D, LOW); press();
      digitalWrite(N, LOW);
       digitalWrite(S, LOW); press();
      digitalWrite(VDR, HIGH); 
       digitalWrite(NSR, HIGH);
       
      digitalWrite(V, HIGH); press();
      delay(500); press();
      digitalWrite(D, HIGH);
      delay(500);press();
       digitalWrite(N, HIGH);press();
      delay(500); press();
      digitalWrite(S, HIGH);press();
      delay(500); press();
         digitalWrite(V, LOW);press();
     digitalWrite(D, LOW);press();
      digitalWrite(N, LOW);press();
       digitalWrite(S, LOW); press();
       digitalWrite(VDR, LOW); press();
       digitalWrite(NSR, LOW);  delay(300); press();
       digitalWrite(VDG, HIGH);  press();
       digitalWrite(NSG, HIGH); press();
         digitalWrite(V, HIGH);press();
      delay(500); press();
      digitalWrite(D, HIGH);press();
      delay(500); press();
       digitalWrite(N, HIGH);press();
      delay(500); press();
      digitalWrite(S, HIGH);press();
      delay(500);press();
         digitalWrite(V, LOW);
     digitalWrite(D, LOW);
      digitalWrite(N, LOW); press();
       digitalWrite(S, LOW);press();
       digitalWrite(VDG, LOW); press();
       digitalWrite(NSG, LOW); delay(300);press();
digitalWrite(VDB, HIGH); press();
       digitalWrite(NSB, HIGH); press();
         digitalWrite(V, HIGH); press();
      delay(500);press();
      digitalWrite(D, HIGH);press();
      delay(500); press();
       digitalWrite(N, HIGH);press();
      delay(500);press();
      digitalWrite(S, HIGH); press();
      delay(500);press();
         digitalWrite(V, LOW);press();
     digitalWrite(D, LOW);press();
      digitalWrite(N, LOW); press();
       digitalWrite(S, LOW);press();
       digitalWrite(VDB, LOW);  press();
       digitalWrite(NSB, LOW); delay(300); press();
}//24242424242424224422424
