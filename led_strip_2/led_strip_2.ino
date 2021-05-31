#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    60

CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

}

void loop() {


  fill_gradient_RGB(leds, 60, CRGB::Orange, CRGB::Magenta, CRGB::Green, CRGB::Blue);

  FastLED.show();
  delay(40);

}


//brown 165, 42, 42
