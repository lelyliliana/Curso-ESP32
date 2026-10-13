# Soluciones razonadas del laboratorio 19

[Volver al laboratorio](LABORATORIO.md)

1. Misma subred, mDNS, firewall y ArduinoOTA.handle; conserva ruta USB.
2. No: esos mecanismos avanzados se mantienen en guía conceptual.
3. Instala el firmware que atiende OTA antes del primer envío por red.

## Qué entregar

Explica la predicción, conserva la entrada o modificación exacta y compara resultado esperado y observado. Para hardware registra GPIO y alimentación; para red registra códigos/estado sin credenciales. Cuando un experimento dependa del ambiente, una respuesta textual no sustituye la medición.

## Criterio de avance

OTA inicio/recibida y nuevo arranque informa lab-2. Clave errónea debe rechazar carga.

## Límite que debes poder explicar

ArduinoOTA local no equivale a OTA firmada de flota. Autenticación no cifra todo el proceso; sin redirección a Internet.

Un fallo detectado y explicado tiene valor formativo; no lo conviertas en éxito por cambiar el objetivo después de ejecutar. Para el proyecto conserva también intentos, pérdidas y condiciones que no pudiste reproducir.
