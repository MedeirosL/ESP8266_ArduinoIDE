#include <ESP8266WiFi.h>

#define APSSID "XXXXXXXXXXXXXX"
#define APPASS "12345678"
#define APCHANNEL 1
#define APHIDDEN false
#define APMAXCON 8

IPAddress local_IP(192,168,4,22);
IPAddress gateway(192,168,4,9);
IPAddress subnet(255,255,255,0);

void setup(){
  Serial.begin(115200);
  Serial.println();
  Serial.print("Setting soft-AP network...");
  WiFi.softAPConfig(local_IP, gateway, subnet);
  WiFi.softAP(APSSID, APPASS, APCHANNEL, APHIDDEN, APMAXCON);
  Serial.println("Ok!");
  Serial.print("Soft-AP IP address: ");
  Serial.println(WiFi.softAPIP());
}

void loop(){
  if(WiFi.softAPgetStationNum()>0){
    Serial.print("Stations connected: ");
    Serial.println(WiFi.softAPgetStationNum());
  }
  delay(1000);
}
