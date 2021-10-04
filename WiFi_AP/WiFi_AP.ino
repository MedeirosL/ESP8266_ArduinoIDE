#include <ESP8266WiFi.h>

#define APSSID "XXXXXXXXXXXXXX"
#define APPASS "12345678"

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.print("Setting soft-AP network...");
  WiFi.softAP(APSSID, APPASS);
  Serial.println("Ok!");
}

void loop()
{
  if(WiFi.softAPgetStationNum()>0){
    Serial.print("Stations connected: ");
    Serial.println(WiFi.softAPgetStationNum());
  }
  delay(1000);
}
