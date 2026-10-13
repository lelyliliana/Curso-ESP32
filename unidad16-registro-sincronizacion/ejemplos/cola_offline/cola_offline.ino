#include "red_lab.h"
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <Preferences.h>
Preferences prefs;
uint32_t secuencia = 0, pendiente = 0, ultimo = 0;
bool hay = false;
void setup() {
  Serial.begin(115200);
  if (!prefs.begin("cola", false)) {
    Serial.println("NVS no disponible");
    while (true)
      delay(1000);
  }
  secuencia = prefs.getUInt("seq", 0);
  hay = prefs.getBool("hay", false);
  pendiente = prefs.getUInt("id", 0);
  iniciarRed();
}
void loop() {
  atenderRed();
  if (millis() - ultimo < 10000)
    return;
  ultimo = millis();
  if (!hay) {
    pendiente = ++secuencia;
    if (prefs.putUInt("seq", secuencia) != 4 || prefs.putUInt("id", pendiente) != 4 ||
        prefs.putBool("hay", true) != 1) {
      Serial.println("NVS fallo: deten prueba");
      while (true)
        delay(1000);
    }
    hay = true;
  }
  if (WiFi.status() != WL_CONNECTED) {
    Serial.printf("Pendiente=%u; cola llena, no genero otro\n", pendiente);
    return;
  }
  WiFiClient tcp;
  HTTPClient http;
  http.setConnectTimeout(2000);
  http.setTimeout(2000);
  if (!http.begin(tcp, String("http://") + LAB_HOST + ":8000/eventos"))
    return;
  http.addHeader("Content-Type", "application/json");
  http.addHeader("Idempotency-Key", String("nodo01-") + pendiente);
  int code = http.POST(String("{\"nodo\":\"nodo01\",\"id\":") + pendiente + "}");
  String cuerpo = http.getString();
  http.end();
  JsonDocument ack;
  bool confirmado =
      (code == 200 || code == 201) && !deserializeJson(ack, cuerpo) &&
      ack["ack"].is<const char *>() &&
      String(ack["ack"].as<const char *>()) == String("nodo01-") + pendiente;
  if (confirmado) {
    if (prefs.putBool("hay", false) == 1)
      hay = false;
    Serial.printf("Confirmado %u\n", pendiente);
  } else
    Serial.printf("Sin confirmar HTTP=%d; conservo %u\n", code, pendiente);
}
