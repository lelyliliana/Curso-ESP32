# Diagnóstico IoT — Por capas

Cuando el sistema no funciona, identifica primero la capa.

## 1. Hardware
¿La placa y el sensor funcionan localmente?

## 2. Red
¿Hay Wi‑Fi? ¿IP? ¿DNS?

## 3. Transporte
¿Puedes establecer conexión TCP/TLS cuando aplica?

## 4. Protocolo
¿HTTP/MQTT responde correctamente?

## 5. Formato
¿JSON/mensaje es válido?

## 6. Aplicación
¿La lógica interpreta correctamente el dato?

## 7. Servicio
¿Broker/API/base de datos están disponibles?

## Regla
“Internet no funciona” no es un diagnóstico. Identifica la capa exacta donde deja de cumplirse el contrato esperado.
