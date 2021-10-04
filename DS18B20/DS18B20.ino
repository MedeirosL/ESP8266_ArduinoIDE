#include <OneWire.h>  
#include <DallasTemperature.h>

#define DATAPIN D1

OneWire oneWire(DATAPIN);  
DallasTemperature sensors(&oneWire);  

void setup(void){ 
  Serial.begin(115200); 
  sensors.begin(); 
}

void loop(void){ 
  Serial.print("Reading Temperature... "); 
  sensors.requestTemperatures(); 
  Serial.println("Done!");  
  Serial.print("Celsius: "); 
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print("\tFahrenheit: "); 
  Serial.println(sensors.getTempFByIndex(0)); 
}
