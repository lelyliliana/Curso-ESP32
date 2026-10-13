#include <Arduino.h>
uint32_t ultimo = 0, espera = 1000;
unsigned intentos = 0;
bool habilitado = true;
void setup() {
  Serial.begin(115200);
  Serial.println("f simula fallo; r simula recuperacion. Sin red.");
}
void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == 'r') {
      espera = 1000;
      intentos = 0;
      habilitado = false;
      Serial.println("RECUPERADO, espera reiniciada");
    }
    if (c == 'f') {
      habilitado = true;
      ultimo = millis();
    }
  }
  if (habilitado && millis() - ultimo >= espera) {
    ultimo = millis();
    Serial.printf("Intento %u fallo simulado; intervalo=%u ms\n", ++intentos, espera);
    espera = min(espera * 2, uint32_t(16000));
  }
}
