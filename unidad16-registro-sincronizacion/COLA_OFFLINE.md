# Patrón — Cola offline

Cada registro puede incluir:
```text
id
timestamp
valor
estado_envio
```

## Al reconectar
1. enviar pendientes en orden;
2. esperar confirmación;
3. marcar/eliminar según política;
4. continuar hasta vaciar o alcanzar límite.

## Problemas
- duplicados;
- reloj incorrecto;
- almacenamiento lleno;
- reinicio durante sincronización.

## Reto
Define una política explícita para cada problema anterior.
