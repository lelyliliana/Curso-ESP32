# Soluciones razonadas del laboratorio 15

[Volver al laboratorio](LABORATORIO.md)

1. Consultas otro conjunto de claves.
2. remove("arranques") dentro de namespace abierto, tras confirmar intención.
3. Flash/capacidad/endurance son finitos.

## Qué entregar

Explica la predicción, conserva la entrada o modificación exacta y compara resultado esperado y observado. Para hardware registra GPIO y alimentación; para red registra códigos/estado sin credenciales. Cuando un experimento dependa del ambiente, una respuesta textual no sustituye la medición.

## Criterio de avance

El contador incrementa tras reset; borrar NVS devuelve el valor por defecto cero.

## Límite que debes poder explicar

El contador puede desbordar y no es identidad global. No conserva hora UTC.

Un fallo detectado y explicado tiene valor formativo; no lo conviertas en éxito por cambiar el objetivo después de ejecutar. Para el proyecto conserva también intentos, pérdidas y condiciones que no pudiste reproducir.
