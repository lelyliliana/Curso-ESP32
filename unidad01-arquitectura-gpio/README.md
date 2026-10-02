# Unidad 01 — Arquitectura, GPIO y diferencias con Arduino

## Objetivo
Comprender que ESP32 ofrece conectividad y periféricos avanzados, pero sus pines tienen restricciones específicas.

## Diferencias clave
Según familia/modelo puede incluir Wi‑Fi, Bluetooth/BLE, varios ADC, PWM, buses y múltiples núcleos/tareas.

## GPIO
No todos los pines son equivalentes. Algunos pueden estar reservados, relacionados con arranque, flash u otras funciones.

**Consulta el pinout exacto antes de elegir un pin.**

## Lógica
ESP32 utiliza típicamente 3.3 V. Un dispositivo de 5 V puede requerir adaptación de nivel.

## Reto
Selecciona pines para LED, pulsador, I2C y una entrada analógica justificando cada elección con documentación de tu placa.
