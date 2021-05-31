int D=1000;
int D2=2000; 
void setup() {
  pinMode(A0,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(A6,OUTPUT);
  }

/*void white() {
digitalWrite(A0,HIGH);
digitalWrite(A2,HIGH);
digitalWrite(A3,HIGH);
}
void violet() {
digitalWrite(A0,HIGH);
digitalWrite(A2,HIGH);
digitalWrite(A3,HIGH);
}
void yelHIGH(){
digitalWrite(A0,HIGH);
digitalWrite(A2,HIGH);
digitalWrite(A3,HIGH);
  
}*/
void red() {
digitalWrite(A0,HIGH);
digitalWrite(3,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH); 
digitalWrite(9,HIGH);
digitalWrite(A6,HIGH);
}
void green() {
digitalWrite(A0,HIGH);
digitalWrite(3,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(9,HIGH); 
digitalWrite(A6,HIGH);
}
void blue(){
digitalWrite(A0,HIGH);
digitalWrite(3,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(9,HIGH);
digitalWrite(A6,HIGH);  
}
                                                               

void green2(){
  digitalWrite(A0,HIGH);
digitalWrite(3,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(9,HIGH);
digitalWrite(A6,HIGH);
}

void red2(){
  digitalWrite(A0,HIGH);
digitalWrite(3,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(9,HIGH);
digitalWrite(A6,HIGH);
}
void blue2(){
  digitalWrite(A0,HIGH);
digitalWrite(3,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(9,HIGH);
digitalWrite(A6,HIGH);
}
void loop() {

red();
delay(D);
green();
delay(D);
blue();
delay(D);
green2();
delay(D);
red2();
delay(D);
blue2();
delay(D2);

}
