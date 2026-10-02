# Recorrido y criterios del curso

## Relación con Arduino

El curso parte de conocimientos de electricidad básica, protoboard, LED, pulsadores, sensores y programación adquiridos en el [Curso de Arduino](https://github.com/lelyliliana/Curso-Arduino). El recorrido se centra en las particularidades de ESP32, la conectividad y el diseño de dispositivos IoT.

## Ejes

Hardware ESP32 → conectividad → protocolos → IoT → robustez → energía → integración.

## Criterios para las prácticas

- Identificar siempre la placa/familia exacta.
- Tratar GPIO como lógica de 3.3 V salvo documentación específica.
- No publicar credenciales reales en repositorios.
- Separar configuración y secretos del código versionado.
- Diseñar reconexión y estados de fallo.
- Evitar bloqueos prolongados que impidan conectividad.
- Validar mensajes recibidos antes de actuar.
- No exponer dispositivos directamente a Internet sin comprender el riesgo.
- Explicar limitaciones de seguridad de ejemplos educativos.
