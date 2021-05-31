#define T_A 490
//array
int Speakers = 3;

void setup() {
  for (int i = 0; i <= 60; i++) {
    pinMode(Speakers, OUTPUT);
    Serial.begin(9600);
  }

}
void loop() {
  for (int i = 0; i <= 1; i++) {
    tone(Speakers, T_A);
    Serial.println(T_A);
    delay(100);
    noTone(Speakers);
    Serial.println(0);

  }

}
