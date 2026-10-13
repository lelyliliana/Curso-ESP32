#include "red_lab.h"
#include <WebServer.h>
WebServer server(80);
void setup() {
  Serial.begin(115200);
  iniciarRed();
  server.on("/", HTTP_GET, [] {
    server.send(200, "text/html; charset=utf-8",
                "<!doctype html><html lang='es'><meta "
                "charset='utf-8'><title>ESP32</title><h1>Nodo local</h1><p>La pagina "
                "proviene del ESP32.</p></html>");
  });
  server.onNotFound([] { server.send(404, "text/plain", "Ruta inexistente"); });
  server.begin();
}
void loop() {
  atenderRed();
  server.handleClient();
}
