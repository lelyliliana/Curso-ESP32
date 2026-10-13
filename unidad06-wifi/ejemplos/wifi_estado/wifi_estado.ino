#include "red_lab.h"
uint32_t ultimo = 0;
void setup() {
  Serial.begin(115200);
  iniciarRed();
}
void loop() {
  atenderRed();
  if (millis() - ultimo >= 2000) {
    ultimo = millis();
    Serial.printf("Tarea local: %u estado=%d\n", millis(), WiFi.status());
  }
}
