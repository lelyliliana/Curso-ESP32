#include <Arduino.h>
#include <ArduinoJson.h>
void probar(const char *texto) {
  JsonDocument d;
  auto err = deserializeJson(d, texto);
  bool valido =
      !err && d.is<JsonObject>() && d.size() == 2 && d["nodo"].is<const char *>() &&
      String(d["nodo"].as<const char *>()) == "nodo01" && d["temperatura_c"].is<float>();
  if (valido) {
    float t = d["temperatura_c"].as<float>();
    valido = isfinite(t) && t >= -40 && t <= 125;
  }
  Serial.println(valido ? "ACEPTADO" : "RECHAZADO");
}
void setup() {
  Serial.begin(115200);
  delay(500);
  probar("{\"nodo\":\"nodo01\",\"temperatura_c\":23.5}");
  probar("{\"nodo\":\"nodo01\",\"temperatura_c\":\"23.5\"}");
  probar("{\"nodo\":\"nodo01\",\"temperatura_c\":999}");
  probar("{");
}
void loop() { delay(1000); }
