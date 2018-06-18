/**
* Objetivo: Projeto Monitoramento de Energia
*  Controle e monitoramento de uma carga, controle de nivel
*
* Author: João Campos
* Referencias:
*
* https://playground.arduino.cc/Code/Timer1
*
*/
// Biblioteca que inicia o timer e variáveis de aquisição de sinal
#include "setupTimer.h"
#include "utils.h"
#include <HTTPClient.h>
#include <sys/time.h>
//#include "OtaUtil.h"
#include "setupModbus.h"



const int CARGA_PORT = GPIO_NUM_19;

const int NIVEL_PORT = GPIO_NUM_21;

IPAddress local_IP(192, 168, 0, 115);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 0, 0);
IPAddress primaryDNS(8, 8, 8, 8); //optional
IPAddress secondaryDNS(8, 8, 4, 4); //optional



void setup()
{
  Serial.begin(115200);
  initADC();



//  WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)
  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("STA falhou a configuracao");
  }
  
  setup_modbus();

 // setupOta();

  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  // Função timer que atualiza dados a cada 1 segundo
  initTimer();
  pinMode(CARGA_PORT, OUTPUT);
  pinMode(NIVEL_PORT, INPUT);
  Serial.println(WiFi.localIP());


}






void loop(){


  digitalWrite(CARGA_PORT, !mb.Coil(CARGA_COIL));
  mb.Ists(NIVEL_0, digitalRead(NIVEL_PORT));


}
