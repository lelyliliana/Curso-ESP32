# Proyecto — Nodo IoT ambiental

## Problema y alcance
- Variable, usuario y utilidad:
- Qué incluye y qué excluye:
- Sensor real o fuente simulada:
- Criterios de aceptación definidos antes de probar:

## Hardware y entorno
- Chip/placa y documentación:
- Sensor, interfaz, tensión y tiempo mínimo entre lecturas:
- Tabla GPIO y restricciones:
- Alimentación y consumo:
- Core, bibliotecas, herramientas y particiones:

## Arquitectura
Documenta adquisición, registro, conectividad, sincronización, servicio y dashboard. Incluye flujo de datos y confirmaciones.

## Contrato
- device_id y record_id estables:
- Esquema, campos, unidad, tamaño y rangos:
- Lectura inválida:
- Hora UTC / hora desconocida y calidad temporal:
- Topics o endpoint/método:
- ACK de aplicación y deduplicación durable:
- Autenticación y permisos del receptor/emisor de ACK:

## Temporización y almacenamiento
- Muestreo:
- Envío por lotes:
- Máxima duración de llamada / hueco de adquisición:
- Timeout, backoff y jitter:
- Bytes por registro y capacidad offline:
- Descarte, rechazo permanente y cuarentena:
- Recuperación de escritura incompleta y reinicio:
- Política de configuración, tipos y versión:

## Estados
Define estados independientes de sensor, almacenamiento, red y servicio. Explica cómo se deriva DEGRADADO y qué sigue funcionando.

## Seguridad y mantenimiento
- Credenciales fuera de Git y logs:
- Provisioning / revocación:
- Validación de transporte y permisos:
- Decisión sobre OTA, BLE y batería:
- Diagnóstico sin secretos:

## Pruebas
| Caso | Condiciones / duración | Esperado medible | Obtenido | Evidencia |
|---|---|---|---|---|
| Normal | | | | |
| Sin Wi-Fi | | | | |
| Sin servicio | | | | |
| Sensor inválido | | | | |
| ACK perdido / duplicado | | | | |
| Reinicio con pendientes | | | | |
| Cola llena | | | | |
| Recuperación y nuevas lecturas | | | | |
| Fallos simultáneos | | | | |

## Balance de datos
| Producidos | Persistidos | Únicos remotos | Pendientes | Rechazados | Descartados |
|---:|---:|---:|---:|---:|---:|
| | | | | | |

Explica las diferencias y el destino de los registros; distingue intentos de envío de registros únicos.

## Reproducción y resultados
- Configuración del servicio, compilación, carga y prueba:
- Versiones/commit:
- Enlaces a montaje, código y demostración:
- Resultados físicos, simulados y pendientes:
- Limitaciones y uso declarado de IA:
- Fuentes, autoría y licencias:

[Volver a la unidad](README.md)
