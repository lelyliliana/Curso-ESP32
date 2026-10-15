# Servir una página desde el dispositivo

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [servidor_web](ejemplos/servidor_web/servidor_web.ino). Abre el código completo mientras sigues el recorrido.


**Apoyo para este recorrido:** [protocolos y estados](../docs/RECORRIDOS_PROTOCOLOS.md) · [lectura del soporte de red/MQTT](../docs/LECTURA_RED_MQTT.md).

## 1. Cambia el papel del ESP32

En la unidad anterior ESP32 consultaba un servidor del computador. Ahora crea `WebServer server(80)` y escucha peticiones. El navegador del computador o teléfono es el cliente. La página proviene del programa cargado en la placa; el router permite la comunicación local, pero no genera ese HTML.

Primero observa la IP que anuncia el soporte de red. Desde un equipo con acceso a esa LAN abre `http://IP_ESP32/`. No utilices LAB_HOST para identificar automáticamente esta placa: en otros ejemplos esa constante nombra al computador de servicios. La IP local puede cambiar entre conexiones.

## 2. Registra comportamiento antes de escuchar

`server.on` asocia ruta, método y función. La ruta `/` acepta GET y ejecuta una función lambda sin argumentos. Dentro se responde 200 con tipo `text/html; charset=utf-8` y un documento HTML. La respuesta combina código, tipo de contenido y cuerpo; no son la misma pieza.

`onNotFound` define la respuesta de los casos que no coinciden con las rutas registradas. `server.begin` inicia el servicio. Ninguna de esas instrucciones sustituye atenderlo después.

## 3. Qué hace loop

Cada vuelta llama atenderRed y server.handleClient. El segundo atiende peticiones pendientes en el modelo de esta biblioteca. Si se elimina, la placa puede conservar su enlace Wi-Fi e incluso anunciar IP, pero deja de atender correctamente las peticiones de esta aplicación.

| Ensayo | Lo esperado |
|---|---|
| GET / | Página del nodo con estado 200 |
| GET /no-existe | Texto Ruta inexistente y 404 |
| Quitar handleClient en una copia | Degradación de atención, no pérdida necesaria de Wi-Fi |

No evalúes solo una página ya cargada: el navegador puede conservar contenido anterior. Repite una petición nueva y observa resultado en las herramientas de red o un cliente HTTP.

## 4. Modifica la respuesta, no el servidor equivocado

Añade un identificador de nodo al HTML que está dentro del callback. Carga esa copia y solicita de nuevo la página. Si modificas el servidor Python del computador no cambiará la página embebida del ESP32. Ubicar qué proceso responde es parte de depurar un sistema distribuido.

## 5. Reconoce el alcance de la demostración

Es una página fija. No autentica usuarios, no almacena formularios y no representa automáticamente un sensor. Para incorporar datos tendrías que adquirirlos y construir una respuesta con un contrato claro. Una página visible en LAN tampoco demuestra que sea accesible desde Internet; el laboratorio no requiere publicar puertos del router.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las soluciones](SOLUCIONES.md) · [Volver a la unidad](README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2008%20%E2%80%94%20Servidor%20web%20en%20ESP32%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad08-servidor-web%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
