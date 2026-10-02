# Diseño — Cola offline

## Contrato
- Formato/version:
- Identidad del nodo:
- Generación de record_id sin reutilización después de reinicio:
- Secuencia y orden:
- Hora de medición, calidad temporal y hora de recepción:
- Tamaño máximo y calidad de lectura:

## Capacidad
- Intervalo de muestreo:
- Duración offline objetivo:
- Bytes medidos por registro y sobrecarga:
- Espacio reservado y margen:
- Máximo de registros:
- Política de llenado y contador de pérdida:

## Entrega
1. Guardar el registro y comprobar resultado.
2. Enviar un lote limitado.
3. Esperar confirmación de aplicación por ID, con timeout.
4. Persistir la confirmación de forma recuperable.
5. Compactar únicamente lo confirmado.

- Qué garantiza exactamente el ACK:
- Identidad/autorización del emisor de ACK:
- Deduplicación durable en servidor:
- Respuesta para un duplicado ya guardado:
- Reenvío tras ACK perdido:
- Tratamiento de rechazo permanente y cuarentena:

## Recuperación
| Interrupción | Resultado requerido |
|---|---|
| Durante append | detectar registro incompleto; conservar completos |
| Después de guardar, antes de enviar | recuperar como pendiente |
| Servidor guarda, ACK se pierde | mismo ID; una sola fila remota |
| ACK llega, nodo reinicia antes de persistirlo | reenvío deduplicado |
| Durante compactación | recuperar copia válida según diseño |
| Cola llena | política explícita y pérdida contabilizada |

## Sincronización
- Lote máximo, frecuencia y cuota de red:
- Tiempo reservado al control local:
- Backoff con límite y jitter:
- Métricas de backlog y antigüedad:

[Volver a la unidad](README.md)
