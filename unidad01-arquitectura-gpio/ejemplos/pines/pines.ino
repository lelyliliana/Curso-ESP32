#include <Arduino.h>
const uint8_t LED = 25, BOTON = 27;
void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  pinMode(BOTON, INPUT_PULLUP);
}
void loop() {
  bool pulsado = digitalRead(BOTON) == LOW;
  digitalWrite(LED, pulsado);
  Serial.println(pulsado ? "pulsado" : "libre");
  delay(250);
}
