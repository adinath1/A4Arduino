#include <DS3231.h>
// Code from the Demo Example of the DS3231 Library
void setup()
{  // Setup Serial connection
DS3231  rtc(SDA, SCL);
  Serial.begin(115200);
  // Uncomment the next line if you are using an Arduino Leonardo
  //while (!Serial) {}
  
  // Initialize the rtc object
  rtc.begin();
  
  // The following lines can be uncommented to set the date and time
  // 
  rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
  //
  rtc.setTime(12, 4, 9);     // Set the time to 12:00:00 (24hr format)
  //
  rtc.setDate(2, 8, 2020);   // Set the date to January 1st, 2014
} 
void loop() {

}
