#define CW A4 //CW is defined as pin #7//
#define CCW A2 //CCW is defined as pin #8//



void setup() { //Setup runs once//

  pinMode(CW, OUTPUT); //Set CW as an output//
  pinMode(CCW, OUTPUT); //Set CCW as an output// 

}

void loop() { //Loop runs forever//
  digitalWrite(CW,HIGH); //Motor runs clockwise// 
  delay(800);            //for 1 second// 
  digitalWrite(CW, LOW); //Motor stops//
  digitalWrite(CCW, HIGH);//Motor runs counter-clockwise// 
  delay(800);            //For 1 second//
  digitalWrite(CCW, LOW); //Motor stops// 
  }
