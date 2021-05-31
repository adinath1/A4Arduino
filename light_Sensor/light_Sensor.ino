 //Define variables for AnalogReadPin, RedledPin
int inputpin=A7;
int outputpin=53;

// Define a integer value for data which is read from AnalogReadPin

int data;

void setup() {

//pinModes for RedledPin and AnalogReadPin
pinMode(inputpin,INPUT);
pinMode(outputpin,OUTPUT);
Serial.begin(9600);
}
void loop() {
//AnalogRead the Data input from AnalogReadPin
data=analogRead(A7);
//Print the Data in Serial.println
Serial.println(data);


}
