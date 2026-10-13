#include <Arduino.h>
enum class Estado { LOCAL, ENLAZADO, DEGRADADO };
Estado estado = Estado::LOCAL;
uint32_t ultimo = 0;
bool enlace = false;
void setup() {
  Serial.begin(115200);
  Serial.println("e=enlace; f=fallo. Es una simulacion, no conecta Wi-Fi.");
}
void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == 'e')
      enlace = true;
    if (c == 'f')
      enlace = false;
  }
  if (millis() - ultimo >= 1000) {
    ultimo = millis();
    estado = enlace ? Estado::ENLAZADO : Estado::DEGRADADO;
    Serial.printf("Lectura SIMULADA=24 C; transporte=%s\n",
                  estado == Estado::ENLAZADO ? "disponible" : "sin enlace");
  }
}
