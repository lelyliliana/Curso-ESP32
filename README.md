# Curso de ESP32 e Internet de las Cosas

**[Comenzar el curso: Unidad 00 — Preparación, seguridad y placa ESP32](unidad00-preparacion/README.md)**

Puedes leer las lecciones aquí sin conocer GitHub. Al terminar cada unidad, usa **Siguiente unidad** para avanzar; **Unidad anterior** y **Volver al índice** te permiten regresar.

[Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/esp32/)

**Versión 1.2 (desarrollo de programas, protocolos y conexiones)**

Curso abierto para avanzar desde prototipos con microcontroladores hacia **dispositivos conectados e Internet de las Cosas (IoT)** utilizando ESP32.

Este curso asume conocimientos básicos de programación, circuitos, entradas/salidas, sensores y actuadores. Si comienzas desde cero, realiza primero el curso de Arduino.

## Comienza con una práctica reproducible

Consulta el [entorno fijado y montaje de referencia](docs/ENTORNO.md), los [24 laboratorios progresivos](laboratorios/README.md) y los [servicios locales HTTP/MQTT](laboratorios/servicios/README.md). Cada unidad enlaza programa completo, experimento, resultado esperado y soluciones razonadas. Revisa [qué se verificó](docs/VERIFICACION.md) antes de interpretar una compilación como prueba física.

## Cómo seguir cada unidad

Cada unidad enlaza un **Desarrollo paso a paso** que acompaña sus programas completos: explica entradas, decisiones, estados, datos y límites. Después realiza el laboratorio y compara las soluciones desarrolladas cuando hayas intentado sus ejercicios.

1. Predice un caso pequeño antes de ejecutar.
2. Identifica el montaje en el [atlas de seis esquemas](docs/ATLAS_CONEXIONES.md), cuando corresponda.
3. Sigue el código y las tablas; abre también los headers del programa.
4. Ejecuta una referencia y cambia una sola condición.
5. Contrasta el resultado y registra qué capa comprobaste.

Para red y servicios utiliza la [lectura del soporte Wi-Fi/MQTT](docs/LECTURA_RED_MQTT.md) y los [recorridos visuales de protocolos y estados](docs/RECORRIDOS_PROTOCOLOS.md). Estos distinguen conexión, recepción, persistencia y efecto físico. Las [fuentes técnicas](docs/FUENTES_TECNICAS.md) permiten ampliar cada API y componente.

Los sketches de referencia conservan su comportamiento. Las ampliaciones del desarrollo se realizan en copias; un proyecto propuesto no se presenta como una función ya implementada.

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

## Material disponible y evaluación

El repositorio reúne 24 unidades (00–23), guías, ejemplos introductorios, plantillas, prácticas y proyectos por etapas. Las guías de proyectos conservan el alcance avanzado; los laboratorios incorporan bases ejecutables de sensor ambiental, control de LED e integración, con límites explícitos. Cada montaje requiere comprobar sus versiones, compilación y funcionamiento físico.

- [Arquitectura pedagógica](docs/ARQUITECTURA.md).
- [Diagnóstico IoT por capas](docs/DIAGNOSTICO_IOT.md).
- [Plantilla del proyecto final](unidad23-proyecto-final/PLANTILLA_PROYECTO.md).
- [Checklist de aceptación](unidad23-proyecto-final/CHECKLIST.md).
- [Rúbrica técnica de 100 puntos](unidad23-proyecto-final/RUBRICA.md).
- [Alcance de la versión](VERSION.md).

Documenta resultados reales, simulados y pendientes; conserva autoría/licencias y declara el uso de IA con las comprobaciones realizadas.

## Principio

> Un dispositivo IoT no está terminado cuando logra conectarse una vez; debe poder funcionar, fallar, recuperarse y explicar qué está ocurriendo.

## Autora

**Leli Liliana Díaz Izquierdo**

Ingeniera de Sistemas · Docente investigadora · Tecnología, educación e investigación.

---

### ¿Necesitas acompañamiento personalizado?

Puedes estudiar este curso por tu cuenta. Si necesitas apoyo para configurar el entorno, comprender o resolver un error, o aplicar lo aprendido a tu tesis o proyecto, podemos trabajarlo en una sesión individual.

- **Preparar el entorno:** revisar la instalación y configuración de herramientas y dependencias.
- **Comprender y resolver errores:** analizar lo que ocurre y trabajar en una solución.
- **Aplicarlo a tu proyecto:** te acompaño a comprender el contenido y adaptarlo a tu caso.

[**Solicitar asesoría sobre este curso**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20revisando%20el%20curso%20de%20ESP32%20e%20Internet%20de%20las%20Cosas%20(lelyliliana%2FCurso-ESP32)%20y%20me%20interesa%20una%20asesor%C3%ADa%20personalizada.%20Necesito%20apoyo%20con%E2%80%A6)
