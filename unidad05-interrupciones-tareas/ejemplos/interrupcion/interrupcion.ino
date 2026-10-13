#include <Arduino.h>
const uint8_t BOTON = 27;
portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;
volatile uint32_t flancos = 0;
uint32_t ultimo = 0;
void ARDUINO_ISR_ATTR alPulsar() {
  portENTER_CRITICAL_ISR(&mux);
  flancos++;
  portEXIT_CRITICAL_ISR(&mux);
}
void setup() {
  Serial.begin(115200);
  pinMode(BOTON, INPUT_PULLUP);
  attachInterrupt(BOTON, alPulsar, FALLING);
}
void loop() {
  if (millis() - ultimo >= 1000) {
    ultimo = millis();
    portENTER_CRITICAL(&mux);
    uint32_t copia = flancos;
    portEXIT_CRITICAL(&mux);
    Serial.printf("Flancos=%u (incluye rebotes)\n", copia);
  }
}
