# Unidad 07 — Cliente HTTP y consumo de APIs

## Objetivo
Consumir información desde un servicio HTTP.

## Flujo
```text
ESP32 → solicitud HTTP → servidor
ESP32 ← respuesta HTTP ← servidor
```

Comprueba:
- conectividad;
- URL;
- código HTTP;
- cuerpo;
- tiempo de espera;
- error de red.

## HTTPS
TLS añade seguridad pero también requisitos de certificados, memoria y configuración. No desactives validación como solución permanente.

## Reto
Consume una API pública apropiada, registra código de estado y procesa un dato de la respuesta.
