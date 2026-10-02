# Arquitectura — Servidor web local

```text
navegador
   ↓ HTTP (LAN)
router/AP
   ↓
ESP32
 ├─ /          interfaz
 ├─ /estado    estado
 └─ /lectura   datos
```

## Separación
La interfaz HTML y los datos pueden evolucionar de forma independiente si expones endpoints claros.

## Seguridad
Este ejemplo está pensado para una red controlada. No conviertas el dispositivo en servidor público mediante redirección de puertos.

## Reto
Diseña una interfaz local que siga mostrando un estado comprensible cuando el sensor falle.
