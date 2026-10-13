#include "mqtt_lab.h"
#include <ArduinoJson.h>
#include <Wire.h>
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
uint32_t ultimo = 0, inicio = 0;
bool esperando = false;
uint8_t crc8(const uint8_t *b) {
  uint8_t c = 0xFF;
  for (int i = 0; i < 2; i++) {
    c ^= b[i];
    for (int k = 0; k < 8; k++)
      c = (c & 0x80) ? (c << 1) ^ 0x31 : c << 1;
  }
  return c;
}
void setup() {
  Serial.begin(115200);
  pinMode(BOTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Wire.begin(21, 22);
  Wire.setTimeOut(50);
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
  }
  uint32_t ahora = millis();
  if (!esperando && ahora - ultimo >= 5000) {
    ultimo = ahora;
    Wire.beginTransmission(0x44);
    Wire.write(0x24);
    Wire.write(0x00);
    if (Wire.endTransmission() != 0) {
      Serial.println("Sensor ausente: no publico valor");
      return;
    }
    inicio = ahora;
    esperando = true;
  }
  if (esperando && ahora - inicio >= 20) {
    esperando = false;
    if (Wire.requestFrom(uint8_t(0x44), uint8_t(6)) != 6) {
      Serial.println("Lectura incompleta");
      return;
    }
    uint8_t b[6];
    for (auto &x : b)
      x = Wire.read();
    if (crc8(b) != b[2] || crc8(b + 3) != b[5]) {
      Serial.println("CRC invalido");
      return;
    }
    float t = -45 + 175 * float((b[0] << 8) | b[1]) / 65535;
    float h = 100 * float((b[3] << 8) | b[4]) / 65535;
    JsonDocument d;
    d["nodo"] = "nodo01";
    d["temperatura_c"] = t;
    d["humedad_pct"] = h;
    d["uptime_ms"] = ahora;
    char texto[256];
    serializeJson(d, texto, sizeof(texto));
    Serial.println(texto);
    if (mqtt.connected())
      Serial.println(mqtt.publish("curso/nodo01/telemetry", texto, false)
                         ? "Publicado QoS0"
                         : "Publicacion fallo");
    else
      Serial.println("Sin broker: lectura solo local, no se almacena");
  }
}
