#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4

Adafruit_SSD1306 display(OLED_RESET);
void setup()
{
  display.clearDisplay();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}
void loop()
{
  
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0, 0);
      display.print("Merry Christmas");
      
    }
  
