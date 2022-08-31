int verde = 13;
int amarelo = 12;
int vermelho = 11;
int semaforoR = 5;
int semaforoG = 4;
int button = 2;
int buttonLed = 7;

int isPressedButton = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(semaforoR, OUTPUT);
  pinMode(semaforoG, OUTPUT);
  pinMode(button, INPUT);
  pinMode(buttonLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly
  //turnOn(buttonLed);
  isPressedButton = digitalRead(button);
  if(isPressedButton == HIGH){
    delay(2000);
    turnOff(verde);
  setInterval(amarelo, 3000);
  turnOn(semaforoG);
  turnOff(semaforoR);
  setInterval(vermelho, 5000);
  turnOff(semaforoG);
  

  } else {
    turnOn(verde);
    turnOn(semaforoR);
  }
  /*
  turnOn(semaforoR);
  setInterval(verde, 5000);
  setInterval(amarelo, 2000);
  turnOff(semaforoR);
  turnOn(semaforoG);
  setInterval(vermelho, 3500);
  turnOff(semaforoG);*/
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

