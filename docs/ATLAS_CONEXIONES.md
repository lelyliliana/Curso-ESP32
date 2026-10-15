# Atlas de conexiones ESP32

[Curso](../README.md) · [Entorno y tabla de conexiones](ENTORNO.md) · [Recorridos de protocolos](RECORRIDOS_PROTOCOLOS.md)

Referencia ESP32 clásico/WROOM-32. Son esquemas funcionales: no describen orientaciones universales de módulos ni una protoboard. Los ejemplos de red, BLE, NVS, OTA y sueño que no usan sensores/salidas requieren solo la placa y el entorno de comunicación indicado en su laboratorio.

| Esquema | Recurso físico |
|---|---|
| [Salida LED de laboratorio](esquemas/led.svg) | Etiquetas de GPIO y conexiones verificables |
| [Botón local y LED independientes](esquemas/boton-led.svg) | Etiquetas de GPIO y conexiones verificables |
| [Potenciómetro y salida PWM LEDC](esquemas/adc-pwm.svg) | Etiquetas de GPIO y conexiones verificables |
| [SHT31 compatible con lógica y alimentación 3.3 V](esquemas/sht31.svg) | Etiquetas de GPIO y conexiones verificables |
| [SPI loopback sin periférico](esquemas/spi.svg) | Etiquetas de GPIO y conexiones verificables |
| [Integrador: SHT31, prioridad local y LED](esquemas/integrador.svg) | Etiquetas de GPIO y conexiones verificables |

Para añadir una placa S2, S3 o C3, revisa primero capacidades y pinout. No se transfiere la numeración de estos diagramas sin adaptación. No todas las familias incluyen BLE.
