# Soluciones razonadas del laboratorio 17

[Volver al laboratorio](LABORATORIO.md)

1. Jitter, además de la espera exponencial.
2. No: timeout limita llamada, backoff separa llamadas.
3. Escoge parte aleatoria dentro de un límite y registra el valor usado.

## Qué entregar

Explica la predicción, conserva la entrada o modificación exacta y compara resultado esperado y observado. Para hardware registra GPIO y alimentación; para red registra códigos/estado sin credenciales. Cuando un experimento dependa del ambiente, una respuesta textual no sustituye la medición.

## Criterio de avance

Al recuperar detiene intentos; tras f vuelve a intervalo 1 s.

## Límite que debes poder explicar

El ejemplo enseña backoff determinista, no afirma que todos los clientes del curso ya lo implementen.

Un fallo detectado y explicado tiene valor formativo; no lo conviertas en éxito por cambiar el objetivo después de ejecutar. Para el proyecto conserva también intentos, pérdidas y condiciones que no pudiste reproducir.
