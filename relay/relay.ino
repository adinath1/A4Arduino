// defines pins numbers


// defines variables

int d = 30000;


void setup() {
pinMode(2,OUTPUT); 
pinMode(3,OUTPUT); 
Serial.begin(9600);
}

void loop() {
fanOn();
}

void fanOn()
{
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
delay(d);
digitalWrite(3,LOW);
digitalWrite(2,HIGH);
delay(d);  
}
