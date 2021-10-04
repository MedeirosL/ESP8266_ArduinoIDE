#include <ESP8266WiFi.h>
 
#define WIFISSID "XXXXXXXXXXXXXX"
#define WIFIPASS "XXXXXXXXXXXXXX"

IPAddress staticIP(192,168,1,200);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);
  
void setup() {
  unsigned int timeLimit = 10000;
  Serial.begin(115200);
  WiFi.config(staticIP, gateway, subnet);
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
  yield();
  
}
