/*
   Usando a biblioteca SoftwareSerial para modificar
   os pinos de comunicação serial e setar os módulos
   HC-05, HC-06 e JY-MCU
   @author - Professor José de Assis
   http://professorjosedeassis.com.br/curso-automacao-residencial-arduino/
*/

// A linha abaixo carrega a biblioteca SoftwareSerial
// O uso desta biblioteca permite definir outros pinos
// do Arduino como RX e TX, liberando a comunicação
// serial via USB (sem esta biblioteca temos que usar
// os pinos 0 e 1 que bloqueiam a comunicação via USB)
#include <SoftwareSerial.h>

// A linha abaixo redefine os pinos RX e TX
// No exemplo abaixo:
// RX -> 2
// TX -> 3
SoftwareSerial MinhaSerial(2, 3);

String comando = ""; //Variável global que irá receber os comandos

void setup()
{
  Serial.begin(115200); //Inicia a serial em 115200
  // Não esqueça de alterar o monitor serial para este valor e ativar "Nenhum final-de-linha"
  Serial.println("Digite os comandos AT :"); //Inicie o monitor serial com este  texto
  MinhaSerial.begin(9600); //Inicia a serial configurada nas portas 2 e 3 em 9600 (padrão)
}

void loop()
{
  // Se o monitor serial estiver disponível
  if (MinhaSerial.available())
  {
    while (MinhaSerial.available())
    {
      comando += (char)MinhaSerial.read(); //adicionar a variável comando os valores digitados no Monitor serial
    }
    Serial.print(comando); //Mostra o comando digitado
    comando = "";
  }

  // Se a comunicação serial do módulo estiver disponível
  if (Serial.available())
  {
    delay(10);
    MinhaSerial.write(Serial.read()); //Enviar o comando ao módulo bluetooth
  }
}

/* Comandos

  Comando     Resposta      Função
  AT          OK            Teste de comunicação
  AT+VERSION  OKlinvorV1.8  Mostra a versão do firmware
  AT+NAMExyz  OKsetname     Altera o nome do módulo
  AT+PIN1234  OKsetPIN      Altera a senha do módulo
  AT+BAUD1    OK1200        Seta o baud rate em 1200
  AT+BAUD2    OK2400        Seta o baud rate em 2400
  AT+BAUD3    OK4800        Seta o baud rate em 4800
  AT+BAUD4    OK9600        Seta o baud rate em 9600
  AT+BAUD5    OK19200       Seta o baud rate em 19200
  AT+BAUD6    OK38400       Seta o baud rate em 38400
  AT+BAUD7    OK57600       Seta o baud rate em 57600
  AT+BAUD8    OK115200      Seta o baud rate em 115200
  AT+BAUD9    OK230400      Seta o baud rate em 230400
  AT+BAUDA    OK460800      Seta o baud rate em 460800
  AT+BAUDB    OK921600      Seta o baud rate em 921600
  AT+BAUDC    OK1382400     Seta o baud rate em 1382400

*/
