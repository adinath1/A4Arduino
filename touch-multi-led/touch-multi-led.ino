#include <MaxMatrix.h>

int DIN = 4;   // DIN pin of MAX7219 module
int CLK = 2;   // CLK pin of MAX7219 module
int CS = 3;    // CS pin of MAX7219 module
int maxInUse = 1;

MaxMatrix m(DIN, CS, CLK, maxInUse); 

char smile01[] = {8, 8,
                  B00000000,
                  B00000000,
                  B00010000,
                  B00010000,
                  B00010000,
                  B00010000,
                  B00000000,
                  B00000000
                 };

char smile02[] = {8, 8,
                  B00000000,
                  B00000000,
                  B00111100,
                  B00000100,
                  B00111100,
                  B00100000,
                  B00111100,
                  B00000000
                 };                 
char smile03[] = {8, 8,
                  B00000000,
                  B00000000,
                  B00111100,
                  B00000100,
                  B00011100,
                  B00000100,
                  B00111100,
                  B00000000
                 };                 

char smile04[] = {8, 8,
                  B00000000,
                  B00101000,
                  B00101000,
                  B00111000,
                  B00001000,
                  B00001000,     
                  B00001000,
                  B00000000
                 };                  

void setup() {
  Serial.begin(9600);
  m.init(); // MAX7219 initialization
  m.setIntensity(10); // initial led matrix intensity, 0-15
}

void loop() {
  m.clear();
  m.clear();
  int ar=analogRead(A15);
  Serial.println(ar);
  m.clear();
  m.clear();
  
  if (ar>1000){
  m.writeSprite(0, 0, smile01);
  delay(1000);
  m.clear();
  m.writeSprite(0, 0, smile02);
  delay(1000);
  m.clear();
  m.writeSprite(0, 0, smile03);
  delay(1000);
  m.clear();
  m.writeSprite(0, 0, smile04);
  delay(1000);
  }
  else{
  m.clear();
  m.clear();
  delay(1000);
  }
}
