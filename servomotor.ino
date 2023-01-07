#include <Servo.h>
#define SERVO 6
Servo servo1;
int pos;
const int buttonPin = 2; 
int i = 5;
void setup() 
{
    pinMode(buttonPin, INPUT);
  servo1.attach(SERVO);
  Serial.begin(9600);
  servo1.write(0);  
}

void loop() 
{

   int buttonState = digitalRead(buttonPin);
   if (buttonState == HIGH) {
    pos += i;
    
    if(pos >= 180 || pos <= 0){i *= -1;}-
    
    Serial.println(pos);
    servo1.write(pos);
    delay(15);
  }

  /*
  for(pos = 0; pos < 90; pos++)
  {
    Serial.println(pos);
    servo1.write(pos);
    delay(15);
  }

  delay(1000);
  
  for(pos = 90; pos >= 0; pos--)
  {
    servo1.write(pos);
    delay(15);
  }*/

}
