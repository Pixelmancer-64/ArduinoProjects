#include <LiquidCrystal.h>

// Define as conexões e cria o objeto para acesso
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
const int backLight = 10;
float temp;
int x = 0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
// Limites para detecção das teclas, em ordem crescente
struct {
  int limite;
  char *nome;
} teclas[] = {
  {   50, "Direita " },
  {  150, "Cima    " },
  {  350, "Baixo   " },
  {  500, "Esquerda" },
  {  750, "Select  " },
  { 1024, "        " }  // nenhuma tecla apertada
};

const char* colour[4]
        = { "Blue", "Red", "Orange", "Yellow" };
 
// Iniciação
void setup() {
  //Progama o pino de backlight como saída
  pinMode(backLight, OUTPUT);
  // Inicia o display e coloca uma mensagem
  lcd.begin(16, 2);
  Serial.begin(9600);

  // Acende o backlight
  digitalWrite(backLight, HIGH);
}
 
// Laço principal
void loop() {
  lcd.clear();
  static int teclaAnt = -1;   // última tecla detectada
 
  // Lê a tensão no pino A0
  int leitura = analogRead(A0);
 
  // Identifica a tecla apertada pela tensão lida
  int teclaNova;
  for (teclaNova = 0; ; teclaNova++) {
    if (leitura < teclas[teclaNova].limite) {
      break;
    }
  }

  Serial.println(teclaNova);
  if(teclaNova == 0){
    x += 1;
  } else if(teclaNova == 3){
    x -= 1 ;
  }
 
  // Atualiza a tela se pressionou uma nova tecla
  if (teclaNova != teclaAnt) {
    lcd.setCursor(0,1);
    lcd.print(teclas[teclaNova].nome);
    teclaAnt = teclaNova;
  }


   lcd.setCursor(x, 0);
   temp = (float(analogRead(A1)) * 5/(1023))/0.01 + 273,15;
   lcd.print(String("Kelvin: " + String(round(temp))));
   
  // Dá um tempo antes do próximo teste
  delay (500);
}
