#include <OneWire.h>  
#include <DallasTemperature.h>

#define DATAPIN D1                //DS18B20 data pin
#define TEMPERATURE_RESOLUTION 12  // 9~12

OneWire oneWire(DATAPIN);             //1Wire Object
DallasTemperature sensors(&oneWire);  //Datas Temperature Library Object
DeviceAddress tempDeviceAddress;      //Temporary Addressing Object

int numberOfDevices = 0;

void setup(void){ 
  Serial.begin(115200); 
  sensors.begin();
  numberOfDevices = sensors.getDeviceCount(); //return the number of sensors connected to the pin
  Serial.print("Searching devices addresses...");
  Serial.print("Found ");
  Serial.print(numberOfDevices, DEC);
  Serial.println(" devices!");

  for(int i=0;i<numberOfDevices; i++) {      
    if(sensors.getAddress(tempDeviceAddress, i)) {
      Serial.print("Device ");
      Serial.print(i, DEC);
      Serial.print(", address: ");
      printAddress(tempDeviceAddress);   //print the address of each sensor
      Serial.println();

      Serial.print("Setting resolution to ");
      Serial.println(TEMPERATURE_RESOLUTION, DEC);
      sensors.setResolution(tempDeviceAddress, TEMPERATURE_RESOLUTION); //set the sensor resolution
    }
  }
}

void loop(void){ 
  if(numberOfDevices>0){
    Serial.print("Reading Temperatures... "); 
    sensors.requestTemperatures();   //Request all sensors temperatures
    Serial.println("Done!");  
  }
  else{
    Serial.println("No sensor availabe"); 
    delay(1000);
  }
  for(int i=0;i<numberOfDevices; i++) {
    if(sensors.getAddress(tempDeviceAddress, i)) {
      Serial.print("Temperature for device: ");
      Serial.println(i,DEC);
      Serial.print("Temp C: ");
      Serial.print(sensors.getTempC(tempDeviceAddress));  //You can run the code almost 2 times faster using just one temperature scale
      Serial.print(" Temp F: ");
      Serial.print(sensors.getTempF(tempDeviceAddress));
    } 
  }
}

void printAddress(DeviceAddress deviceAddress){
  for (uint8_t i = 0; i < 8; i++)
  {
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}
