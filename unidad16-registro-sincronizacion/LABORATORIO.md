# Laboratorio 16: Reenviar un pendiente con identidad estable tras pérdida de respuesta

[Unidad](README.md) · [Entorno común](../docs/ENTORNO.md) · [Servicios locales](../laboratorios/servicios/README.md)

## Qué vas a comprobar

Reenviar un pendiente con identidad estable tras pérdida de respuesta. Trabaja primero con la referencia ESP32 clásico/WROOM-32 y el core fijado en ENTORNO. Si utilizas otra familia, adapta hardware y registra la diferencia antes de cargar.

## Montaje y materiales

ESP32 y servidor HTTP SQLite de SERVICIOS; no se requieren sensores.

La referencia usa lógica de 3.3 V. GPIO25/27/34 y SDA21/SCL22 corresponden al perfil clásico; verifica que estén disponibles en tu tarjeta. No sustituyas pines a partir del color de cables ni de la posición física en una fotografía.

## Preparar y ejecutar, paso a paso

1. Completa el [entorno](../docs/ENTORNO.md) y comprueba primero identidad y puerto.
2. Abre [cola_offline](ejemplos/cola_offline/cola_offline.ino). El archivo debe estar dentro de una carpeta con el mismo nombre; los `.h` adyacentes pertenecen al mismo sketch.
3. Copia `config_local.example.h` a `config_local.h` en la carpeta del sketch; completa tu red y, cuando corresponda, IP del computador y credenciales. Mantén el archivo privado.
4. Compila para tu placa, carga por USB y abre monitor a **115200 baud**. Conserva la salida de compilación y fecha.
5. Detén receptor, espera pendiente y reinicia ESP32. Inicia receptor. Reenvía desde computador el mismo Idempotency-Key con mismo cuerpo; luego cambia cuerpo manteniendo key.
6. Registra resultado antes de cambiar código. Modifica una sola condición y vuelve a comprobar.

## Resultado esperado

El pendiente reaparece tras reset. Mismo key/cuerpo entrega ACK repetido sin duplicar fila; contenido distinto devuelve 409.

Estos resultados son criterios de aceptación, no una declaración de prueba física realizada por la autora. Completa [EVIDENCIAS.md](../docs/EVIDENCIAS.md) con tu resultado observado y señala montaje real, simulación o caso pendiente.

## Cómo funciona el programa

Cola de capacidad UNO aplica backpressure: no produce mientras hay pendiente. NVS guarda ID antes de envío. El servidor valida, escribe en SQLite y confirma. El sketch solo libera pendiente después de comprobar ACK por identidad; nunca por un 200 sin contrato.

Lee `setup` para reconocer inicialización; `loop` para localizar tareas periódicas y condiciones de fallo; y los callbacks o funciones auxiliares para seguir validación y efectos. En los laboratorios de red revisa también `red_lab.h` y, si existe, `mqtt_lab.h`: no son bibliotecas externas sino código visible del curso.

## Ejercicios de comprobación

1. ¿Por qué repetir POST sin identidad estable es peligroso?
2. ¿Qué lecturas se pierden mientras la cola está llena?
3. Identifica la ventana de corte entre putUInt y putBool.

Consulta [SOLUCIONES.md](SOLUCIONES.md) después de predecir y ejecutar. La explicación debe vincular entrada, decisión y salida; una captura sin descripción no permite valorar comprensión.

## Diagnóstico

- Si no compila, registra la primera línea de error y confirma core/bibliotecas; un error de compilación no se arregla moviendo un cable.
- Si compila pero no carga, confirma puerto y cable de datos, prueba placa sin periféricos y consulta diagnóstico de Unidad02.
- Si carga pero incumple resultado, compara primero montaje/configuración y después el estado reportado; separa fallo de red, sensor y aplicación.
- No presentes como exitoso un caso que no ejecutaste. Conserva el esperado y el observado, aunque difieran.

## Alcance y siguiente mejora

No es cola de 200 muestras ni almacenamiento de temperatura. Un borrado de NVS exige nueva identidad de dispositivo para evitar colisiones.

Vuelve a [la unidad](README.md) para seguir su navegación. [Volver a Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/esp32/).
