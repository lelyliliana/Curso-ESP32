# Unidad 10 — Fundamentos de MQTT

## Objetivo
Comprender comunicación publish/subscribe.

## Actores
- broker;
- publisher;
- subscriber;
- topic.

```text
sensor → publica → broker → entrega → suscriptor
```

Ejemplo de topics:
```text
casa/sala/temperatura
casa/sala/comando
```

## Diseño
Los topics deben ser consistentes y describir jerarquía/propósito.

## QoS
MQTT ofrece distintos niveles de entrega. Más garantías implican más costo. Elige según el caso.

## Reto
Diseña árbol de topics para tres dispositivos con telemetría y comandos.
