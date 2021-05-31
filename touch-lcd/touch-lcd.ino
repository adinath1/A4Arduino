/* this program will funciton as counter. Every time the touch module is touch
 * the counter increments +1 to the counter. The count number is displayed on LCD1602 display
 * We have got a reset button to restart the counting from zero.
 * 
 * Watch video instruciton for this video:https://youtu.be/5A9jPD5nUCw
 * 
 * Written by Ahmad Shamshiri on Saturday 27th of October at 16:28 in Ajax, Ontario, Canada
 * Get this code from Robojax.com
 * 
 * This code is "AS IS" without warranty or liability. Free to be used as long as you keep this note intact.* 
 * This code has been download from Robojax.com
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

// start of settings for LCD1602 with I2C
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
// end of settings for LCD1602 with I2C

const int touchPin = 2;// the input pin where touch sensor is connected
const int resetPin = 12;// the input pin for reset button
const int touchDelay = 500;//millisecond delay between each touch

int count=0;// variable holding the count number

void setup() {
 // Robojax.com Touch counter 20181027
  // initialize the LCD
  lcd.begin();
  lcd.backlight();// turn the backlight ON for the LCD
      lcd.print("Robojax Touch");
      lcd.setCursor(0,1);
      lcd.print("Counter V2");      
  Serial.begin(9600);// initialize serial monitor with 9600 baud
  Serial.println("Robojax Touch Counter V2");  
  pinMode(touchPin,INPUT);// define a pin for touch module
  pinMode(resetPin,INPUT_PULLUP);// define a pin for reset button
  // see video ( link in the video description) on using PULLUP

  delay(3000);// give time to user to read the display at the beginning

  
  // Robojax.com Touch counter 20181027        
}

void loop() {
  // Robojax.com Touch counter 20181027

  int touchValue = digitalRead(touchPin);// read touchPin and store it in touchValue

  // if touchValue is HIGH
  if(touchValue == HIGH)
  {
      count++;// increment the count   
      
      lcd.clear();// clear previous values from screen      
      lcd.print("Robojax  TCV2");
      lcd.setCursor(0,1);
      lcd.print("Touched:"); 
      lcd.setCursor(9,1);
      lcd.print(count);  
   
      Serial.print("Touched ");//print the information
      Serial.print(count);//print count
      Serial.println(" times.");        
    delay(touchDelay);// touch delay time
  }


      
   // if reset switch is pushed
   if(digitalRead(resetPin) == LOW)
   {
    lcd.clear();// clear previous values from screen     
    count =0;// reset the counter;
      Serial.println("Counter Retestted.");//print the information
      lcd.setCursor(0,0);      
      lcd.print("Robojax  TCV2");
      lcd.setCursor(0,1);
      lcd.print("Resetted");    
    
   }

  // Robojax.com Touch counter 20181027
}


 
