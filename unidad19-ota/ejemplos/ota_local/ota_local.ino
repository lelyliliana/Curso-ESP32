#include "red_lab.h"
#include <ArduinoOTA.h>
const char *VERSION_FIRMWARE = "lab-1";
void setup() {
  Serial.begin(115200);
  Serial.printf("Firmware %s\n", VERSION_FIRMWARE);
  iniciarRed();
  if (String(LAB_OTA_PASS) == "CAMBIAR_OTA_EN_TU_EQUIPO" || strlen(LAB_OTA_PASS) < 12) {
    Serial.println("Configura clave OTA local de 12+ caracteres");
    while (true)
      delay(1000);
  }
  ArduinoOTA.setHostname("leli-nodo01");
  ArduinoOTA.setPassword(LAB_OTA_PASS);
  ArduinoOTA.onStart([] { Serial.println("OTA inicio: sin actuadores conectados"); });
  ArduinoOTA.onEnd([] { Serial.println("OTA recibida: verificar nuevo arranque"); });
  ArduinoOTA.onError([](ota_error_t e) { Serial.printf("OTA error=%u\n", e); });
  ArduinoOTA.begin();
}
void loop() {
  atenderRed();
  if (WiFi.status() == WL_CONNECTED)
    ArduinoOTA.handle();
}
