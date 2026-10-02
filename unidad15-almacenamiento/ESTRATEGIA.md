# Estrategia de almacenamiento

Clasifica cada dato:

| dato | RAM | persistente | frecuencia de escritura | razón |
|---|---|---|---|---|
| lectura actual | ✓ | | alta | temporal |
| umbral | | ✓ | baja | configuración |
| contador | depende | depende | | requisito |

## Evita
Escribir en flash cada ciclo.

## Integridad
Si una configuración es crítica, valida rango y versión al recuperarla.

## Reto
Diseña estructura de configuración con versión, valores por defecto y validación.
