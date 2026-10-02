# Proyecto — Nodo IoT ambiental

## Identidad
deviceId:

## Placa
Modelo exacto:
Pinout/documentación:

## Sensor
Modelo:
Interfaz:
Tensión:
Intervalo:

## Arquitectura
```text
sensor → ESP32 → Wi‑Fi → MQTT/HTTP → servicio
             ↘ almacenamiento local
```

## Mensaje
Documenta JSON/topic.

## Estados
- INICIANDO
- SIN_RED
- SIN_SERVICIO
- OPERATIVO
- SENSOR_ERROR
- DEGRADADO

## Reconexión
Intervalos/backoff:

## Credenciales
Cómo se mantienen fuera del repositorio:

## Pruebas
| escenario | esperado | obtenido |
|---|---|---|
| normal | | |
| sin Wi‑Fi | | |
| sin servicio | | |
| sensor inválido | | |
| reinicio | | |
| recuperación | | |

## Limitaciones
