# Guía — Cliente HTTP robusto

No basta con “recibí texto”.

Registra:
1. conectividad;
2. resultado de conexión;
3. código HTTP;
4. Content-Type cuando importe;
5. cuerpo;
6. error de parseo;
7. timeout.

## Ejemplos de estados
```text
200 → respuesta correcta
4xx → problema de solicitud/autorización
5xx → fallo del servidor
```

No conviertas todos los errores en “sin Internet”.

## Reto
Diseña una función que distinga fallo Wi‑Fi, fallo HTTP y JSON inválido.
