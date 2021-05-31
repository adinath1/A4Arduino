#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//#define NUMFLAKES     10 // Number of snowflakes in the animation example

const int buttonPin1 = 8;     // the number of the pushbutton pin
const int buttonPin2 = 5;     // the number of the pushbutton pin
const int buttonPin3 = 6;     // the number of the pushbutton pin
const int buttonPin4 = 7;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

const int MAX_WICKET = 10;   // change it depending on number of players

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

int runs = 0;
int wicket = 0;

int prestate1 = 0;
int prestate2 = 0;
int prestate3 = 0;
int prestate4 = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);


  display.clearDisplay();
  display.display();
}

void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);

  display.clearDisplay();
  //display.display();
  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  //display.print("HI");
 // display.display();
  //delay(8000);
  // check if the pushbutton is pressed. If it is, then the buttonState is HIGH:
  if (buttonState1 == HIGH && prestate1 == 0 && wicket <= (MAX_WICKET - 1)) {
    display.setCursor(0, 0);
    runs++;
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(runs);
    display.print("/");
    display.print(wicket);
    
    display.println("");
    display.display();
    Serial.println(runs);
    prestate1 = 1;
  } else if (buttonState1 == LOW) {
    prestate1 = 0;
  }

  buttonState2 = digitalRead(buttonPin2);
  // check if the pushbutton is pressed. If it is, then the buttonState is HIGH:

  if (buttonState2 == HIGH && prestate2 == 0 && wicket <= (MAX_WICKET - 1)) {
    runs = runs + 4;
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(runs);
    display.print("/");
    display.print(wicket);
    
    display.println("");
display.display();

    Serial.println(runs);
   
//    display.display();
    //delay(2000);
    prestate2 = 1;
  }
  else if (buttonState2 == LOW) {
    prestate2 = 0;
  }

  buttonState3 = digitalRead(buttonPin3);
  // check if the pushbutton is pressed. If it is, then the buttonState is HIGH:
  if (buttonState3 == HIGH && prestate3 == 0 && wicket <= (MAX_WICKET - 1)) {
    runs = runs + 6;
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(runs);
    display.print("/");
    display.print(wicket);
    display.println("");
    display.display();

    Serial.println(runs);
   
        //delay(2000);
    prestate3 = 1;
  }
  else if (buttonState3 == LOW) {
    prestate3 = 0;
  }

  buttonState4 = digitalRead(buttonPin4);
  // check if the pushbutton is pressed. If it is, then the buttonState is HIGH:
  if (buttonState4 == HIGH && prestate4 == 0 && wicket <= (MAX_WICKET - 1)) {
    wicket++;
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(runs);
    display.print("/");
    display.print(wicket);
    //display.print("");
    Serial.println(runs);
    display.display();
    //delay(2000);
    prestate4 = 1;
  } else if (buttonState4 == LOW) {
    prestate4 = 0;
  }

  if (wicket >= MAX_WICKET) {
    display.clearDisplay();
    display.setCursor(0, 0);
    //display.print(runs);
    //display.print("/");
    //display.print(wicket);
    display.println("Over");
    display.display();
    //delay(2000);
  }

}
