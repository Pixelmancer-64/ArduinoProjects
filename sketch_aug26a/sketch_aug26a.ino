#include <Ultrasonic.h>

Ultrasonic ultrasom(8, 7);
long cm;
int ledVermelho=4;
int ledAmarelo=3;
int ledVerde=2;
void setup(){
  Serial.begin(9600);
   pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}
void loop(){
  cm = ultrasom.Ranging(CM);
  Serial.print(cm);
  Serial.println(" cm");
  delay(100);
  if(cm>80){
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  }
  else if(cm<=80 && cm>=50){
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
  }
 else  if(cm>=10 || cm<=49){
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, HIGH);
  }
}

