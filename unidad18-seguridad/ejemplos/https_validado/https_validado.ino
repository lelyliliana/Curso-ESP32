#include "red_lab.h"
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <time.h>
#if __has_include("ca_local.h")
#include "ca_local.h"
#else
const char *LAB_CA = "";
#define LAB_TLS_URL "https://TU_HOST_AUTORIZADO/"
#endif
uint32_t ultimo = 0;
void setup() {
  Serial.begin(115200);
  iniciarRed();
  configTime(0, 0, "pool.ntp.org");
}
void loop() {
  atenderRed();
  if (WiFi.status() != WL_CONNECTED || millis() - ultimo < 10000)
    return;
  ultimo = millis();
  if (!strlen(LAB_CA)) {
    Serial.println("Configura CA y hostname: no se omite TLS");
    return;
  }
  if (time(nullptr) < 1700000000) {
    Serial.println("Reloj aun no sincronizado");
    return;
  }
  WiFiClientSecure tcp;
  tcp.setCACert(LAB_CA);
  HTTPClient http;
  http.setConnectTimeout(3000);
  http.setTimeout(3000);
  if (!http.begin(tcp, LAB_TLS_URL))
    return;
  int code = http.GET();
  Serial.printf("HTTPS=%d\n", code);
  http.end();
}
