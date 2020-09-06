#include<SoftwareSerial.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
SoftwareSerial bt(2,3);
int x=7;
int y=6;
int a1=8;
int b1=9;
int a2=10;
int b2=11;
void setup() {
   
   pinMode(x,OUTPUT);
  pinMode(y,INPUT);
pinMode(a1,OUTPUT);
pinMode(b1,OUTPUT);
pinMode(a2,OUTPUT);
pinMode(b2,OUTPUT);
bt.begin(9600);
Serial.begin(9600); 
lcd.init();
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("TN 28");
lcd.setCursor(0,1);
lcd.print("vv 5758");  
}

void loop() {
  long dur,in,cm;
   digitalWrite(x,LOW);
  delayMicroseconds(2);
   digitalWrite(x,HIGH);
  delayMicroseconds(10);
   digitalWrite(x,LOW);
   dur=pulseIn(y,HIGH);
   cm= dur/29/2;
 Serial.println(cm);
   if(bt.available()){
    char c =bt.read();
    Serial.write(c);
    Serial.println(c);
   
   if(c=='F'){
     f12();
     
     lcd.setCursor(8,0);
     lcd.print("front");
     
   }
  else if(c=='B'){
  r12();
    lcd.setCursor(8,0);
   lcd.print("back");
    
   }
   if(c=='S'){
    stop12();
    lcd.setCursor(8,0);
   lcd.print("stop");
    lcd.clear(); 
    } 
     else if(c=='G'){
     f1_left();
       lcd.setCursor(8,0);
      lcd.print("for_lef");
       
     }
      else if(c=='H'){
  
 r1_left();
   lcd.setCursor(8,0);
  lcd.print("rev_lef");
   
      }
 /* if(c=="S"){
 stop1();
   lcd.setCursor(8,0);
  lcd.print("stop1");
   lcd.clear();
 } */
  else if(c=='I'){
f2_right();
  lcd.setCursor(8,0);
 lcd.print("for_2");
  
  }
   else if(c=='J'){
r2_rig();
  lcd.setCursor(8,0);
 lcd.print("rev_rig");
  
   }
   else if(cm<=20){
     stop12();
     delay(500);
       r12();
       delay(1000);
       r2_rig();
       delay(1000);
       if(cm<=20)
       {
        f2_right();
        delay(1000);
        }
       stop12();




       
       
   }
  /* else if(c=="S"){
 stop2();
   lcd.setCursor(8,0);
  lcd.print("stop2");
   lcd.clear();
    } */
   }

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
void stop1()
{
   digitalWrite(a1,LOW);
  digitalWrite(b1,LOW);
  }

  void f2_right(){
    digitalWrite(a1,LOW);
  digitalWrite(b1,LOW); 
  digitalWrite(a2,HIGH);
  digitalWrite(b2,LOW);
}
   void r2_rig(){
  digitalWrite(a2,LOW);
  digitalWrite(b2,HIGH);
  
}
void stop2()
{
   digitalWrite(a2,LOW);
  digitalWrite(b2,LOW);
  }
  void f12()
  {
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

    void stop12()
    {
      digitalWrite(a1,LOW);
  digitalWrite(b1,LOW);
   digitalWrite(a2,LOW);
  digitalWrite(b2,LOW);
      }
