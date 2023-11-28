/*
  Setar módulo bluetooth HC-06
  @author Professor José de Assis
  @link https://roboticapratica.com.br/
  
  --------------------
  | Módulo | Arduino |
  | VCC    | 5V      |
  | GND    | GND     |
  | TX     | pino 2  |
  | RX *   | pino 3  |
  --------------------

   * Usar divisor de tensão

     ----- 1K ----- pino 3
   /
  RX
   \
     ----- 2K ----- GND   

   * Configure o Serial Monitor para [No Line Ending] e [115200 baud]

*/

#include <SoftwareSerial.h>
SoftwareSerial modulo(2, 3);
String comando = "";
void setup() {
  modulo.begin(9600);  
  Serial.begin(115200);
  Serial.println("1. Configure o Serial Monitor para [No Line Ending] e [115200 baud]");
  Serial.println("2. Digite o comando desejado na caixa de entrada");
  Serial.println("-----------------------------------------------------------");
  Serial.println("| Comando    | Finalidade                   | Resposta    |");
  Serial.println("-----------------------------------------------------------");
  Serial.println("| AT         | Teste                        | OK          |");
  Serial.println("| AT+VERSION | Identificar firmware         | OKlinvorVer |");
  Serial.println("| AT+NAME    | Mudar SSID Ex: AT+NAMEHC-06  | OKsetname   |");
  Serial.println("| AT+PIN     | Mudar senha Ex: AT+PIN1234   | OKsetPIN    |");
  Serial.println("|            |(Senha numerica de 4 digitos) |             |");
  Serial.println("----------------------------------------------------------");
  Serial.println("Resposta:");
}

void loop() {
  if (modulo.available()) {
    while (modulo.available()) {
      comando += (char)modulo.read();
    }
    Serial.print(comando);
    comando = "";
  }

  if (Serial.available()) {
    delay(10);
    modulo.write(Serial.read());
  }
}
