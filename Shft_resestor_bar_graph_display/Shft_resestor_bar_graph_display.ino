// The setup function runs once when you press reset or power the board

volatile int i=0;

void setup()

{

                pinMode(2, OUTPUT);   // sets the pin2 as output

                pinMode(1, OUTPUT); // sets the pin1 as output

                pinMode(0, OUTPUT); // sets the pin0 as output

}

void loop()

{

                for (int i=0;i<255;i++) //if binary count is less than 255

                {

                                digitalWrite(2,HIGH);

                                shiftOut(0,1,2,i); //send eight bit data serially for each time there is a increment

                                digitalWrite(2,LOW);

                                delay(500); //wait for half a second

                }             

}
