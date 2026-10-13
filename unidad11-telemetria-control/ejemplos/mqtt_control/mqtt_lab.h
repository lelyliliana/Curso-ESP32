#pragma once
#include "red_lab.h"
#include <PubSubClient.h>
WiFiClient mqttTransporte;
PubSubClient mqtt(mqttTransporte);
uint32_t mqttIntento = 0;
bool mqttPrimerIntento = true;
const char *DISP = "curso/nodo01/availability";
void iniciarMqtt() {
  mqtt.setServer(LAB_HOST, 1883);
  mqtt.setSocketTimeout(2);
  mqtt.setKeepAlive(15);
  mqtt.setBufferSize(512);
}
bool atenderMqtt() {
  atenderRed();
  if (WiFi.status() != WL_CONNECTED)
    return false;
  if (!mqtt.connected()) {
    if (!mqttPrimerIntento && millis() - mqttIntento < 5000)
      return false;
    mqttPrimerIntento = false;
    mqttIntento = millis();
    if (!mqtt.connect("leli-nodo01", LAB_MQTT_USER, LAB_MQTT_PASS, DISP, 1, true,
                      "offline")) {
      Serial.printf("MQTT fallo %d\n", mqtt.state());
      return false;
    }
    mqtt.publish(DISP, "online", true);
    Serial.println("MQTT conectado");
    return true;
  }
  mqtt.loop();
  return false;
}
