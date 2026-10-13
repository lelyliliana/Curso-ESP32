# Soluciones razonadas del laboratorio 21

[Volver al laboratorio](LABORATORIO.md)

1. No: el laboratorio lo imprime como lectura solo local.
2. El receptor debe aceptar ese contrato ampliado.
3. Persiste el registro completo e ID y espera ACK; no basta guardar uptime.

## Qué entregar

Explica la predicción, conserva la entrada o modificación exacta y compara resultado esperado y observado. Para hardware registra GPIO y alimentación; para red registra códigos/estado sin credenciales. Cuando un experimento dependa del ambiente, una respuesta textual no sustituye la medición.

## Criterio de avance

Lectura local con T/HR; broker entrega JSON si conectado. Sensor ausente/CRC inválido: no publica dato falso.

## Límite que debes poder explicar

Base mínima reproducible. Los requisitos avanzados de README (200 registros, jitter, dashboard) son extensión evaluada, no capacidad de este firmware.

Un fallo detectado y explicado tiene valor formativo; no lo conviertas en éxito por cambiar el objetivo después de ejecutar. Para el proyecto conserva también intentos, pérdidas y condiciones que no pudiste reproducir.
