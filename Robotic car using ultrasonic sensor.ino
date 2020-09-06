#include <Servo.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
Servo myservo;
int x=7;
int y=6;
int a1=8;
int b1=9;
int a2=10;
int b2=11; 
int s=10;
void setup() {

Serial.begin(9600);
pinMode(x,OUTPUT);
pinMode(y,INPUT);
pinMode(a1,OUTPUT);
pinMode(b1,OUTPUT);
pinMode(a2,OUTPUT);
pinMode(b2,OUTPUT);
myservo.attach(s);
myservo.write(115);  
delay(100);
lcd.init();
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("TN 28");
lcd.setCursor(0,1);
lcd.print("vv 5758");
delay(2000);
lcd.clear();
lcd.setCursor(6,0);
lcd.print("GET");
delay(500);
lcd.clear(); 
lcd.setCursor(6,0);
lcd.print("SET");
delay(500); 
lcd.clear();
lcd.setCursor(7,0);
lcd.print("GO");
delay(500); 
lcd.clear();
}

void loop() {
int distance;  
int distanceR;
int distanceL;
distance=readdis();
if(distance<=20){
  
stop12();
delay(100);
r12();
delay(300);
stop12();
delay(200);
distanceR = lookRight();
delay(200);
distanceL = lookLeft();
delay(200);

   if(distanceR>=distanceL){
    
       f2_right();
       delay(500);
       stop12();
      }
    else{
    
        f1_left();
        delay(500);
        stop12();
       }
}
else{
  
f12();
}
distance = readdis();
}

int lookRight(){
  
myservo.write(50); 
delay(500);
int distance = readdis();
delay(100);
myservo.write(115); 
return distance;
}

int lookLeft(){
  
myservo.write(170); 
delay(500);
int distance = readdis();
delay(100);
myservo.write(115); 
return distance;
delay(100);
}

int readdis() { 

long dur,cm;
digitalWrite(x,LOW);
delayMicroseconds(2);
digitalWrite(x,HIGH);
delayMicroseconds(10);
digitalWrite(x,LOW);
dur=pulseIn(y,HIGH);
cm= dur/29/2;
Serial.println(cm);
return cm;
}
void f12(){
  
digitalWrite(a1,HIGH);
digitalWrite(b1,LOW);
digitalWrite(a2,HIGH);
digitalWrite(b2,LOW);
}

void r12(){
  
digitalWrite(a1,LOW);
digitalWrite(b1,HIGH);
digitalWrite(a2,LOW);
digitalWrite(b2,HIGH);
}

void stop12(){
  
digitalWrite(a1,LOW);
digitalWrite(b1,LOW);
digitalWrite(a2,LOW);
digitalWrite(b2,LOW);
}

void f2_right(){

digitalWrite(a1,LOW);
digitalWrite(b1,LOW); 
digitalWrite(a2,HIGH);
digitalWrite(b2,LOW);
}
  
void r2_rig(){

digitalWrite(a1,LOW);
digitalWrite(b1,LOW);
digitalWrite(a2,LOW);
digitalWrite(b2,HIGH);
}

void f1_left(){
  
digitalWrite(a1,HIGH);
digitalWrite(b1,LOW);
digitalWrite(a2,LOW);
digitalWrite(b2,LOW);
}

void r1_left(){

digitalWrite(a1,LOW);
digitalWrite(b1,HIGH);
digitalWrite(a2,LOW);
digitalWrite(b2,LOW);
}
