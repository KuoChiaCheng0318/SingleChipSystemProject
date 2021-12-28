#include "I2Cdev.h"
 #include "MPU6050.h" 
 #include "Wire.h"
 #include <Servo.h>
  MPU6050 accelgyro;
 Servo servo1;
 int16_t ax, ay, az;
 int16_t gx, gy, gz;
 int val;
 int prev;
void setup() 
{
    // 設定 RS232
    Wire.begin();
    Serial.begin(9600);

    accelgyro.initialize();
    
    
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
}
 
void loop() 
{
    
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    Serial.print("a/g:\t");
    Serial.print(ax); Serial.print("\t");
    Serial.print(ay); Serial.print("\t");
    Serial.print(az); Serial.print("\t");
    Serial.print(gx); Serial.print("\t");
    Serial.print(gy); Serial.print("\t");
    Serial.println(gz);
    // 讀值
    int val0 = analogRead(A0);
    delay(10); 
    int val1 = analogRead(A1);
    delay(10); 
    int val2 = analogRead(A2);
    delay(10); 
    int val3 = analogRead(A3);
    delay(10); 
    // 傳送資料至電腦
    Serial.print( "A0:" );Serial.println( val0 );
    Serial.print( "A1:" );Serial.println( val1 );
    Serial.print( "A2:" );Serial.println( val2 );
    Serial.print( "A3:" );Serial.println( val3 );
    Serial.println( "\n" );
    //delay(300);
///////////////////////////
    if(val0<940&&val0>920){   //sound
      digitalWrite(2,HIGH);
      //delay(100);
    }
    else if(val0<1000&&val0>970){   //redblueLED
      digitalWrite(2,HIGH);
      //delay(7000);
    }
    else if(val0<710&&val0>680){    //normalYellowRedGreenLED
     analogWrite(2,450);
     /*delay(1000);
     digitalWrite(2,LOW);
     delay(1000);*/
    }
    else if(val0<850&&val0>810){    //buzzer
    unsigned char i;//定義變量
    //while(1)
    {
    for(i=0;i<80;i++)//輸出一個頻率的聲音
    {
    digitalWrite(2,HIGH);//發聲音
    delay(1);//延時1ms
    digitalWrite(2,LOW);//不發聲音
    delay(1);//延時ms
    }
    for(i=0;i<100;i++)//輸出另一個頻率的聲音
    {
    digitalWrite(2,HIGH);//發聲音
    delay(2);//延時2ms
    digitalWrite(2,LOW);//不發聲音
    delay(2);//延時2ms
    }
    }
      //delay(1000);
    }
//////////////////////////
    if(val1<940&&val1>920){   //sound
      digitalWrite(3,HIGH);
      //delay(100);
    }
    else if(val1<1000&&val1>970){   //redblueLED
      digitalWrite(3,HIGH);
      //delay(7000);
    }
    else if(val1<710&&val1>680){    //normalYellowRedGreenLED
      analogWrite(3,450);
      /*delay(1000);
     digitalWrite(3,LOW);
     delay(1000);*/
    }
    else if(val1<850&&val1>810){    //buzzer
    unsigned char i;//定義變量
    //while(1)
    {
    for(i=0;i<80;i++)//輸出一個頻率的聲音
    {
    digitalWrite(3,HIGH);//發聲音
    delay(1);//延時1ms
    digitalWrite(3,LOW);//不發聲音
    delay(1);//延時ms
    }
    for(i=0;i<100;i++)//輸出另一個頻率的聲音
    {
    digitalWrite(3,HIGH);//發聲音
    delay(2);//延時2ms
    digitalWrite(3,LOW);//不發聲音
    delay(2);//延時2ms
    }
    }
      //delay(1000);
    }
//////////////////////////
    if(val2<940&&val2>920){   //sound
      digitalWrite(4,HIGH);
      //delay(100);
    }
    else if(val2<1000&&val2>970){   //redblueLED
      digitalWrite(4,HIGH);
      //delay(7000);
    }
    else if(val2<710&&val2>680){    //normalYellowRedGreenLED
      analogWrite(4,450);
      /*delay(1000);
     digitalWrite(4,LOW);
     delay(1000);*/
    } 
    else if(val2<850&&val2>810){    //buzzer
    unsigned char i;//定義變量
    //while(1)
    {
    for(i=0;i<80;i++)//輸出一個頻率的聲音
    {
    digitalWrite(4,HIGH);//發聲音
    delay(1);//延時1ms
    digitalWrite(4,LOW);//不發聲音
    delay(1);//延時ms
    }
    for(i=0;i<100;i++)//輸出另一個頻率的聲音
    {
    digitalWrite(4,HIGH);//發聲音
    delay(2);//延時2ms
    digitalWrite(4,LOW);//不發聲音
    delay(2);//延時2ms
    }
    }
      //delay(1000);
    }

//////////////////////////
    if(val3<940&&val3>920){   //sound
      digitalWrite(5,HIGH);
      //delay(100);
    }
    else if(val3<1000&&val3>970){   //redblueLED
      digitalWrite(5,HIGH);
      //delay(7000);
    }
    else if(val3<710&&val3>680){    //normalYellowRedGreenLED
      analogWrite(5,450);
      /*delay(1000);
     digitalWrite(5,LOW);
     delay(1000);*/
    } 
    else if(val3<850&&val3>810){    //buzzer
    unsigned char i;//定義變量
    //while(1)
    {
    for(i=0;i<80;i++)//輸出一個頻率的聲音
    {
    digitalWrite(5,HIGH);//發聲音
    delay(1);//延時1ms
    digitalWrite(5,LOW);//不發聲音
    delay(1);//延時ms
    }
    for(i=0;i<100;i++)//輸出另一個頻率的聲音
    {
    digitalWrite(5,HIGH);//發聲音
    delay(2);//延時2ms
    digitalWrite(5,LOW);//不發聲音
    delay(2);//延時2ms
    }
    }
      //delay(1000);
    }

////////////////////////// 
if((abs(gx)>300)||(abs(gy)>300)||(abs(gz)>300))
{
  analogWrite(6,450);
}
else
{
  digitalWrite(6,LOW);
}

//////////////////////////    
    if(val0<100){
      digitalWrite(2,LOW);
    }
    if(val1<100){
      digitalWrite(3,LOW);
    }
    if(val2<100){
      digitalWrite(4,LOW);
    }
    if(val3<100){
      digitalWrite(5,LOW);
    }
}
