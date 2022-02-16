/*
  Setar módulo bluetooth HC-06
  @author Professor José de Assis
   ------------------
  | Módulo | Arduino |
  | VCC    | 5V      |
  | GND    | GND     |
  | TX     | pino 2  |
  | RX *   | pino 3  |
   ------------------

    Usar divisor de tensão

     ----- 1K ----- pino 3
   /
  RX
   \
     ----- 2K ----- GND

    Modificar no rodapé do monitor serial:
    Auto-rolagem | Ambos, NL e CR | 115200 velocidade
*/

#include <SoftwareSerial.h>
SoftwareSerial modulo(2, 3);
String comando = "";
void setup() {
  modulo.begin(9600);
  Serial.begin(115200);
  Serial.println("                                       ");
  Serial.println("Digite o comando AT na caixa de entrada");
  Serial.println(" --------------------------------------------");
  Serial.println("| COMANDO      | RESPOSTA                    |");
  Serial.println("| AT           | OK                          |");
  Serial.println("| AT+VERSION   | (versão do firmware)        |");
  Serial.println("| AT+NAME      | (SSID)                      |");
  Serial.println("| AT+NAME=     | (mudar SSID)                |");
  Serial.println("| AT+PSWD      | (senha)                     |");
  Serial.println("| AT+PSWD=\"\"   | (mudar senha (4 digitos))   |");
  Serial.println(" --------------------------------------------"); 
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
