#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    60

CRGB leds[NUM_LEDS];
uint8_t hue=0;
void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

}

void loop() {
 /* fill_gradient_RGB(leds, 60, CRGB::Red, CRGB::Yellow, CRGB::Green, CRGB::Blue); FastLED.show();
  delay(300);
  for (int i = 10; i <= 60; i = i + 1) {
    fill_rainbow(leds, i, 0, 255 / i);
    FastLED.show();
    delay(50);
  }
   */ 
  for (int i = 0; i < NUM_LEDS; i++) {
    //leds[i] = CHSV(hue, 255, 255);
    leds[i] = CHSV(hue + (i * 10), 255, 255);
  }

  EVERY_N_MILLISECONDS(0){
    hue++;
  }

  FastLED.show();
  
}
String run_color(int my_color) {
  for (int i = 0; i <= 57; i++) {

    switch (my_color) {
      case 1:
        leds[i] = CRGB::Violet;
        leds[i + 1] = CRGB::Violet;
        leds[i + 2] = CRGB::Violet;

        break;
      case 2:
        leds[i] = CRGB::Indigo;
        break;
      case 3:
        leds[i] = CRGB::Blue;
        break;
      case 4:
        leds[i] = CRGB::Green;
        break;
      case 5:
        leds[i] = CRGB::Yellow;
        break;
      case 6:
        leds[i] = CRGB::Orange;
        break;
      case 7:
        leds[i] = CRGB::Red;
        break;

      default:
        leds[i] = CRGB::Black;

    }
    FastLED.show();
    delay(10);
  }
  for (int i = 0; i <= 57; i++) {
    leds[i] = CRGB (255, 0, 255);
    leds[i + 1] = CRGB (255, 255, 0);
    leds[i + 2] = CRGB (0, 255, 255);

    FastLED.show();
    delay(10);
  }
}

//brown 165, 42, 42
