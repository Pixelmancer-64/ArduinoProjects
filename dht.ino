#include <dhtnew.h>

DHTNEW mySensor(A1);
uint32_t timer = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  if(millis() - timer >= 2000){
    mySensor.read();

    Serial.print(mySensor.getHumidity());
    Serial.println(" %");

     Serial.print(mySensor.getTemperature());
    Serial.println(" Celcius");


    timer = millis();
  }
}

