int A=0;
int V=0;
void setup() {
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

void loop() {
 A=analogRead(A1); 
 V=analogRead(A2);
 Serial.println(A); 
 Serial.println(V);
}
