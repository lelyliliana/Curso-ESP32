# Unidad 19 — Actualizaciones OTA

## Objetivo
Comprender actualización de firmware sin acceso físico.

## Riesgo
Una actualización fallida puede dejar un dispositivo inoperable. Un sistema real necesita estrategia de recuperación.

## Consideraciones
- autenticación;
- integridad;
- versión;
- energía estable;
- particiones/espacio;
- rollback cuando la plataforma lo soporte.

## Reto
Diseña el flujo de una actualización segura: comprobar versión → descargar → verificar → instalar → reiniciar → validar.
