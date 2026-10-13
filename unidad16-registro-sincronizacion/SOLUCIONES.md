# Soluciones razonadas del laboratorio 16

[Volver al laboratorio](LABORATORIO.md)

1. Podría crear filas repetidas.
2. Aquí son eventos sintéticos, no una serie continua; no genera nuevos.
3. Las claves no forman una transacción; puede existir un hueco de secuencia, que debes registrar, sin reutilizar IDs confirmados.

## Qué entregar

Explica la predicción, conserva la entrada o modificación exacta y compara resultado esperado y observado. Para hardware registra GPIO y alimentación; para red registra códigos/estado sin credenciales. Cuando un experimento dependa del ambiente, una respuesta textual no sustituye la medición.

## Criterio de avance

El pendiente reaparece tras reset. Mismo key/cuerpo entrega ACK repetido sin duplicar fila; contenido distinto devuelve 409.

## Límite que debes poder explicar

No es cola de 200 muestras ni almacenamiento de temperatura. Un borrado de NVS exige nueva identidad de dispositivo para evitar colisiones.

Un fallo detectado y explicado tiene valor formativo; no lo conviertas en éxito por cambiar el objetivo después de ejecutar. Para el proyecto conserva también intentos, pérdidas y condiciones que no pudiste reproducir.
