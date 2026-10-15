# Validar TLS sin confundir cifrado con autorización

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [https_validado](ejemplos/https_validado/https_validado.ino). Abre el código completo mientras sigues el recorrido.


**Apoyo para este recorrido:** [protocolos y estados](../docs/RECORRIDOS_PROTOCOLOS.md) · [lectura del soporte de red/MQTT](../docs/LECTURA_RED_MQTT.md).

## 1. Cambia transporte y confianza

Esta práctica utiliza WiFiClientSecure en lugar del transporte sin cifrar de HTTP/MQTT anteriores. Necesita una CA confiable en ca_local.h y una URL cuyo hostname corresponda al certificado. Los archivos de ejemplo no contienen una identidad TLS ya preparada para tu servidor.

El programa evita continuar si LAB_CA está vacía. No sustituye esa ausencia por una conexión insegura. Que el firmware compile con el placeholder no demuestra una validación de certificado ejecutada.

## 2. El reloj participa en la comprobación

`configTime` solicita sincronización. Antes de intentar la operación se exige una fecha posterior al umbral del ejemplo. Eso descarta un reloj claramente no inicializado, pero no demuestra que la hora exacta sea correcta ni que la fuente de tiempo esté autenticada.

Un certificado puede estar fuera de sus fechas válidas si el reloj es incorrecto. El diagnóstico debe separar confianza, nombre, fechas y disponibilidad de red. Cambiar la CA para aceptar cualquier error oculta la causa.

## 3. Sigue las condiciones

| Condición | Comportamiento de la referencia |
|---|---|
| Wi-Fi no conectado | Espera y atiende red |
| Aún no vencen diez segundos | No inicia otra operación |
| CA vacía | Informa configuración pendiente |
| Reloj claramente sin sincronizar | Informa reloj pendiente |
| Condiciones previas satisfechas | Configura CA e intenta HTTPS |

Las comprobaciones previas no garantizan que el servidor presente un certificado aceptable. La conexión real debe validar la cadena, el hostname y las condiciones soportadas por el entorno.

## 4. Qué protege y qué no

TLS con validación apropiada protege el transporte y permite comprobar identidad del servidor según la confianza configurada. No autentica automáticamente al usuario del dispositivo, no autoriza una operación de control y no verifica calidad del dato recibido.

El broker de la Unidad 10 usa WiFiClient a puerto 1883 sin TLS. Sus credenciales de aplicación no se cifran por utilizar MQTT. Cambiar la práctica HTTPS no transforma el transporte MQTT de otros sketches.

## 5. Un ensayo de rechazo tiene valor

Con un servicio autorizado, registra resultado con configuración correcta y después un caso controlado de nombre o CA incompatible. Debe fallar la confianza correspondiente. Restaura la configuración. `setInsecure` elimina comprobaciones que eran el objetivo del ensayo; conseguir una respuesta de esa manera no resuelve la validación.

No publiques claves ni certificados privados. Una CA pública de confianza y una clave privada son objetos diferentes; el curso pide configurar confianza, no distribuir identidad privada en el repositorio.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las soluciones](SOLUCIONES.md) · [Volver a la unidad](README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2018%20%E2%80%94%20Credenciales%20y%20seguridad%20b%C3%A1sica%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad18-seguridad%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
