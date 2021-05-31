#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,4,5,6,7);//rs,e,d4,d5,d6,d7 respectively
void setup(){
lcd.begin(16,2);
lcd.setCursor(0,1);
lcd.print("Working");
}
void loop(){
}
