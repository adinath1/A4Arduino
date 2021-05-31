#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();

}


void loop()
{
    lcd.setCursor(5,0);
  lcd.print("|O   O|");
  lcd.setCursor(7,1);
  lcd.print("---");
  delay(1000);
    lcd.setCursor(5,0);
  lcd.print("|-   -|");
  lcd.setCursor(7,1);
  lcd.print("---");
  delay(1000);
    lcd.setCursor(5,0);
  lcd.setCursor(7,1);
  lcd.print("---");
 
  delay(1000);
    lcd.setCursor(5,0);
  lcd.print("|-   -|");
  lcd.setCursor(7,1);
  lcd.print("---");
  delay(1000);

  lcd.setCursor(5,0);
  lcd.print("|O   O|");
  lcd.setCursor(7,1);
  lcd.print("---");
  delay(4000);



  
}
