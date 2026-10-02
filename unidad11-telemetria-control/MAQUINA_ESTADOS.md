# Máquina de estados — Cliente IoT

```text
INICIANDO
   ↓
SIN_WIFI ←────────┐
   ↓              │
CONECTANDO_WIFI   │
   ↓              │
SIN_BROKER ←──────┤
   ↓              │
CONECTANDO_MQTT   │
   ↓              │
OPERATIVO ────────┘ ante fallo
```

## Estado operativo
- medir;
- publicar según intervalo;
- procesar comandos válidos;
- reportar estado.

## Regla
Reconectar no debe bloquear indefinidamente la medición local.

## Reto
Añade estado DEGRADADO para seguir registrando datos sin broker.
