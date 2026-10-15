# Definir una API que representa un estado

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [api_led](ejemplos/api_led/api_led.ino). Abre el código completo mientras sigues el recorrido.



**Apoyo para este recorrido:** [protocolos y estados](../docs/RECORRIDOS_PROTOCOLOS.md) · [lectura del soporte de red/MQTT](../docs/LECTURA_RED_MQTT.md).

## Esquema de conexiones

Los diagramas identifican señales, no posiciones físicas. Usa la referencia clásica y confirma el pinout de tu tarjeta y módulo. [Atlas completo](../docs/ATLAS_CONEXIONES.md).

![Salida LED de laboratorio](../docs/esquemas/led.svg)


## 1. El recurso es el estado del LED

GET `/api/led` representa `activo` como JSON. PUT en esa misma ruta solicita un estado con el cuerpo `{"activo":true}` o `{"activo":false}`. No es un comando alternar: pedir true dos veces conserva el estado encendido.

La respuesta representa una variable del firmware. No hay sensor de brillo o corriente. Tampoco existe una etapa de potencia: GPIO25 controla el LED con su resistencia.

## 2. Sigue la validación antes del efecto

El callback cambiar deserializa el cuerpo sin procesar. Si falla el JSON, hay una cantidad de campos distinta de uno o activo no es booleano, responde 400 y retorna antes de modificar la variable y la salida.

| Cuerpo | Decisión |
|---|---|
| {"activo":true} | Solicita ON y representa estado |
| {"activo":false} | Solicita OFF y representa estado |
| {} | 400; conserva estado anterior |
| {"activo":"true"} | 400; una cadena no es booleano |
| {"activo":true,"extra":1} | 400; no cumple campo único |

La referencia valida contenido JSON. No implementa una comprobación estricta de Content-Type ni autenticación. No le atribuyas un rechazo 415 que no programa.

## 3. Del dato validado al resultado

Después de aceptar, `.as<bool>()` obtiene el valor. Se asigna activo y se llama digitalWrite. La función estado construye un documento JSON nuevo, serializa a String y responde 200. Usar la misma función para GET y después del PUT mantiene coherencia de representación.

Repetir el mismo PUT no crea elementos nuevos ni invierte el LED. Esa propiedad de estado no demuestra ejecución física correcta ni identifica qué persona envió la petición.

## 4. Ensaya rechazo sin perder estado

Enciende con un cuerpo válido. Después envía {} utilizando el cliente del laboratorio. Comprueba 400 y solicita GET: debe seguir true. A continuación apaga con false. Esa secuencia demuestra que el rechazo no se confundió con una instrucción de apagado.

No pruebes únicamente el estado inicial OFF: si un cuerpo inválido apagara por error, esa prueba aislada no lo detectaría. Elegir una condición previa que revele el fallo hace útil la comprobación.

## 5. Extensión con requisitos explícitos

Si añadieras otro campo, por ejemplo intensidad, tendrías que definir tipo, rango, representación y efecto. El validador actual lo rechaza por campo extra. Cambiar solo el formulario del cliente no amplía el contrato del servidor.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las soluciones](SOLUCIONES.md) · [Volver a la unidad](README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2009%20%E2%80%94%20API%20REST%20b%C3%A1sica%20en%20el%20dispositivo%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad09-api-rest%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
