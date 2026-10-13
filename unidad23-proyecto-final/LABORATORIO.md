# Laboratorio 23: Integrar medición ambiental y control de LED

[Unidad](README.md) · [Entorno común](../docs/ENTORNO.md) · [Servicios locales](../laboratorios/servicios/README.md)

## Qué vas a comprobar

Integrar medición ambiental y control de LED. Trabaja primero con la referencia ESP32 clásico/WROOM-32 y el core fijado en ENTORNO. Si utilizas otra familia, adapta hardware y registra la diferencia antes de cargar.

## Montaje y materiales

SHT31, LED25, pulsador27 y broker local. Requiere completar21 y22 por separado.

La referencia usa lógica de 3.3 V. GPIO25/27/34 y SDA21/SCL22 corresponden al perfil clásico; verifica que estén disponibles en tu tarjeta. No sustituyas pines a partir del color de cables ni de la posición física en una fotografía.

## Preparar y ejecutar, paso a paso

1. Completa el [entorno](../docs/ENTORNO.md) y comprueba primero identidad y puerto.
2. Abre [integrador](ejemplos/integrador/integrador.ino). El archivo debe estar dentro de una carpeta con el mismo nombre; los `.h` adyacentes pertenecen al mismo sketch.
3. Copia `config_local.example.h` a `config_local.h` en la carpeta del sketch; completa tu red y, cuando corresponda, IP del computador y credenciales. Mantén el archivo privado.
4. Compila para tu placa, carga por USB y abre monitor a **115200 baud**. Conserva la salida de compilación y fecha.
5. Prueba temperatura, comando, prioridad local, fallo sensor y caída broker por separado. Ejecuta después sensor ausente y broker caído simultáneamente.
6. Registra resultado antes de cambiar código. Modifica una sola condición y vuelve a comprobar.

## Resultado esperado

Fallo sensor no inventa datos; LED se apaga por protección local/vencimiento. Broker disponible publica medición real y estado software.

Estos resultados son criterios de aceptación, no una declaración de prueba física realizada por la autora. Completa [EVIDENCIAS.md](../docs/EVIDENCIAS.md) con tu resultado observado y señala montaje real, simulación o caso pendiente.

## Cómo funciona el programa

Cada subsistema conserva un estado propio. No se interpreta red como salud del sensor. El integrador reúne dos bases verificables, pero todavía carece de cola multirregistro/ACK durable; usa rúbrica con evidencia parcial cuando corresponda.

Lee `setup` para reconocer inicialización; `loop` para localizar tareas periódicas y condiciones de fallo; y los callbacks o funciones auxiliares para seguir validación y efectos. En los laboratorios de red revisa también `red_lab.h` y, si existe, `mqtt_lab.h`: no son bibliotecas externas sino código visible del curso.

## Ejercicios de comprobación

1. Traza recorrido de una lectura desde I2C hasta suscriptor.
2. Explica quién confirma efecto físico de una carga.
3. Diseña siguiente incremento con persistencia, ACK y pruebas de reinicio.

Consulta [SOLUCIONES.md](SOLUCIONES.md) después de predecir y ejecutar. La explicación debe vincular entrada, decisión y salida; una captura sin descripción no permite valorar comprensión.

## Diagnóstico

- Si no compila, registra la primera línea de error y confirma core/bibliotecas; un error de compilación no se arregla moviendo un cable.
- Si compila pero no carga, confirma puerto y cable de datos, prueba placa sin periféricos y consulta diagnóstico de Unidad02.
- Si carga pero incumple resultado, compara primero montaje/configuración y después el estado reportado; separa fallo de red, sensor y aplicación.
- No presentes como exitoso un caso que no ejecutaste. Conserva el esperado y el observado, aunque difieran.

## Alcance y siguiente mejora

Integrador educativo de referencia. Para cierre final aplica CHECKLIST y RUBRICA al alcance implementado y documenta pendientes.

Vuelve a [la unidad](README.md) para seguir su navegación. [Volver a Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/esp32/).
