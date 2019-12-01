#include <Arduino.h>
#include "Ultrasonic.h"

//Os fios devem estar conectados nos pinos abaixo para o RX e TX
#define RX 0
#define TX 10

Ultrasonic ultrassom1(8,7); // define o nome do sensor(ultrassom)
//e onde esta ligado o trig(8) e o echo(7) respectivamente
Ultrasonic ultrassom2(6,5);

long distancia1;
long distancia2;

void setup() {
Serial.begin(9600); //Habilita Comunicação Serial a uma taxa de 9600 bauds.

}

 void loop()
 {
    distancia1 = ultrassom1.Ranging(CM); // ultrassom.Ranging(CM) retorna a distancia em cm
    distancia2 = ultrassom2.Ranging(CM);

    if(distancia1 < 40){
      Serial.println("Passou o lixo na entrada 1");
      Serial.print(distancia1); //imprime o valor da variável distancia
      Serial.println("cm");
      digitalWrite(TX, LOW);  //Mensagem para a haspberry de que passou o lixo
    }else{
      digitalWrite(TX, HIGH); //Mensagem para a haspberry de que ainda não percebe nada no sensor
    }

    if(distancia2 < 40){
      Serial.println("Passou o lixo na entrada 2");
      Serial.print(distancia2); //imprime o valor da variável distancia
      Serial.println("cm");
      digitalWrite(TX, LOW);  //Mensagem para a haspberry de que passou o lixo
    }else{
      digitalWrite(TX, HIGH); //Mensagem para a haspberry de que ainda não percebe nada no sensor
    }

    delay(100);
 }