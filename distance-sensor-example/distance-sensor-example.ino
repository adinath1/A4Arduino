#include <Servo.h>

// defines pins numbers
const int trigPin = 50;
const int echoPin = 52;
// defines variables
long duration;
int distance;
Servo myservo;  
 
int pos = 0;   

void setup() {
pinMode(53,OUTPUT);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
myservo.attach(53);
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
\
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

if (distance<10){
digitalWrite(53,HIGH);
Serial.println("kick");
myservo.write(180);
delay(1000);  
 }
else{
digitalWrite(53,LOW);
myservo.write(0);
delay(1000);
}
}
