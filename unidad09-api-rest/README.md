# Unidad 09 — API REST básica en el dispositivo

## Objetivo
Separar datos y control de la interfaz HTML.

Ejemplos:
```text
GET /api/estado
GET /api/sensor
POST /api/salida
```

## JSON
```json
{"temperatura":25.4,"estado":"normal"}
```

## Validación
Nunca actúes sobre datos recibidos sin comprobar formato y rango.

## Reto
Diseña una API local con lectura de sensor y control de una salida. Define códigos de respuesta para datos inválidos.
