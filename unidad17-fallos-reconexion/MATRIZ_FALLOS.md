# Matriz de fallos

| Fallo | Detectar | Estado de capa | Acción local | Recuperación / evidencia |
|---|---|---|---|---|
| Wi-Fi | eventos/status y timeout | SIN_RED | medir/controlar según política | backoff+jitter; último éxito |
| DNS/TCP | código y timeout | SIN_SERVICIO | conservar pendientes | reintento limitado por capa |
| Broker caído | desconexión/timeout | SIN_SERVICIO | store-and-forward | lotes limitados al recuperar |
| Autenticación | rechazo explícito | ACCESO_RECHAZADO | modo seguro | reprovisioning; sin insistencia agresiva |
| TLS | error de validación | CONFIANZA_ERROR | no transmitir al origen no validado | revisar hora/CA/hostname |
| Sensor | rango, bus, calidad y edad | SENSOR_ERROR | no fabricar lectura válida | reintento del sensor y alarma |
| JSON | parser y contrato | MENSAJE_INVALIDO | no aplicar cambios | rechazo observable |
| Almacenamiento | error/capacidad | STORAGE_ERROR | política de pérdida | conservar evidencia; no formatear automáticamente |
| Alimentación | reset/brownout y medición del montaje | ARRANQUE_SEGURO | salidas seguras | revisar fuente, picos y conexiones |
| OTA | descarga, validación o arranque fallido | UPDATE_ERROR | conservar firmware válido | recuperación/rollback configurado |

## Fallos simultáneos
Describe sensor inválido + broker caído y cola llena + red caída. Resolver Wi-Fi no debe borrar el diagnóstico del sensor.

## Criterios antes de probar
- Periodo local y hueco máximo:
- Duración máxima de una llamada:
- Calendario de reintentos:
- Edad máxima de datos para controlar:
- Cuándo se considera recuperación estable:
- Qué información conservas tras reinicio:

## Evidencias
Registra evento, hora relativa/real con calidad, estado de cada capa, acción, resultado y pérdida de datos. No incluyas secretos.

[Volver a la unidad](README.md)
