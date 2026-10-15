# Soluciones desarrolladas de la Unidad 17

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. Distribuir intentos

Añade jitter con límites definidos. El patrón determinista puede sincronizar nodos; tener diferentes clientId no distribuye por sí solo sus tiempos de reconexión.

## 2. Timeout

Sigue siendo necesario. Backoff regula separación entre operaciones; timeout acota la espera dentro de una de ellas. Son controles complementarios.

## 3. Jitter acotado

Por ejemplo, para una base de 8000 ms elige un retraso entre 4000 y 8000, y para base 16000 entre 8000 y 16000. No añadas un valor positivo a 16000 sin recortar, porque superarías el máximo.

## Detalle del reinicio

r restablece intervalo y contador y detiene la simulación. f habilita y reinicia la marca del momento, pero no restablece los otros dos valores. Describe esa diferencia al probar recuperación y fallo nuevo.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
