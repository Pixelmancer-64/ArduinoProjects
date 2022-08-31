float valorSeno;
int valorTom;
int buzzer=8;


void setup() {
  pinMode(buzzer, OUTPUT);

}

void loop() {
  for(int x=0; x<180; x++)
  {
    valorSeno=(sin(x*3.1416/180));
    valorTom = 3000* (int(valorSeno*1000));
    tone(buzzer, valorTom);
    delay(20);
  }

}
