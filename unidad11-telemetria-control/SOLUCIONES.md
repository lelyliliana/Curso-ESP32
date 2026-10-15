# Soluciones desarrolladas de la Unidad 11

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. Repetir true

Conserva ON y renueva ultimoComando. Si el segundo llega a los seis segundos, el plazo se cuenta desde esa segunda aceptación. Es idempotente respecto al valor de salida, no respecto al tiempo de autorización.

## 2. Retained en command

Puede reactivar una orden antigua después de reconectar. La referencia no comprueba antigüedad ni command_id. Retener state para observación y retener una orden de actuación son decisiones diferentes.

## 3. Demora de pérdida del broker

Mide entre detenerlo y observar OFF, indicando condiciones y registros. Keepalive, timeouts y llamadas síncronas afectan detección. No infieras una respuesta instantánea del botón o de la red por el nombre de una condición.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
