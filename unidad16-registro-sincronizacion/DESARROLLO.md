# Reenviar el mismo pendiente sin duplicar su identidad

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [cola_offline](ejemplos/cola_offline/cola_offline.ino). Abre el código completo mientras sigues el recorrido.


**Apoyo para este recorrido:** [protocolos y estados](../docs/RECORRIDOS_PROTOCOLOS.md) · [lectura del soporte de red/MQTT](../docs/LECTURA_RED_MQTT.md).

## 1. La cola solo conserva un evento

Este programa no mide temperatura. Genera un identificador de evento y mantiene un único pendiente con NVS. Cuando hay uno, no crea otro. El periodo de diez segundos organiza oportunidades de generación/reenvío; no significa que haya diez segundos de muestras históricas guardadas.

Las claves seq, id y hay guardan secuencia, identidad pendiente y existencia de pendiente. Al arrancar se leen antes de iniciar red. Las tres escrituras se comprueban por separado, pero no forman una transacción atómica de aplicación.

## 2. Sigue la identidad de extremo a extremo

| Elemento | Ejemplo para evento 7 |
|---|---|
| Nodo | nodo01 |
| id | 7 |
| Idempotency-Key | nodo01-7 |
| Cuerpo POST | {"nodo":"nodo01","id":7} |
| ACK que se acepta | {"ack":"nodo01-7", ...} |

Una retransmisión debe conservar identidad y contenido. Asignar id nuevo después de perder una respuesta haría que el receptor pudiera guardar dos eventos distintos para una misma intención.

## 3. Qué hace el receptor

El servidor valida nodo/id y correspondencia de clave. En una transacción SQLite comprueba si existe. Si no, inserta y confirma antes de responder 201. Si existe con el mismo cuerpo, responde 200 con duplicado=true. Si el cuerpo cambió bajo la misma identidad, responde 409 y no sobrescribe.

Si la primera respuesta se pierde después de guardar, el dispositivo conserva el pendiente. Al reenviar, el servidor reconoce la misma identidad. Así se evita una fila adicional bajo ese contrato; no significa que no haya retransmisiones por red.

## 4. Aceptar no es solo recibir 200

El dispositivo exige 200 o 201, JSON interpretable y un ack de texto que coincida con su identidad. Después intenta guardar hay=false. Si esa escritura falla, conserva hay en RAM y puede reenviar otra vez. La referencia imprime Confirmado aunque no haya logrado limpiar ese marcador; el texto informa ACK remoto, no prueba que NVS dejó de contener el pendiente.

## 5. Examina la ventana de corte

Se escribe seq, después id y después hay=true. Un corte entre ellas puede dejar avance parcial y saltos en la secuencia. El ejemplo no afirma creación atómica ni captura sin pérdidas. Para un registro completo habría que definir una estructura con versión/integridad y una estrategia de recuperación ante escrituras parciales.

Borrar NVS y reutilizar nodo01 con contador reiniciado también puede chocar con eventos antiguos del servidor. Una nueva época de identidad o una identidad de dispositivo distinta requiere cambios coordinados del contrato, que actualmente acepta nodo01.

## 6. Prueba la propiedad que importa

Detén el receptor y observa que se conserva un pendiente. Reinicia el dispositivo y restablece servicio usando la misma base. Contrasta una sola fila para la identidad, además del ACK. Las siete pruebas del receptor verifican reenvío, conflicto y concurrencia en software; no prueban cortes eléctricos de la flash de una placa.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las soluciones](SOLUCIONES.md) · [Volver a la unidad](README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2016%20%E2%80%94%20Registro%20local%20y%20sincronizaci%C3%B3n%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad16-registro-sincronizacion%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
