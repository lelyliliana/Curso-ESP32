# Unidad 22 — Proyecto: control remoto

## Objetivo
Controlar una salida desde otro sistema sin convertir cualquier mensaje recibido en una acción.

## Requisitos
- canal de comando;
- validación;
- confirmación de estado;
- timeout o estado seguro cuando corresponda;
- reconexión;
- registro de eventos.

## Arquitectura
```text
usuario/app → servicio/broker → ESP32 → validación → actuador
                                      ↓
                                estado/confirmación
```

## Seguridad
Utiliza una carga segura de baja tensión para el proyecto educativo. No controles red eléctrica directamente.

## Reto
Añade modo manual/local que siga funcionando sin Internet.
