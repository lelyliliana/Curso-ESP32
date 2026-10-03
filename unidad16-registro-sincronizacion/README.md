# Unidad 16 — Registro local y sincronización

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/esp32/)

## Qué aprenderás
Diseñar una cola finita que conserve mediciones durante una caída y sincronice sin perder registros silenciosamente ni duplicar efectos.

## 1. Persistir antes de intentar enviar
Si el requisito exige sobrevivir a un reinicio, guardar solo después de un envío fallido deja una ventana de pérdida. Diseña un patrón store-and-forward: validar la medición, asignar identidad, guardar el registro y luego intentar enviarlo.

Una cola en RAM es útil, pero se pierde al reiniciar. La persistencia tampoco garantiza pérdida cero: define qué ocurre con la lectura que estaba en RAM o a medio escribir cuando se corta la energía.

## 2. Contrato de registro
| Campo | Propósito |
|---|---|
| schema_version | interpretar formato |
| device_id | identificar origen |
| record_id | deduplicar reenvíos |
| sequence | ordenar dentro del origen |
| measured_at | hora UTC si es conocida; null si no |
| time_quality | sincronizada, estimada o desconocida |
| value / quality | valor y validez de la medición |

El ID debe mantenerse igual en todos los reenvíos y no reutilizarse al reiniciar. Una opción es un contador persistente con reserva de bloques; otra, combinar identidad de arranque suficientemente única y secuencia. Documenta las garantías y el coste. millis() solo describe tiempo relativo del arranque.

received_at, asignado por el servidor, no reemplaza measured_at. No inventes la hora de una lectura antigua porque el reloj se sincronizó después.

## 3. Estados y confirmación
Un registro pasa por PENDIENTE, EN_VUELO y CONFIRMADO. EN_VUELO es temporal: tras un reinicio, lo no confirmado vuelve a ser pendiente.

El éxito de publish puede significar que una biblioteca aceptó el mensaje. PUBACK confirma recepción MQTT por el broker, no escritura en tu base de datos. Define una confirmación de aplicación vinculada al ID cuando necesites confirmar almacenamiento remoto durable.

El servidor debe deduplicar por identidad del registro y confirmar también los duplicados ya almacenados. Confirma después del compromiso durable. Si el ACK se pierde, el nodo reenvía el mismo ID y el servidor no crea una segunda fila.

## 4. Esquema de procesamiento
Este pseudocódigo describe responsabilidades; no implementa un sistema de archivos ni una biblioteca de red:

```text
al medir:
  validar lectura
  crear registro con ID estable
  append durable; comprobar resultado
  si falla: registrar perdida y aplicar politica

en cada ciclo:
  atender sensor y control local
  si servicio disponible y vence turno:
    recuperar un lote pequeno pendiente
    enviar sin espera indefinida
  al recibir ACK autorizado:
    comprobar ID y resultado durable
    marcar confirmado de forma recuperable
  compactar solo registros confirmados
```

Si falla la persistencia del ACK local, puede haber reenvío; la deduplicación remota debe cubrirlo. No borres el registro antes de comprobar la confirmación.

## 5. Capacidad y descarte
Calcula capacidad a partir de bytes por registro, metadatos y tiempo offline. Por ejemplo, una lectura cada 10 s produce 8 640 registros al día; a 128 bytes son 1 105 920 bytes, sin índices ni sobrecarga.

Decide antes de llenarse: descartar los más antiguos, rechazar nuevos, agregar mediciones o reducir frecuencia. Cada opción pierde información diferente. Registra conteo de descartes y periodo afectado; no anuncies “sin pérdida” si tu política descarta.

No almacenes comandos momentáneos para ejecutarlos horas después sin autorización y expiración. Una cola de telemetría y una cola de control tienen requisitos diferentes.

## 6. Reenvío controlado
Envía lotes acotados, limita mensajes/bytes por turno y conserva tiempo para el control local. Usa timeout, backoff y jitter ante fallos. No descargues todo el historial en un bucle cerrado al reconectar.

Distingue errores transitorios de permanentes. Un registro que el servidor rechaza por esquema no debe bloquear toda la cola indefinidamente: conserva evidencia en una cuarentena acotada y aplica una política explícita.

## 7. Recuperación de archivos
Define cómo detectar una escritura incompleta, recuperar registros completos y compactar sin destruir la única copia. Prueba el mecanismo real; append, flush o rename no tienen garantías universales de durabilidad y atomicidad entre todos los medios.

Completa [COLA_OFFLINE.md](COLA_OFFLINE.md) con capacidad, ACK, deduplicación y recuperación.

## 8. Práctica guiada
1. Genera lecturas simuladas con ID y calidad de tiempo.
2. Desconecta el servicio durante 5 minutos; comprueba crecimiento de pendientes.
3. Reinicia el nodo: los registros completos persistidos deben reaparecer.
4. Reconecta y envía como máximo un lote pequeño por turno.
5. Pierde intencionalmente un ACK: comprueba reenvío del mismo ID y una sola fila remota.
6. Reinicia después de confirmar remotamente y antes de guardar el ACK local.
7. Llena una cola pequeña de laboratorio; verifica la política y contador de descartes.
8. Introduce un registro rechazado: comprueba que no bloquea indefinidamente los válidos.

Registra producidos, guardados, únicos remotos, pendientes, rechazados y descartados. Los conteos deben explicar el destino de cada registro.

## 9. Observabilidad
Publica capacidad usada, antigüedad del pendiente más viejo, reintentos, descartes y último ACK. Evita registrar secretos o todo el contenido sensible.

## 10. Reto y autoevaluación
Diseña una cola para 24 h sin red, con medición cada 10 s y almacenamiento finito. Calcula bytes reales, velocidad de vaciado y competencia con lecturas nuevas.

¿Quién confirma durabilidad? ¿Qué pasa si el ACK se pierde? ¿Cómo evitas IDs repetidos? ¿Qué significa una hora desconocida? ¿Qué descarta tu política?

## 11. Checklist
- [ ] IDs estables y deduplicación remota.
- [ ] Persistencia acorde al requisito.
- [ ] ACK de aplicación definido.
- [ ] Cola y cuarentena acotadas.
- [ ] Recuperación tras reinicio.
- [ ] Pérdidas contabilizadas.
- [ ] Reenvío sin bloquear control.

[Anterior: almacenamiento](../unidad15-almacenamiento/) · [Siguiente: fallos](../unidad17-fallos-reconexion/) · [Índice](../README.md)


---

## Continuar el curso

- **Unidad anterior:** [Unidad 15 — Almacenamiento y configuración](../unidad15-almacenamiento/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 17 — Manejo de fallos y reconexión](../unidad17-fallos-reconexion/README.md)
