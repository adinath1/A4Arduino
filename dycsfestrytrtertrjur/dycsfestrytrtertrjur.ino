//this project is made by BEASTIDREES62 https://id.arduino.cc/?code=MTxqeHweG6vL2cur&state=amxEcTB2bnNiYjluTUxmRExWaWZnOXIzUk1BLWRqZTZYUGtJNGtxODB%2Bdg%3D%3D
const int pingPin = 7;
//adjust this to set the min speed of wave gesture
const int waveBackWait = 5000;
//Range of detection from the sensor in cm
const int range = 100;
void setup() {
  pinMode(10, OUTPUT);
}
void loop() {
  long duration, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  
  cm = microsecondsToCentimeters(duration);
if(cm < range && cm > 4){
    for(int i=waveBackWait; i>0; i--){
      long new_duration, new_cm;
      pinMode(pingPin, OUTPUT);
      digitalWrite(pingPin, LOW);
      delayMicroseconds(2);
      digitalWrite(pingPin, HIGH);
      delayMicroseconds(5);
      digitalWrite(pingPin, LOW);
      pinMode(pingPin, INPUT);
      new_duration = pulseIn(pingPin, HIGH);
  
      new_cm = microsecondsToCentimeters(new_duration);
      if(new_cm < range && new_cm > 1){
        //ring the doorbell
        digitalWrite(10,HIGH);
        delay(500);
        digitalWrite(10,LOW);
      }
    }
  }
}
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
