# Unidad 17 — Manejo de fallos y reconexión

## Objetivo
Tratar fallos como estados normales de un sistema conectado.

Posibles fallos:
- sensor;
- Wi‑Fi;
- DNS;
- servidor;
- broker;
- respuesta inválida;
- almacenamiento.

## Evita
Reintentar en un ciclo cerrado miles de veces.

## Backoff
Incrementar intervalos entre reintentos puede reducir congestión y consumo.

## Estado degradado
El dispositivo puede continuar midiendo localmente aunque no pueda transmitir.

## Reto
Diseña una máquina de estados para NORMAL, SIN_RED, SIN_SERVICIO y SENSOR_ERROR.
