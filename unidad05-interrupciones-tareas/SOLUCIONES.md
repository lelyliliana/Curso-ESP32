# Soluciones desarrolladas de la Unidad 05

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. Imprimir en ISR

Introduce trabajo largo y dependencias no apropiadas para la interrupción. La referencia actualiza el contador y representa una copia desde loop. Conserva las secciones críticas cortas.

## 2. Estabilidad de 30 ms

Guarda nivel crudo, nivel aceptado y marca del último cambio. Cuando se mantenga el nuevo nivel 30 ms, acepta la transición; emite un evento solo al aceptar LOW. Contar flancos antes de estabilizar no equivale a contar pulsaciones.

## 3. ISR frente a tarea

La ISR atiende un evento de hardware en un contexto especial. Una tarea es planificada por FreeRTOS y puede esperar en primitivas como una cola. Usa operaciones compatibles con cada contexto y una política explícita de datos compartidos.

## Cola llena

La referencia omite el número cuyo envío agotó 100 ms. No crece indefinidamente ni guarda automáticamente en flash. Para demostrar pérdidas añade instrumentación, no una afirmación basada solo en ver algunos números recibidos.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
