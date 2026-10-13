#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
const char *SERVICIO = "12345678-1234-1234-1234-1234567890ab";
const char *CARACTERISTICA = "12345678-1234-1234-1234-1234567890ac";
BLECharacteristic *valor;
uint32_t ultimo = 0;
void setup() {
  Serial.begin(115200);
  BLEDevice::init("Leli-Nodo01");
  auto server = BLEDevice::createServer();
  auto servicio = server->createService(SERVICIO);
  valor =
      servicio->createCharacteristic(CARACTERISTICA, BLECharacteristic::PROPERTY_READ);
  valor->setValue("0");
  servicio->start();
  auto anuncio = BLEDevice::getAdvertising();
  anuncio->addServiceUUID(SERVICIO);
  anuncio->setScanResponse(true);
  BLEDevice::startAdvertising();
  Serial.println("BLE de solo lectura; sin datos privados");
}
void loop() {
  if (millis() - ultimo >= 1000) {
    ultimo = millis();
    valor->setValue(String(millis() / 1000));
  }
}
