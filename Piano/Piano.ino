//Arduino Piano
/*
Visit the Channel for more interesting projects
https://www.youtube.com/channel/UCks-9JSnVb22dlqtMgPjrlg
*/
#define T_H 500
#define T_C 262
#define T_D 294
#define T_E 330
#define T_F 349
#define T_G 392
#define T_A 440
#define T_B 493
const int H = 3;
const int C = 10;
const int D = 9;
const int E = 8;
const int F = 7;
const int G = 6;
const int A = 5;
const int B = 4;
 
const int Buzz = 2;
const int LED = 13;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(C, INPUT);
  digitalWrite(C,HIGH);
  
  pinMode(D, INPUT);
  digitalWrite(D,HIGH);
  
  pinMode(E, INPUT);
  digitalWrite(E,HIGH);
  
  pinMode(F, INPUT);
  digitalWrite(F,HIGH);
  
  pinMode(G, INPUT);
  digitalWrite(G,HIGH);
  
  pinMode(A, INPUT);
  digitalWrite(A,HIGH);
  
  pinMode(B, INPUT);
  digitalWrite(B,HIGH);

  digitalWrite(LED,LOW);
  pinMode(51,OUTPUT);
  pinMode(50,OUTPUT);
  pinMode(49,OUTPUT);
  pinMode(48,OUTPUT);
  pinMode(47,OUTPUT);
  pinMode(46,OUTPUT);
  pinMode(45,OUTPUT);
  pinMode(44,OUTPUT);
}

void loop()
{
  while(digitalRead(C) == HIGH)
  {
    tone(Buzz,T_C);
    digitalWrite(LED,HIGH);
    digitalWrite(51,HIGH);
  }

  while(digitalRead(D) == HIGH)
  {
    tone(Buzz,T_D);
    digitalWrite(LED,HIGH);
    digitalWrite(50,HIGH);
  }

  while(digitalRead(E) == HIGH)
  {
    tone(Buzz,T_E);
    digitalWrite(LED,HIGH);
    digitalWrite(49,HIGH);
  }

  while(digitalRead(F) == HIGH)
  {
    tone(Buzz,T_F);
    digitalWrite(LED,HIGH);
    digitalWrite(48,HIGH);
  }

  while(digitalRead(G) == HIGH)
  {
    tone(Buzz,T_G);
    digitalWrite(LED,HIGH);
    digitalWrite(47,HIGH);
  }

  while(digitalRead(A) == HIGH)
  {
    tone(Buzz,T_A);
    digitalWrite(LED,HIGH);
    digitalWrite(46,HIGH);
  }

  while(digitalRead(B) == HIGH)
  {
    tone(Buzz,T_B);
    digitalWrite(LED,HIGH);
    digitalWrite(45,HIGH);
  }
while(digitalRead(H) == LOW)
  {
    tone(Buzz,T_H);
    digitalWrite(LED,LOW);
    digitalWrite(44,HIGH);
  }
  noTone(Buzz);
  digitalWrite(LED,LOW);
  digitalWrite(44,LOW);
  digitalWrite(45,LOW);
  digitalWrite(46,LOW);
  digitalWrite(47,LOW);
  digitalWrite(48,LOW);
  digitalWrite(49,LOW);
  digitalWrite(50,LOW);
  digitalWrite(51,LOW);
}
