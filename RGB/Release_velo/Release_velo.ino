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
      
      if(regim > 41)                     // Если номер режима превышает требуемого
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
          regim = 41;
         
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
 void setVD(int r,int g,int b)
 {
 analogWrite(VDR,r);
 analogWrite(VDG,g);
 analogWrite(VDB,b);
 delay(2);
 press();
 }
 void setNS(int r,int g,int b)
 {
 analogWrite(NSR,r);
 analogWrite(NSG,g);
 analogWrite(NSB,b);
 delay(2);
 press();
 }
 void setRGB1(int r,int g,int b)
 {
 analogWrite(VDR,r);
 analogWrite(VDG,g);
 analogWrite(VDB,b);

 analogWrite(NSR,r);
 analogWrite(NSG,g);
 analogWrite(NSB,b);
 delayMicroseconds(100);
 press();
 }
  void ANIM()
 {
  digitalWrite(VDR, HIGH); press();
  delay(120);
    digitalWrite(VDR, LOW); press();
  delay(120);
    digitalWrite(VDG, HIGH); press();
  delay(120);
    digitalWrite(VDG, LOW); press();
  delay(120);
    digitalWrite(VDB, HIGH); press();
  delay(120);
    digitalWrite(VDB, LOW); press();
  delay(120);
 }
 void setFadeColor(int cPin1,int cPin2,int cPin3){
  for(int i=0;i<=255;i++){
    analogWrite(cPin1, i);
    analogWrite(cPin2, 255-i);
    analogWrite(cPin3, 255);
    delay(5);
  }
}
void setFadeColor1(int cPin1,int cPin2,int cPin3){
  for(int i=0;i<=255;i++){
    analogWrite(cPin1, i);
    analogWrite(cPin2, 255-i);
    analogWrite(cPin3, 255);
    delay(2);
  }
}
void setFadeColor2(int cPin1,int cPin2,int cPin3){
  for(int i=0;i<=255;i++){
    analogWrite(cPin1, i);
    analogWrite(cPin2, 255-i);
    analogWrite(cPin3, 255);
    delay(1);
  }
}
void loop() {//LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
  Serial.println(regim);
  //**********************************************************************
  //ПРОСТО ЦВЕТА
   if(regim == 0){//ooooooooooofffffffffffff
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
    }
     if(regim == 1){
      digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); 
      digitalWrite(S, HIGH);
      digitalWrite(VDR, HIGH); 
      digitalWrite(NSR, HIGH); 
       press();
     }
     if(regim == 2){
      digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); 
      digitalWrite(S, HIGH);
      digitalWrite(VDR, HIGH); 
      digitalWrite(NSR, HIGH); 
      digitalWrite(VDG, HIGH); 
      digitalWrite(NSG, HIGH); 
       press();
     }
     if(regim == 3){
      digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); 
      digitalWrite(S, HIGH);
      digitalWrite(VDG, HIGH); 
      digitalWrite(NSG, HIGH); 
       press();
     }
     if(regim == 4){
      digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); 
      digitalWrite(S, HIGH);
      digitalWrite(VDG, HIGH); 
      digitalWrite(NSG, HIGH); 
      digitalWrite(VDB, HIGH); 
      digitalWrite(NSB, HIGH); 
       press();
     }
     if(regim == 5){
      digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); 
      digitalWrite(S, HIGH);
      digitalWrite(VDB, HIGH); 
      digitalWrite(NSB, HIGH); 
       press();
     }
     if(regim == 6){
      digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); 
      digitalWrite(S, HIGH);
      digitalWrite(VDB, HIGH); 
      digitalWrite(NSB, HIGH); 
      digitalWrite(VDR, HIGH); 
      digitalWrite(NSR, HIGH); 
       press();
     }
     if(regim == 7){
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
     }//*************************************************************
     //*********AAAAAANNNNNNNNIIIIIIIMMMMMMM**************
    if(regim == 8){//0000000000000000000000000000000***POLICE***0000000
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
        }
        if(regim == 9){  //*******************NOPARALEL
      
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
        }//****************************
       if(regim == 10)//44444444444444400000000000011111111177777777777******
    {
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

    }
      if(regim == 11){
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
 }
       if(regim == 12){
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
 }
 press();
 if(regim == 13){
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
        
 }
 
 if(regim == 14){
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
     }
 
  if(regim == 15)
    {digitalWrite(V, HIGH);
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
 
  }
 if(regim == 16)
    
  {   digitalWrite(VDR, HIGH);
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
    
    }
 
 if(regim == 17)
    {    
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
  }}
 if(regim == 18){ 

     
      
      digitalWrite(VDR, HIGH);
      digitalWrite(NSG, HIGH); press();
      digitalWrite(V, HIGH);
      digitalWrite(D, HIGH); 
      digitalWrite(N, HIGH); press();
      digitalWrite(S, HIGH);
 press();

      
 }

    if(regim == 19){ 

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
 }

 if(regim == 20){ 

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
 }
 if(regim == 21)
    {   digitalWrite(V, HIGH);
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
    }

if(regim == 22)
    {   digitalWrite(V, HIGH);press();
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
    }




if(regim == 23)//ppppooolllliiicccceeee
    {   
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
    }





 

 if(regim == 24)///ggggaaavvvvnnooo
    {   digitalWrite(V, LOW);
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
    }

 if(regim == 25)
    {   
      digitalWrite(V, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(N, HIGH);
  digitalWrite(S, HIGH);
         press();

      // от красного к желтому
 Serial.println("red - yellow");
 red=255;green=0;blue=0;
 for(green=0;green<=255;green++) setRGB1(red,green,blue);  
 press();
 // от желтому к зеленому 
 Serial.println("yellow - green");
 red=255;green=255;blue=0; 
 for(red=255;red>=0;red--)  setRGB1(red,green,blue); 
 press();
 // от зеленого к голубому
 Serial.println("green - blue");
 red=0;green=255;blue=0;
 for(blue=0;blue<=255;blue++) setRGB1(red,green,blue);   
 press();
 // от голубого к синему 
 Serial.println("blue - blue"); 
 red=0;green=255;blue=255; 
 for(green=255;green>=0;green--) setRGB1(red,green,blue); 
 press();
 // от синего к фиолетовому
 Serial.println("blue - purple");
 red=0;green=0;blue=255;
 for(red=0;red<=255;red++) setRGB1(red,green,blue);  
 press();
 // от фиолетового к красному
 Serial.println("purple - red");
 red=255;green=0;blue=255; 
 for(blue=255;blue>=0;blue--)  setRGB1(red,green,blue); 
       
      press();
    }
 if(regim == 26)
    {   
      digitalWrite(V, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(N, HIGH);
  digitalWrite(S, HIGH);
         press();



 
  digitalWrite(VDR, HIGH);
  digitalWrite(NSR, HIGH); press();
  delay(120);
  digitalWrite(VDR, LOW);
  digitalWrite(NSR, LOW); press();
  delay(120);
  digitalWrite(VDG, HIGH);
  digitalWrite(NSG, HIGH);
  delay(120);
  digitalWrite(VDG, LOW);
  digitalWrite(NSG, LOW); press();
  delay(120);
  digitalWrite(VDB, HIGH);
  digitalWrite(NSB, HIGH);
  delay(120);
  digitalWrite(VDB, LOW);
  digitalWrite(NSB, LOW); press();
  delay(120);

    digitalWrite(VDR, HIGH);
  digitalWrite(NSR, HIGH); press();
  delay(120);
  digitalWrite(VDR, LOW);
  digitalWrite(NSR, LOW);
  delay(120);
  digitalWrite(VDG, HIGH);
  digitalWrite(NSG, HIGH); press();
  delay(120);
  digitalWrite(VDG, LOW);
  digitalWrite(NSG, LOW);
  delay(120);
  digitalWrite(VDB, HIGH);
  digitalWrite(NSB, HIGH); press();
  delay(120);
  digitalWrite(VDB, LOW);
  digitalWrite(NSB, LOW); press();
  delay(120);

    digitalWrite(VDR, HIGH);
  digitalWrite(NSR, HIGH);
  delay(120);
  digitalWrite(VDR, LOW);
  digitalWrite(NSR, LOW); press();
  delay(120);
  digitalWrite(VDG, HIGH);
  digitalWrite(NSG, HIGH);
  delay(120);
  digitalWrite(VDG, LOW); press();
  digitalWrite(NSG, LOW);
  delay(120);
  digitalWrite(VDB, HIGH);
  digitalWrite(NSB, HIGH);
  delay(120);
  digitalWrite(VDB, LOW);
  digitalWrite(NSB, LOW); press();
  delay(120);

  


  digitalWrite(VDR, HIGH);
  digitalWrite(NSR, HIGH);
  digitalWrite(VDG, HIGH);
  digitalWrite(NSG, HIGH);
  delay(120);
  digitalWrite(VDR, LOW); press();
  digitalWrite(NSR, LOW);
  digitalWrite(VDG, LOW);
  digitalWrite(NSG, LOW);
  delay(120);
  digitalWrite(VDG, HIGH);
  digitalWrite(NSG, HIGH); press();
  digitalWrite(VDB, HIGH);
  digitalWrite(NSB, HIGH);
  delay(120);
  digitalWrite(VDG, LOW);
  digitalWrite(NSG, LOW);
   digitalWrite(VDB, LOW);
  digitalWrite(NSB, LOW);
  delay(120);
  digitalWrite(VDB, HIGH); press();
  digitalWrite(NSB, HIGH);
  digitalWrite(VDR, HIGH);
  digitalWrite(NSR, HIGH);
  delay(120);
  digitalWrite(VDB, LOW);
  digitalWrite(NSB, LOW);
  digitalWrite(VDR, LOW);
  digitalWrite(NSR, LOW);
  delay(120);
   digitalWrite(VDR, HIGH);
  digitalWrite(NSR, HIGH); press();
  digitalWrite(VDG, HIGH);
  digitalWrite(NSG, HIGH);
  delay(120);
  digitalWrite(VDR, LOW);
  digitalWrite(NSR, LOW);
  digitalWrite(VDG, LOW);
  digitalWrite(NSG, LOW);
  delay(120);
  digitalWrite(VDG, HIGH);
  digitalWrite(NSG, HIGH);
  digitalWrite(VDB, HIGH);
  digitalWrite(NSB, HIGH);
  delay(120);
  digitalWrite(VDG, LOW);
  digitalWrite(NSG, LOW); press();
   digitalWrite(VDB, LOW);
  digitalWrite(NSB, LOW);
  delay(120);
  digitalWrite(VDB, HIGH);
  digitalWrite(NSB, HIGH);
  digitalWrite(VDR, HIGH);
  digitalWrite(NSR, HIGH);
  delay(120);
  digitalWrite(VDB, LOW);
  digitalWrite(NSB, LOW);
  digitalWrite(VDR, LOW);
  digitalWrite(NSR, LOW);
  delay(120);



  
      press();
    }
  
 if(regim == 27)
    {   
      digitalWrite(V, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(N, HIGH);
  digitalWrite(S, HIGH);
         press();
 // от красного к желтому
 Serial.println("red - yellow");
 red=255;green=0;blue=0;
 for(green=0;green<=255;green++) setVD(red,green,blue);  
 press();
 // от желтому к зеленому 
 Serial.println("yellow - green");
 red=255;green=255;blue=0; 
 for(red=255;red>=0;red--)  setVD(red,green,blue); 
 press();
 // от зеленого к голубому
 Serial.println("green - blue");
 red=0;green=255;blue=0;
 for(blue=0;blue<=255;blue++) setVD(red,green,blue);   
 press();
 // от голубого к синему 
 Serial.println("blue - blue"); 
 red=0;green=255;blue=255; 
 for(green=255;green>=0;green--) setVD(red,green,blue); 
 press();
 // от синего к фиолетовому
 Serial.println("blue - purple");
 red=0;green=0;blue=255;
 for(red=0;red<=255;red++) setVD(red,green,blue);  
 press();
 // от фиолетового к красному
 Serial.println("purple - red");
 red=255;green=0;blue=255; 
 for(blue=255;blue>=0;blue--)  setVD(red,green,blue); ///////////////

  // от красного к желтому
 Serial.println("red - yellow");
 red=255;green=0;blue=0;
 for(green=0;green<=255;green++) setNS(red,green,blue);  
 press();
 // от желтому к зеленому 
 Serial.println("yellow - green");
 red=255;green=255;blue=0; 
 for(red=255;red>=0;red--)  setNS(red,green,blue); 
 press();
 // от зеленого к голубому
 Serial.println("green - blue");
 red=0;green=255;blue=0;
 for(blue=0;blue<=255;blue++) setNS(red,green,blue);   
 press();
 // от голубого к синему 
 Serial.println("blue - blue"); 
 red=0;green=255;blue=255; 
 for(green=255;green>=0;green--) setNS(red,green,blue); 
 press();
 // от синего к фиолетовому
 Serial.println("blue - purple");
 red=0;green=0;blue=255;
 for(red=0;red<=255;red++) setNS(red,green,blue);  
 press();
 // от фиолетового к красному
 Serial.println("purple - red");
 red=255;green=0;blue=255; 
 for(blue=255;blue>=0;blue--)  setNS(red,green,blue); 
  
      press();
    }
  if(regim == 28)
    {   
      digitalWrite(V, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(N, HIGH);
  digitalWrite(S, HIGH);
         press();

         digitalWrite(VDR, HIGH);
    digitalWrite(NSR, HIGH);
    delay(20);
     digitalWrite(VDR, LOW);
  digitalWrite(NSR, LOW);
   delay(20);
 press();
 digitalWrite(VDB, HIGH);
    digitalWrite(NSB, HIGH);
    delay(20);
     digitalWrite(VDB, LOW);
  digitalWrite(NSB, LOW);
   delay(20);
 
      press();
    }

if(regim == 29)
    {   
      digitalWrite(V, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(N, HIGH);
  digitalWrite(S, HIGH);
         press();

         digitalWrite(VDR, HIGH);
  
    delay(20);
     digitalWrite(VDR, LOW);
 
   delay(20);
 press();
 digitalWrite(VDB, HIGH);
   
    delay(20);
     digitalWrite(VDB, LOW);

   delay(20);
 
      press();



    digitalWrite(NSR, HIGH);
    delay(20);
    
  digitalWrite(NSR, LOW);
   delay(20);
 press();

    digitalWrite(NSG, HIGH);
    delay(20);
   
  digitalWrite(NSG, LOW);
   delay(20);
 
      press();

      
    }

if(regim == 30)
    {   
      digitalWrite(V, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(N, HIGH);
  digitalWrite(S, HIGH);
         press();


  for(int i=0;i<=255;i++){
    analogWrite(VDB, i);
     analogWrite(NSR, i);

    delay(1);
  }
  
  //затухания светодиода
  for(int i=255;i>=0;i--){
    analogWrite(VDB, i);
    analogWrite(NSR, i);
  
    delay(1);
 
      press();}

        for(int i=0;i<=255;i++){
    analogWrite(NSB, i);
     analogWrite(VDR, i);

    delay(1);
  }
  
  //затухания светодиода
  for(int i=255;i>=0;i--){
    analogWrite(NSB, i);
    analogWrite(VDR, i);
  
    delay(1);
 
      press();
    }
  }

if(regim == 31)
    {   
      digitalWrite(V, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(N, HIGH);
  digitalWrite(S, HIGH);
         press();


  for(int i=0;i<=255;i++){
    analogWrite(VDB, i);
     analogWrite(NSR, i);

    delay(1);
  }
  
  //затухания светодиода
  for(int i=255;i>=0;i--){
    analogWrite(VDB, i);
    analogWrite(NSR, i);
  
    delay(1);
 
      press();}

        for(int i=0;i<=255;i++){
    analogWrite(NSB, i);
     analogWrite(VDR, i);

    delay(1);
  }
  
  //затухания светодиода
  for(int i=255;i>=0;i--){
    analogWrite(NSB, i);
    analogWrite(VDR, i);
  
    delay(1);
  }
      press();
       for(int i=0;i<=255;i++){
    analogWrite(VDB, i);
     analogWrite(NSR, i);

    delay(1);
  }
  
  //затухания светодиода
  for(int i=255;i>=0;i--){
    analogWrite(VDB, i);
    analogWrite(NSR, i);
  
    delay(1);
 
      press();}

        for(int i=0;i<=255;i++){
    analogWrite(NSB, i);
     analogWrite(VDR, i);

    delay(1);
  }
  
  //затухания светодиода
  for(int i=255;i>=0;i--){
    analogWrite(NSB, i);
    analogWrite(VDR, i);
  
    delay(1);
  }
      press();
       for(int i=0;i<=255;i++){
    analogWrite(VDB, i);
     analogWrite(NSR, i);

    delay(1);
  }
  
  //затухания светодиода
  for(int i=255;i>=0;i--){
    analogWrite(VDB, i);
    analogWrite(NSR, i);
  
    delay(1);
 
      press();}

        for(int i=0;i<=255;i++){
    analogWrite(NSB, i);
     analogWrite(VDR, i);

    delay(1);
  }
  
  //затухания светодиода
  for(int i=255;i>=0;i--){
    analogWrite(NSB, i);
    analogWrite(VDR, i);
  
    delay(1);
 
      press();
    }
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


  
  }

if(regim == 32)
    {   
      digitalWrite(V, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(N, HIGH);
  digitalWrite(S, HIGH);
         press();

  digitalWrite(VDB, HIGH);
    digitalWrite(NSB, HIGH);
    delay(200);

  digitalWrite(VDB, LOW);
    digitalWrite(NSB, LOW);
delay(200);

    
       press();


  
  }
if(regim == 33)
    {   
      digitalWrite(V, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(N, HIGH);
  digitalWrite(S, HIGH);
         press();

  digitalWrite(VDB, HIGH);
    digitalWrite(NSB, HIGH);
    delay(50);

  digitalWrite(VDB, LOW);
    digitalWrite(NSB, LOW);
delay(50);

    
       press();


  
  }
if(regim == 34)
    {   
      digitalWrite(V, HIGH);
        digitalWrite(D, HIGH);
  digitalWrite(N, HIGH);
    digitalWrite(S, HIGH);press();
  
  digitalWrite(NSR, HIGH);
      delay(150);
      digitalWrite(NSR, LOW);
      delay(150); press();
      digitalWrite(VDB, HIGH);  
      delay(150);
      digitalWrite(VDB, LOW);
      delay(150);
      digitalWrite(VDR, HIGH);
      delay(150);
      digitalWrite(VDR, LOW);
      delay(150); press();
      digitalWrite(VDB, HIGH);
      delay(150);
      digitalWrite(VDB, LOW);
      delay(150);
      digitalWrite(NSG, HIGH);
      delay(150);
      digitalWrite(NSG, LOW);
      delay(150);
      digitalWrite(VDG, HIGH);
      delay(150);
      digitalWrite(VDG, LOW);
      delay(150);
         digitalWrite(VDG, HIGH);
      delay(150); press();
      digitalWrite(VDG, LOW);
      delay(150);
      digitalWrite(NSR, HIGH);
      delay(150);
      digitalWrite(NSR, LOW);
           digitalWrite(NSG, HIGH);
      delay(150);
      digitalWrite(NSG, LOW);
      delay(150);
           digitalWrite(VDR, HIGH);
      delay(150); press();
      digitalWrite(VDR, LOW);
       digitalWrite(VDG, HIGH);
      delay(150);
      digitalWrite(VDG, LOW);
      delay(150);
       press();


  
  }
  if(regim == 35)
    {   
      digitalWrite(VDR, HIGH);
  digitalWrite(NSG, HIGH); press();
  
  digitalWrite(S, HIGH);
      delay(150);
      digitalWrite(S, LOW);
      delay(150); press();
      digitalWrite(D, HIGH);
      delay(150);
      digitalWrite(D, LOW);
      delay(150);
      digitalWrite(V, HIGH);
      delay(150);
      digitalWrite(V, LOW);
      delay(150); press();
      digitalWrite(D, HIGH);
      delay(150);
      digitalWrite(D, LOW);
      delay(150);
      digitalWrite(S, HIGH);
      delay(150);
      digitalWrite(S, LOW);
      delay(150);
      digitalWrite(N, HIGH);
      delay(150);
      digitalWrite(N, LOW);
      delay(150);
         digitalWrite(D, HIGH);
      delay(150); press();
      digitalWrite(D, LOW);
      delay(150);
      digitalWrite(V, HIGH);
      delay(150);
      digitalWrite(V, LOW);
           digitalWrite(S, HIGH);
      delay(150);
      digitalWrite(S, LOW);
      delay(150);
           digitalWrite(D, HIGH);
      delay(150); press();
      digitalWrite(D, LOW);
       digitalWrite(S, HIGH);
      delay(150);
      digitalWrite(S, LOW);
      delay(150);
       press();


  
  }
if(regim == 36)
    {   digitalWrite(V, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(N, HIGH);
    digitalWrite(S, HIGH);

      
      digitalWrite(VDR, HIGH);
  digitalWrite(NSR, HIGH); press();
  
 
       press();
  for(int i=0;i<=255;i++){
    analogWrite(VDB, i);
     analogWrite(NSB, i);
  
   
    //Задержка для более плавного эффекта свечения
    delay(1);
  }
  
  //затухания светодиода
  for(int i=255;i>=0;i--){
    analogWrite(VDB, i);
    analogWrite(NSB, i);
  

    //Задержка для более плавного эффекта потухания
    delay(1);
  }
    }

  if(regim == 37)
    {     
        digitalWrite(NSG, LOW);
        digitalWrite(V, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(N, HIGH);press();
    digitalWrite(S, HIGH);
    
  digitalWrite(NSB, HIGH); press();
  ANIM();
 
       press();
  for(int i=0;i<=255;i++){

     analogWrite(NSR, i);
  
   press();
    //Задержка для более плавного эффекта свечения
    delay(1);
  }
    ANIM();
  //затухания светодиода
  for(int i=255;i>=0;i--){
 
    analogWrite(NSR, i);
  press();

    //Задержка для более плавного эффекта потухания
    delay(1);
  }
 
 press();}
if(regim == 38)
    {     digitalWrite(V, HIGH);press();
    digitalWrite(D, HIGH);
    digitalWrite(N, HIGH);
    digitalWrite(S, HIGH);press();
    
  setFadeColor(VDR,VDG,VDB);
   setFadeColor(NSR,NSG,NSB);press();
  setFadeColor(VDG,VDB,VDR);
   setFadeColor(NSG,NSB,NSR);press();
  setFadeColor(VDB,VDR,VDG);
   setFadeColor(NSB,NSR,NSG);press();

  
  }

  if(regim == 39)
    {     digitalWrite(V, HIGH);press();
    digitalWrite(D, HIGH);
    digitalWrite(N, HIGH);
    digitalWrite(S, HIGH);press();
    
  setFadeColor1(VDR,VDG,VDB);
   setFadeColor1(NSR,NSG,NSB);press();
  setFadeColor1(VDG,VDB,VDR);
   setFadeColor1(NSG,NSB,NSR);press();
  setFadeColor1(VDB,VDR,VDG);
   setFadeColor1(NSB,NSR,NSG);press();

  
  }

if(regim == 40)
    {     digitalWrite(V, HIGH);press();
    digitalWrite(D, HIGH);
    digitalWrite(N, HIGH);
    digitalWrite(S, HIGH);press();
    
  setFadeColor2(VDR,VDG,VDB);
   setFadeColor2(NSR,NSG,NSB);press();
  setFadeColor2(VDG,VDB,VDR);
   setFadeColor2(NSG,NSB,NSR);press();
  setFadeColor2(VDB,VDR,VDG);
   setFadeColor2(NSB,NSR,NSG);press();

  
  }
if(regim == 41){
  digitalWrite(VDR, LOW);  
  digitalWrite(NSR, LOW);
    digitalWrite(VDG, HIGH);
     digitalWrite(NSG, LOW);
   
    digitalWrite(V, HIGH);press();
       delay(300);
     digitalWrite(V, LOW); press();
     delay(100);
      digitalWrite(V, HIGH);press();
       delay(70);
     digitalWrite(V, LOW); press();
     delay(100);
     digitalWrite(VDG, LOW);
    
     digitalWrite(VDR, HIGH);
    
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
digitalWrite(NSR, HIGH);  
digitalWrite(N, HIGH);
digitalWrite(S, HIGH);
     digitalWrite(NSB, HIGH);press();
  
       delay(100);
     
     digitalWrite(NSB, LOW); press();
digitalWrite(VDR, LOW);
delay(3);
digitalWrite(VDB, HIGH);
     delay(100);
      digitalWrite(NSB, HIGH);press();
   
       delay(70);
     digitalWrite(NSB, LOW); press();
   
     delay(100);
     digitalWrite(NSB, HIGH);press();
     
       delay(50);
     digitalWrite(NSB, LOW); press();
     
     delay(200);
       digitalWrite(NSB, HIGH);press();
 
       delay(100);
     digitalWrite(NSB, LOW); press();
 
     delay(100);
     digitalWrite(NSB, HIGH);press();
  
     delay(2500);
     digitalWrite(V, LOW);press();
     digitalWrite(D, LOW);
     digitalWrite(N, LOW);
     digitalWrite(S, LOW);
     digitalWrite(NSB, LOW);press();
      digitalWrite(VDB, LOW);press();
     delay(300);
        
 }




 
     press();
    }

    
      
