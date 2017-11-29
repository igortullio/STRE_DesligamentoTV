#include <IRremote.h>
unsigned int powerIRout[] = {4500,4450,650,1600,600,1650,550,1650,600,500,600,550,550,550,550,550,550,550,600,1600,650,1600,600,1650,600,
                              500,550,550,550,550,600,550,500,600,550,550,550,1650,650,500,550,550,550,550,550,600,500,600,500,600,500,
                              1700,650,500,500,1700,600,1600,650,1600,600,1600,650,1600,600,1600,650};
IRsend irsend;
int tempo = 0;
int led = 3;
int pinopir = 4;
int acionamento;


void setup() {
  pinMode(led, OUTPUT);
  pinMode(pinopir, INPUT);
  Serial.begin(9600);
}

void loop() {
  tempo = 0;
  acionamento = digitalRead(pinopir);                                    
  Serial.println(acionamento);

  while(tempo < 5){
    delay(5000);
    acionamento = digitalRead(pinopir);
    if(acionamento == 0){
      delay(1000);      
      tempo++;
      Serial.println(tempo);
    } else {
      delay(1000);
      tempo=0;
    }   
  }
  liga_desliga();
}

void liga_desliga(){
  Serial.println("Enviando comando");
  irsend.sendRaw(powerIRout, 68, 38);    
}
