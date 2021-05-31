int count = 29;
int Ateam [] = {53,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24};
int d = 50;
void setup() {
  for (int i = 0; i < count ; i++) {
    pinMode(Ateam[i], OUTPUT);
  }
}


void loop() {
  for (int i = 1; i < count; i++) {
    digitalWrite(Ateam[i],HIGH);
    delay(d);
  }
  delay(d);
  for (int i = 0; i < count; i++) {
    digitalWrite(Ateam[i],LOW);
    delay(d);
  }
  delay(d);
  
}
