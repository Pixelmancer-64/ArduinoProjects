int verde = 13;
int amarelo = 12;
int vermelho = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly

  setInterval(verde, 5000);
  setInterval(amarelo, 2000);
 

  setInterval(vermelho, 3500);

}

void setInterval(int porta, int interval){
  turnOn(porta);
  delay(interval);
  turnOff(porta);
}

void turnOn(int porta){
  digitalWrite(porta, HIGH);
}

void turnOff(int porta){
  digitalWrite(porta, LOW);
}

