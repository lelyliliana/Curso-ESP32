#include <Arduino.h>
uint32_t ultimo = 0, contador = 0;
void setup() { Serial.begin(115200); }
void loop() {
  if (millis() - ultimo >= 1000) {
    ultimo = millis();
    Serial.printf("latido %u, uptime %u ms\n", ++contador, millis());
  }
}
