# Laboratorio 05: Mantener la interrupción corta y observar rebote

**[Desarrollo paso a paso: Distinguir interrupción, tarea y dato compartido](DESARROLLO.md)**. Sigue el código, las tablas y el experimento antes de resolver la práctica.

[Unidad](README.md) · [Entorno común](../docs/ENTORNO.md) · [Servicios locales](../laboratorios/servicios/README.md)


## Esquema de conexiones

Los diagramas identifican señales, no posiciones físicas. Usa la referencia clásica y confirma el pinout de tu tarjeta y módulo. [Atlas completo](../docs/ATLAS_CONEXIONES.md).

![Botón local y LED independientes](../docs/esquemas/boton-led.svg)


## Qué vas a comprobar

Mantener la interrupción corta y observar rebote. Trabaja primero con la referencia ESP32 clásico/WROOM-32 y el core fijado en ENTORNO. Si utilizas otra familia, adapta hardware y registra la diferencia antes de cargar.

## Montaje y materiales

Pulsador GPIO27 a GND con INPUT_PULLUP; sin cargas.

La referencia usa lógica de 3.3 V. GPIO25/27/34 y SDA21/SCL22 corresponden al perfil clásico; verifica que estén disponibles en tu tarjeta. No sustituyas pines a partir del color de cables ni de la posición física en una fotografía.

## Preparar y ejecutar, paso a paso

1. Completa el [entorno](../docs/ENTORNO.md) y comprueba primero identidad y puerto.
2. Abre [interrupcion](ejemplos/interrupcion/interrupcion.ino). El archivo debe estar dentro de una carpeta con el mismo nombre; los `.h` adyacentes pertenecen al mismo sketch.
3. Revisa los pines del montaje indicado; no conectes periféricos si este laboratorio usa solo USB.
4. Compila para tu placa, carga por USB y abre monitor a **115200 baud**. Conserva la salida de compilación y fecha.
5. Pulsa una vez lentamente y compara flancos. Repite diez pulsaciones.
6. Registra resultado antes de cambiar código. Modifica una sola condición y vuelve a comprobar.

## Resultado esperado

Flancos puede superar pulsaciones por rebote. La salida serial se realiza en loop, no en la ISR.

Estos resultados son criterios de aceptación, no una declaración de prueba física realizada por la autora. Completa [EVIDENCIAS.md](../docs/EVIDENCIAS.md) con tu resultado observado y señala montaje real, simulación o caso pendiente.

## Cómo funciona el programa

volatile evita ciertas optimizaciones, pero no sustituye sincronización. La sección crítica protege copia/incremento. El interrupt cuenta eventos físicos, no decide que cada flanco sea una acción del usuario.

Lee `setup` para reconocer inicialización; `loop` para localizar tareas periódicas y condiciones de fallo; y los callbacks o funciones auxiliares para seguir validación y efectos. En los laboratorios de red revisa también `red_lab.h` y, si existe, `mqtt_lab.h`: no son bibliotecas externas sino código visible del curso.

## Ejercicios de comprobación

1. ¿Por qué no imprimir en la ISR?
2. Diseña una regla de estabilización de 30 ms en loop.
3. Distingue interrupción de una tarea FreeRTOS.

Consulta [SOLUCIONES.md](SOLUCIONES.md) después de predecir y ejecutar. La explicación debe vincular entrada, decisión y salida; una captura sin descripción no permite valorar comprensión.

## Diagnóstico

- Si no compila, registra la primera línea de error y confirma core/bibliotecas; un error de compilación no se arregla moviendo un cable.
- Si compila pero no carga, confirma puerto y cable de datos, prueba placa sin periféricos y consulta diagnóstico de Unidad02.
- Si carga pero incumple resultado, compara primero montaje/configuración y después el estado reportado; separa fallo de red, sensor y aplicación.
- No presentes como exitoso un caso que no ejecutaste. Conserva el esperado y el observado, aunque difieran.

## Alcance y siguiente mejora

No promete un contador de pulsaciones sin rebotes; FreeRTOS también se demuestra en la segunda práctica con una cola finita.

Vuelve a [la unidad](README.md) para seguir su navegación. [Volver a Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/esp32/).

## Segunda práctica: tarea productora y cola FreeRTOS

Abre [tarea_cola.ino](ejemplos/tarea_cola/tarea_cola.ino), sin periféricos. La tarea productor genera un contador cada500ms y lo envía a una cola de capacidad4; loop recibe sin esperar y muestra el número. Deben aparecer valores crecientes. La cola transfiere copias; evita una variable compartida modificada sin sincronización.

1. Predice el periodo y carga el sketch.
2. Cambia temporalmente delay(1) de loop por delay(3000). La cola puede llenarse: xQueueSend espera como máximo100ms y omite ese número si falla.
3. Observa huecos y restablece el ejemplo. Explica por qué una cola finita necesita política de saturación.

xTaskCreate comprueba que haya recursos; en ESP-IDF el tamaño de stack se expresa en bytes, distinto de algunas variantes de FreeRTOS. vTaskDelay cede CPU dentro de la tarea; no uses delay o printf en una ISR para copiar este modelo. Esta tarea no está fijada a un núcleo ni promete exactitud temporal estricta.
