# Unidad 06 — Conexión Wi‑Fi y reconexión

## Objetivo
Conectar el dispositivo sin asumir que la red estará siempre disponible.

## Credenciales
En ejemplos públicos:
```cpp
const char* ssid = "TU_RED";
const char* password = "TU_CLAVE";
```
No publiques valores reales.

## Estados
```text
SIN RED → CONECTANDO → CONECTADO
             ↑           ↓
             └── fallo ──┘
```

## Diseño
Evita esperar indefinidamente bloqueando todo el dispositivo. Implementa reintentos con intervalos razonables.

## Reto
Muestra por Serial cambios de estado Wi‑Fi y recupera la conexión después de una desconexión.
