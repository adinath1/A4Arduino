Serial.end()
Seril
Serial.read()












/* IR Obstacle Detection Module */
/*www.factoryforward.com */

int M1 = 5; // Onboard M1 pin
int M2 = 6; // Onboard M2 pin
int irPin = 7;  // This is our input pin (IR M1 at pin 7)
int sensorOut = HIGH;  // HIGH at No Obstacle

void setup() {
  pinMode(M1, OUTPUT);
  pinMode(irPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  sensorOut = digitalRead(irPin);
  if (sensorOut == LOW)
  {
    Serial.println("What is this Obstacle?");
    digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  }
  else
  {
    Serial.println("No Obstacle");
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
  }
  delay(200);
}
