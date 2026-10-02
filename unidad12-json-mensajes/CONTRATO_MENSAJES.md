# Contrato de mensajes

## Telemetría v1
```json
{
  "version": 1,
  "deviceId": "nodo-01",
  "temperatureC": 25.4,
  "humidityPct": 68.0,
  "status": "ok"
}
```

## Comando v1
```json
{
  "version": 1,
  "command": "setOutput",
  "enabled": true
}
```

## Validación
Antes de actuar:
- versión conocida;
- comando permitido;
- campos presentes;
- tipos;
- rangos.

## Evolución
Versionar el formato permite cambiarlo sin fingir que todos los dispositivos entienden el nuevo esquema.
