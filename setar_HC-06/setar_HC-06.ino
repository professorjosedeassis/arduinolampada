/*
  Setar módulo bluetooth HC-06
  @author Professor José de Assis
  @link https://roboticapratica.com.br/
  
   ------------------
  | Módulo | Arduino |
  | VCC    | 5V      |
  | GND    | GND     |
  | TX     | pino 2  |
  | RX *   | pino 3  |
   ------------------

   * Usar divisor de tensão

     ----- 1K ----- pino 3
   /
  RX
   \
     ----- 2K ----- GND   

*/

#include <SoftwareSerial.h>
SoftwareSerial modulo(2, 3);
String comando = "";
void setup() {
  modulo.begin(9600);
  Serial.begin(115200);
  Serial.println("1. Configure o monitor serial para [No Line Ending] e [115200 baud]");
  Serial.println("2. Digite o comando desejado na caixa de entrada");
  Serial.println(" ----------------------------------------------");
  Serial.println("| COMANDO      | RESPOSTA                      |");
  Serial.println("| AT           | OK                            |");
  Serial.println("| AT+VERSION   | (identificar firmware)        |");
  Serial.println("| AT+NAME      | (mudar SSID) Ex: AT+NAMEHC06  |");
  Serial.println("| AT+PIN       | (mudar senha) Ex: AT+PIN1234  |");
  Serial.println(" ----------------------------------------------"); 
  Serial.println("Resposta:");                     
}

void loop() {
  if (modulo.available())  {
    while (modulo.available())    {
      comando += (char)modulo.read();
    }
    Serial.print(comando);
    comando = "";    
  }

  if (Serial.available())  {
    delay(10);
    modulo.write(Serial.read());   
  }
}
