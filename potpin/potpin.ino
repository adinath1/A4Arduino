int frog = 0;
int good = 0;
int zoo = 0;
int wall = 0;
int fall = 0;
int girl = 0;
int zero = 0;
int will = 0;
int cat = 0;
int uno = 0;
int aji = 0;
int ball = 0;
int dev = 0;
int elephant = 0;
int yank = 0;
int x = 0;
int f = 0;
int w = 0;
int c = 0;
int u = 0;
int g=0;
int a = 0;
int b = 0;
int d = 0;
int e = 0;
int y = 0;
int z = 0;
int potPin = A5;    // select the input pin for the potentiometer
int val = 0;       // variable to store the value coming from the sensor
int hatl = 0;
void setup() {
  Serial.begin(9600);
  }


void loop() {
  val = analogRead(potPin);    // read the value from the sensor
  hatl=val+10;
  x=val+35;
  y=val+45;
  d=val+10;
  e=val+65;
  a=val+75;
  b=val+90;  
  c=val+25;
  u=val+15;  
  z=val+95;
  w=val+85;  
  f=val+98;
  g=val+88;  
  cat=val+42;
  uno=val+23;
  frog=g+21;
  good=w+17;
  Serial.print(hatl);
  Serial.print(",");
  Serial.print(val); 
  Serial.print(",");
  Serial.print(y);
  Serial.print(",");
  Serial.print(x);
  Serial.print(",");
  Serial.print(e);
  Serial.print(",");
  Serial.print(d);
  Serial.print(",");
  Serial.print(a);
  Serial.print(",");
  Serial.print(b); 
  Serial.print(",");
  Serial.print(c);
  Serial.print(",");
  Serial.print(u);   
  Serial.print(",");
  Serial.print(w);
  Serial.print(",");
  Serial.print(z);   
  Serial.print(",");
  Serial.print(g);
  Serial.print(",");
  Serial.print(f);     
  Serial.print(",");
  Serial.print(uno);   
  Serial.print(",");
  Serial.print(cat);
  Serial.print(",");
  Serial.print(frog);   
  Serial.print(",");
  Serial.println(good);
  
  
  }
  
