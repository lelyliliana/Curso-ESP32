# Curso de ESP32 e Internet de las Cosas

Curso abierto para avanzar desde prototipos con microcontroladores hacia **dispositivos conectados e Internet de las Cosas (IoT)** utilizando ESP32.

Este curso asume conocimientos básicos de programación, circuitos, entradas/salidas, sensores y actuadores. Si comienzas desde cero, realiza primero el curso de Arduino.

## Objetivo

Al finalizar podrás:

- preparar un entorno de desarrollo para ESP32;
- reconocer diferencias importantes entre familias y placas ESP32;
- seleccionar GPIO considerando restricciones de la placa;
- trabajar correctamente con lógica de 3.3 V;
- conectar ESP32 a redes Wi‑Fi;
- crear clientes y servidores HTTP;
- consumir y publicar datos mediante APIs;
- utilizar MQTT para telemetría y control;
- trabajar con Bluetooth/BLE a nivel introductorio;
- almacenar configuración y datos;
- diseñar dispositivos IoT con reconexión y manejo de fallos;
- comprender OTA, seguridad básica y gestión de credenciales;
- considerar consumo energético y modos de bajo consumo;
- construir un proyecto IoT completo.

## Requisito recomendado

[Curso de Arduino desde cero](https://github.com/lelyliliana/Curso-Arduino)

## Importante sobre ESP32

**ESP32 no es una única placa.** Existen diferentes familias, módulos y tarjetas de desarrollo con pinouts y capacidades distintas.

Antes de conectar hardware:

1. identifica el modelo exacto;
2. consulta su documentación y pinout;
3. verifica tensión y restricciones de GPIO;
4. evita asumir que un ejemplo para otra placa es eléctricamente equivalente.

La lógica de ESP32 es habitualmente de **3.3 V**. No apliques 5 V a un GPIO salvo que la documentación específica indique compatibilidad.

## Ruta de aprendizaje

### Nivel 1 — Plataforma ESP32
- [Unidad 00 — Preparación, seguridad y placa](unidad00-preparacion/)
- [Unidad 01 — Arquitectura, GPIO y diferencias con Arduino](unidad01-arquitectura-gpio/)
- [Unidad 02 — Primer programa y diagnóstico serial](unidad02-primer-programa/)

### Nivel 2 — Hardware aplicado
- [Unidad 03 — Entradas, salidas, ADC y PWM](unidad03-io-adc-pwm/)
- [Unidad 04 — Sensores, I2C y SPI](unidad04-sensores-buses/)
- [Unidad 05 — Interrupciones, temporización y tareas](unidad05-interrupciones-tareas/)

### Nivel 3 — Wi‑Fi y Web
- [Unidad 06 — Conexión Wi‑Fi y reconexión](unidad06-wifi/)
- [Unidad 07 — Cliente HTTP y consumo de APIs](unidad07-cliente-http/)
- [Unidad 08 — Servidor web en ESP32](unidad08-servidor-web/)
- [Unidad 09 — API REST básica en el dispositivo](unidad09-api-rest/)

### Nivel 4 — IoT
- [Unidad 10 — Fundamentos de MQTT](unidad10-mqtt/)
- [Unidad 11 — Telemetría y control con MQTT](unidad11-telemetria-control/)
- [Unidad 12 — Diseño de mensajes y JSON](unidad12-json-mensajes/)
- [Unidad 13 — Arquitectura de un sistema IoT](unidad13-arquitectura-iot/)

### Nivel 5 — Comunicación y persistencia
- [Unidad 14 — Bluetooth y BLE](unidad14-ble/)
- [Unidad 15 — Almacenamiento y configuración](unidad15-almacenamiento/)
- [Unidad 16 — Registro local y sincronización](unidad16-registro-sincronizacion/)

### Nivel 6 — Dispositivo robusto
- [Unidad 17 — Manejo de fallos y reconexión](unidad17-fallos-reconexion/)
- [Unidad 18 — Credenciales y seguridad básica](unidad18-seguridad/)
- [Unidad 19 — Actualizaciones OTA](unidad19-ota/)
- [Unidad 20 — Consumo energético y deep sleep](unidad20-energia/)

### Nivel 7 — Proyectos
- [Unidad 21 — Proyecto: nodo IoT ambiental](unidad21-proyecto-nodo-iot/)
- [Unidad 22 — Proyecto: control remoto](unidad22-proyecto-control/)
- [Unidad 23 — Proyecto final IoT](unidad23-proyecto-final/)

## Metodología

Cada práctica seguirá, cuando corresponda:

1. objetivo;
2. arquitectura;
3. hardware;
4. restricciones eléctricas;
5. configuración;
6. código;
7. prueba;
8. observabilidad;
9. manejo de fallos;
10. reto.

## Principio

> Un dispositivo IoT no está terminado cuando logra conectarse una vez; debe poder funcionar, fallar, recuperarse y explicar qué está ocurriendo.

## Autora

**Leli Liliana Díaz Izquierdo**

Ingeniera de Sistemas · Docente investigadora · Tecnología, educación e investigación.
