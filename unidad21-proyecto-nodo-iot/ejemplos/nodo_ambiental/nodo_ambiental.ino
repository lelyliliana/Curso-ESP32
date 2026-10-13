#include "mqtt_lab.h"
#include <ArduinoJson.h>
#include <Wire.h>
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
  Wire.begin(21, 22);
  Wire.setTimeOut(50);
  iniciarRed();
  iniciarMqtt();
}
void loop() {
  atenderMqtt();
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
