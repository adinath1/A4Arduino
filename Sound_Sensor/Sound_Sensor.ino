int senpin=A0;
int whitelight=8;
int yellowlight=7;
int redlight=13;
long val=0;
long average=0;
int threshold=40;
String answ;

void setup() {
  
pinMode(senpin,INPUT);
pinMode(redlight,OUTPUT);
pinMode(whitelight,OUTPUT);
pinMode(yellowlight,OUTPUT);
Serial.begin(9600);
}
void loop() {
  if(Serial.available ()!=0 ){
    answ=Serial.readStringUntil('\n');
    threshold=answ.toInt();
  }
  sensor();
}
void sensor() {
  for(int i=0;i<160;i++){
    average=average+analogRead(senpin);
  }
    val = average/160;
    average = 0;
    delay(10);
    Serial.println('\t');
    Serial.println(val);
    Serial.print("--------------------------");
    Serial.print(threshold);

    if (val > 700){
      digitalWrite(redlight,HIGH);
      delay(200);
      digitalWrite(redlight,LOW);
      delay(200); 
    }
    
    if (val > 400){
      digitalWrite(whitelight,HIGH);
      delay(200);
      digitalWrite(whitelight,LOW);
      delay(200); 
    }
    if (val > 600){
      digitalWrite(yellowlight,HIGH);
      delay(200);
      digitalWrite(yellowlight,LOW);
      delay(200); 
    }
}
