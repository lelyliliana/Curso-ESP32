#include <Arduino.h>
void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.printf("Chip: %s revision %d, nucleos %d\n", ESP.getChipModel(),
                ESP.getChipRevision(), ESP.getChipCores());
  Serial.printf("Flash: %u bytes; heap libre: %u\n", ESP.getFlashChipSize(),
                ESP.getFreeHeap());
}
void loop() { delay(1000); }
