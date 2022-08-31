// C++ code
//
const int buzzer = 13;
const int button = 2;
const int sendButton = 8;
volatile byte state = LOW;
int toStart;
String letra;
String resultado;
      
void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(sendButton, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(button), blink, CHANGE);
}

void loop()
{
  if(!digitalRead(sendButton) == LOW){
   Serial.println(letra); 
    
  if(letra == ".-") resultado += "A";
  	else if(letra == "-...")resultado += "B";
    else if(letra == "-.-.")resultado += "C";
    else if(letra == "-..")resultado += "D";
    else if(letra == ".")resultado += "E";
    else if(letra == "..-.")resultado += "F";
    else if(letra == "--.")resultado += "G";
  	else if(letra == "....")resultado += "H";
  	else if(letra == "..")resultado += "I";
  	else if(letra == ".---")resultado += "J";
  	else if(letra == "-.-")resultado += "K";
    else if(letra == ".-..")resultado += "L";
    else if(letra == "--")resultado += "M";
    else if(letra == "-.")resultado += "N";
    else if(letra == "---")resultado += "O";
    else if(letra == ".--.")resultado += "P";
    else if(letra == "--.-")resultado += "Q";
    else if(letra == ".-.")resultado += "R";  
    else if(letra == "...")resultado += "S";
    else if(letra == "-")resultado += "T";
    else if(letra == "..-")resultado += "U";
    else if(letra == "...-")resultado += "V";
    else if(letra == ".--")resultado += "W";
    else if(letra == "-..-")resultado += "X";
  	else if(letra == "-.--")resultado += "Y";
  	else if(letra == "--..")resultado += "Z";
  	else if(letra == ".----")resultado += "1";
  	else if(letra == "..---")resultado += "2";
    else if(letra == "...--")resultado += "3";
    else if(letra == "....-")resultado += "4";
    else if(letra == ".....")resultado += "5";
    else if(letra == "-....")resultado += "6";
    else if(letra == "--...")resultado += "7";
    else if(letra == "---..")resultado += "8";
    else if(letra == "----.")resultado += "9";
  	else if(letra == "-----")resultado += "0";
    else resultado = "?";
    
    Serial.println(resultado);
    letra = "";
    delay(1000);
  }
	
}


void blink(){
 state = !state;
  
  if(state){
   toStart = millis();
  }
  else{
  	int interval = millis() - toStart;
    
    if(interval < 500){
     tone(buzzer, 330, 100);
      letra = letra + ".";
    }
    else{
    	tone(buzzer, 1596, 200);
      	letra = letra + "-";
    }
  }
}