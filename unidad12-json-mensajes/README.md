# Unidad 12 — Diseño de mensajes y JSON

## Objetivo
Diseñar mensajes estables y comprensibles.

Ejemplo:
```json
{
  "deviceId": "nodo-01",
  "temperature": 25.4,
  "humidity": 68,
  "status": "ok"
}
```

## Buen diseño
- nombres consistentes;
- unidades documentadas;
- versión si el formato evolucionará;
- timestamp cuando tenga sentido;
- identificación del dispositivo;
- estados de error explícitos.

## No confíes en el mensaje
Valida tipos, campos y rangos.

## Reto
Diseña esquema JSON para un nodo ambiental y documenta cada campo.
