#define SCL A5
#define SDO A4
byte Key;

byte Read_TTP229_Keypad(void)
{
 byte Num;
 byte Key_State = 0;
 for(Num = 1; Num <= 16; Num++)
 {
   digitalWrite(SCL, LOW);
   if (!digitalRead(SDO))
     Key_State = Num;
     digitalWrite(SCL, HIGH);
 } 
 return Key_State;
}

void setup()
{
 Serial.begin(9600);
 pinMode(SCL, OUTPUT); 
 pinMode(SDO, INPUT);
}

void loop()
{
 Key = Read_TTP229_Keypad();
 if (Key)
 Serial.println(Key);
 delay(1000);
}
