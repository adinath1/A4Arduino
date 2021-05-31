int myArray [] = {2, 3};
int count = 2;
int d1 = 2000;
void setup() {
  for (int i = 0; i <= 3; i++)
  {
    pinMode(myArray[i], OUTPUT);
  }

}

void loop() {
  for (int i = 0; i < count; i++)
  {
    delay(d1);
    analogWrite(myArray[i], 255);
    delay(d1);
    analogWrite(myArray[i], 0);
    delay(d1);



  }
}
