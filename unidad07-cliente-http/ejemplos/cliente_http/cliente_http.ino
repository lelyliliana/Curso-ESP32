#include "red_lab.h"
#include <HTTPClient.h>
uint32_t ultimo = 0;
void setup() {
  Serial.begin(115200);
  iniciarRed();
}
void loop() {
  atenderRed();
  if (WiFi.status() != WL_CONNECTED || millis() - ultimo < 5000)
    return;
  ultimo = millis();
  WiFiClient tcp;
  HTTPClient http;
  http.setConnectTimeout(2000);
  http.setTimeout(2000);
  if (!http.begin(tcp, String("http://") + LAB_HOST + ":8000/medicion")) {
    Serial.println("No inicia HTTP");
    return;
  }
  int codigo = http.GET();
  Serial.printf("HTTP %d\n", codigo);
  if (codigo == 200)
    Serial.println(http.getString());
  else if (codigo < 0)
    Serial.println(http.errorToString(codigo));
  http.end();
}
