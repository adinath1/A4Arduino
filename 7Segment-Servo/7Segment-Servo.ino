int e=53;
int d=52;
int c=51;
int g=50;
int f=49;
int a=47;
int b=48;
int aa=24;
int bb=22;
int cc=7;
int dd=28;
int ee=31;
int ff=32;
int gg=33;
#include <Servo.h>

Servo myservo; 
int pos = 0;   

void setup() {
  // put your setup code here, to run once:
pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);
pinMode(d,OUTPUT);
pinMode(e,OUTPUT);
pinMode(f,OUTPUT);
pinMode(g,OUTPUT);
pinMode(aa,OUTPUT);
pinMode(bb,OUTPUT);
pinMode(cc,OUTPUT);
pinMode(dd,OUTPUT);
pinMode(ee,OUTPUT);
pinMode(ff,OUTPUT);
pinMode(gg,OUTPUT);
myservo.attach(9); 
}

void loop() {
  // put your main code here, to run repeatedly:
myservo.write(91);               
//11 
digitalWrite(aa,HIGH);
digitalWrite(bb,HIGH);
digitalWrite(cc,HIGH);
digitalWrite(dd,HIGH);
digitalWrite(ee,LOW);
digitalWrite(ff,HIGH);
digitalWrite(gg,HIGH);

digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,LOW);
delay(2000);

digitalWrite(aa,LOW);
digitalWrite(bb,LOW);
digitalWrite(cc,LOW);
digitalWrite(dd,LOW);
digitalWrite(ee,HIGH);
digitalWrite(ff,HIGH);
digitalWrite(gg,LOW);

digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,LOW);
myservo.write(19);
delay(2000);
}
