# Soluciones desarrolladas de la Unidad 20

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. Continuación del programa

Deep sleep con despertar de esta referencia vuelve a ejecutar setup. No reanuda loop desde una instrucción suspendida. El contador RTC permite observar continuidad limitada entre esos despertares.

## 2. Promedio del ejercicio

La corriente media es `(100 mA × 1 s + 1 mA × 10 s) / 11 s = 10 mA`. La carga es 110 mA·s, equivalente a 0.110 C. Falta tensión para calcular energía; a 3.3 V hipotéticos sería 0.363 J por ciclo.

## 3. Medición USB

Incluye tarjeta, regulador, conversor y otros consumos según montaje. No demuestra corriente del chip aislado. Registra punto de medición, instrumento y duración de cada fase antes de extrapolar autonomía.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
