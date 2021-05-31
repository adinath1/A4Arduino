const int ledPin = 13;

const int ldrPin = A7;

void setup() {

Serial.begin(9600);

pinMode(ledPin, OUTPUT);

pinMode(ldrPin, INPUT);

}

void loop() {

int ldrStatus = analogRead(ldrPin);
Serial.println(ldrStatus);
if (ldrStatus <= 2000) {

digitalWrite(ledPin, LOW);

Serial.print("Its DARK, Turn on the LED : ");

Serial.println(ldrStatus);

} else {

digitalWrite(ledPin, HIGH);

Serial.print("Its BRIGHT, Turn off the LED : ");

Serial.println(ldrStatus);

}

}
