# Soluciones desarrolladas de la Unidad 01

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. HIGH como pulsado

Invierte la interpretación del contacto con pull-up: anunciará pulsado al soltar y libre al cerrar. El problema está en la comparación, no en que el botón produzca un dato aleatorio.

## 2. GPIO34 como salida

En el ESP32 clásico es solo entrada y no tiene polarización interna configurable como la de GPIO27. Puede utilizarse para el ADC del curso, con la señal externa apropiada.

## 3. Sustitución temporal por texto

Conserva el cálculo de pulsado e imprime su valor sin depender de una nueva salida. Cuando la regla esté clara, comprueba el pinout de la nueva placa y conecta el LED en un GPIO admitido. Una compilación no certifica ese montaje.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
