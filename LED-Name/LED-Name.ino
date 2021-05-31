#include <MaxMatrix.h>

int DIN = 7;   // DIN pin of MAX7219 module
int CLK = 6;   // CLK pin of MAX7219 module
int CS = 5;    // CS pin of MAX7219 module
int maxInUse = 1;

MaxMatrix m(DIN, CS, CLK, maxInUse); 

char smile00[] = {8, 8,
                  B00000011,
                  B00000011,
                  B00000000,
                  B00000000,
                  B00000000,
                  B00000000,
                  B00000000,
                  B00000000,
                 };

char smile01[] = {8, 8,
                  B00000000,
                  B00000110,
                  B00000110,
                  B00000000,
                  B00000000,
                  B00000000,
                  B00000000,
                  B00000000,
                 };

char smile02[] = {8, 8,
                  B00000000,
                  B00000000,
                  B00001100,
                  B00001100,
                  B00000000,
                  B00000000,
                  B00000000,
                  B00000000,
                 };                 
char smile03[] = {8, 8,
                  B00000000,
                  B00000000,
                  B00000000,
                  B00011000,
                  B00011000,
                  B00000000,
                  B00000000,
                  B00000000,
                 };                 

char smile04[] = {8, 8,
                  B00000000,
                  B00000000,
                  B00000000,
                  B00000000,
                  B00110000,
                  B00110000,
                  B00000000,
                  B00000000,
                 };                 

char smile05[] = {8, 8,
                  B00000000,
                  B00000000,
                  B00000000,
                  B00000000,
                  B00000000,
                  B01100000,
                  B01100000,
                  B00000000,
                 };                 

char smile06[] = {8, 8,
                  B00000000,
                  B00000000,
                  B00000000,
                  B00000000,
                  B00000000,
                  B00000000,
                  B11000000,
                  B11000000,
                 };                 

void setup() {
  m.init(); // MAX7219 initialization
  m.setIntensity(10); // initial led matrix intensity, 0-15
}

void loop() {
  m.writeSprite(0, 0, smile00);
  delay(10);
  m.writeSprite(0, 0, smile00);
  delay(10);
  m.writeSprite(0, 0, smile00);
  delay(1000);
  m.clear();
  m.clear();
  m.writeSprite(0, 0, smile01);
  delay(10);
  m.writeSprite(0, 0, smile01);
  delay(10);
  m.writeSprite(0, 0, smile01);
  delay(1000);
  m.clear();
  m.clear();
  m.writeSprite(0, 0, smile02);
  delay(10);
  m.writeSprite(0, 0, smile02);
  delay(10);
  m.writeSprite(0, 0, smile02);
  delay(1000);
  m.clear();
  m.clear();
  m.writeSprite(0, 0, smile03);
  delay(10);
  m.writeSprite(0, 0, smile03);
  delay(10);
  m.writeSprite(0, 0, smile03);
  delay(1000);
  m.clear();
  m.clear();
  m.writeSprite(0, 0, smile04);
  delay(10);
  m.writeSprite(0, 0, smile04);
  delay(10);
  m.writeSprite(0, 0, smile04);
  delay(1000);
  m.clear();
  m.clear();
  m.writeSprite(0, 0, smile05);
  delay(10);
  m.writeSprite(0, 0, smile05);
  delay(10);
  m.writeSprite(0, 0, smile05);
  delay(1000);
  m.clear();
  m.clear();
  m.writeSprite(0, 0, smile06);
  delay(10);
  m.writeSprite(0, 0, smile06);
  delay(10);
  m.writeSprite(0, 0, smile06);
  delay(1000);
  m.clear();
  m.clear();
  m.writeSprite(0, 0, smile05);
  delay(10);
  m.writeSprite(0, 0, smile05);
  delay(10);
  m.writeSprite(0, 0, smile05);
  delay(1000);
  m.clear();
  m.clear();
  m.writeSprite(0, 0, smile04);
  delay(10);
  m.writeSprite(0, 0, smile04);
  delay(10);
  m.writeSprite(0, 0, smile04);
  delay(1000);
  m.clear();
  m.clear();
  m.writeSprite(0, 0, smile03);
  delay(10);
  m.writeSprite(0, 0, smile03);
  delay(10);
  m.writeSprite(0, 0, smile03);
  delay(1000);
  m.clear();
  m.clear();
  m.writeSprite(0, 0, smile02);
  delay(10);
  m.writeSprite(0, 0, smile02);
  delay(10);
  m.writeSprite(0, 0, smile02);
  delay(1000);
  m.clear();
  m.clear();
  m.writeSprite(0, 0, smile01);
  delay(10);
  m.writeSprite(0, 0, smile01);
  delay(10);
  m.writeSprite(0, 0, smile01);
  delay(1000);
  m.clear();
  m.clear();
  m.writeSprite(0, 0, smile00);
  delay(10);
  m.writeSprite(0, 0, smile00);
  delay(10);
  m.writeSprite(0, 0, smile00);
  delay(1000);
  m.clear();
  m.clear();
  
}
