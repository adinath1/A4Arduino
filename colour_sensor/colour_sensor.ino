#define S0 53
#define S1 51
#define S2 47
#define S3 45
#define sensorOut 49


int frequency = 0;
int color=0;

void setup() {

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  Serial.begin(9600);
}

void loop() {
  delay(500);
  
  color = readColor();
  //Serial.println("debugging");
  //Serial.println(color);
  delay(10);
  
  switch (color) {
    case 1:
     Serial.println("RED");
    break;

    case 2:
     Serial.println("ORANGE");
    break;

    case 3:
     Serial.println("GREEN");
    break;

    case 4:
     Serial.println("YELLOW");
    break;

    case 5:
     Serial.println("BROWN");
    break;

    case 6:
     Serial.println("BLUE");
    break;
    
    case 0:
    break;
  }
  delay(300);
  //color = 0;
}

// Custom Function - readColor()
int readColor() {
  //Serial.println("HELLO");
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  // Printing the value on the serial monitor
  Serial.print("R =>  ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  // Printing the value on the serial monitor
  Serial.print("G =>  ");//printing name
  Serial.print(frequency);//printing RED color frequency
 Serial.print("  ");
  delay(50);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  // Printing the value on the serial monitor
  Serial.print("B =>  ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");
  delay(50);
  
  
  if(R<45 & R>32 & G<65 & G>55){
    color = 1; // Red
    Serial.println(" RED ");
  }
  if(G<55 & G>43 & B<47 &B>35){
    color = 2; // Orange
    Serial.println("ORANGE");
  }
  if(R<53 & R>40 & G<53 & G>40){
    color = 3; // Green
    Serial.println("GREEN");
  }
  if(R<38 & R>24 & G<44 & G>30){
    color = 4; // Yellow
    Serial.println("YELLOW");
  }
  if(R<56 & R>46 & G<65 & G>55){
    color = 5; // Brown
    Serial.println("BROWN");
  }
  if (G<58 & G>45 & B<40 &B>26){
    color = 6; // Blue
    Serial.println("BLUE");
  }
  return color;  
}
