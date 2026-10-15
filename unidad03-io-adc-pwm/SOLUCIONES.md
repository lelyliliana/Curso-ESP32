# Soluciones desarrolladas de la Unidad 03

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. duty para 2048

El producto es 522240. Dividido entre 4095 da 127 con división entera. La cuenta representa casi media escala, no una promesa de mitad de brillo percibido.

## 2. Máximo 128

Antes de ledcWrite, aplica `if (duty > 128) duty = 128;` en una copia. Para ADC 4095 se obtiene inicialmente 255 y se recorta. Para 2048 queda 127. Una conversión proporcional a 128 tendría otro resultado intermedio.

## 3. Tensión exacta

No se deduce de una regla de tres ideal. Comprueba atenuación, referencia/calibración, rango y montaje. La unidad de un código no es voltios. Si amplías a milivoltios, declara qué función y condiciones utilizaste.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
