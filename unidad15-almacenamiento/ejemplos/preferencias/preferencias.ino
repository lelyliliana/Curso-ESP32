#include <Arduino.h>
#include <Preferences.h>
Preferences prefs;
void setup() {
  Serial.begin(115200);
  delay(500);
  if (!prefs.begin("curso", false)) {
    Serial.println("NVS fallo");
    return;
  }
  uint32_t visitas = prefs.getUInt("arranques", 0);
  size_t n = prefs.putUInt("arranques", visitas + 1);
  Serial.printf("Arranque anterior=%u; escritura=%s\n", visitas, n == 4 ? "OK" : "FALLO");
  prefs.end();
  Serial.println("Reinicia: el contador debe incrementar. No se escribe en loop.");
}
void loop() { delay(1000); }
