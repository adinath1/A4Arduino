#include <FastLED.h>
#define LED_PIN 2
#define NUM_LEDS 1

CRGB leds[NUM_LEDS];
uint8_t hue = 0;

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  FastLED.show();
 
}

void loop() {

   for (int i = 0; i < 60; i++) {
    //leds[i] = CHSV(hue, 255, 255);
    leds[0] = CHSV(hue + (i * 10), 255, 255);
  }

  EVERY_N_MILLISECONDS(15){
    hue++;
  }

  FastLED.show();
}
