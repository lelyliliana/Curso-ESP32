# Soluciones desarrolladas de la Unidad 14

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. Advertising y conexión

El anuncio permite descubrir el servicio. Leer una característica exige la operación GATT correspondiente. Ver el nombre no demuestra haber leído datos ni identifica de forma segura al emisor.

## 2. Descriptor de notificaciones

No hace falta para esta práctica de solo lectura, que no ofrece NOTIFY. Actualizar el valor con setValue no envía por sí solo notificaciones a quien ya lo leyó.

## 3. Escribir un LED

No está implementado. La característica tiene permiso READ y el sketch ni define la salida del LED. Una ampliación necesita característica de escritura, validación y lógica de actuación.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
