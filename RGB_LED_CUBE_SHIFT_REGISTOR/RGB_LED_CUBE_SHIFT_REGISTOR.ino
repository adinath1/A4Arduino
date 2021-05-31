int latchPin = 2;  // Latch pin of 74HC595 is connected to Digital pin 5
int clockPin = 3; // Clock pin of 74HC595 is connected to Digital pin 6
int dataPin = 4;  // Data pin of 74HC595 is connected to Digital pin 4

int latchPin2 = 5;  // Latch pin of 74HC595 is connected to Digital pin 5
int clockPin2 = 6; // Clock pin of 74HC595 is connected to Digital pin 6
int dataPin2 = 7;  // Data pin of 74HC595 is connected to Digital pin 4

int latchPin3 = 8;  // Latch pin of 74HC595 is connected to Digital pin 5
int clockPin3 = 9; // Clock pin of 74HC595 is connected to Digital pin 6
int dataPin3 = 10;  // Data pin of 74HC595 is connected to Digital pin 4

int latchPin4 = 10;  // Latch pin of 74HC595 is connected to Digital pin 5
int clockPin4 = 11; // Clock pin of 74HC595 is connected to Digital pin 6
int dataPin4 = 12;  // Data pin of 74HC595 is connected to Digital pin 4

byte leds = 0;    // Variable to hold the pattern of which LEDs are currently turned on or off

/*
   setup() - this function runs once when you turn your Arduino on
   We initialize the serial connection with the computer
*/
void setup()
{
  // Set all the pins of 74HC595 as OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  pinMode(latchPin2, OUTPUT);
  pinMode(dataPin2, OUTPUT);
  pinMode(clockPin2, OUTPUT);

  pinMode(latchPin3, OUTPUT);
  pinMode(dataPin3, OUTPUT);
  pinMode(clockPin3, OUTPUT);

  pinMode(latchPin4, OUTPUT);
  pinMode(dataPin4, OUTPUT);
  pinMode(clockPin4, OUTPUT);
}

/*
   loop() - this function runs over and over again
*/
void loop()
{
  leds = 0; // Initially turns all the LEDs off, by giving the variable 'leds' the value 0
  updateShiftRegister();
  delay(500);
  for (int i = 0; i < 8; i++) // Turn all the LEDs ON one by one.
  {
    bitSet(leds, i);    // Set the bit that controls that LED in the variable 'leds'
    updateShiftRegister();
    delay(500);
  }
}

/*
   updateShiftRegister() - This function sets the latchPin to low, then calls the Arduino function 'shiftOut' to shift out contents of variable 'leds' in the shift register before putting the 'latchPin' high again.
*/
void updateShiftRegister()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin2, clockPin2, LSBFIRST, leds);
  digitalWrite(latchPin2, HIGH);
  
  digitalWrite(latchPin3, LOW);
  shiftOut(dataPin3, clockPin3, LSBFIRST, leds);
  digitalWrite(latchPin3, HIGH);
  
  digitalWrite(latchPin4, LOW);
  shiftOut(dataPin4, clockPin4, LSBFIRST, leds);
  digitalWrite(latchPin4, HIGH);
}
