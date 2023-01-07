int red = 7;
int blue = 8;
int sensor = 12;
int acionamento;

void setup() 
{
 pinMode(red, OUTPUT);
 pinMode(blue, OUTPUT);
 pinMode(sensor, INPUT); 
}

void loop() {
  acionamento = digitalRead(sensor);
  if(acionamento == LOW)
  {
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
  }
  else{
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
  }

delay(100);
}
