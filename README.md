# Projeto


Calcular o valor do  corrente e tensão, nível de bóia e acionamento de carga via modbus IP

## Portas utilizadas


1. 12 --> CARGA
2. 26 --> BOIA
3. 35 --> TC
4. 36 --> TP

## Registros Modbus

### Input Register

1. Corrente 0 e 1
2. Tensão 2 e 3

###  Coil Register
 0

### Switch Register
0


# Referencias


https://techtutorialsx.com/2017/10/07/esp32-arduino-timer-interrupts/

https://github.com/espressif/arduino-esp32/blob/master/libraries/Ticker/examples/Blinker/Blinker.ino

https://github.com/espressif/arduino-esp32/blob/master/libraries/WiFi/examples/WiFiClientStaticIP/WiFiClientStaticIP.ino

https://esp32.com/viewtopic.php?t=1341
Arduino Ota Example
