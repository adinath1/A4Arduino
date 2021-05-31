#include <Wire.h>
#include <LiquidCrystal_I2C.h>  
 
LiquidCrystal_I2C lcd(0x3F,16,2); // Address and Size LCD, 
 
#define buttonPin  2  // Game button
 
byte stone[8] = {
  0b00100,
  0b01110,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00100,
  0b01110
};
 
byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};
 
byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};
 
byte explosion[8] = {
  0b10001,
  0b01010,
  0b01010,
  0b00100,
  0b01010,
  0b01010,
  0b10001,
  0b00000
};
 
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b00000
};
 
int stones[16];
int heroY = 2;
int heroX = 7;
int score = 0;
int level=350;
 
int life = 5; // number of lives
 
void setup() {
  lcd.init();   
  lcd.backlight();  
  Serial.begin (9600);
  
  randomSeed(analogRead(0));
  
  pinMode(buttonPin, INPUT_PULLUP);
  
  int i = 0;
  for (i = 0; i<16; i++) {
    stones[i] = 0;
  }
  
 
  lcd.begin(16, 2);
 
 
  lcd.createChar(0, stone);
  lcd.createChar(1, armsUp);
  lcd.createChar(2, armsDown);
  lcd.createChar(3, explosion);
  lcd.createChar(4, heart);
}
 
void hero() {
  int buttonValue = digitalRead(buttonPin);
  int charId = 0;
  
  if (buttonValue == LOW) {
    heroY = 0;
    charId = 1;
  } else {
    heroY = 1;
    charId = 2;
    if (stones[heroX] == 1) {
      charId = 3;
      life--;
      score--;
    }
  }
  lcd.setCursor(heroX, heroY);
  lcd.write((byte)charId);
}
 
void moveStones() {
  int randS = random(0, 2);
  // shift the  stones
  int i;
  for (i=1; i<16; i++) {
    stones[i-1] = stones[i];
  }
  
  if (randS == 1 && (stones[14] == 1 || stones[13] == 1)) {
      stones[15] = 0;
  } else {
     stones[15] = randS;
  }
    
  for (i = 0; i<16; i++) {
    if (stones[i] != 0) {
      lcd.setCursor(i, 1);
      lcd.write((byte)0);
    }
  }
}
 
void showLife() {
  int i;
  for (i=0; i<life; i++) {
    lcd.setCursor(i, 0);
    lcd.write((byte)4);
  }
}
 
void loop() {
  lcd.clear();
  if (life > 0) {
    moveStones();
    hero();
    showLife();
    score++;
    level--;
  } else  {
    lcd.setCursor(2, 0);
    lcd.print("GAME OVER");
    lcd.setCursor(2, 1);
    lcd.print("Score:");
    lcd.print(score);
  }
  delay(level);
 
}
