#include "mqtt_lab.h"
uint32_t ultimo = 0;
void setup() {
  Serial.begin(115200);
  iniciarRed();
  iniciarMqtt();
}
void loop() {
  atenderMqtt();
  if (mqtt.connected() && millis() - ultimo >= 5000) {
    ultimo = millis();
    char b[80];
    snprintf(b, sizeof(b), "{\"uptime_ms\":%lu}", (unsigned long)millis());
    Serial.println(mqtt.publish("curso/nodo01/telemetry", b, false) ? "publicado"
                                                                    : "no publicado");
  }
}
