# Unidad 16 — Registro local y sincronización

## Objetivo
Diseñar un dispositivo que no pierda toda utilidad cuando la red falla.

## Patrón
```text
medir → intentar enviar
          ↓ fallo
       almacenar
          ↓ red vuelve
       sincronizar
```

## Preguntas
- ¿cuánto puedes almacenar?
- ¿qué ocurre al llenarse?
- ¿cómo evitas duplicados?
- ¿cómo marcas datos enviados?
- ¿qué reloj/timestamp utilizas?

## Reto
Diseña una cola de mediciones pendientes y una política de reenvío.
