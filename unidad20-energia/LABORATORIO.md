# Laboratorio 20: Observar despertar por timer y memoria RTC

**[Desarrollo paso a paso: Medir un ciclo de sueño sin confundir corriente y energía](DESARROLLO.md)**. Sigue el código, las tablas y el experimento antes de resolver la práctica.

[Unidad](README.md) · [Entorno común](../docs/ENTORNO.md) · [Servicios locales](../laboratorios/servicios/README.md)

## Qué vas a comprobar

Observar despertar por timer y memoria RTC. Trabaja primero con la referencia ESP32 clásico/WROOM-32 y el core fijado en ENTORNO. Si utilizas otra familia, adapta hardware y registra la diferencia antes de cargar.

## Montaje y materiales

Placa sola, cable USB para ver serial. Medición energética requiere fuente e instrumento apropiados.

La referencia usa lógica de 3.3 V. GPIO25/27/34 y SDA21/SCL22 corresponden al perfil clásico; verifica que estén disponibles en tu tarjeta. No sustituyas pines a partir del color de cables ni de la posición física en una fotografía.

## Preparar y ejecutar, paso a paso

1. Completa el [entorno](../docs/ENTORNO.md) y comprueba primero identidad y puerto.
2. Abre [deep_sleep](ejemplos/deep_sleep/deep_sleep.ino). El archivo debe estar dentro de una carpeta con el mismo nombre; los `.h` adyacentes pertenecen al mismo sketch.
3. Revisa los pines del montaje indicado; no conectes periféricos si este laboratorio usa solo USB.
4. Compila para tu placa, carga por USB y abre monitor a **115200 baud**. Conserva la salida de compilación y fecha.
5. Observa al menos tres despertares. Desconecta y reconecta alimentación, y compara contador.
6. Registra resultado antes de cambiar código. Modifica una sola condición y vuelve a comprobar.

## Resultado esperado

Despierta aproximadamente cada 10 s; timer wakeup reportado y RTC incrementa mientras se conserva alimentación.

Estos resultados son criterios de aceptación, no una declaración de prueba física realizada por la autora. Completa [EVIDENCIAS.md](../docs/EVIDENCIAS.md) con tu resultado observado y señala montaje real, simulación o caso pendiente.

## Cómo funciona el programa

Deep sleep detiene el programa; al despertar ejecuta setup. RTC_DATA_ATTR puede conservar datos durante sueño, no ante corte de alimentación. UART/regulador/LED de placa consumen aunque duerma el chip.

Lee `setup` para reconocer inicialización; `loop` para localizar tareas periódicas y condiciones de fallo; y los callbacks o funciones auxiliares para seguir validación y efectos. En los laboratorios de red revisa también `red_lab.h` y, si existe, `mqtt_lab.h`: no son bibliotecas externas sino código visible del curso.

## Ejercicios de comprobación

1. ¿loop continúa desde la instrucción anterior?
2. Calcula corriente media y carga con 100 mA durante 1 s y 1 mA durante 10 s. ¿Qué dato adicional necesitas para obtener energía?
3. ¿USB prueba consumo del chip aislado?

Consulta [SOLUCIONES.md](SOLUCIONES.md) después de predecir y ejecutar. La explicación debe vincular entrada, decisión y salida; una captura sin descripción no permite valorar comprensión.

## Diagnóstico

- Si no compila, registra la primera línea de error y confirma core/bibliotecas; un error de compilación no se arregla moviendo un cable.
- Si compila pero no carga, confirma puerto y cable de datos, prueba placa sin periféricos y consulta diagnóstico de Unidad02.
- Si carga pero incumple resultado, compara primero montaje/configuración y después el estado reportado; separa fallo de red, sensor y aplicación.
- No presentes como exitoso un caso que no ejecutaste. Conserva el esperado y el observado, aunque difieran.

## Alcance y siguiente mejora

No afirma microamperios reales ni activa Wi-Fi; debes medir tu montaje.

Vuelve a [la unidad](README.md) para seguir su navegación. [Volver a Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/esp32/).
