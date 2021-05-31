#include <LiquidCrystal.h>

// Code from the Demo Example of the DS3231 Library
#include <DS3231.h>
// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);
LiquidCrystal lcd(2, 7, 8, 9, 10, 11);
Time t;
void setup()
{
  rtc.begin();
  Serial.begin(9600);
  rtc.setDOW(THURSDAY);     // Set Day-of-Week to SUNDAY
  rtc.setTime(8, 37, 50);     // Set the time to 12:00:00 (24hr format)
  rtc.setDate(31, 10, 2019);   // Set the date to January 1st, 2014
}
// Code from the Demo Example of the DS3231 Library

void loop()
{
  // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // Send time
  Serial.println(rtc.getTimeStr());
  
  // Wait one second before repeating
  delay (1000);
  
 
 
}
