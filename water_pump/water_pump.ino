int In1 = 9;
int In2 = 10;
int ENA = 11;
int SPEED = 210;

void setup(){
pinMode(In1,OUTPUT);
pinMode(In2,OUTPUT);
pinMode(ENA,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(In1,HIGH);
digitalWrite(In2,LOW);

analogWrite(ENA,SPEED);

}
