# Laboratorio 04: Leer un sensor I2C con integridad del mensaje

**[Desarrollo paso a paso: Leer un SHT31 completo y separar el ensayo SPI](DESARROLLO.md)**. Sigue el código, las tablas y el experimento antes de resolver la práctica.

[Unidad](README.md) · [Entorno común](../docs/ENTORNO.md) · [Servicios locales](../laboratorios/servicios/README.md)


## Esquema de conexiones

Los diagramas identifican señales, no posiciones físicas. Usa la referencia clásica y confirma el pinout de tu tarjeta y módulo. [Atlas completo](../docs/ATLAS_CONEXIONES.md).

![SHT31 compatible con lógica y alimentación 3.3 V](../docs/esquemas/sht31.svg)

![SPI loopback sin periférico](../docs/esquemas/spi.svg)


## Qué vas a comprobar

Leer un sensor I2C con integridad del mensaje. Trabaja primero con la referencia ESP32 clásico/WROOM-32 y el core fijado en ENTORNO. Si utilizas otra familia, adapta hardware y registra la diferencia antes de cargar.

## Montaje y materiales

Módulo SHT31 compatible con señales 3.3 V: VCC a 3V3, GND a GND, SDA21, SCL22. Usa módulo con pull-ups a 3.3 V. Referencia dirección 0x44.

La referencia usa lógica de 3.3 V. GPIO25/27/34 y SDA21/SCL22 corresponden al perfil clásico; verifica que estén disponibles en tu tarjeta. No sustituyas pines a partir del color de cables ni de la posición física en una fotografía.

## Preparar y ejecutar, paso a paso

1. Completa el [entorno](../docs/ENTORNO.md) y comprueba primero identidad y puerto.
2. Abre [i2c_sht31](ejemplos/i2c_sht31/i2c_sht31.ino). El archivo debe estar dentro de una carpeta con el mismo nombre; los `.h` adyacentes pertenecen al mismo sketch.
3. Revisa los pines del montaje indicado; no conectes periféricos si este laboratorio usa solo USB.
4. Compila para tu placa, carga por USB y abre monitor a **115200 baud**. Conserva la salida de compilación y fecha.
5. Observa el escaneo. Obtén diez lecturas. Desconecta USB antes de retirar el sensor; vuelve a energizar sin sensor.
6. Registra resultado antes de cambiar código. Modifica una sola condición y vuelve a comprobar.

## Resultado esperado

Con sensor responde 0x44 y aparecen T/HR. Sin sensor informa ausente; no inventa una temperatura.

Estos resultados son criterios de aceptación, no una declaración de prueba física realizada por la autora. Completa [EVIDENCIAS.md](../docs/EVIDENCIAS.md) con tu resultado observado y señala montaje real, simulación o caso pendiente.

## Cómo funciona el programa

El comando 0x2400 inicia medición de alta repetibilidad sin clock stretching. El loop espera 20 ms sin bloquear. La respuesta de seis bytes contiene dos valores y dos CRC. crc8 aplica polinomio 0x31 e inicial 0xFF.

Lee `setup` para reconocer inicialización; `loop` para localizar tareas periódicas y condiciones de fallo; y los callbacks o funciones auxiliares para seguir validación y efectos. En los laboratorios de red revisa también `red_lab.h` y, si existe, `mqtt_lab.h`: no son bibliotecas externas sino código visible del curso.

## Ejercicios de comprobación

1. Explica qué prueba el escaneo y qué no.
2. Cambia SENSOR a 0x45 si tu ADDR está configurado así.
3. Predice qué ocurre cuando no llegan seis bytes.

Consulta [SOLUCIONES.md](SOLUCIONES.md) después de predecir y ejecutar. La explicación debe vincular entrada, decisión y salida; una captura sin descripción no permite valorar comprensión.

## Diagnóstico

- Si no compila, registra la primera línea de error y confirma core/bibliotecas; un error de compilación no se arregla moviendo un cable.
- Si compila pero no carga, confirma puerto y cable de datos, prueba placa sin periféricos y consulta diagnóstico de Unidad02.
- Si carga pero incumple resultado, compara primero montaje/configuración y después el estado reportado; separa fallo de red, sensor y aplicación.
- No presentes como exitoso un caso que no ejecutaste. Conserva el esperado y el observado, aunque difieran.

## Alcance y siguiente mejora

Se implementa I2C; SPI se practica por separado con loopback; un periférico real sigue requiriendo su protocolo específico.

Vuelve a [la unidad](README.md) para seguir su navegación. [Volver a Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/esp32/).

## Segunda práctica: SPI en loopback

Abre [spi_loopback.ino](ejemplos/spi_loopback/spi_loopback.ino). Desconecta USB y retira el SHT31 u otros dispositivos para estudiar una conexión a la vez. Conecta únicamente **GPIO23 (MOSI) a GPIO19 (MISO)** en la placa clásica. SCK18 y CS26 quedan como salidas del ESP32, sin otra carga. Conecta USB y carga.

El master envía0xA5; el puente devuelve el mismo patrón al receptor MISO. Debe aparecer TX=A5 RX=A5 coincide. Quita el puente solo después de desenergizar: sin él, MISO queda flotante y el valor recibido no tiene por qué ser0. Repite con0x3C y verifica.

beginTransaction fija frecuencia100kHz, orden MSB primero y modo0; transfer desplaza un byte mientras recibe. CS delimita una transferencia como lo haría en un periférico, aunque en loopback ningún esclavo interpreta CS. Este ensayo demuestra recorrido eléctrico MOSI→MISO; **no identifica un sensor SPI ni implementa su protocolo**. Un periférico real necesita además su datasheet, comandos y modo correcto.
