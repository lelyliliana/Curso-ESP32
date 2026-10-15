# Seguir un mensaje MQTT y distinguir tres tópicos

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [mqtt_publicar](ejemplos/mqtt_publicar/mqtt_publicar.ino). Abre el código completo mientras sigues el recorrido.


**Apoyo para este recorrido:** [protocolos y estados](../docs/RECORRIDOS_PROTOCOLOS.md) · [lectura del soporte de red/MQTT](../docs/LECTURA_RED_MQTT.md).

## 1. Los participantes tienen roles

ESP32 se conecta como cliente al broker del computador, puerto 1883. Otro cliente se suscribe para observar. El broker recibe publicaciones y las distribuye según tópicos y suscripciones. No genera la lectura ni garantiza que otro programa la guarde.

El soporte mqtt_lab.h configura cliente, keepalive de 15 s, timeout de socket de 2 s y buffer de 512 bytes. Usa credenciales de laboratorio y transporte WiFiClient sin TLS. La [lectura del soporte](../docs/LECTURA_RED_MQTT.md) muestra cómo se combina con red_lab.h.

## 2. Separa tópico, contenido y política

| Tópico | Contenido de esta referencia | Retained |
|---|---|---|
| curso/nodo01/availability | online u offline | Sí |
| curso/nodo01/telemetry | JSON con uptime_ms | No |
| curso/nodo01/command | Se utilizará para control en otra unidad | No usar retained en los ensayos |

Los tópicos son nombres que el sistema acordó, no propiedades especiales activadas por escribir esas palabras. La barra organiza un espacio de nombres.

## 3. Conexión y Last Will

Al conectar se registra un testamento: availability=offline, QoS1 y retained. Si el broker detecta una desconexión no limpia, podrá publicarlo. Después del éxito de conexión el firmware publica online retenido. La detección de pérdida depende del protocolo y del estado de la conexión; no es instantánea al quitar alimentación.

`atenderMqtt` devuelve true al establecer una conexión nueva. En vueltas posteriores llama mqtt.loop para mantener el protocolo y procesar mensajes. Un delay largo puede impedir atenderlo con la frecuencia necesaria.

## 4. Publicación de la muestra

Cada cinco segundos, estando conectado, se construye JSON con uptime_ms y se publica sin retained. Es tiempo de actividad de la placa, no temperatura. PubSubClient publica estos mensajes con QoS0. Que publish retorne true no confirma que un suscriptor lo procesó ni que una base de datos lo almacenó.

Abre primero un suscriptor, observa dos mensajes y después abre otro. El segundo puede recibir el último availability retenido, pero no un histórico de telemetría. Deberá esperar publicaciones nuevas de esa telemetría.

## 5. Identidad de otro nodo

Cambiar solo el tópico no basta para añadir una segunda placa. Cada cliente necesita clientId único; de otro modo se desplazan sesiones con la misma identidad. Revisa además tópico, credenciales y ACL. El laboratorio comparte usuario y permisos para nodo01: no implementa automáticamente aislamiento de otro nodo.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las soluciones](SOLUCIONES.md) · [Volver a la unidad](README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2010%20%E2%80%94%20Fundamentos%20de%20MQTT%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad10-mqtt%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
