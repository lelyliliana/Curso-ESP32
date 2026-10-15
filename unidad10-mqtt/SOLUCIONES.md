# Soluciones desarrolladas de la Unidad 10

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. Offline no instantáneo

El broker necesita detectar pérdida no limpia según keepalive y condiciones de la conexión. Mide demora observada sin prometer que sea exactamente 15 s. El testamento tiene un propósito distinto del mensaje local del monitor.

## 2. Telemetría para un suscriptor nuevo

No se retiene en esta referencia. Puede recibir availability retenido y esperar una telemetría futura. Retained conserva el último valor de un tópico, no un histórico completo.

## 3. Segundo dispositivo

Una propuesta es clientId leli-nodo02 y prefijo curso/nodo02, acompañados por permisos apropiados. Cambia todos los lugares relevantes y registra la identidad. Dos conexiones con leli-nodo01 pueden reemplazarse mutuamente aunque publiquen datos distintos.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
