# Leer el soporte de red sin saltarse su implementación

[Curso](../README.md) · [Servicios del laboratorio](../laboratorios/servicios/README.md) · [Recorridos de protocolos](RECORRIDOS_PROTOCOLOS.md)

Los sketches de red incluyen archivos del propio curso. No son bibliotecas ocultas: forman parte del programa que debes estudiar. La copia de referencia para esta lectura es [red_lab.h](../unidad06-wifi/ejemplos/wifi_estado/red_lab.h) y [mqtt_lab.h](../unidad10-mqtt/ejemplos/mqtt_publicar/mqtt_lab.h). Los demás laboratorios conservan esas funciones en su carpeta para que cada sketch pueda abrirse completo.

## 1. Abre configuración antes de buscar el servidor

red_lab.h incluye configuración pública y, si existe, config_local.h de tu copia. `__has_include` comprueba presencia de archivo al compilar; no descarga configuraciones de Internet. Los valores de ejemplo permiten construir el firmware, pero sus placeholders no son credenciales que funcionen en tu red.

| Nombre | Qué espera | Error que debes evitar |
|---|---|---|
| LAB_WIFI_SSID | Nombre de red compatible | Confundirlo con hostname del servidor |
| LAB_WIFI_PASS | Credencial de esa red | Imprimirla para demostrar conexión |
| LAB_HOST | IP o nombre alcanzable del computador de servicios | Usar 127.0.0.1 esperando llegar desde ESP32 al computador |
| LAB_MQTT_USER / PASS | Credenciales del broker de práctica | Suponer que cifran el transporte |
| LAB_OTA_PASS | Clave local de actualización | Mantener el placeholder como si fuera una clave elegida |

`127.0.0.1` nombra al equipo donde se utiliza. El servicio Python escucha por defecto solo en loopback. Primero se prueba desde el mismo computador; para la placa se configura la interfaz LAN autorizada según su guía. Una IP puede cambiar por la configuración de red: comprueba cuál tiene cada equipo durante el ensayo.

## 2. iniciarRed configura y comienza

`WiFi.mode(WIFI_STA)` define al ESP32 como estación. `WiFi.setAutoReconnect(true)` habilita reconexión del core y `WiFi.begin` solicita iniciar enlace con los valores configurados. La marca wifiIntento registra el momento de esa solicitud.

No hay aquí un bucle que detenga todo esperando conexión. Que iniciarRed retorne no significa que DHCP, aplicación HTTP y broker estén listos. La observación se realiza después, atendiendo el soporte en loop.

## 3. atenderRed observa cambios y solicita reintento

Compara `WiFi.status()` con WL_CONNECTED. Si acaba de conectar y antes no lo estaba, imprime IP. Si acaba de perderlo después de estar conectado, anuncia pérdida. Actualiza wifiEstaba para que esos mensajes informen transiciones y no llenen el monitor en cada vuelta.

Cuando no hay enlace y han pasado al menos 15000 ms desde la marca, solicita WiFi.reconnect y actualiza esa marca. La política manual convive con reconexión automática del core; no demuestra una única operación exacta cada quince segundos. Cambiar el periodo de impresión de un sketch no cambia esta condición de reintento.

**Predicción útil:** mientras no se conecte, el sketch wifi_estado puede seguir imprimiendo su tarea local cada dos segundos. Una tarea local que progresa no prueba disponibilidad de red; una IP asignada no prueba disponibilidad de un servicio.

## 4. iniciarMqtt prepara un cliente, no una base de datos

WiFiClient es el transporte de esta referencia. PubSubClient lo utiliza para conectar con LAB_HOST:1883. Se fijan timeout de socket de 2 s, keepalive de 15 s y buffer de 512 bytes. El buffer contiene información de los paquetes; no debe interpretarse como 512 bytes garantizados de cualquier payload sin considerar cabeceras/tópico.

El código usa transporte sin TLS. El usuario/contraseña se valida en el broker, pero no cifra por sí mismo los mensajes. Los laboratorios trabajan en una LAN autorizada y no publican ese puerto en Internet.

## 5. atenderMqtt tiene tres recorridos

| Situación | Trabajo de la función | Retorno |
|---|---|---|
| Wi-Fi no conectado | Atiende red y no intenta MQTT | false |
| MQTT desconectado y no vence plazo manual | Conserva espera | false |
| MQTT desconectado y corresponde intentar | Ejecuta connect; informa fallo o éxito | true solo si estableció sesión |
| MQTT ya conectado | Ejecuta mqtt.loop | false |

El primer intento MQTT se permite sin esperar cinco segundos. Después de un intento se espacian los siguientes con la marca mqttIntento. `connect` sigue siendo una operación síncrona que puede tardar; organizar su frecuencia no la vuelve no bloqueante.

Un retorno false no significa siempre fallo de conexión. También es el resultado normal de atender una sesión ya establecida. Un sketch que usa `bool nueva = atenderMqtt()` utiliza true para volver a suscribirse y publicar estado al reconectar.

## 6. Conexión, testamento y publicación

La llamada connect utiliza clientId leli-nodo01, credenciales y Last Will en `curso/nodo01/availability`: mensaje offline, QoS1 y retained. Cuando conecta, el firmware solicita publicar online retenido. El resultado de esa publicación inicial no se comprueba en el header; una sesión establecida no es por sí sola evidencia de que todos los consumidores recibieron online.

Si se pierde la conexión de manera no limpia, el broker publica el testamento cuando detecta la condición correspondiente. El tiempo depende del protocolo y del enlace; no prometas offline en el instante exacto en que se quitó alimentación.

La llamada habitual publish de PubSubClient usada para telemetría es QoS0. Retained decide si el broker conserva el último mensaje de un tópico para futuras suscripciones. Ninguna de esas opciones añade un ACK durable de aplicación ni una tabla histórica de una base.

## 7. Mantener el protocolo también es trabajo

mqtt.loop atiende tráfico y mecanismos de mantenimiento. Una operación HTTP larga, una conversión bloqueante o una impresión excesiva pueden retrasarla. El loop de aplicación necesita una política de tiempos para todos sus trabajos.

En control, el callback recibe bytes con longitud. No uses funciones de cadenas que asuman un terminador cero que el payload no garantiza. Los ejemplos pasan payload y largo directamente a ArduinoJson. La validación precede al cambio de salida.

## 8. Añadir un segundo nodo exige varios cambios

No basta publicar otro campo nodo. Define clientId único, prefijo propio, credenciales/permisos y contratos de servicio coherentes. Los archivos de broker de práctica permiten el prefijo de nodo01 con usuario compartido. El receptor HTTP también valida nodo01: un cambio de etiqueta requiere coordinación, no solo editar una constante de un productor.

**Comprobación de comprensión:** explica por qué puedes tener Wi-Fi disponible y MQTT rechazado, MQTT conectado y sensor inválido, JSON local correcto y ningún dato guardado, o un mensaje state retenido que ya no describe una observación física actual. Son combinaciones posibles porque cada capa comprueba una propiedad distinta.
