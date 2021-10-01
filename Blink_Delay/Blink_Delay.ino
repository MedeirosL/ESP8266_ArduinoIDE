#define LED   LED_BUILTIN

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  Serial.println("LED turned ON");
  delay(1000);
  digitalWrite(LED, LOW);
  Serial.println("LED turned OFF");
  delay(1000);
}
