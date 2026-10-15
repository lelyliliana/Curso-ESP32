# Laboratorio 01: Relacionar números GPIO con conexiones físicas

**[Desarrollo paso a paso: Relacionar GPIO, nivel eléctrico y significado](DESARROLLO.md)**. Sigue el código, las tablas y el experimento antes de resolver la práctica.

[Unidad](README.md) · [Entorno común](../docs/ENTORNO.md) · [Servicios locales](../laboratorios/servicios/README.md)


## Esquema de conexiones

Los diagramas identifican señales, no posiciones físicas. Usa la referencia clásica y confirma el pinout de tu tarjeta y módulo. [Atlas completo](../docs/ATLAS_CONEXIONES.md).

![Botón local y LED independientes](../docs/esquemas/boton-led.svg)


## Qué vas a comprobar

Relacionar números GPIO con conexiones físicas. Trabaja primero con la referencia ESP32 clásico/WROOM-32 y el core fijado en ENTORNO. Si utilizas otra familia, adapta hardware y registra la diferencia antes de cargar.

## Montaje y materiales

LED externo: GPIO25 → resistencia 330 Ω → ánodo; cátodo → GND. Pulsador entre GPIO27 y GND. Monta sin USB conectado.

La referencia usa lógica de 3.3 V. GPIO25/27/34 y SDA21/SCL22 corresponden al perfil clásico; verifica que estén disponibles en tu tarjeta. No sustituyas pines a partir del color de cables ni de la posición física en una fotografía.

## Preparar y ejecutar, paso a paso

1. Completa el [entorno](../docs/ENTORNO.md) y comprueba primero identidad y puerto.
2. Abre [pines](ejemplos/pines/pines.ino). El archivo debe estar dentro de una carpeta con el mismo nombre; los `.h` adyacentes pertenecen al mismo sketch.
3. Revisa los pines del montaje indicado; no conectes periféricos si este laboratorio usa solo USB.
4. Compila para tu placa, carga por USB y abre monitor a **115200 baud**. Conserva la salida de compilación y fecha.
5. Observa libre y pulsa el botón. Localiza GPIO25 y GPIO27 en el pinout de tu ESP32 clásico; no cuentes patas desde una imagen genérica.
6. Registra resultado antes de cambiar código. Modifica una sola condición y vuelve a comprobar.

## Resultado esperado

LED apagado al liberar y encendido al pulsar. El monitor alterna libre/pulsado.

Estos resultados son criterios de aceptación, no una declaración de prueba física realizada por la autora. Completa [EVIDENCIAS.md](../docs/EVIDENCIAS.md) con tu resultado observado y señala montaje real, simulación o caso pendiente.

## Cómo funciona el programa

INPUT_PULLUP mantiene alto el pin libre; el botón lo lleva a GND. Pulsado se interpreta como LOW y se transforma en un estado booleano. La resistencia del LED limita corriente.

Lee `setup` para reconocer inicialización; `loop` para localizar tareas periódicas y condiciones de fallo; y los callbacks o funciones auxiliares para seguir validación y efectos. En los laboratorios de red revisa también `red_lab.h` y, si existe, `mqtt_lab.h`: no son bibliotecas externas sino código visible del curso.

## Ejercicios de comprobación

1. Predice el resultado si interpretas HIGH como pulsado.
2. Explica por qué GPIO34 no sirve como salida LED.
3. Sustituye el LED por un texto serial antes de cambiar de placa.

Consulta [SOLUCIONES.md](SOLUCIONES.md) después de predecir y ejecutar. La explicación debe vincular entrada, decisión y salida; una captura sin descripción no permite valorar comprensión.

## Diagnóstico

- Si no compila, registra la primera línea de error y confirma core/bibliotecas; un error de compilación no se arregla moviendo un cable.
- Si compila pero no carga, confirma puerto y cable de datos, prueba placa sin periféricos y consulta diagnóstico de Unidad02.
- Si carga pero incumple resultado, compara primero montaje/configuración y después el estado reportado; separa fallo de red, sensor y aplicación.
- No presentes como exitoso un caso que no ejecutaste. Conserva el esperado y el observado, aunque difieran.

## Alcance y siguiente mejora

El ejemplo no elimina rebote. La selección de pines no es universal para S3/C3.

Vuelve a [la unidad](README.md) para seguir su navegación. [Volver a Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/esp32/).
