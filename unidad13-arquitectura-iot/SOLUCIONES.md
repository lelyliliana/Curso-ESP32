# Soluciones desarrolladas de la Unidad 13

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. Arquitectura completa

Faltan adquisición real, transporte real, broker/servicio y consumidor según el objetivo, además de pruebas de integración. Este sketch solo simula una lectura y disponibilidad mediante Serial.

## 2. Capas de la Unidad 21

SHT31/Wire adquiere; la conversión produce unidades; ArduinoJson forma el mensaje; MQTT solicita publicarlo y el broker lo distribuye. Guardarlo exige otro componente. No hay persistencia local en ese nodo.

## 3. Sensor inválido independiente

Usa una dimensión separada del enlace y define cuatro combinaciones. Red disponible con dato inválido debe conservar un diagnóstico distinto de sensor válido sin transporte. Dos etiquetas impresas no sustituyen implementar adquisición y transporte.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
