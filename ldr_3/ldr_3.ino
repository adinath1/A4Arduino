const int ledPin = 13;

const int ldrPin = A0;

void setup() {

Serial.begin(9600);

pinMode(ledPin, OUTPUT);
pinMode(53, OUTPUT);
pinMode(ldrPin, INPUT);

}

void loop() {

int ldrStatus = analogRead(ldrPin);

if (ldrStatus <= 20) {
 
digitalWrite(ledPin, LOW);
Serial.print("Its not touthed ");

Serial.println(ldrStatus);

} else {

digitalWrite(ledPin, HIGH);


Serial.print("Its touthed ");

Serial.println(ldrStatus);

}

}
