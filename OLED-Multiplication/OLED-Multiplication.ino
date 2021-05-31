#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4

Adafruit_SSD1306 display(OLED_RESET);
void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}
void loop()
{
  for (int t = 1; t < 21 ; t++)
  {
    for (int a = 1; a < 21 ; a++)
    {
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(15, 0);
      display.print(t);
      display.setCursor(40, 0);
      display.print("+");
      display.setCursor(55, 0);
      display.print(a);
      display.setCursor(80, 0);
      display.print("=");
      display.setCursor(95, 0);
      display.print(t+a);
      display.display();
      delay(1000);
    }
  }
}
