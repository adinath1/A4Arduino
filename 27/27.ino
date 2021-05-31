
// Include Libraries
#include "Arduino.h"


// Pin Definitions
#define SEVENSEGSINGLE_1_PIN_DP  6
#define SEVENSEGSINGLE_1_PIN_C  4
#define SEVENSEGSINGLE_1_PIN_D  5
#define SEVENSEGSINGLE_1_PIN_E  7
#define SEVENSEGSINGLE_1_PIN_B  3
#define SEVENSEGSINGLE_1_PIN_A  2
#define SEVENSEGSINGLE_1_PIN_F  8
#define SEVENSEGSINGLE_1_PIN_G  9
#define SEVENSEGSINGLE_2_PIN_DP 14
#define SEVENSEGSINGLE_2_PIN_C  12
#define SEVENSEGSINGLE_2_PIN_D  13
#define SEVENSEGSINGLE_2_PIN_E  15
#define SEVENSEGSINGLE_2_PIN_B  11
#define SEVENSEGSINGLE_2_PIN_A  10
#define SEVENSEGSINGLE_2_PIN_F  16
#define SEVENSEGSINGLE_2_PIN_G  17



// Global variables and defines
//define an array for all the segments
int SevenSegSingle_1Pins[] = { SEVENSEGSINGLE_1_PIN_DP, SEVENSEGSINGLE_1_PIN_C, SEVENSEGSINGLE_1_PIN_D, SEVENSEGSINGLE_1_PIN_E, SEVENSEGSINGLE_1_PIN_B, SEVENSEGSINGLE_1_PIN_A, SEVENSEGSINGLE_1_PIN_F, SEVENSEGSINGLE_1_PIN_G };
//define an array for all the segments
int SevenSegSingle_2Pins[] = { SEVENSEGSINGLE_2_PIN_DP, SEVENSEGSINGLE_2_PIN_C, SEVENSEGSINGLE_2_PIN_D, SEVENSEGSINGLE_2_PIN_E, SEVENSEGSINGLE_2_PIN_B, SEVENSEGSINGLE_2_PIN_A, SEVENSEGSINGLE_2_PIN_F, SEVENSEGSINGLE_2_PIN_G };
// object initialization


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    pinMode(SEVENSEGSINGLE_1_PIN_DP, OUTPUT);
    pinMode(SEVENSEGSINGLE_1_PIN_C, OUTPUT);
    pinMode(SEVENSEGSINGLE_1_PIN_D, OUTPUT);
    pinMode(SEVENSEGSINGLE_1_PIN_E, OUTPUT);
    pinMode(SEVENSEGSINGLE_1_PIN_B, OUTPUT);
    pinMode(SEVENSEGSINGLE_1_PIN_A, OUTPUT);
    pinMode(SEVENSEGSINGLE_1_PIN_F, OUTPUT);
    pinMode(SEVENSEGSINGLE_1_PIN_G, OUTPUT);
    //turn off all segments:
    for (int i = 0; i < 8; i++) { 
    digitalWrite(SevenSegSingle_1Pins[i],HIGH);
    }
    pinMode(SEVENSEGSINGLE_2_PIN_DP, OUTPUT);
    pinMode(SEVENSEGSINGLE_2_PIN_C, OUTPUT);
    pinMode(SEVENSEGSINGLE_2_PIN_D, OUTPUT);
    pinMode(SEVENSEGSINGLE_2_PIN_E, OUTPUT);
    pinMode(SEVENSEGSINGLE_2_PIN_B, OUTPUT);
    pinMode(SEVENSEGSINGLE_2_PIN_A, OUTPUT);
    pinMode(SEVENSEGSINGLE_2_PIN_F, OUTPUT);
    pinMode(SEVENSEGSINGLE_2_PIN_G, OUTPUT);
    //turn off all segments:
    for (int i = 0; i < 8; i++) { 
    digitalWrite(SevenSegSingle_2Pins[i],HIGH);
    }
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1') {
    // 7 - Segment Display (Single Digit) #1 - Test Code
    //This loop will turn on and off each segment in the array for 0.5 sec
    for (int i = 0; i < 8; i++) { 
    digitalWrite(SevenSegSingle_1Pins[i],LOW);
    delay(500);
    }
    for (int i = 0; i < 8; i++) { 
    digitalWrite(SevenSegSingle_1Pins[i],HIGH);
    }

    }
    else if(menuOption == '2') {
    // 7 - Segment Display (Single Digit) #2 - Test Code
    //This loop will turn on and off each segment in the array for 0.5 sec
    for (int i = 0; i < 8; i++) { 
    digitalWrite(SevenSegSingle_2Pins[i],LOW);
    delay(500);
    }
    for (int i = 0; i < 8; i++) { 
    digitalWrite(SevenSegSingle_2Pins[i],HIGH);
    }

    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) 7 - Segment Display (Single Digit) #1"));
    Serial.println(F("(2) 7 - Segment Display (Single Digit) #2"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
          Serial.println(F("Now Testing 7 - Segment Display (Single Digit) #1"));
        else if(c == '2') 
          Serial.println(F("Now Testing 7 - Segment Display (Single Digit) #2"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}

/*******************************************************

*    Circuito.io is an automatic generator of schematics and code for off
*    the shelf hardware combinations.

*    Copyright (C) 2016 Roboplan Technologies Ltd.

*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.

*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.

*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*    In addition, and without limitation, to the disclaimers of warranties 
*    stated above and in the GNU General Public License version 3 (or any 
*    later version), Roboplan Technologies Ltd. ("Roboplan") offers this 
*    program subject to the following warranty disclaimers and by using 
*    this program you acknowledge and agree to the following:
*    THIS PROGRAM IS PROVIDED ON AN "AS IS" AND "AS AVAILABLE" BASIS, AND 
*    WITHOUT WARRANTIES OF ANY KIND EITHER EXPRESS OR IMPLIED.  ROBOPLAN 
*    HEREBY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT 
*    NOT LIMITED TO IMPLIED WARRANTIES OF MERCHANTABILITY, TITLE, FITNESS 
*    FOR A PARTICULAR PURPOSE, NON-INFRINGEMENT, AND THOSE ARISING BY 
*    STATUTE OR FROM A COURSE OF DEALING OR USAGE OF TRADE. 
*    YOUR RELIANCE ON, OR USE OF THIS PROGRAM IS AT YOUR SOLE RISK.
*    ROBOPLAN DOES NOT GUARANTEE THAT THE PROGRAM WILL BE FREE OF, OR NOT 
*    SUSCEPTIBLE TO, BUGS, SECURITY BREACHES, OR VIRUSES. ROBOPLAN DOES 
*    NOT WARRANT THAT YOUR USE OF THE PROGRAM, INCLUDING PURSUANT TO 
*    SCHEMATICS, INSTRUCTIONS OR RECOMMENDATIONS OF ROBOPLAN, WILL BE SAFE 
*    FOR PERSONAL USE OR FOR PRODUCTION OR COMMERCIAL USE, WILL NOT 
*    VIOLATE ANY THIRD PARTY RIGHTS, WILL PROVIDE THE INTENDED OR DESIRED
*    RESULTS, OR OPERATE AS YOU INTENDED OR AS MAY BE INDICATED BY ROBOPLAN. 
*    YOU HEREBY WAIVE, AGREE NOT TO ASSERT AGAINST, AND RELEASE ROBOPLAN, 
*    ITS LICENSORS AND AFFILIATES FROM, ANY CLAIMS IN CONNECTION WITH ANY OF 
*    THE ABOVE. 
********************************************************/
