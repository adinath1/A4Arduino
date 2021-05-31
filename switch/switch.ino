void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  // initialize the LED pins:
  for (int thisPin = 2; thisPin < 7; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
  // read the sensor:
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    Serial.println(inByte);
    
    // do something different depending on the character received.
    // The switch statement expects single number values for each case; in this
    // example, though, you're using single quotes to tell the controller to get
    // the ASCII value for the character. For example 'a' = 97, 'b' = 98,
    // and so forth:

    switch (inByte) {
      case 'a':
        digitalWrite(2, HIGH);
        Serial.println("A is entered");
        delay(500);
        break;
      case 'b':
        digitalWrite(3, HIGH);
        Serial.println("B is entered");
        delay(500);
        break;
      case 'c':
        digitalWrite(4, HIGH);
        Serial.println("C is entered");
        delay(500);
        break;
      case 'd':
        Serial.println("D is entered");
        digitalWrite(5, HIGH);
        delay(500);
        break;
      case 'e':
        Serial.println("E is entered");
        digitalWrite(6, HIGH);
        delay(5000);
        break;
      default:
        // turn all the LEDs off:
        for (int thisPin = 2; thisPin < 7; thisPin++) {
          digitalWrite(thisPin, LOW);
        }
    }
  }
  }
