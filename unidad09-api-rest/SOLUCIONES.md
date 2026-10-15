# Soluciones desarrolladas de la Unidad 09

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. Repetir PUT true

El resultado representado sigue true. No alterna. Se conserva la propiedad de solicitar un estado concreto, aunque no se midan sus efectos físicos.

## 2. Enviar {}

Devuelve 400 antes de modificar activo. Prueba con el LED previamente ON y consulta después GET; debe conservarlo. Un rechazo no significa OFF.

## 3. Carga de potencia

Un GPIO y un LED de laboratorio no constituyen driver, alimentación ni realimentación de un actuador. Ampliar a potencia requiere un diseño específico. Esta API local tampoco incorpora identidad de usuarios o autorización.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
