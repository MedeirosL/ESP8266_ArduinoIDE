#define LED     LED_BUILTIN
#define BUTTON  D1   //GPIO5 or 5

int buttonState = 0;        

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  digitalWrite(LED,!digitalRead(BUTTON));
}
