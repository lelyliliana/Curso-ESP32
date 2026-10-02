# Diseño de topics MQTT

## Ejemplo
```text
casa/sala/nodo01/telemetria
casa/sala/nodo01/estado
casa/sala/nodo01/comando
```

## Evita
- nombres ambiguos;
- mezclar telemetría y comandos;
- incluir secretos;
- cambiar estructura sin documentar.

## Preguntas
- ¿quién publica?
- ¿quién se suscribe?
- ¿qué ocurre al reconectar?
- ¿necesitas mensaje retenido?
- ¿qué QoS requiere el caso?

## Reto
Diseña topics para 10 nodos en dos ubicaciones sin crear nombres manualmente uno por uno.
