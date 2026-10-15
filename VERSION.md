# Versión 1.2: desarrollo didáctico de ESP32 e IoT

Fecha: 2026-10-14 (America/Bogota).

Las 24 unidades incorporan desarrollos específicos del código, tablas de seguimiento, derivaciones, experimentos y diagnóstico por capas. Se amplían las 24 soluciones y se añaden seis esquemas SVG, cinco diagramas Mermaid de protocolos/estados y una tabla temporal de backoff.

La guía de red/MQTT explica los headers locales, configuración, reconexión, retorno de funciones, QoS, Last Will y alcance de publicación. Se desarrollan además ADC/LEDC, integridad SHT31, ISR/tareas, contratos JSON, BLE de lectura, NVS, reenvío con identidad estable, TLS, OTA, sueño y los tres proyectos.

Se conserva el código de los 26 sketches. El material hace explícitos límites que ya existen: cola de un evento con escrituras separadas, telemetría sin persistencia en el nodo ambiental, comandos sin verificación de antigüedad y prioridad local sujeta a tiempos del loop. La actualización OTA no declara firma ni rollback probado.

Consulta el [registro de verificación](docs/VERIFICACION.md) y conserva evidencia física de cada montaje.

---

# Versión 1.1: laboratorios de referencia

Fecha: 2026-10-13.

Se conserva el recorrido 00–23 y se añaden 26 sketches independientes, 24 laboratorios y 24 soluciones razonadas. El índice LABORATORIOS permite realizar el curso por incrementos con materiales, configuración, experimentos, esperado, errores y alcance explícito.

## Combinación de referencia

ESP32 clásico/WROOM-32, perfil esp32:esp32:esp32, Arduino-ESP32 3.3.12, ArduinoJson 7.4.2 y PubSubClient 2.8.0. Servidor Python 3.10+ con SQLite y broker Mosquitto 2.0.22 de LAN. Consulta docs/ENTORNO.md para instalación y adaptación a otras placas.

## Qué implementa

- Identidad, GPIO, ADC/PWM, SHT31 I2C con CRC e interrupción breve.
- Diagnóstico/reconexión Wi-Fi, HTTP cliente/servidor y API LED validada.
- MQTT autenticado de LAN, disponibilidad, telemetría y control por estado deseado.
- JSON validado, modelo de arquitectura y backoff simulado.
- BLE de solo lectura, NVS y un pendiente durable con ACK HTTP por identidad.
- HTTPS con CA configurada por el estudiante, OTA local y deep sleep por timer.
- Bases de nodo ambiental, control con prioridad local e integrador.

## Alcance honesto

Las bases 21–23 no implementan todos los requisitos avanzados de sus guías. MQTT QoS0 no conserva lecturas perdidas; el pendiente de 16 tiene capacidad uno y no registra temperatura; la unidad 20 no representa una medición energética ya realizada; la unidad 19 no implementa firma/rollback de flota. La unidad 18 necesita endpoint y CA de confianza. Las unidades 13 y 17 son simulaciones, no red real.

Cola multirregistro, jitter integrado, órdenes con ID/expiración y dashboard durable se desarrollan como extensiones según el proyecto. No se presentan como capacidades ya ejecutadas. Usa la rúbrica con evidencia del alcance real.

## Verificación

Consulta docs/VERIFICACION.md para compilación, pruebas del receptor y enlaces. Sin placa física en este entorno, pruebas eléctricas, radio, OTA real, consumo y latencia de control permanecen pendientes para cada montaje. El código compilado no reemplaza esas evidencias.
