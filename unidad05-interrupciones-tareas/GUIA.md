# Guía — Interrupciones y tareas

## Interrupción
La ISR debe hacer lo mínimo:
```text
evento físico → ISR breve → bandera/contador → procesamiento normal
```

Evita dentro de ISR:
- esperas;
- operaciones lentas;
- lógica extensa.

## Tareas
Antes de crear tareas concurrentes pregunta:
- ¿millis() y una máquina de estados bastan?
- ¿qué datos serán compartidos?
- ¿qué condición de carrera podría aparecer?

## Reto
Compara dos diseños del mismo sistema: bucle cooperativo vs. tareas. Justifica cuál es más simple y suficiente.
