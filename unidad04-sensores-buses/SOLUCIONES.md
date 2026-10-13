# Soluciones razonadas del laboratorio 04

[Volver al laboratorio](LABORATORIO.md)

1. Prueba ACK en una dirección, no identidad/calibración.
2. Debe coincidir con el módulo, no cambia por software su cableado.
3. Se rechaza la lectura incompleta antes de acceder al arreglo.

## Qué entregar

Explica la predicción, conserva la entrada o modificación exacta y compara resultado esperado y observado. Para hardware registra GPIO y alimentación; para red registra códigos/estado sin credenciales. Cuando un experimento dependa del ambiente, una respuesta textual no sustituye la medición.

## Criterio de avance

Con sensor responde 0x44 y aparecen T/HR. Sin sensor informa ausente; no inventa una temperatura.

## Límite que debes poder explicar

Se implementa I2C; SPI conserva la guía conceptual y queda como extensión, no como montaje probado.

Un fallo detectado y explicado tiene valor formativo; no lo conviertas en éxito por cambiar el objetivo después de ejecutar. Para el proyecto conserva también intentos, pérdidas y condiciones que no pudiste reproducir.

## SPI

Con puente MOSI→MISO, RX debe reproducir TX. Sin puente el valor puede ser indeterminado, por lo que no aceptes0 como única salida esperada. CS no controla un dispositivo real en esta prueba.
