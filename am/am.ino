
// Include Libraries
#include "Arduino.h"
#include "MaxMatrix.h"


// Pin Definitions
#define LEDMATRIX_PIN_DIN  50
#define LEDMATRIX_PIN_CLK 51
#define LEDMATRIX_PIN_CS  53



// Global variables and defines
byte ledMatrixinUse = 1;                      //Specify how many Max7219 led matrices are chained
int ledMatrixtextScrollingSpeed = 50;        //Specify the scrolling speed
char ledMatrixStr[] = "Hello World!    ";     //Specify the string to be displayed
// object initialization
MaxMatrix ledMatrix(LEDMATRIX_PIN_DIN,LEDMATRIX_PIN_CS,LEDMATRIX_PIN_CLK);


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
    
    ledMatrix.init(ledMatrixinUse);       //Initialize Led Matrices
    ledMatrix.setIntensity(5);            //LED Intensity 0-15
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1') {
    // 8x8 LED display Matrix - MAX7219 - Test Code
    //Note that this function is blocking the loop until the end of the scrolling
    ledMatrix.printStringWithShift(ledMatrixStr, ledMatrixtextScrollingSpeed);  // Send scrolling Text
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
    Serial.println(F("(1) 8x8 LED display Matrix - MAX7219"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
          Serial.println(F("Now Testing 8x8 LED display Matrix - MAX7219"));
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
