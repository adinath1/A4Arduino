const int hot = 30; //set hot parameter
const int cold = 75; //set cold parameter
void setup() {
pinMode(A2, INPUT); //sensor
pinMode(2, OUTPUT); //blue
pinMode(3, OUTPUT); //green
pinMode(3, OUTPUT); //red
Serial.begin(9600);
}
void loop() {
int sensor = analogRead(A2);
float voltage = (sensor / 1023.0) * 5000;
float tempC = (voltage/10);
float tempF = (tempC * 1.8) + 32;
Serial.print("temp: ");
Serial.println(tempC);
if (tempC >= hot) { //hot
analogWrite(A5, 255);
analogWrite(A4, 0);
delay(100);
Serial.println(" It's Hot.");
}
else { //fine
analogWrite(A5, 0);
analogWrite(A4, 255);
delay(100);
Serial.println(" It's Fine.");
}

delay(1000);
}
