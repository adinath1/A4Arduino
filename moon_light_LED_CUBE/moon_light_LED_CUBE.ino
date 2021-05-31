int RedPins [] = {53, 49};
int GreenPins [] = {51, 48};
int BluePins [] = {50, 47};

int count = 3;
void setup() {
  for (int y = 0; y < count; y++) {
    pinMode(RedPins[y], OUTPUT);
    pinMode(GreenPins[y], OUTPUT);
    pinMode(BluePins[y], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < count; i++) {
    fadeFromTo(RedPins[i], BluePins[i]);
    fadeFromTo(GreenPins[i], BluePins[i]);

    fadeFromTo(BluePins[i], RedPins[i]);
    fadeFromTo(GreenPins[i], RedPins[i]);

    fadeFromTo(RedPins[i], GreenPins[i]);
    fadeFromTo(BluePins[i], GreenPins[i]);
  }
}

void fadeFromTo(int from, int to) {
  for (int i = 0; i < 255; i++) {
    analogWrite(to, i);
    delay(1);
    analogWrite(from, 255 - i);
    delay(1);
  }
}
