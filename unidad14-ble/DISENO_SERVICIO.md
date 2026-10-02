# Diseño conceptual de servicio BLE

## Servicio
```text
EnvironmentalService
```

## Características
```text
temperature → read / notify
humidity    → read / notify
threshold   → read / write
status      → read
```

## Preguntas
- ¿qué datos son solo lectura?
- ¿qué configuración puede escribirse?
- ¿qué debe validarse?
- ¿qué frecuencia de notificación tiene sentido?

## Seguridad
No asumas que estar “cerca” hace seguro un comando. Evalúa autenticación/emparejamiento según el caso.
