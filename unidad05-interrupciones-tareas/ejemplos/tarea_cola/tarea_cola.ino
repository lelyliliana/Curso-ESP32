#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/queue.h>
#include <freertos/task.h>
QueueHandle_t cola = nullptr;
void producir(void *) {
  uint32_t numero = 0;
  while (true) {
    numero++;
    if (xQueueSend(cola, &numero, pdMS_TO_TICKS(100)) !=
        pdTRUE) { /* Cola llena: en este laboratorio se omite el contador, sin memoria
                     ilimitada. */
    }
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}
void setup() {
  Serial.begin(115200);
  cola = xQueueCreate(4, sizeof(uint32_t));
  if (!cola || xTaskCreate(producir, "productor", 2048, nullptr, 1, nullptr) != pdPASS) {
    Serial.println("No crea cola/tarea");
    while (true)
      delay(1000);
  }
}
void loop() {
  uint32_t recibido;
  if (xQueueReceive(cola, &recibido, 0) == pdTRUE)
    Serial.printf("Recibido=%u\n", recibido);
  delay(1);
}
