# Actualizar por OTA y verificar el nuevo arranque

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [ota_local](ejemplos/ota_local/ota_local.ino). Abre el código completo mientras sigues el recorrido.


**Apoyo para este recorrido:** [protocolos y estados](../docs/RECORRIDOS_PROTOCOLOS.md) · [lectura del soporte de red/MQTT](../docs/LECTURA_RED_MQTT.md).

## 1. Dos programas participan

El firmware inicial debe cargarse por USB. Ese firmware incorpora ArduinoOTA y atiende solicitudes por red. El proceso del computador envía la nueva imagen. Una placa que todavía no ejecuta el soporte OTA no adquiere esa capacidad por seleccionar un puerto de red.

La referencia fija VERSION_FIRMWARE a lab-1. Una comprobación visible consiste en preparar una copia lab-2, transferirla y observar el nuevo encabezado tras arrancar. Recibir progreso de transferencia no es lo mismo que verificar la aplicación nueva en ejecución.

## 2. Requisitos que el sketch comprueba

Inicia Serial y red. Después rechaza la clave placeholder o una clave de menos de doce caracteres. Si falla, queda esperando e informa que debes configurar; no habilita OTA sin clave por conveniencia.

`setHostname` configura leli-nodo01; `setPassword` establece la clave del laboratorio. Se registran callbacks para inicio, fin y error. Son puntos de observación: imprimir inicio no mide que una carga física esté deshabilitada.

## 3. Atención continua

En cada vuelta se atiende la red y, cuando Wi-Fi está conectado, ArduinoOTA.handle procesa la actualización. Una operación larga añadida al loop puede reducir esa atención. Tener IP no demuestra descubrimiento de puerto por el computador: también intervienen descubrimiento local, acceso de red y herramientas.

| Paso | Evidencia diferente |
|---|---|
| Primera carga USB | Firmware con receptor OTA instalado |
| IP y descubrimiento local | Dispositivo alcanzable bajo condiciones del ensayo |
| Transferencia terminada | Imagen recibida según herramienta/protocolo |
| Encabezado lab-2 al arrancar | Nueva aplicación observada |
| Práctica funcional posterior | El comportamiento requerido sigue funcionando |

## 4. No atribuyas firma o rollback

Una contraseña OTA no demuestra verificación criptográfica de firma del firmware ni un rollback probado ante una aplicación defectuosa. El esquema de particiones debe admitir OTA; una selección incompatible puede impedir la transferencia. Revisa esa configuración antes de culpar a la clave.

La referencia trabaja sin actuadores conectados. El callback lo anuncia, pero no contiene una lógica completa de parada o enclavamiento de cargas. Esa política requeriría implementación y verificación propias.

## 5. Ensayo reproducible

Confirma lab-1 por USB y conserva esa vía de recuperación. Prepara lab-2 cambiando solo el identificador, compila con configuración compatible y realiza la transferencia en la red de práctica autorizada. Observa nuevo arranque y resultado. Si no aparece puerto, investiga conectividad y descubrimiento; no borres el único firmware recuperable sin haber localizado el problema.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las soluciones](SOLUCIONES.md) · [Volver a la unidad](README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2019%20%E2%80%94%20Actualizaciones%20OTA%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad19-ota%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
