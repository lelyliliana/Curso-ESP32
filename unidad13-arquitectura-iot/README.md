# Unidad 13 — Arquitectura de un sistema IoT

## Objetivo
Comprender que ESP32 es una pieza de un sistema.

```text
sensor
  ↓
ESP32
  ↓
red
  ↓
broker/API
  ↓
procesamiento/almacenamiento
  ↓
dashboard/alerta
```

## Decisiones
- procesamiento local o remoto;
- frecuencia de muestreo;
- frecuencia de transmisión;
- tolerancia a pérdida de red;
- almacenamiento temporal;
- seguridad;
- actualización;
- energía.

## Reto
Diseña arquitectura completa para monitoreo ambiental en tres ubicaciones. Explica qué ocurre si Internet falla durante una hora.
