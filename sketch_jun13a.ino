int numero;
int vetor[] = {3,4,5,6,7,8,9,10};

void setup(){
  Serial.begin(9600);
  for(int i = 0; i < 8; i++){
    pinMode(vetor[i], OUTPUT);
  }
}

void loop(){
  if(Serial.available() > 0){
    numero = Serial.parseInt();
    Serial.print("Decimal: ");
    Serial.println(numero, DEC);
    Serial.print("Binario: ");
    Serial.println(numero, BIN);
    for(int i = 0; i < 8; i++){
      digitalWrite(vetor[i], bitRead(numero, i));
    }
    delay(500);
  }
  
}

