# Contrato de API local

## GET /api/estado
Respuesta:
```json
{"status":"ok","uptimeMs":123456}
```

## GET /api/sensor
Respuesta normal:
```json
{"value":25.4,"unit":"C","valid":true}
```

Respuesta de sensor inválido:
```json
{"value":null,"unit":"C","valid":false}
```

## POST /api/salida
Solicitud:
```json
{"enabled":true}
```

## Validación
Rechaza:
- JSON mal formado;
- campos faltantes;
- tipos incorrectos;
- valores fuera de rango.

## Reto
Define códigos HTTP y cuerpos de error consistentes para cada caso.
