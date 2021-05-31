int myArray [] = {19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
int count = 19;
int delay1 = 50;
void setup() {
  for (int i = 2; i <= 8; i++)
  {
    pinMode(myArray[i], OUTPUT);
  }
}
void loop() {
  for (int i = 0; i < count; i++)
  {
    analogWrite(myArray[i], 255);
    delay(delay1);
  }
  for (int i = count; i >= 0; i--)
  {
    analogWrite(myArray[i], 0);
    delay(delay1);
  }
}
