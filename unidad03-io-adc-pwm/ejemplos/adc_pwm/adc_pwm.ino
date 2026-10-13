#include <Arduino.h>
const uint8_t ADC = 34, LED = 25;
uint32_t ultimo = 0;
void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  analogSetPinAttenuation(ADC, ADC_11db);
  if (!ledcAttach(LED, 5000, 8)) {
    Serial.println("LEDC fallo");
    while (true)
      delay(1000);
  }
}
void loop() {
  if (millis() - ultimo >= 200) {
    ultimo = millis();
    int bruto = analogRead(ADC);
    unsigned duty = bruto * 255UL / 4095;
    ledcWrite(LED, duty);
    Serial.printf("ADC=%d PWM=%u\n", bruto, duty);
  }
}
