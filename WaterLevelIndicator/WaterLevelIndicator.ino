int water1 = A8;
int water2 = A9;
int water3 = A10;
int val1 = 0;
int val2 = 0;
int val3 = 0;


void setup() {
  pinMode(water1,INPUT);
  pinMode(water2,INPUT);
  pinMode(water3,INPUT);
  
  Serial.begin(9600);
}

void loop() {
 val1 = analogRead(water1);
 val2 = analogRead(water2);
 val3 = analogRead(water3);

 if (val1 > 1000 && val2 < 1000 && val3 < 1000){
  Serial.println("val1"); 
 }
 if (val1 > 1000 && val2 > 1000 && val3 < 1000){
  Serial.println("val2"); 
 }
 if (val1 > 1000 && val2 > 1000 && val3 > 1000){
  Serial.println("val3"); 
 }
}
