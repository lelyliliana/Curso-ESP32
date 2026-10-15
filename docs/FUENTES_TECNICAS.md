# Fuentes técnicas del desarrollo ESP32

[Curso](../README.md) · [Entorno fijado](ENTORNO.md) · [Soporte de red](LECTURA_RED_MQTT.md)

El curso utiliza ESP32 clásico/WROOM-32 y Arduino-ESP32 3.3.12. Para otra familia revisa capacidades y terminales antes de reutilizar esquemas. Las versiones de bibliotecas que fijan la referencia están en ENTORNO.

| Tema | Fuente primaria | Aspecto consultado |
|---|---|---|
| Core y APIs | [Arduino-ESP32](https://docs.espressif.com/projects/arduino-esp32/en/latest/) | API del entorno y diferencias por familia |
| GPIO | [GPIO ESP32 clásico](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/peripherals/gpio.html) | Entradas exclusivas, polarización y restricciones |
| ADC | [API ADC](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/adc.html) | Código crudo, atenuación y conversión a milivoltios |
| PWM | [API LEDC](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/ledc.html) | Pin, frecuencia, resolución y resultado de configuración |
| Migración | [Cambios 2.x a 3.x](https://docs.espressif.com/projects/arduino-esp32/en/latest/migration_guides/2.x_to_3.0.html) | Cambios de API que afectan ejemplos antiguos |
| Sensor | [SHT31 (Sensirion)](https://sensirion.com/products/catalog/SHT31-DIS-B) | Comandos, palabras de respuesta, CRC y fórmulas |
| MQTT | [PubSubClient: API](https://pubsubclient.knolleary.net/api) | Conexión, testamento, publicación y suscripción |
| Broker | [Mosquitto](https://mosquitto.org/man/mosquitto-conf-5.html) | Autenticación y permisos de la guía local |
| JSON | [ArduinoJson 7](https://arduinojson.org/v7/) | Deserialización, tipos y representación |
| Persistencia | [Preferences](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/preferences.html) | Namespace, tipos y resultados de escritura |
| Sueño | [Sleep modes ESP32](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/system/sleep_modes.html) | Despertar y retención de memoria RTC |
| BLE | [Ejemplos BLE de core 3.3.12](https://github.com/espressif/arduino-esp32/tree/3.3.12/libraries/BLE/examples) | Servicios y propiedades de características |
| OTA | [ArduinoOTA de core 3.3.12](https://github.com/espressif/arduino-esp32/tree/3.3.12/libraries/ArduinoOTA) | Recepción de actualización y callbacks |

Las referencias ayudan a interpretar la implementación. No se les atribuye una prueba de hardware del curso. Las lecturas simuladas, los resultados de pruebas de software y las observaciones físicas se registran por separado.
