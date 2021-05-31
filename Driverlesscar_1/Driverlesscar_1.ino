#define IN1 2 //WHEEL-2  
#define IN2 3 //WHEEL-2  
#define IN3 4 //WHEEL-1  
#define IN4 5 //WHEEL-1  
#define IN5 6 //WHEEL-3
#define IN6 7 //WHEEL-3
#define IN7 8 //WHEEL-4
#define IN8 9 //WHEEL-4

// defines pins numbers
const int trigPin = A0;
const int echoPin = A1;

// defines variables
long duration;
int distance;

void setup() {  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  pinMode(IN1, OUTPUT);  
  pinMode(IN2, OUTPUT);  
  pinMode(IN3, OUTPUT);  
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);  
  pinMode(IN6, OUTPUT);  
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);  
}
void stopping(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  digitalWrite(IN5,LOW);
  digitalWrite(IN6,LOW);
  digitalWrite(IN7,LOW);
  digitalWrite(IN8,LOW);
  }
void straight(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  digitalWrite(IN5,LOW);
  digitalWrite(IN6,HIGH);
  digitalWrite(IN7,LOW);
  digitalWrite(IN8,HIGH); 
}

void left(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  digitalWrite(IN5,LOW);
  digitalWrite(IN6,LOW);
  digitalWrite(IN7,LOW);
  digitalWrite(IN8,LOW); 
}
void right(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  digitalWrite(IN5,LOW);
  digitalWrite(IN6,HIGH);
  digitalWrite(IN7,LOW);
  digitalWrite(IN8,HIGH); 
}
void loop(){
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance < 20)
  {
  left();
  delay(1000);
  straight();
  }
  else
  {
  straight();
  }
}
