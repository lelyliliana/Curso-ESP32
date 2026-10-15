# Soluciones desarrolladas de la Unidad 19

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. Puerto de red ausente

Comprueba firmware OTA inicial, clave, IP, red común alcanzable, descubrimiento local y configuración de la herramienta. Una red de invitados puede impedir acceso. Tener Wi-Fi no prueba que el computador descubra el servicio.

## 2. Firma o rollback

No están demostrados por el sketch. Una clave de transferencia y callbacks de progreso no equivalen a firmware firmado ni recuperación automática probada.

## 3. Primero USB

Instala el receptor OTA y proporciona una vía de recuperación. Después verifica el nuevo arranque con VERSION_FIRMWARE distinto, no solo el porcentaje de transferencia. El esquema de particiones también debe soportar la actualización.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
