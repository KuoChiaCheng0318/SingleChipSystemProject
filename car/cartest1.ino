#include <SoftwareSerial.h>
#include <Wire.h>
#define IN1 2
#define IN2 4
#define IN3 5
#define IN4 6
#define ENA 3
#define ENB 9
int buzzer=8;//設置控制蜂鳴器的數字IO腳

SoftwareSerial BT(10, 11); // 接收腳, 傳送腳

int input='0'; //input to be used
const int MPU_addr=0x68;
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

int minVal=265; int maxVal=402;

double x; double y; double z;

void setup() {
  // put your setup code here, to run once:
    Wire.begin(); 
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B); 
  Wire.write(0); 
  Wire.endTransmission(true); 
  Serial.begin(9600);
  BT.begin(9600); 
  pinMode(IN1,OUTPUT); pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT); pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT); pinMode(ENB,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(buzzer,OUTPUT);//設置數字IO腳 模式，OUTPUT為輸出
  analogWrite(ENA,150);
  analogWrite(ENB,150);
  //Serial.println("BT is ready!");

}

void loop() {
  // put your main code here, to run repeatedly:
   
////////////////////////////MPU6050/////////////////////////////////    
    Wire.beginTransmission(MPU_addr);
    Wire.write(0x3B);
    Wire.endTransmission(false);
   Wire.requestFrom(MPU_addr,14,true); 
   AcX=Wire.read()<<8|Wire.read();
   AcY=Wire.read()<<8|Wire.read(); 
  AcZ=Wire.read()<<8|Wire.read(); 
  int xAng = map(AcX,minVal,maxVal,-90,90);
  int yAng = map(AcY,minVal,maxVal,-90,90);
  int zAng = map(AcZ,minVal,maxVal,-90,90);

x= RAD_TO_DEG * (atan2(-yAng, -zAng)+PI);
y= RAD_TO_DEG * (atan2(-xAng, -zAng)+PI); 
z= RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);

Serial.print("AngleX= "); Serial.println(x);

Serial.print("AngleY= "); Serial.println(y);

Serial.print("AngleZ= "); Serial.println(z); 
Serial.println("-----------------------------------------"); 
delay(10);

if((150<x&&x<200)||(150<y&&y<200)){
    digitalWrite(7,HIGH);
    delay(100);
    digitalWrite(7,LOW);
    for(int i=0;i<80;i++)//輸出一個頻率的聲音
    {
    digitalWrite(buzzer,HIGH);//發聲音
    delay(1);//延時1ms
    digitalWrite(buzzer,LOW);//不發聲音
    delay(1);//延時ms
    }
    for(int i=0;i<100;i++)//輸出另一個頻率的聲音
    {
    digitalWrite(buzzer,HIGH);//發聲音
    delay(2);//延時2ms
    digitalWrite(buzzer,LOW);//不發聲音
    delay(2);//延時2ms
    }
  }
else {
  digitalWrite(7,LOW);
  digitalWrite(buzzer,LOW);//不發聲音
}



//////////////////////////////////////////////////////////////////

  
  
  if(BT.available()>0)
 {
  input = BT.read();
  Serial.print(input);
 }
// forward
if(input == '1')
  {
  digitalWrite(IN1,HIGH);
   digitalWrite(IN2,LOW);
   digitalWrite(IN3,HIGH);
   digitalWrite(IN4,LOW);
   }

 //turn left  
 else if(input == '2')
  {
   digitalWrite(IN1,LOW);
   digitalWrite(IN2,HIGH);
   digitalWrite(IN3,HIGH);
   digitalWrite(IN4,LOW);
}

//turn right
else if(input == '3')
  {
   digitalWrite(IN1,HIGH);
   digitalWrite(IN2,LOW);
   digitalWrite(IN3,LOW);
   digitalWrite(IN4,HIGH);
   }
 //backward 
 else if(input == '4')
  {
   digitalWrite(IN1,LOW);
   digitalWrite(IN2,HIGH);
   digitalWrite(IN3,LOW);
   digitalWrite(IN4,HIGH);
}



   //stop
    else if(input == '0')
  {
   digitalWrite(IN1,LOW);
   digitalWrite(IN2,LOW);
   digitalWrite(IN3,LOW);
   digitalWrite(IN4,LOW);
}

 

}
