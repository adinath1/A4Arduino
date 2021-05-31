#define T_H 500
int val=0;
int val2=0;
int Buzz=53;
int le[]={0,0,0};
int sp[]={0,0,0}; 
void setup() {
  pinMode(A15,INPUT);
  pinMode(A14,INPUT);
  pinMode(Buzz,OUTPUT);
  pinMode(51,OUTPUT);
  Serial.begin(9600);
  }

void loop() {
   //Serial.println(le[0]);
   //Serial.println(le[1]);
   //Serial.println(le[2]);
   val=analogRead(A14); //LED
   val2=analogRead(A15); //BUZZER
   if (le[2]==4){  //if LED array is full, then switch on LED & MAKE LED array 0,0,0
    digitalWrite(51,HIGH);
    le[0]=0;
    le[1]=0;
    le[2]=0;
  }
   if (sp[2]==5){  // is SPEAKER array is full, then switch on SPEAKER with toneH
    tone(Buzz,T_H);
    digitalWrite(51,LOW);
    sp[0]=0;
    sp[1]=0;
    sp[2]=0;
   }
   if (val > 1000);
   {
    Serial.println("PUSHED");
   }
   /*
   if (val > 500 && le[0] == 0 &&  le[1] == 0 &&  le[2] == 0  )
   {
    Serial.println("PUSHED1");
    le[0] = 4 ;
   }
   if (val > 500 && le[0] == 4 &&  le[1] == 0 &&  le[2] == 0  )
   {
    Serial.println("PUSHED2");
    le[1] = 4 ;
   }
   if (val > 500 && le[0] == 4 &&  le[1] == 4 &&  le[2] == 0  )
   {
    Serial.println("PUSHED3");
    le[2] = 4 ;
   }*/
   
 }
