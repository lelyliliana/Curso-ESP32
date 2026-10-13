# Soluciones razonadas del laboratorio 09

[Volver al laboratorio](LABORATORIO.md)

1. Conserva ON; no hace toggle.
2. Rechazo porque falta el booleano.
3. El LED es la carga de laboratorio y no hay etapa de potencia ni realimentación.

## Qué entregar

Explica la predicción, conserva la entrada o modificación exacta y compara resultado esperado y observado. Para hardware registra GPIO y alimentación; para red registra códigos/estado sin credenciales. Cuando un experimento dependa del ambiente, una respuesta textual no sustituye la medición.

## Criterio de avance

GET 200; PUT válido 200 y cambio LED. Tipo incorrecto/campo extra: 400 sin cambiar salida.

## Límite que debes poder explicar

No hay autenticación de esta API: solo LED en LAN de laboratorio. Unidad18 aborda transporte protegido.

Un fallo detectado y explicado tiene valor formativo; no lo conviertas en éxito por cambiar el objetivo después de ejecutar. Para el proyecto conserva también intentos, pérdidas y condiciones que no pudiste reproducir.
