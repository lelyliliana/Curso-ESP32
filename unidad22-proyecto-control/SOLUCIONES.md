# Soluciones desarrolladas de la Unidad 22

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. ON repetido y motor

Mantiene un estado lógico y renueva el plazo, pero no verifica una carga física. La referencia solo controla LED. Un motor exigiría otros componentes y evidencia.

## 2. Retained antiguo

Podría aceptarse al volver a suscribirse si el cuerpo es válido y el botón libre. No se comprueban fecha ni command_id. La política del ensayo es no retener órdenes; no se presenta como protección completa contra reenvíos antiguos.

## 3. Latencia del botón

Mide bajo condiciones definidas y con instrumento/resolución documentados. Reconexión y llamadas síncronas pueden retrasar atención. Informa máximo observado y tamaño del ensayo; no lo conviertas en garantía universal de peor caso.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
