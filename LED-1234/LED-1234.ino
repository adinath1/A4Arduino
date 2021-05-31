
#include <MaxMatrix.h>

int DIN = 7;   // DIN pin of MAX7219 module
int CLK = 6;   // CLK pin of MAX7219 module
int CS = 5;    // CS pin of MAX7219 module
int maxInUse = 1;

MaxMatrix m(DIN, CS, CLK, maxInUse); 

char smile01[] = {8, 8,
                  B11000000,
                  B11100000,
                  B01110000,
                  B00111000,
                  B00011100,
                  B00001110,
                  B00000111,
                  B00000011
                 };

char smile02[] = {8, 8,
                  B00111000,
                  B00111000,
                  B00111000,
                  B00111000,
                  B00111000,
                  B00111000,
                  B00111000,
                  B00111000
                 };                 
char smile03[] = {8, 8,
                  B00000011,
                  B00000111,
                  B00001110,
                  B00011100,
                  B00111000,
                  B01110000,
                  B11100000,
                  B11000000
                 };                 

char smile04[] = {8, 8,
                  B00000000,
                  B00000000,
                  B11111111,
                  B11111111,
                  B11111111,
                  B00000000,
                  B00000000,
                  B00000000
                 };                 


char smile05[] = {8, 8,
                  B11000000,
                  B11100000,
                  B01110000,
                  B00111000,
                  B00011100,
                  B00001110,
                  B00000111,
                  B00000011
                 };                 

char smile06[] = {8, 8,
                  B00111000,
                  B00111000,
                  B00111000,
                  B00111000,
                  B00111000,
                  B00111000,
                  B00111000,
                  B00111000
                 };

char smile07[] = {8, 8,
                  B00000011,
                  B00000111,
                  B00001110,
                  B00011100,
                  B00111000,
                  B01110000,
                  B11100000,
                  B11000000
                 };                 
char smile08[] = {8, 8,
                  B00000000,
                  B00000000,
                  B00000000,
                  B11111111,
                  B11111111,
                  B00000000,
                  B00000000,
                  B00000000
                 };                 



void setup() {
  m.init(); // MAX7219 initialization
  m.setIntensity(5); // initial led matrix intensity, 0-15
}

void loop() {
  m.writeSprite(0, 0, smile01);
  delay(500);
  m.clear();
  m.clear();
  m.writeSprite(0, 0, smile02);
  delay(500);
  m.clear();
  m.clear();
  m.writeSprite(0, 0, smile03);
  delay(500);
  m.clear();
  m.clear();
  m.writeSprite(0, 0, smile04);
  delay(500);
  m.clear();
  m.clear();
  m.writeSprite(0, 0, smile05);
  delay(500);
  m.clear();
  m.clear();
  m.writeSprite(0, 0, smile06);
  delay(500);
  m.clear();
  m.clear();
  m.writeSprite(0, 0, smile07);
  delay(500);
  m.clear();
  m.clear();
  m.writeSprite(0, 0, smile08);
  delay(500);
  m.clear();
  m.clear();

}
