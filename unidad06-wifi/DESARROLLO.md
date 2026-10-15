# Conectarse sin confundir Wi-Fi con servicio disponible

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [wifi_estado](ejemplos/wifi_estado/wifi_estado.ino). Abre el código completo mientras sigues el recorrido.


**Apoyo para este recorrido:** [protocolos y estados](../docs/RECORRIDOS_PROTOCOLOS.md) · [lectura del soporte de red/MQTT](../docs/LECTURA_RED_MQTT.md).

## 1. Abre también el header

El sketch llama iniciarRed y atenderRed, definidas en red_lab.h junto al programa. Allí se configura WIFI_STA, se inicia la conexión y se atienden cambios. No es una biblioteca oculta del fabricante. La [lectura del soporte de red](../docs/LECTURA_RED_MQTT.md) desarrolla ese recorrido.

La configuración privada se toma de config_local.h si existe. Parte del ejemplo local y completa red y claves en tu copia. Compilar con placeholders demuestra construcción del programa, no conexión a tu red.

## 2. Sigue las observaciones

| Estado observado | Qué informa el soporte |
|---|---|
| No conectado al arrancar | Continúa atendiendo loop |
| Primer paso a WL_CONNECTED | Imprime IP local |
| Pérdida después de estar conectado | Anuncia Wi-Fi perdido |
| Continúa sin conexión durante el intervalo de reintento | Solicita WiFi.reconnect |

La marca wifiIntento impone 15000 ms entre solicitudes manuales de reconexión en este soporte. También está habilitada la reconexión automática del core. El sketch principal imprime su tarea local cada dos segundos.

## 3. No confundas dos periodos

El experimento de cambiar el periodo a 30 s se refiere al reintento manual de red: cambia 15000 a 30000 en el header de una copia. Si cambias el 2000 del sketch, solo reduces frecuencia de los mensajes locales. Señala exactamente qué constante cambiaste para interpretar el resultado.

## 4. Capas de conectividad

Tener IP no demuestra salida a Internet, servidor HTTP activo ni broker accesible. Una red de invitados puede aislar ESP32 y computador aunque ambos naveguen. En la referencia clásica se configura una red de 2.4 GHz adecuada a la placa; no deduzcas compatibilidad por el nombre comercial del router.

Para hablar con un servicio del computador, LAB_HOST es su IP alcanzable desde la placa. `127.0.0.1` en ESP32 designaría al propio ESP32, no al computador. Registra dirección del cliente y del servidor por separado.

## 5. Ensayo controlado

Primero confirma la tarea local sin conectividad. Después configura la red correcta y observa el cambio de estado e IP. En una copia prueba credenciales incorrectas sin mostrarlas y conserva que la tarea local continúa. Restablece la configuración y registra la recuperación; no cambies simultáneamente SSID, puerto de servicio y firmware.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las soluciones](SOLUCIONES.md) · [Volver a la unidad](README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2006%20%E2%80%94%20Conexi%C3%B3n%20Wi%E2%80%91Fi%20y%20reconexi%C3%B3n%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad06-wifi%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
