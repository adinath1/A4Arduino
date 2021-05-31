int motorPin3 = A3;//led2
int motorPin4 = A2;

int motorPin2 = A1;//led1
int motorPin1 = A0;

int motorPin5 = A4;//led3
int motorPin6 = A5;

int motorPin7 = A6;//led4
int motorPin8 = A7;
//int ledline [] = {23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53};

void setup() {
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  for (int z = 23; z <= 53; z = z + 2) {
    pinMode(z, OUTPUT);
  }
}

void loop()
{
  LED_Glow(255, 84);
  LED_RGlow(255, 84);
  
}

void LED_Glow(int speedOfRotate, int length) {
  analogWrite(motorPin1, speedOfRotate);
  analogWrite(motorPin2, 0);
  delay(length);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, speedOfRotate);
  delay(length);
  analogWrite(motorPin5, 0);
  analogWrite(motorPin6, speedOfRotate);
  delay(length);
  analogWrite(motorPin7, 0);
  analogWrite(motorPin8, speedOfRotate);
  delay(length);
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  delay(length);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 0);
  delay(length);
  analogWrite(motorPin5, 0);
  analogWrite(motorPin6, 0);
  delay(length);
  analogWrite(motorPin7, 0);
  analogWrite(motorPin8, 0);
  delay(length);
}
void LED_RGlow(int speedOfRotate, int length) {
  analogWrite(motorPin7, 0);
  analogWrite(motorPin8, speedOfRotate);
  delay(length);
  analogWrite(motorPin5, 0);
  analogWrite(motorPin6, speedOfRotate);
  delay(length);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, speedOfRotate);
  delay(length);
  analogWrite(motorPin1, speedOfRotate);
  analogWrite(motorPin2, 0);
  delay(length);
  //Line_glow(ledline,134); 
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  delay(length);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 0);
  delay(length);
  analogWrite(motorPin5, 0);
  analogWrite(motorPin6, 0);
  delay(length);
  analogWrite(motorPin7, 0);
  analogWrite(motorPin8, 0);
  delay(length);
}
