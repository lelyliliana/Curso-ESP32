#include <Arduino.h>
#include <esp_sleep.h>
RTC_DATA_ATTR uint32_t arranques = 0;
void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.printf("Despertar=%d, contador RTC=%u\n", esp_sleep_get_wakeup_cause(),
                ++arranques);
  Serial.println("Duermo 10 s; no uso Wi-Fi en esta medicion");
  Serial.flush();
  esp_sleep_enable_timer_wakeup(10ULL * 1000000ULL);
  esp_deep_sleep_start();
}
void loop() {}
