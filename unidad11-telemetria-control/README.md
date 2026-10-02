# Unidad 11 — Telemetría y control con MQTT

## Objetivo
Publicar mediciones y recibir comandos.

## Telemetría
El dispositivo publica datos a intervalos razonables.

## Control
El dispositivo se suscribe a un topic de comandos.

## Validación
Un mensaje recibido no debe convertirse automáticamente en una acción física. Valida:
- topic;
- formato;
- rango;
- estado permitido.

## Reconexión
El cliente debe poder recuperar Wi‑Fi y sesión MQTT.

## Reto
Publica una lectura y controla una salida mediante mensajes validados.
