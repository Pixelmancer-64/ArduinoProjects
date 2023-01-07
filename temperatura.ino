#include <dhtnew.h>

DHTNEW mySensor(5);

//Sensor de temperatura usando o LM35

float temperatura;
  
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 temperatura = (float(analogRead(LM35)) * 5/(1023))/0.01;
 Serial.print("Temperatura: ");
 Serial.println(temperatura);
 delay(2000);

 
}
