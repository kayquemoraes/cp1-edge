#include <math.h>

#define R0 10000 // Resistência do LDR em condições de iluminação de referência
#define A 1.00   // Fator de correção de interceptação
#define B -0.50  // Fator de correção de inclinação

// Porta analógica conectada ao LED_VERDE(3)
#define LED_VERDE 3  
// Porta analógica conectada ao LED_VERMELHO(6)
#define LED_VERMELHO 6 
// Porta analógica conectada ao LED_AMARELO(9)
#define LED_AMARELO 9 
// Porta analógica conectada a Buzina(10)
#define Buzina 10      
// tempo pré estabelecido para facilitar a mudança da variável(Controla o tempo da Buzina 1+tempo ou 0+tempo)
#define Buzina_Tempo 3000 


int LDR_PIN = A0;  // Porta analógica conectada ao LDR

void setup() {
  Serial.begin(9600);  // Inicializa a comunicação serial com taxa de transmissão de 9600 bps(bits por segundo).
  pinMode(LDR_PIN, INPUT); //declaração de uma ENTRADA DE DADOS 
  pinMode(LED_VERDE, OUTPUT);//declaração de uma SAÍDA
  pinMode(LED_VERMELHO, OUTPUT);//declaração de uma SAÍDA
  pinMode(LED_AMARELO, OUTPUT);//declaração de uma SAÍDA
  pinMode(Buzina, OUTPUT);//declaração de uma SAÍDA
}

void loop() {
  
  int LDR_value = analogRead(LDR_PIN);  // Faz a leitura em bits (leitura de 10 bits)
  
  float voltage = LDR_value * (5.0 / 1023.0);  // Converte bits em volts
  float resistance = (5.0 - voltage) * R0 / voltage;  // Calcula a resistência usando a Lei de Ohm
  float lux = pow(10, (log10(resistance/R0) - A) / B);  // Converte a resistência em lux usando a equação matemática

  // Imprime valor da porta analógica em bits
  Serial.print("VALOR DA PORTA A0(bits):");
  Serial.print(LDR_value);
  
  // Imprime o valor da porta já convertida para lux
  Serial.print(" lux:");
  Serial.print(lux);
  
  // Condição para iluminação ideal  
  if(lux >= 10 && lux <= 15){
    
    digitalWrite(LED_VERMELHO, 0);// desliga o LED vermelho
    digitalWrite(LED_AMARELO, 0); // desliga o LED amarelo
    digitalWrite(LED_VERDE, 1); // liga o LED verde
    
    Serial.println(" Status:OK");
  }
  // Condição para iluminação em níveis de alerta
  else if ((lux > 15 && lux <=18) || (lux < 10 && lux >= 7)){
    
    digitalWrite(LED_VERMELHO, 0);// desliga o LED vermelho
    digitalWrite(LED_VERDE, 0); // desliga o LED verde
    digitalWrite(LED_AMARELO, 1); // liga o LED amarelo
    
    Serial.println(" Status: ALERTA");  
  }
  // Condição para iluminação em níveis de problema
  else{
    
    digitalWrite(LED_AMARELO, 0); // desliga o LED amarelo
    digitalWrite(LED_VERDE, 0);// desliga o LED verde
    digitalWrite(LED_VERMELHO, 1); // liga o LED vermelho
    
    Serial.println(" Status: PROBLEMA");
    
    digitalWrite(Buzina, 1);// liga a Buzina
    delay(Buzina_Tempo);// tempo 3s
    digitalWrite(Buzina, 0);// desliga a Buzina
    delay(Buzina_Tempo);// tempo 3s	
  }  
}
