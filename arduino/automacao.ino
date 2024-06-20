/*
   Executando comandos através da comunicação serial
   Professor José de Assis 
   nubia testando
*/

int leitor; //criando uma variável que irá receber um valor

void setup() {
  pinMode(13, OUTPUT); //configurando o pino 13 como saída
  Serial.begin(9600); //setando a comunicação serial na velocidade 9600
}


void loop() {
  if (Serial.available()) { //esta estrutura evita o acionamento indevido do Led ou outros dispositivos
    leitor = Serial.read(); //armazenando a tecla pressionada na variável leitor
    if (leitor == '1') { //se tecla 1 pressionada
      digitalWrite(13, !digitalRead(13)); //alterando o estado do pino 13 do arduino
    }
  }
}
