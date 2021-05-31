#include <IRremote.h> //include the library
#define Button_1 0xFFA25D
#define Button_2 0xFF629D
#define Button_3 0xFFE21D
#define Button_4 0xFF22DD
#define Button_5 0xFF02FD
#define Button_6 0xFFC23D
int receiver = 13; //initialize pin 13 as recevier pin.
uint32_t Previous; 
IRrecv irrecv(receiver); //create a new instance of receiver
decode_results results;


void setup() {
 Serial.begin(9600);
 irrecv.enableIRIn(); //start the receiver
pinMode(12, OUTPUT);
}
void loop() {
 if (irrecv.decode(&results)) { //if we have received an IR signal
  if (results.value==0xFFFFFFFF) { 
      results.value=Previous;
      }

    switch(results.value) {
           case Button_1 : digitalWrite(12, HIGH); break;
           case Button_2 : digitalWrite(11, HIGH); break;
           case Button_3 : digitalWrite(10, HIGH); break;
           case Button_4 : digitalWrite(12, LOW); break;
           case Button_5 : digitalWrite(11, LOW); break;
           case Button_6 : digitalWrite(10, LOW); break;
      } 
 Serial.println (results.value, HEX); //display HEX results 
 irrecv.resume(); //next value
 }
 Previous=results.value;
 }
