# Soluciones desarrolladas de la Unidad 16

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. POST sin identidad estable

Perder la respuesta no demuestra que el servidor no guardó. Crear otra identidad al reintentar puede duplicar la intención. Reenviar la misma identidad/cuerpo permite que el receptor detecte duplicados.

## 2. Cola llena

No se generan otros eventos mientras hay=true. Tampoco se están capturando temperaturas. Es un pendiente de demostración, no un histórico de mediciones almacenadas.

## 3. Corte entre escrituras

seq, id y hay se escriben en operaciones distintas. Un reinicio intermedio puede dejar una combinación parcial o saltos. No se presenta como registro atómico de aplicación.

## ACK y limpieza

200/201 con ACK correcto confirma al receptor. Limpiar hay en NVS es otro paso, que también puede fallar. Si queda pendiente se reenvía sin crear otra fila gracias a identidad y contenido estables. Verifica ambas partes por separado.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
