#include "red_lab.h"
#include <ArduinoJson.h>
#include <WebServer.h>
WebServer server(80);
const uint8_t LED = 25;
bool activo = false;
void estado() {
  JsonDocument d;
  d["activo"] = activo;
  String s;
  serializeJson(d, s);
  server.send(200, "application/json", s);
}
void cambiar() {
  JsonDocument d;
  auto err = deserializeJson(d, server.arg("plain"));
  if (err || d.size() != 1 || !d["activo"].is<bool>()) {
    server.send(400, "application/json",
                "{\"error\":\"Se requiere solo activo booleano\"}");
    return;
  }
  activo = d["activo"].as<bool>();
  digitalWrite(LED, activo);
  estado();
}
void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  iniciarRed();
  server.on("/api/led", HTTP_GET, estado);
  server.on("/api/led", HTTP_PUT, cambiar);
  server.onNotFound([] { server.send(404, "application/json", "{\"error\":\"ruta\"}"); });
  server.begin();
}
void loop() {
  atenderRed();
  server.handleClient();
}
