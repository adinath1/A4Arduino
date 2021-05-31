int a=0;

void setup() {
pinMode(A15,INPUT); //touch sensor
pinMode(22,OUTPUT);
pinMode(23,OUTPUT);
pinMode(24,OUTPUT);
Serial.begin(9600);
}

void loop() {
a=analogRead(A15);
Serial.println(a);

if (a>=1000){
    digitalWrite(22,HIGH);
    digitalWrite(24,LOW);
    digitalWrite(23,LOW);
  } 
  else{
  digitalWrite(22,LOW);
  digitalWrite(24,LOW);
  digitalWrite(23,HIGH);
  }  
}
