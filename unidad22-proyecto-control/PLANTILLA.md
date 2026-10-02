# Proyecto — Control remoto seguro

## Montaje
- Placa, chip, versiones y pinout:
- Carga de baja tensión:
- GPIO, resistencia/driver y nivel activo:
- Fuente y consumo:
- Realimentación física disponible:
- Estado eléctrico durante arranque/reset/sueño:

## Alcance y autoridad
- Usuario y problema:
- Canal elegido:
- Quién puede controlar qué:
- Modo local/remoto y precedencia:
- Política de pérdida de supervisión:
- Tiempo máximo de respuesta local:

## Contrato
- Esquema y tamaño máximo:
- device_id / command_id:
- Operación de estado deseado:
- Tipos y rangos:
- Vigencia y fuente de hora:
- Política si el reloj no es fiable:
- Secuencia/revisión y concurrencia:
- Mismo ID con contenido diferente:
- Retained permitido/prohibido y razón:

## Aplicación y confirmación
- Recibido, aceptado, aplicado, verificado, fallido:
- Campos del resultado por ID:
- Qué demuestra el software:
- Qué demuestra la realimentación:
- Consulta/reconciliación si se pierde resultado:
- Deduplicación: capacidad, duración, persistencia y reinicio:
- Ambigüedad de una acción momentánea:

## Estados seguros
| Evento | Salida / acción | Motivo | Evidencia |
|---|---|---|---|
| Arranque / reinicio | | | |
| Comando inválido | | | |
| Emisor no autorizado | | | |
| Red perdida | | | |
| Timeout de supervisión | | | |
| Modo local activo | | | |
| OTA / sueño si aplica | | | |

## Pruebas
| Caso | Esperado medible | Obtenido | Evidencia |
|---|---|---|---|
| Válido | | | |
| Formato/tipo/rango/tamaño inválido | | | |
| No autorizado | | | |
| Duplicado idéntico | | | |
| ID repetido con otro contenido | | | |
| Vencido / reordenado | | | |
| Resultado perdido | | | |
| Cambios concurrentes | | | |
| Local + remoto | | | |
| Caída y reconexión | | | |
| Reinicio tras aplicar | | | |

## Reproducibilidad y límites
- Configuración sin secretos, compilación y carga:
- Servicio/cliente y versiones:
- Montaje, código, resultados y demostración:
- Pruebas físicas / simuladas / pendientes:
- Limitaciones de confirmación y control:
- Uso de IA, fuentes y licencias:

[Volver a la unidad](README.md)
