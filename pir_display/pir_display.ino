int ledPin = 13;                // LED 
int pirPin = A5;                 // PIR Out pin 
int pirStat = 0;                   // PIR status
void setup() {
 pinMode(ledPin, OUTPUT);     
 pinMode(pirPin, INPUT);     
 Serial.begin(9600);
}
void loop(){
 pirStat = digitalRead(pirPin); 
 if (pirStat == HIGH) {            // if motion detected
   digitalWrite(ledPin, HIGH);  // turn LED ON
   
    } 
 else {
   digitalWrite(ledPin, LOW); // turn LED OFF if we have no motion
 }
} 
