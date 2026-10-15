# Verificación de la versión 1.2

La validación separa compilación, software de servicio y pruebas físicas. Se utiliza la referencia clásica de ENTORNO, no una selección genérica de todas las familias ESP32.

## Comprobaciones reproducibles

Desde la raíz del curso, ejecuta cada comando por separado; usa python3 o py -3 según tu sistema.

```text
python scripts/verificar_material.py
```

```text
python -m unittest discover -s tests -v
```

```text
python scripts/compilar.py
```

La suite del receptor comprueba almacenamiento SQLite previo al ACK, duplicados después de perder la respuesta, conflicto de contenido, tipos/identidad inválidos, reenvíos simultáneos y comportamiento HTTP (200/201/400/404/409/413/415). Los tests ejecutan el servidor solo en loopback con archivos temporales; no modifican tu configuración.

## Revisión didáctica 1.2 (2026-10-14, America/Bogota)

- Se recompilaron los **26 sketches: todos correctos**, con `esp32:esp32:esp32`, Arduino CLI 1.2.2, Arduino-ESP32 3.3.12, ArduinoJson 7.4.2 y PubSubClient 2.8.0. No se cargó firmware ni se conectó la placa a una red.
- Se ejecutaron las siete pruebas del receptor HTTP/SQLite: todas aprobadas. Son comprobaciones de software en loopback, no de conexión de una placa.
- Se revisaron los enlaces locales de todo el curso y el acceso desde unidades/laboratorios a los 24 desarrollos y 24 soluciones ampliadas.
- Los seis esquemas SVG se comprobaron como XML, se renderizaron y revisaron visualmente y se contrastaron con los GPIO de los programas. No son simulaciones eléctricas.
- Se revisaron cinco diagramas Mermaid de protocolos/estados y la tabla de tiempos de backoff, además de las distinciones entre publicación, recepción y persistencia.
- Se contrastaron cálculos de ADC/PWM, intervalos de reintento, corriente media/carga y energía con tensión explícita. Las copias de red_lab.h y mqtt_lab.h son coherentes entre sus respectivos sketches.
- Los 26 sketches y headers conservan su código en esta ampliación; los cambios de ejercicios se realizan en copias.

## Registro anterior (versión 1.1)

- 24 laboratorios y sus soluciones conectados a las unidades.
- 7 pruebas del receptor aprobadas.
- **26 sketches compilados correctamente** para `esp32:esp32:esp32` con Arduino-ESP32 3.3.12, ArduinoJson 7.4.2 y PubSubClient 2.8.0.
- Catálogo, nombres de carpetas Arduino y enlaces locales comprobados, sin rutas faltantes.
- Fecha de revisión: 2026-10-13. Se utilizó Arduino CLI 1.5.1; no se cargó firmware a una placa.

## Qué aún requiere equipo físico

Montaje eléctrico, compatibilidad de tu módulo, lectura SHT31, detección de rebote, Wi-Fi, MQTT entre placa y LAN, lectura BLE desde teléfono, actualización OTA por radio y consumo energético. Los ejemplos 18 y 19 dependen además de configuración de confianza/clave propia. No se han realizado esas pruebas en este entorno.

No se marca como probado un caso porque exista código. Los resultados esperados del laboratorio son criterios que cada estudiante contrasta con su hardware. MQTT de LAN tiene una guía reproducible; el broker Docker no se ejecutó en este entorno.
