# Arquitectura pedagógica

## Relación con Arduino

ESP32 continúa el curso de Arduino. No repetirá de forma extensa electricidad básica, protoboard, LED, pulsadores, sensores elementales ni fundamentos de programación.

## Ejes

Hardware ESP32 → conectividad → protocolos → IoT → robustez → energía → integración.

## Reglas

- Identificar siempre la placa/familia exacta.
- Tratar GPIO como lógica de 3.3 V salvo documentación específica.
- No publicar credenciales reales en repositorios.
- Separar configuración y secretos del código versionado.
- Diseñar reconexión y estados de fallo.
- Evitar bloqueos prolongados que impidan conectividad.
- Validar mensajes recibidos antes de actuar.
- No exponer dispositivos directamente a Internet sin comprender el riesgo.
- Explicar limitaciones de seguridad de ejemplos educativos.
