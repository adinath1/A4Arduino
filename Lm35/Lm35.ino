/*
   Created by Sathish Deva
   youtube.com/Staysay
   youtube.com/SathishDeva
*/

#define LM35 A0
#define RED A7
#define GREEN A6
#define BLUE A8
float lm_value;
float tempc;

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE,OUTPUT);
}

void loop() {
  lm_value = analogRead(LM35);
  tempc = ((lm_value * 500) / 1023 )-3;
  Serial.println(tempc);//Temperature in Celcius

  //Condition
  if (tempc > 39) {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE,LOW);
  }
  if (tempc < 10 ) {
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, LOW);
    digitalWrite(BLUE,HIGH);
  }
  if ( tempc > 10 && tempc < 39 ){
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
    digitalWrite(BLUE,LOW);
  }
  delay(100);
  
}
