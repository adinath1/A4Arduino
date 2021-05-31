int D=400 ;
 

void setup() {
  pinMode(A0,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
  
  }

void loop() {
analogWrite(A0,0);
analogWrite(A2,0);
analogWrite(A3,255);
analogWrite(A4,0);
analogWrite(A5,0);
delay(D);
analogWrite(A0,0);
analogWrite(A2,255);
analogWrite(A3,0);
analogWrite(A4,0);
analogWrite(A5,0);
delay(D);
analogWrite(A0,255);
analogWrite(A2,0);
analogWrite(A3,0);
analogWrite(A4,0);
analogWrite(A5,0);
delay(D);
analogWrite(A0,0);
analogWrite(A2,0);
analogWrite(A3,0);
analogWrite(A4,255);
analogWrite(A5,0);
delay(D);
analogWrite(A0,0);
analogWrite(A2,0);
analogWrite(A3,0);
analogWrite(A4,0);
analogWrite(A5,255);
delay(D);

}
