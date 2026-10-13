# Soluciones razonadas del laboratorio 11

[Volver al laboratorio](LABORATORIO.md)

1. No alterna, pero renueva el plazo.
2. Una orden antigua podría llegar al reconectar.
3. Detección TCP/MQTT y bloqueos pueden demorar: no equivale a protección de tiempo real.

## Qué entregar

Explica la predicción, conserva la entrada o modificación exacta y compara resultado esperado y observado. Para hardware registra GPIO y alimentación; para red registra códigos/estado sin credenciales. Cuando un experimento dependa del ambiente, una respuesta textual no sustituye la medición.

## Criterio de avance

ON al aceptar y OFF tras vencimiento o enlace perdido detectado; comandos inválidos no aplican cambios.

## Límite que debes poder explicar

ON/OFF es salida software sin realimentación. No detecta comando antiguo ni implementa ACL por nodo por sí solo.

Un fallo detectado y explicado tiene valor formativo; no lo conviertas en éxito por cambiar el objetivo después de ejecutar. Para el proyecto conserva también intentos, pérdidas y condiciones que no pudiste reproducir.
