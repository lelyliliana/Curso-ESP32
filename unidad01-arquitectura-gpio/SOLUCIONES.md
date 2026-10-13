# Soluciones razonadas del laboratorio 01

[Volver al laboratorio](LABORATORIO.md)

1. Invertirías el significado: encendido al liberar.
2. En ESP32 clásico GPIO34 es solo entrada.
3. Conserva la lectura del botón y cambia únicamente la representación.

## Qué entregar

Explica la predicción, conserva la entrada o modificación exacta y compara resultado esperado y observado. Para hardware registra GPIO y alimentación; para red registra códigos/estado sin credenciales. Cuando un experimento dependa del ambiente, una respuesta textual no sustituye la medición.

## Criterio de avance

LED apagado al liberar y encendido al pulsar. El monitor alterna libre/pulsado.

## Límite que debes poder explicar

El ejemplo no elimina rebote. La selección de pines no es universal para S3/C3.

Un fallo detectado y explicado tiene valor formativo; no lo conviertas en éxito por cambiar el objetivo después de ejecutar. Para el proyecto conserva también intentos, pérdidas y condiciones que no pudiste reproducir.
