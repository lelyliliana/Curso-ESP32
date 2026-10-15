# Dar prioridad a una entrada local en control remoto

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [control_remoto](ejemplos/control_remoto/control_remoto.ino). Abre el código completo mientras sigues el recorrido.



**Apoyo para este recorrido:** [protocolos y estados](../docs/RECORRIDOS_PROTOCOLOS.md) · [lectura del soporte de red/MQTT](../docs/LECTURA_RED_MQTT.md).

## Esquema de conexiones

Los diagramas identifican señales, no posiciones físicas. Usa la referencia clásica y confirma el pinout de tu tarjeta y módulo. [Atlas completo](../docs/ATLAS_CONEXIONES.md).

![Botón local y LED independientes](../docs/esquemas/boton-led.svg)


## 1. El botón no alterna aquí un modo

La referencia usa LED25 y botón27 con INPUT_PULLUP. Mientras el botón está LOW, una orden remota true se rechaza. El loop también apaga si estaba activo y observa LOW. Al liberar no reactiva la salida por sí mismo: hace falta otra orden válida.

La entrada es un nivel directo, no un evento estabilizado de la práctica Arduino. No se guarda un enclavamiento permanente de parada ni se realiza una función de seguridad certificada. Es prioridad local de un LED de laboratorio.

## 2. Sigue dos puntos de decisión

El callback decide si una orden recibida puede aceptarse. El loop revisa si una salida ya activa debe apagarse. Si solo comprobaras el botón al recibir comandos, presionarlo cuando no llegan mensajes no afectaría inmediatamente el estado de salida.

| Secuencia | Resultado lógico |
|---|---|
| true con botón libre | ON y renueva plazo |
| Pulsar mientras ON | Apaga cuando el loop lo detecta |
| true con botón pulsado | Rechaza sin activar |
| Liberar sin comando | Permanece OFF |
| Nuevo true válido después de liberar | Puede activar |

La palabra inmediatamente necesita condiciones de tiempo verificadas: en este código atenderMqtt se ejecuta antes de revisar el nivel y una llamada síncrona puede retrasar esa revisión.

## 3. Conserva el significado del vencimiento

La supervisión de diez segundos comienza al aceptar una orden. Otra true válida lo renueva. Una orden bloqueada por el botón retorna antes de guardar ultimoComando. El mensaje genérico de apagado menciona enlace o vencimiento, aunque el botón también puede ser la causa; interpreta la condición completa, no solo esa frase.

## 4. Orden retenida y antigüedad

Un retained ON antiguo puede entregarse después de resuscribir. Si el botón está libre y el cuerpo es válido, la referencia puede aceptarlo. Prioridad local no sustituye command_id, tiempo de emisión o política de caducidad. El ejercicio exige publicar órdenes sin retained; no afirma que el receptor reconozca todas las órdenes antiguas.

## 5. Mide una latencia con alcance

Define el instante de cambio eléctrico y el de cambio de salida que quieres comparar. Si solo usas observación humana y mensajes, declara su resolución limitada. Repite con red estable, broker detenido y reconexión, porque esas condiciones afectan el tiempo del loop. El máximo observado en una muestra no demuestra una cota garantizada de peor caso.

Controlar un motor requeriría potencia, realimentación y requisitos propios. El tópico state informa una variable del firmware; no mide movimiento ni corriente.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las soluciones](SOLUCIONES.md) · [Volver a la unidad](README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2022%20%E2%80%94%20Proyecto%3A%20control%20remoto%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad22-proyecto-control%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
