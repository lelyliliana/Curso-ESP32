# Interpretar una petición HTTP de extremo a extremo

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [cliente_http](ejemplos/cliente_http/cliente_http.ino). Abre el código completo mientras sigues el recorrido.


**Apoyo para este recorrido:** [protocolos y estados](../docs/RECORRIDOS_PROTOCOLOS.md) · [lectura del soporte de red/MQTT](../docs/LECTURA_RED_MQTT.md).

## 1. Identifica quién escucha

ESP32 es el cliente; el programa Python del computador escucha como servidor en puerto 8000. Primero comprueba el servicio local según su guía. Para acceso desde la placa debe escuchar en la interfaz LAN apropiada, no solo en loopback.

El recurso `/medicion` devuelve una muestra fija marcada como simulated. Su objetivo es estudiar transporte y contrato. Que su nombre contenga medición no lo convierte en una lectura de un sensor conectado.

## 2. Sigue una operación completa

El loop atiende red y solo intenta GET si está conectado y venció el periodo de cinco segundos. Crea un transporte WiFiClient y una operación HTTPClient; fija límites de conexión y lectura de dos segundos. `http.begin` prepara la URL. `http.GET` ejecuta la solicitud y produce un código.

| Resultado | Interpretación |
|---|---|
| 200 | El servidor respondió con éxito a esa petición |
| 404 | Un servidor HTTP respondió, pero no encontró la ruta |
| Código negativo de HTTPClient | Fallo de transporte o cliente, según error informado |
| JSON con source simulated | El dato sigue siendo simulado aunque HTTP sea 200 |

Después de utilizar la respuesta se llama `http.end` para liberar recursos de la operación.

## 3. Lo que todavía no valida

La referencia imprime el cuerpo de un 200. No comprueba esquema, tipos, unidades ni origen. Si el servidor devolviera un texto inesperado con ese código, la referencia también lo mostraría. La Unidad 12 enseñará a exigir un contrato.

Los timeouts limitan aspectos de conexión/lectura; no equivalen a una promesa exacta de duración total de dos segundos. GET es síncrono y puede retrasar otras tareas del loop. El periodo de cinco segundos no garantiza una operación no bloqueante.

## 4. Diseña tres fallos diferentes

Primero solicita la ruta correcta. Después cambia solo `/medicion` por una ruta inexistente y observa 404. Restaura la ruta, detén el servidor y compara el error de transporte. Por último cambia únicamente el contenido de prueba del servidor en una copia y conserva source simulated.

Registra tiempo antes y después de la operación si necesitas medir su demora. Una respuesta 404 demuestra que se alcanzó un servidor en ese ensayo; no significa que faltara Wi-Fi. Separa la capa que falló de la descripción humana del problema.

## 5. Una ampliación verificable

Propón validar nodo, temperatura y source antes de representar el dato. No elimines la etiqueta simulated para que parezca un sensor real. La procedencia es parte de la información que necesita quien interpreta la lectura.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las soluciones](SOLUCIONES.md) · [Volver a la unidad](README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2007%20%E2%80%94%20Cliente%20HTTP%20y%20consumo%20de%20APIs%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad07-cliente-http%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
