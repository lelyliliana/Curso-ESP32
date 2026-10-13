#include <Arduino.h>
#include <Wire.h>
const uint8_t SENSOR = 0x44;
uint32_t inicio = 0, ultimo = 0;
bool esperando = false;
uint8_t crc8(const uint8_t *b) {
  uint8_t c = 0xFF;
  for (int i = 0; i < 2; i++) {
    c ^= b[i];
    for (int k = 0; k < 8; k++)
      c = (c & 0x80) ? (c << 1) ^ 0x31 : c << 1;
  }
  return c;
}
void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  Wire.setTimeOut(50);
  for (uint8_t a = 1; a < 127; a++) {
    Wire.beginTransmission(a);
    if (Wire.endTransmission() == 0)
      Serial.printf("I2C 0x%02X\n", a);
  }
}
void loop() {
  uint32_t ahora = millis();
  if (!esperando && ahora - ultimo >= 2000) {
    ultimo = ahora;
    Wire.beginTransmission(SENSOR);
    Wire.write(0x24);
    Wire.write(0x00);
    if (Wire.endTransmission() != 0) {
      Serial.println("SHT31 ausente");
      return;
    }
    inicio = ahora;
    esperando = true;
  }
  if (esperando && ahora - inicio >= 20) {
    esperando = false;
    if (Wire.requestFrom(SENSOR, uint8_t(6)) != 6) {
      Serial.println("Lectura incompleta");
      return;
    }
    uint8_t b[6];
    for (auto &x : b)
      x = Wire.read();
    if (crc8(b) != b[2] || crc8(b + 3) != b[5]) {
      Serial.println("CRC invalido");
      return;
    }
    float t = -45 + 175 * float((b[0] << 8) | b[1]) / 65535;
    float h = 100 * float((b[3] << 8) | b[4]) / 65535;
    Serial.printf("T=%.2f C HR=%.2f %%\n", t, h);
  }
}
