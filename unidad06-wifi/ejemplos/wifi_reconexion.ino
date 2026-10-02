#include <WiFi.h>

const char* SSID = "TU_RED";
const char* PASSWORD = "TU_CLAVE";

unsigned long ultimoIntento = 0;
const unsigned long INTERVALO_REINTENTO = 10000;

void conectarWiFi() {
  Serial.println("Intentando Wi-Fi...");
  WiFi.begin(SSID, PASSWORD);
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  conectarWiFi();
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    // El dispositivo puede continuar con sus tareas conectadas.
    return;
  }

  unsigned long ahora = millis();
  if (ahora - ultimoIntento >= INTERVALO_REINTENTO) {
    ultimoIntento = ahora;
    conectarWiFi();
  }
}
