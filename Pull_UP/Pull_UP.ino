const int btn_pin = A0;
const int led_pin = 6;

int btn_prev;
  
void setup() {
  // put your setup code here, to run once:
pinMode(btn_pin,INPUT_PULLUP);
pinMode(led_pin,OUTPUT);
digitalWrite(led_pin,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
int btn_state;

btn_state = digitalRead(btn_pin);

if (( btn_prev == LOW )&& (btn_state == HIGH)){
  digitalWrite(led_pin,HIGH);
  delay(500);
  digitalWrite(led_pin,LOW);
  }
  btn_prev = btn_state;
}
