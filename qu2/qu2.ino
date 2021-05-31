void setup() {
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
for (int i=1;i<=20;i++)
{
 Serial.println(i);
 delay(300);
}
}
