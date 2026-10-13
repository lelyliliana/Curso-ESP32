#include <Arduino.h>
#include <SPI.h>
const uint8_t CS = 26;
uint32_t ultimo = 0;
void setup() {
  Serial.begin(115200);
  pinMode(CS, OUTPUT);
  digitalWrite(CS, HIGH);
  SPI.begin(18, 19, 23, CS);
  Serial.println("Loopback: puente GPIO23 MOSI a GPIO19 MISO, sin otro periferico");
}
void loop() {
  if (millis() - ultimo < 1000)
    return;
  ultimo = millis();
  SPI.beginTransaction(SPISettings(100000, MSBFIRST, SPI_MODE0));
  digitalWrite(CS, LOW);
  uint8_t enviado = 0xA5, recibido = SPI.transfer(enviado);
  digitalWrite(CS, HIGH);
  SPI.endTransaction();
  Serial.printf("TX=%02X RX=%02X %s\n", enviado, recibido,
                recibido == enviado ? "coincide" : "revisa puente");
}
