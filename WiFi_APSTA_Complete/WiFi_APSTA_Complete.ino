#include <ESP8266WiFi.h>
 
 
#define APSSID "XXXXXXXXXXXXXX"
#define APPASS "12345678"
#define APCHANNEL 1
#define APHIDDEN false
#define APMAXCON 8

#define WIFISSID "XXXXXXXXXXXXXX"
#define WIFIPASS "XXXXXXXXXXXXXX"

IPAddress local_IP_AP(192,168,4,123);
IPAddress gateway_AP(192,168,4,9);
IPAddress subnet_AP(255,255,255,0);

IPAddress staticIP_STA(192,168,1,200);
IPAddress gateway_STA(192,168,1,1);
IPAddress subnet_STA(255,255,255,0);


 
void setup(){
  unsigned int timeLimit = 10000;
  Serial.begin(115200);
  Serial.println();
  //soft-AP static config
  WiFi.mode(WIFI_AP_STA);
  Serial.print("Setting soft-AP network...");
  WiFi.softAPConfig(local_IP_AP, gateway_AP, subnet_AP); 
  WiFi.softAP(APSSID, APPASS, APCHANNEL, APHIDDEN, APMAXCON);
  Serial.println("Ok!");
  Serial.print("Soft-AP IP address: ");
  Serial.println(WiFi.softAPIP());
  //WiFi static config
  WiFi.config(staticIP_STA, gateway_STA, subnet_STA);
  WiFi.begin(WIFISSID, WIFIPASS);
  Serial.print("\nConnecting to ");
  Serial.print(WIFISSID);
  while (WiFi.status() != WL_CONNECTED && millis() < timeLimit){ //trying to connect
    delay(250);
    Serial.print(".");
  }
  Serial.println();
  if(WiFi.status() == WL_CONNECTED){
    Serial.print("Connected! IP address: ");
    Serial.println(WiFi.localIP());
  }
  else{
    Serial.print("Failed to connect. Restarting device...");
    ESP.restart();
  }
}
 
void loop() {
  if(WiFi.softAPgetStationNum()>0){
    Serial.print("Stations connected: ");
    Serial.println(WiFi.softAPgetStationNum());
  }
  delay(1000);
  
}
