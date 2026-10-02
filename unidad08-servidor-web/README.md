# Unidad 08 — Servidor web en ESP32

## Objetivo
Exponer una interfaz local para consultar o controlar el dispositivo.

## Arquitectura
```text
navegador → Wi‑Fi local → ESP32 → respuesta
```

## Endpoints
Empieza con:
- / estado;
- /lectura;
- /control.

## Seguridad
Un servidor educativo en red local no equivale a un servicio seguro para Internet. No abras puertos ni expongas el dispositivo públicamente sin una arquitectura adecuada.

## Reto
Crea una página local que muestre una lectura y el estado de una salida.
