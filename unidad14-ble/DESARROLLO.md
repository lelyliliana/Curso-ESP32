# Leer una característica BLE desde su contrato

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [ble_lectura](ejemplos/ble_lectura/ble_lectura.ino). Abre el código completo mientras sigues el recorrido.


**Apoyo para este recorrido:** [protocolos y estados](../docs/RECORRIDOS_PROTOCOLOS.md).

## 1. Publicidad no es todavía lectura

ESP32 crea un servidor GATT con nombre Leli-Nodo01. Configura un servicio y una característica mediante UUID diferentes. El anuncio incluye el UUID del servicio para que un cliente pueda descubrirlo. El nombre visible ayuda a una persona, pero no autentica el dispositivo.

Advertising permite descubrir presencia y datos anunciados. Para leer esta característica, el cliente sigue el servicio y realiza una operación de lectura. No necesita una conexión Wi-Fi al broker porque esta práctica utiliza BLE directamente.

## 2. Qué representa la característica

Se crea con PROPERTY_READ y valor inicial "0". Cada segundo el programa actualiza el texto con `millis()/1000`, segundos desde arranque con división entera. No es un sensor de temperatura ni un número de paquetes entregados.

| Instante | Valor almacenado aproximado | Qué ve un cliente |
|---|---|---|
| Arranque | "0" | Puede leer el valor inicial |
| Después de varios segundos | Texto de segundos de actividad | Solo cambia su vista al leer de nuevo |
| Sin nuevas lecturas del cliente | La placa sigue actualizando | No se envía automáticamente una notificación |

El tipo transmitido es texto. El cliente debe interpretar esa representación si quiere usarla como número.

## 3. Permisos definen operaciones

PROPERTY_READ no incorpora escritura ni notificación. No se configura un descriptor para suscribirse a notificaciones porque esta referencia no las ofrece. Añadir un botón ON en una aplicación móvil no permite escribir el LED si el servidor BLE no implementa esa característica, sus permisos y su callback.

Descubrimiento, lectura, escritura y notificación son operaciones diferentes. Un escaneo exitoso no comprueba que el cliente leyó la característica correcta.

## 4. Ensayo por pasos

Usa un cliente BLE capaz de explorar servicios. Encuentra el nodo, identifica el UUID de servicio y después la característica terminada en 90ac. Lee, espera varios segundos y vuelve a leer. Registra ambos valores y sus momentos. No confundas un valor conservado en la pantalla del cliente con el valor actual de la placa.

Al desconectar y volver a intentar, registra si reaparece el anuncio. El ejemplo no incorpora callbacks explícitos para reiniciar advertising tras cada desconexión; no se presenta como demostración de reconexión robusta bajo todas las condiciones.

## 5. Una ampliación requiere su propio ensayo

Para notificar, define propiedad, mecanismo de suscripción, frecuencia y comportamiento cuando no hay clientes. Para controlar una salida, define escritura validada y autorización apropiada. No envíes datos privados por asumir que conocer un UUID equivale a tener una identidad confiable.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las soluciones](SOLUCIONES.md) · [Volver a la unidad](README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2014%20%E2%80%94%20Bluetooth%20y%20BLE%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad14-ble%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
