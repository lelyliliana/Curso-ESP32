#include "mqtt_lab.h"
#include <ArduinoJson.h>
const uint8_t LED = 25, BOTON = 27;
bool activo = false;
uint32_t ultimoComando = 0;
void publicarEstado() { mqtt.publish("curso/nodo01/state", activo ? "ON" : "OFF", true); }
void recibir(char *topic, byte *payload, unsigned int largo) {
  if (String(topic) != "curso/nodo01/command" || largo > 128)
    return;
  JsonDocument d;
  if (deserializeJson(d, payload, largo) || d.size() != 1 || !d["activo"].is<bool>()) {
    Serial.println("Comando rechazado");
    return;
  }
  if (d["activo"].as<bool>() && digitalRead(BOTON) == LOW) {
    Serial.println("Comando bloqueado por prioridad local");
    return;
  }
  activo = d["activo"].as<bool>();
  ultimoComando = millis();
  digitalWrite(LED, activo);
  publicarEstado();
}
void setup() {
  Serial.begin(115200);
  pinMode(BOTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  iniciarRed();
  iniciarMqtt();
  mqtt.setCallback(recibir);
}
void loop() {
  bool nueva = atenderMqtt();
  if (nueva) {
    mqtt.subscribe("curso/nodo01/command", 0);
    publicarEstado();
  }
  if (activo && (digitalRead(BOTON) == LOW || !mqtt.connected() ||
                 WiFi.status() != WL_CONNECTED || millis() - ultimoComando >= 10000)) {
    activo = false;
    digitalWrite(LED, LOW);
    if (mqtt.connected())
      publicarEstado();
    Serial.println("Salida OFF por perdida de enlace o vencimiento");
  }
}
