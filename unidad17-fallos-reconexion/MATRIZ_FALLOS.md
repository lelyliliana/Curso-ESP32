# Matriz de fallos

| Fallo | Detectar | Estado | Acción | Recuperación |
|---|---|---|---|---|
| Wi‑Fi | status | SIN_RED | operar local | reintento |
| broker | conexión | SIN_SERVICIO | almacenar | backoff |
| sensor | validación | SENSOR_ERROR | no publicar dato falso | reintento |
| JSON | parser | MENSAJE_INVALIDO | ignorar/rechazar | esperar siguiente |

## Reto
Añade fallos de almacenamiento y alimentación a la matriz.
