int motorPin1=5;
int motorPin2=6;

void setup(){
pinMode(motorPin1, OUTPUT);
pinMode(motorPin2, OUTPUT);
}
void loop() {
  rotateRight(50, 1000);
  rotateRight(150, 1000);
  rotateRightOFF(0, 0);
  rotateRight(0, 0);
}

void rotateRight(int speedOfRotate, int length) {
  analogWrite(motorPin2, speedOfRotate);
  digitalWrite(motorPin1, LOW);
  delay(length);
  digitalWrite(motorPin2, LOW);
}
void rotateRightOFF(int speedOfRotate, int length) {
  analogWrite(motorPin2, LOW);
  digitalWrite(motorPin1, LOW);
  delay(length);
  digitalWrite(motorPin2, LOW);
}
