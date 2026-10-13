# Soluciones razonadas del laboratorio 10

[Volver al laboratorio](LABORATORIO.md)

1. Depende del keepalive y detección del broker.
2. No, se publica sin retained.
3. Debe ser único; dos clientId iguales se desplazan.

## Qué entregar

Explica la predicción, conserva la entrada o modificación exacta y compara resultado esperado y observado. Para hardware registra GPIO y alimentación; para red registra códigos/estado sin credenciales. Cuando un experimento dependa del ambiente, una respuesta textual no sustituye la medición.

## Criterio de avance

online retained y telemetría periódica; el broker publica offline cuando detecta desconexión no limpia.

## Límite que debes poder explicar

Sin TLS: broker autorizado de LAN, sin puertos redirigidos a Internet.

Un fallo detectado y explicado tiene valor formativo; no lo conviertas en éxito por cambiar el objetivo después de ejecutar. Para el proyecto conserva también intentos, pérdidas y condiciones que no pudiste reproducir.
