#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,2,1,0,4,7,3,POSITIVE);  

void setup()
{
  //Wire.begin();
  lcd.begin(16,2);                      
  lcd.clear();
  lcd.print("Welcome to LCD");
}
void loop()
{
 delay(1000);
 lcd.begin();                      
 lcd.backlight();
 lcd.setCursor(1,0);
 lcd.print("HAPPY");
 lcd.setCursor(0,1);
  lcd.print("INDEPENDENCE DAY");
  delay(5000);
  lcd.clear();
 }
