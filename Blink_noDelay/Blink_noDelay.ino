#define LED   LED_BUILTIN

unsigned long lastMillis = 0;
unsigned long currentMillis = 0;
int interval = 1000; //milliseconds

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  currentMillis = millis();
  if (currentMillis - lastMillis >= interval) { //check millis
    lastMillis = currentMillis;   //update lastMillis value
    Serial.print("Changing LED level. Last millis value: ");
    Serial.println(lastMillis);   //just to check the methode
    digitalWrite(LED,!digitalRead(LED));  //Change LED digital level
  }
}
