                                                                                                                                                                                                                                                                                                                                                                                                                                                                     int greenPin = 2;
int bluePin = 3;
int redPin = 4;

int greenPin2 = 5;
int bluePin2 = 6;
int redPin2 = 7;

int greenPin3 = 8;
int bluePin3 = 9;
int redPin3 = 10;

void setup(){
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  
  pinMode(greenPin2, OUTPUT);
  pinMode(bluePin2, OUTPUT);
  pinMode(redPin2, OUTPUT);

  pinMode(greenPin3, OUTPUT);
  pinMode(bluePin3, OUTPUT);
  pinMode(redPin3, OUTPUT);


}

void loop(){
    fadeFromTo(bluePin, greenPin);
    fadeFromTo(bluePin2, greenPin2);
    fadeFromTo(bluePin3, greenPin3);
    
    fadeFromTo(greenPin, redPin);
    fadeFromTo(greenPin2, redPin2);
    fadeFromTo(greenPin3, redPin3);
    
    fadeFromTo(redPin, bluePin);
    fadeFromTo(redPin2, bluePin2);
    fadeFromTo(redPin3, bluePin3);
}

void fadeFromTo(int from, int to){
  for(int i = 0; i < 255; i++){
    analogWrite(to, i);
    delay(1);
    analogWrite(from, 255 - i);
    delay(1);
  }
}
