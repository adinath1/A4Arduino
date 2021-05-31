#include <FastLED.h>
#define LED_PIN 2
#define NUM_LEDS 60

CRGB leds[NUM_LEDS];


void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  FastLED.show();

}

void loop() {
  // Turn lights from green to blue from left to right   R G B
  for (int i = 0; i <= NUM_LEDS; i++) {
   for(int j=0;j<=255;j++){
    leds[i] = CRGB (j, j-255, 0-j);
    FastLED.show();
    delay(1);
  }
  }
}
