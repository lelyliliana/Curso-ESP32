# Distinguir interrupción, tarea y dato compartido

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [interrupcion](ejemplos/interrupcion/interrupcion.ino) · [tarea_cola](ejemplos/tarea_cola/tarea_cola.ino). Abre el código completo mientras sigues el recorrido.


## Esquema de conexiones

Los diagramas identifican señales, no posiciones físicas. Usa la referencia clásica y confirma el pinout de tu tarjeta y módulo. [Atlas completo](../docs/ATLAS_CONEXIONES.md).

![Botón local y LED independientes](../docs/esquemas/boton-led.svg)


## 1. Un flanco no es una pulsación estable

El primer programa conecta botón GPIO27→GND con pull-up y registra FALLING. Cada paso de HIGH a LOW puede disparar la ISR. Los rebotes pueden producir varios flancos para una sola pulsación física. Por eso el texto impreso dice explícitamente que el contador incluye rebotes.

`volatile` obliga a tratar la variable como observable por ejecuciones diferentes; no sustituye sincronización. El contador se modifica en una sección crítica ISR y se copia en otra sección crítica del loop usando el mismo mux. Después se imprime fuera de esa sección.

## 2. Mantén corto el trabajo de la ISR

La ISR incrementa un entero y vuelve. No imprime, no espera HTTP ni procesa JSON. Un trabajo largo interfiere con la atención del sistema y utiliza funciones que pueden no ser apropiadas en ese contexto. La impresión periódica se realiza en el recorrido normal, sobre una copia.

Una regla de 30 ms de estabilidad requiere observar cuándo cambió el nivel y aceptar solo tras permanencia. Contar flancos con una ISR no implementa esa regla. Si solo deseas reconocer un botón humano, comienza con una solución por niveles estabilizados antes de añadir interrupciones sin necesidad.

## 3. La segunda referencia usa una cola

En `tarea_cola` se crea una cola de cuatro enteros uint32_t. La tarea producir incrementa un número, intenta enviarlo con hasta 100 ms de espera y luego duerme aproximadamente 500 ms. El loop recibe sin esperar y muestra los números disponibles.

| Elemento | Responsabilidad |
|---|---|
| Productor | Generar y solicitar envío |
| Cola de longitud 4 | Conservar una cantidad acotada de valores |
| Consumidor | Recibir y representar |
| Política de cola llena | Omitir ese número después del plazo |

La cola copia el valor enviado; no conserva una referencia a la variable local del productor. Ese detalle permite que el productor cambie numero después del envío.

## 4. Qué puede perderse

Si el consumidor se retrasa, se acumulan hasta cuatro valores. Si no se libera espacio durante el envío, se omite el siguiente. El código no imprime un contador de pérdidas, de modo que una ausencia de error no demuestra ausencia de omisiones. Una ampliación útil es registrar ese fallo con una política de sincronización apropiada.

`pdMS_TO_TICKS` convierte una duración a ticks del sistema. La tarea y una ISR tienen contextos diferentes; crear una tarea no significa elegir explícitamente un núcleo. Ningún programa de esta unidad demuestra un tiempo de respuesta estricto para una carga real.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las soluciones](SOLUCIONES.md) · [Volver a la unidad](README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2005%20%E2%80%94%20Interrupciones%2C%20temporizaci%C3%B3n%20y%20tareas%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad05-interrupciones-tareas%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
