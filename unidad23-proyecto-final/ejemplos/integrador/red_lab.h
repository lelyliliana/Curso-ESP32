#pragma once
#include "config_ejemplo.h"
#include <WiFi.h>
// Copia config_local.example.h a config_local.h SOLO en tu equipo.
#if __has_include("config_local.h")
#include "config_local.h"
#endif
#ifndef LAB_WIFI_SSID
#define LAB_WIFI_SSID "TU_RED_2G4"
#define LAB_WIFI_PASS "TU_CLAVE_LOCAL"
#define LAB_HOST "192.168.1.100"
#define LAB_MQTT_USER "curso"
#define LAB_MQTT_PASS "CAMBIAR_EN_TU_EQUIPO"
#define LAB_OTA_PASS "CAMBIAR_OTA_EN_TU_EQUIPO"
#endif
uint32_t wifiIntento = 0;
bool wifiEstaba = false;
void iniciarRed() {
  WiFi.mode(WIFI_STA);
  WiFi.setAutoReconnect(true);
  WiFi.begin(LAB_WIFI_SSID, LAB_WIFI_PASS);
  wifiIntento = millis();
}
void atenderRed() {
  bool conectado = WiFi.status() == WL_CONNECTED;
  if (conectado && !wifiEstaba) {
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
  }
  if (!conectado && wifiEstaba)
    Serial.println("Wi-Fi perdido; tareas locales continúan");
  wifiEstaba = conectado;
  if (!conectado && millis() - wifiIntento >= 15000) {
    wifiIntento = millis();
    WiFi.reconnect();
  }
}
