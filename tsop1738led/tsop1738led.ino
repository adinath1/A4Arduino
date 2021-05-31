
#include <IRremote.h>      //header file -> to use ir remote in arduino
 
int RECV_PIN = 3;               //declared for receiving pulses
long int c=0;                        // declared if you want to control with a single button
IRrecv irrecv(RECV_PIN);    
decode_results results;   //structure to get the value from pressing different button in remote
#include <FastLED.h>
#define LED_PIN     2
#define NUM_LEDS    20
CRGB leds[NUM_LEDS];

void setup()
{
   
   Serial.begin(9600);
  irrecv.enableIRIn();                      //function to Start the ir receiver
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  

}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    irrecv.resume();                        // Receive the next value
  if(results.value==37)   //this will switch led off   -- getting value 37 while pressing OK button                                 
  {
             leds[0] = CRGB(0, 0, 0);
             FastLED.show();
             delay(500);
             Serial.println("off");
             
  }
  if(results.value==12)   // this will turn led on.. getting value 12 while pressing POWER ON button
  {
              leds[0] = CRGB(255, 0, 0);
              FastLED.show();
              delay(500);
             Serial.println("on");
  }
                                }
}
