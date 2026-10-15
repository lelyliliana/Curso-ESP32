# Laboratorio 13: Separar adquisición, transporte y degradación

**[Desarrollo paso a paso: Construir una arquitectura sin atribuir capacidades simuladas](DESARROLLO.md)**. Sigue el código, las tablas y el experimento antes de resolver la práctica.

[Unidad](README.md) · [Entorno común](../docs/ENTORNO.md) · [Servicios locales](../laboratorios/servicios/README.md)

## Qué vas a comprobar

Separar adquisición, transporte y degradación. Trabaja primero con la referencia ESP32 clásico/WROOM-32 y el core fijado en ENTORNO. Si utilizas otra familia, adapta hardware y registra la diferencia antes de cargar.

## Montaje y materiales

Solo placa y monitor serie; datos SIMULADOS.

La referencia usa lógica de 3.3 V. GPIO25/27/34 y SDA21/SCL22 corresponden al perfil clásico; verifica que estén disponibles en tu tarjeta. No sustituyas pines a partir del color de cables ni de la posición física en una fotografía.

## Preparar y ejecutar, paso a paso

1. Completa el [entorno](../docs/ENTORNO.md) y comprueba primero identidad y puerto.
2. Abre [arquitectura_estado](ejemplos/arquitectura_estado/arquitectura_estado.ino). El archivo debe estar dentro de una carpeta con el mismo nombre; los `.h` adyacentes pertenecen al mismo sketch.
3. Revisa los pines del montaje indicado; no conectes periféricos si este laboratorio usa solo USB.
4. Compila para tu placa, carga por USB y abre monitor a **115200 baud**. Conserva la salida de compilación y fecha.
5. Envía e y f desde monitor. Observa que continúa el valor simulado aunque cambie transporte. Dibuja sensor→validación→transporte→receptor.
6. Registra resultado antes de cambiar código. Modifica una sola condición y vuelve a comprobar.

## Resultado esperado

El diagnóstico alterna disponible/sin enlace; ninguna lectura pasa a ser real.

Estos resultados son criterios de aceptación, no una declaración de prueba física realizada por la autora. Completa [EVIDENCIAS.md](../docs/EVIDENCIAS.md) con tu resultado observado y señala montaje real, simulación o caso pendiente.

## Cómo funciona el programa

Estado de red y validez del sensor son responsabilidades distintas. El sketch modela decisiones sin fingir conexión. La capa de servicio debe confirmar recepción/persistencia según el contrato real.

Lee `setup` para reconocer inicialización; `loop` para localizar tareas periódicas y condiciones de fallo; y los callbacks o funciones auxiliares para seguir validación y efectos. En los laboratorios de red revisa también `red_lab.h` y, si existe, `mqtt_lab.h`: no son bibliotecas externas sino código visible del curso.

## Ejercicios de comprobación

1. ¿Qué falta para tener una arquitectura ejecutada completa?
2. Identifica las capas en Unidad 21.
3. Agrega un estado sensor inválido independiente del enlace.

Consulta [SOLUCIONES.md](SOLUCIONES.md) después de predecir y ejecutar. La explicación debe vincular entrada, decisión y salida; una captura sin descripción no permite valorar comprensión.

## Diagnóstico

- Si no compila, registra la primera línea de error y confirma core/bibliotecas; un error de compilación no se arregla moviendo un cable.
- Si compila pero no carga, confirma puerto y cable de datos, prueba placa sin periféricos y consulta diagnóstico de Unidad02.
- Si carga pero incumple resultado, compara primero montaje/configuración y después el estado reportado; separa fallo de red, sensor y aplicación.
- No presentes como exitoso un caso que no ejecutaste. Conserva el esperado y el observado, aunque difieran.

## Alcance y siguiente mejora

Modelo ejecutable de estados, no un nodo conectado; el estado LOCAL inicial cambia al primer tick.

Vuelve a [la unidad](README.md) para seguir su navegación. [Volver a Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/esp32/).
