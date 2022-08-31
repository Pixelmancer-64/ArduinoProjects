#include <Ultrasonic.h>
int apitinho = 12;
Ultrasonic ultrassom(8,7);
long distancia;

void setup() {
  pinMode(apitinho, OUTPUT);
  Serial.begin(9600);
}



void loop() {
  // put your main code here, to run repeatedly:
  distancia = ultrassom.Ranging(CM);

  if(distancia<10)
  {
    tone(apitinho, 440, 200);
    delay(500);
    tone(apitinho, 440, 200);
  }

  Serial.print(distancia);
  Serial.println("cm");
  delay(100);
}
