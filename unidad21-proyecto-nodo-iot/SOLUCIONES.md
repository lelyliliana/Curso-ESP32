# Soluciones desarrolladas de la Unidad 21

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. Medidas sin Wi-Fi

No quedan almacenadas en este nodo. La lectura local puede continuar según atención del loop, pero no existe cola de telemetría. La reconexión no recupera automáticamente ese pasado.

## 2. Campos nuevos

Añade source como texto real y schema_version como número 1 al JsonDocument. Actualiza consumidores y pruebas; el validador estricto de la Unidad 12 rechazaría esos campos extras sin una ampliación coordinada. Comprueba tamaño y serialización.

## 3. Pendiente persistente

El registro debe conservar valor original, unidad, calidad e identidad antes del envío. Una retransmisión usa los mismos datos. La Unidad 16 guarda solo un evento nodo/id y tiene escrituras separadas; no basta copiarla para afirmar una cola ambiental completa y atómica.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
