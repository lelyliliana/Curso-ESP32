# Unidad 20 — Consumo energético y deep sleep

## Objetivo
Diseñar nodos que puedan funcionar con energía limitada.

## Presupuesto
El consumo depende de:
- radio;
- sensores;
- regulador;
- LED;
- tiempo activo;
- frecuencia de transmisión.

## Estrategia
```text
despertar → medir → conectar → transmitir → dormir
```

## Deep sleep
Puede reducir drásticamente consumo, pero cambia la arquitectura del programa.

## Medir
No confíes únicamente en valores teóricos. Mide el dispositivo completo cuando el consumo sea requisito del proyecto.

## Reto
Diseña un nodo que mida cada 10 minutos. Define qué permanece encendido y estima conceptualmente el ciclo de trabajo.
