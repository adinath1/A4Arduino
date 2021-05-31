int val;
int b=11;
int g=10;
int r=9;
int pot=A0;

void setup() {
  // put your setup code here, to run once:
pinMode(r,OUTPUT);
pinMode(g,OUTPUT);
pinMode(b,OUTPUT);
pinMode(pot,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(pot);
//Serial.println(val);
val = map(val,0,1024,0,395);
Serial.println(val);
analogWrite(g,val);
analogWrite(r,255-val);


}
