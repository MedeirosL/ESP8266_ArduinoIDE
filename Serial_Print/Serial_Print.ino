void setup() {
  Serial.begin(115200);
}

void loop() {
  int i=0;
  Serial.println("Counting to 10..."); //print the info and start a new line (\n)
  for(i=1;i<10;i++){
    Serial.print(i);    //print the info and continue in the same line
    Serial.print(", "); //print the info and continue in the same line
    delay(500);
  }
  Serial.println(i);  //print the info and start a new line (\n)
  Serial.println("Restarting count in 2 sec");  //print the info and start a new line (\n)
  delay(2000);
}
