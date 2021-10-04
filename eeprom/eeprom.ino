#include <EEPROM.h>
#include <stdio.h>
#include <stdlib.h>

char byteValue = 0;

char randomGen(int min, int max){ //different way to generate a random number
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void setup(){
  Serial.begin(115200); 
  Serial.println();
  EEPROM.begin(4096);//Start memory with *parameter* bytes. minumium: 4, maximum 4096
  delay(200);
  
}

void loop(){
  for(int j=0;j<10;j++){
    Serial.println("data stored before de insertion: ");  //read the byte saved in the position 
    for (int i=0;i<10;i++){
      Serial.print(EEPROM.read(i)); //read the byte saved in the position "i"
      Serial.print("\t");
      delay(200);   //for viewing only. not necessary
    }
    Serial.println();
  
    Serial.println("Inserting new random data...");
    for (int i=0;i<10;i++){
      char toSave = randomGen(0,255);
      EEPROM.write(i, toSave); //insert a new random byte in position "i"
    }
    EEPROM.commit();//after writing, you need to commit the data
    Serial.println("Done!");
    
    Serial.println("new data stored: ");  //read the byte saved in the position 
    for (int i=0;i<10;i++){
      Serial.print(EEPROM.read(i)); //read the byte saved in the position "i"
      Serial.print("\t");
      delay(200);   //for viewing only. not necessary
    }
    Serial.println();
    //EEPROM.end();//Close memory if you need

    Serial.println("Restarting loop in 3 seconds..\n\n\n");  
    delay(3000);
  }
}
