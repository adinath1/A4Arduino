void setup() {
  // put your setup code here, to run once:
pinMode(A0,OUTPUT);



}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(A0,1023);
delay(500);
analogWrite(A0,0);
delay(500);
}
