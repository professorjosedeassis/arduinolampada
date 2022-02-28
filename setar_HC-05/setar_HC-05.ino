/*
  Setar módulo bluetooth HC-05 ZS-040
  @author Professor José de Assis
  @link https://roboticapratica.com.br/
  
   ------------------
  | Módulo | Arduino |
  | EN     | 3.3V    |
  | VCC    | 5V      |
  | GND    | GND     |
  | TX *   | pino 1  |
  | RX *   | pino 0  |
  | STATE  |         |
   ------------------

   * Usar divisor de tensão

     ----- 1K ----- pino 1
   /
  TX
   \
     ----- 2K ----- GND
     

     ----- 1K ----- pino 0
   /
  RX
   \
     ----- 2K ----- GND
     
    Instruções:
    1) Fazer o upload deste código para o Arduino
       antes de ligar os pinos 0 e 1.
    2) Ligar os pinos 0 e 1 e abrir o monitor serial
    3) Modificar no rodapé do monitor serial:
       Auto-rolagem | Ambos, NL e CR | 38400 velocidade
    4) Digitar o comando AT (normalmente retorna ERROR:(0))
    6) Digitar novamente o comando AT (retorna OK)

 ----------------------------------------------
| COMANDO           | RESPOSTA                 |
| AT                | OK                       |
| AT+VERSION        | (versão do firmware)     |
| AT+NAME           | (SSID)                   |
| AT+NAME=          | (mudar SSID)             |
| AT+PSWD           | (senha)                  |
| AT+PSWD=""        | (mudar senha (4 digitos))|
| AT+UART           | (velocidade)             |
| AT+UART=9600,0,0  | (setar velocidade 9600)  |
| AT+UART=38400,0,0 | (setar velocidade 38400) |   
 ----------------------------------------------    

*/

void setup() {
  // todo processo é realizado pelo monitor serial
}

void loop() {
  // todo processo é realizado pelo monitor serial
}
