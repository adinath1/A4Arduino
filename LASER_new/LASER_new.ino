#define T_C 993
#define T_D 495


//PINS FOR LDRs
const int LDR = A0;
const int LDR2 = A1;

//reading data frpm ldr
int input_val = 0;
int input_val2 = 0;

//we need two speakers
int speaker_pin = 2;
int speaker_pin2 = 4;

void setup()
{
  Serial.begin(9600);  //just to print to troubleshoot.
}

void loop()
{
  input_val = analogRead(LDR);
  input_val2 = analogRead(LDR2);
  Serial.print("LDR Value is: ");
  Serial.print("LDR2 Value is: ");
  Serial.println(input_val);
  Serial.println(input_val2);
  delay(2);
  
  if (input_val < 600) {
    tone(speaker_pin, T_C);
  }
  else {
    noTone(speaker_pin);
  }

  if (input_val2 < 600) {
    tone(speaker_pin2, T_D);
  }
  else {
    noTone(speaker_pin2);
  }
}
