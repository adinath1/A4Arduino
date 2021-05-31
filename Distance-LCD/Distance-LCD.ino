#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 
// defines pins numbers
const int trigPin = 10;
const int echoPin = 11;
//const int greenpin = 11;
//const int redpin = 13;

// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
lcd.init();                       
lcd.backlight();

pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
//pinMode(greenpin, OUTPUT);
//pinMode(redpin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;


//CLEAR LCD
lcd.clear();

//TOP LINE
lcd.setCursor(0,0);
lcd.print(distance);

//2nd LINE
lcd.setCursor(5,0);
lcd.print("CM");

lcd.setCursor(0,1);
lcd.print("Sonic Distance");
delay(500);
}
