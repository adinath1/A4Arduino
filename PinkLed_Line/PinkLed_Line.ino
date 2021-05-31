int ledPin3 = A3;//led2
int ledPin4 = A2;

int ledPin2 = A1;//led1
int ledPin1 = A0;

int ledPin5 = A4;//led3
int ledPin6 = A5;

int ledPin7 = A6;//led4
int ledPin8 = A7;

int ledPin9 = A8;//led5
int ledPin10 = A9;

int ledPin11 = A10;//led6
int ledPin12 = A11;


int ledPin13 = A12;//led7
int ledPin14 = A13;

int ledPin15 = A14;//led8
int ledPin16 = A15;
//int ledline [] = {23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53};

void setup() {
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  for (int z = 23; z <= 53; z = z + 2) {
    pinMode(z, OUTPUT);
  }
}

void loop()
{
  LED_Glow(255, 134);
  LED_RGlow(255, 134);
  //LED_RGlow(255, 134);
}

void LED_Glow(int speedOfRotate, int length) {
  analogWrite(ledPin1, speedOfRotate);
  analogWrite(ledPin2, 0);
  delay(length);
  analogWrite(ledPin3, 0);
  analogWrite(ledPin4, speedOfRotate);
  delay(length);
  analogWrite(ledPin5, 0);
  analogWrite(ledPin6, speedOfRotate);
  delay(length);
  analogWrite(ledPin7, 0);
  analogWrite(ledPin8, speedOfRotate);
  delay(length);
  analogWrite(ledPin9, 0);
  analogWrite(ledPin10, speedOfRotate);
  delay(length);
  analogWrite(ledPin11, 0);
  analogWrite(ledPin12, speedOfRotate);
  delay(length);
  analogWrite(ledPin13, 0);
  analogWrite(ledPin14, speedOfRotate);
  delay(length);
  analogWrite(ledPin15, 0);
  analogWrite(ledPin16, speedOfRotate);
  delay(length);
  //Line_glow(ledline,134); 
  analogWrite(ledPin1, 0);
  analogWrite(ledPin2, 0);
  delay(length);
  analogWrite(ledPin3, 0);
  analogWrite(ledPin4, 0);
  delay(length);
  analogWrite(ledPin5, 0);
  analogWrite(ledPin6, 0);
  delay(length);
  analogWrite(ledPin7, 0);
  analogWrite(ledPin8, 0);
  delay(length);
  analogWrite(ledPin9, 0);
  analogWrite(ledPin10, 0);
  delay(length);
  analogWrite(ledPin11, 0);
  analogWrite(ledPin12, 0);
  delay(length);
  analogWrite(ledPin13, 0);
  analogWrite(ledPin14, 0);
  delay(length);
  analogWrite(ledPin15, 0);
  analogWrite(ledPin16, 0);
  delay(length);
}
void LED_RGlow(int speedOfRotate, int length) {
  analogWrite(ledPin15, 0);
  analogWrite(ledPin16, speedOfRotate);
  delay(length);
  analogWrite(ledPin13, 0);
  analogWrite(ledPin14, speedOfRotate);
  delay(length);
  analogWrite(ledPin11, 0);
  analogWrite(ledPin12, speedOfRotate);
  delay(length);
  analogWrite(ledPin9, 0);
  analogWrite(ledPin10, speedOfRotate);
  delay(length);
  analogWrite(ledPin7, 0);
  analogWrite(ledPin8, speedOfRotate);
  delay(length);
  analogWrite(ledPin5, 0);
  analogWrite(ledPin6, speedOfRotate);
  delay(length);
  analogWrite(ledPin3, 0);
  analogWrite(ledPin4, speedOfRotate);
  delay(length);
  analogWrite(ledPin1, speedOfRotate);
  analogWrite(ledPin2, 0);
  delay(length);
  //Line_glow(ledline,134); 
  analogWrite(ledPin1, 0);
  analogWrite(ledPin2, 0);
  delay(length);
  analogWrite(ledPin3, 0);
  analogWrite(ledPin4, 0);
  delay(length);
  analogWrite(ledPin5, 0);
  analogWrite(ledPin6, 0);
  delay(length);
  analogWrite(ledPin7, 0);
  analogWrite(ledPin8, 0);
  delay(length);
  analogWrite(ledPin9, 0);
  analogWrite(ledPin10, 0);
  delay(length);
  analogWrite(ledPin11, 0);
  analogWrite(ledPin12, 0);
  delay(length);
  analogWrite(ledPin13, 0);
  analogWrite(ledPin14, 0);
  delay(length);
  analogWrite(ledPin15, 0);
  analogWrite(ledPin16, 0);
  delay(length);
}
