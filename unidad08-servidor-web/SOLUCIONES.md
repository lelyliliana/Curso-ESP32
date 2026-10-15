# Soluciones desarrolladas de la Unidad 08

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. Quitar handleClient

El registro de rutas sigue existiendo, pero falta su atención habitual en loop. Separa ese síntoma del enlace Wi-Fi: una IP válida no demuestra que la aplicación responda.

## 2. Identificador de nodo

Modifica el texto HTML del callback de `/`, compila y carga la copia. Solicita una respuesta nueva para distinguirla de una página anterior conservada por el navegador.

## 3. Origen del 404

La lambda registrada en onNotFound llama server.send con 404. Es una decisión de la aplicación para una petición que no coincide con sus rutas, no un error genérico del router.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
