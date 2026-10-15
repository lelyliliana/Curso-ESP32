# Soluciones desarrolladas de la Unidad 02

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. Contador después de reiniciar

Se inicializa en RAM. No se usa Preferences ni otra memoria persistente. Un reinicio vuelve a comenzar en cero y la primera impresión periódica anuncia uno.

## 2. Tarea de 3000 ms

Utiliza una marca propia y un segundo if. Si comparte ultimo con la tarea de un segundo, esta puede impedir que alcance su periodo. A los múltiplos comunes pueden ejecutarse ambas sin ser hilos nuevos.

## 3. Periodo y exactitud

1000 ms es una decisión nominal. Tiempo de ejecución, reloj e instrumentación producen diferencias. Cronometrar varios intervalos permite describir lo observado; no convierte el dispositivo en un reloj calibrado.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
