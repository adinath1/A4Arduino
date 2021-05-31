//Robo India tutorial on Controlling Arduino with Android
//https://www.roboindia.com/tutorials/
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position


#include <SoftwareSerial.h>

SoftwareSerial mySerial(7, 8); // RX, TX

String BT_input;                          // to store input character received via BT.
int LED = 13;                              // device to control

// Define Motor Pin
const int Motor_L_F = 2;
const int Motor_L_B = 3;
const int Motor_R_F = 4;
const int Motor_R_B = 5;

void setup()
{
  myservo.attach(9);
  Serial.begin(9600);                      //default baud rate of module
  mySerial.begin(9600);
  pinMode(LED, OUTPUT);
  while (!Serial)
  {
    // wait for serial port to connect. Needed for native USB port only
  }
}

void loop()

{
  if (mySerial.available())
  {
    BT_input = mySerial.read();   // read input string from bluetooth
    Serial.println(BT_input);
    if (BT_input == "1")
    {
      //for (pos = 180; pos >= 0; pos -= 1) { 
        myservo.write(0);
       // delay(10);
      //}
      Forward();
    }
    if (BT_input == "2")
    {
      Right();
    }
    if (BT_input == "3")
    {
      Left();
    }
    if (BT_input == "4")
    {
      Back();
    }

    if (BT_input == "5")
    {
      Stop();
    }
    if (BT_input == "6")
    {
      Serial.println("SERVO");
      for (pos = 0; pos <= 180; pos += 1) { 
        myservo.write(pos);
        delay(10);
      }
    }
  }

 }


  void Forward() {
    // Run Left Motor In Forward Direction
    digitalWrite(Motor_L_F, HIGH);
    digitalWrite(Motor_L_B, LOW);

    //Run Right Motor in Forward Direction
    digitalWrite(Motor_R_F, HIGH);
    digitalWrite(Motor_R_B, LOW);

  }

  void Right() {
    //Stop Right Motor
    digitalWrite(Motor_R_F, LOW);
    digitalWrite(Motor_R_B, HIGH);

    //Run Left Motor in Forward Direction
    digitalWrite(Motor_L_F, HIGH);
    digitalWrite(Motor_L_B, LOW);

  }

  void Left() {
    //Stop Left Motor
    digitalWrite(Motor_L_F, LOW);
    digitalWrite(Motor_L_B, HIGH);

    //Run Right Motor in Forward Direction
    digitalWrite(Motor_R_F, HIGH);
    digitalWrite(Motor_R_B, LOW);

  }

  void Back() {
    // Run Left Motor In Forward Direction
    digitalWrite(Motor_L_F, LOW);
    digitalWrite(Motor_L_B, HIGH);

    //Run Right Motor in Forward Direction
    digitalWrite(Motor_R_F, LOW);
    digitalWrite(Motor_R_B, HIGH);

  }


  void Stop() {
    // Run Left Motor In Forward Direction
    digitalWrite(Motor_L_F, LOW);
    digitalWrite(Motor_L_B, LOW);

    //Run Right Motor in Forward Direction
    digitalWrite(Motor_R_F, LOW);
    digitalWrite(Motor_R_B, LOW);

  }
