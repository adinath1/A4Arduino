int val;
int current_status=1;

void setup() {
pinMode(13,OUTPUT);
pinMode(A0,INPUT);
Serial.begin(9600);
}

void loop() {
val = analogRead(A0);
Serial.println(val);

if ((val > 1000) && (current_status == 1) ){
  digitalWrite(13,HIGH);
  delay(2000);
  current_status = 0;
}
if ((val > 1000) && (current_status == 0) ){
  digitalWrite(13,LOW);
  delay(2000);
  current_status = 1;
}
//delay(2000);
}
