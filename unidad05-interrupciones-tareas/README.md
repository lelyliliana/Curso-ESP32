# Unidad 05 — Interrupciones, temporización y tareas

## Objetivo
Responder a eventos y organizar trabajo sin bloquear el sistema.

## Interrupciones
Una ISR debe ser breve. Evita operaciones lentas y trabajo complejo dentro de ella.

## Temporización
Prefiere diseños no bloqueantes para mantener conectividad y respuesta.

## Tareas
ESP32 permite modelos de ejecución más avanzados. Introduce tareas solo cuando aporten claridad; concurrencia innecesaria aumenta complejidad.

## Reto
Detecta un evento mediante interrupción, registra una bandera y procesa el evento de forma segura fuera de la ISR.
