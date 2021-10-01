void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(0));
}

void loop() {
  Serial.print("printing a random number up to 1000: ");
  Serial.println(random(1000));
  Serial.print("printing a random number between 5 and 10: ");
  Serial.println(random(5, 10));
  delay(1000);
}
