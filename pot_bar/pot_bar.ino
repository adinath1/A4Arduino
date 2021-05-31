int Array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

void glow(int x) {
  for (int i = 1; i <= x; i ++) {
    analogWrite(Array[i], 255);
  }

  for (int i = x; i <= 12; i ++) {
    analogWrite(Array[i], 0);
  }

}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A15, INPUT);
  for (int i = 2; i <= 11; i++) {
    pinMode(Array[i], OUTPUT);
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  int  d = analogRead(A15);
  Serial.println(d);
  switch (d) {
    case 1 ... 200:
      glow(2);
      break;
    case 201 ... 300 :
      glow(3);
      break;
    case 301 ... 400 :
      glow(4);
      break;
    case 401 ... 500 :
      glow(5);
      break;
    case 501 ... 600 :
      glow(6);
      break;
    case 601 ... 700 :
      glow(7);
      break;
    case 701 ... 800 :
      glow(8);
      break;
    case 801 ... 900 :
      glow(9);
      break;
    case 901 ... 1023:
      glow(11);
      break;
  }
}
