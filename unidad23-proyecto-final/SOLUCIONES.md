# Soluciones desarrolladas de la Unidad 23

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. Lectura completa

SHT31 → Wire → comprobación de longitud/CRC → conversión → JSON → publicación QoS0 → broker → suscriptor. Cada flecha necesita evidencia distinta; Serial no demuestra recepción remota y recepción no demuestra persistencia.

## 2. Efecto de una carga

La variable activo y state solo informan decisión de firmware. Observación o realimentación física adecuada debe confirmar el efecto. El integrador base controla un LED, no una carga de potencia.

## 3. Persistencia y ACK

Guarda un registro completo e identidad estable, conserva el pendiente hasta un ACK de aplicación que corresponda a ese registro y prueba reenvío del mismo contenido tras perder la respuesta. Documenta capacidad y ventanas de escritura. Una respuesta MQTT o un JSON local no sustituyen esa confirmación durable.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
