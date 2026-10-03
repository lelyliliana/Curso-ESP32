# Unidad 21 — Proyecto: nodo IoT ambiental

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/esp32/)

## Qué construirás
Un nodo ESP32 que mide una variable ambiental, publica datos con calidad e identidad, conserva pendientes durante una caída y se recupera de forma observable.

Este proyecto integra las unidades anteriores. Es una guía de construcción: debes implementar y verificar el firmware y el servicio elegidos. No incluye una aplicación completa precompilada ni resultados de hardware ya comprobados.

## 1. Alcance mínimo
Elige una variable y un sensor compatible. Empieza con lecturas simuladas para comprobar el flujo; luego integra el sensor real y distingue ambas fuentes en tus evidencias.

El sistema mínimo incluye:
- placa y conexiones documentadas;
- muestreo independiente de transmisión;
- Wi-Fi con timeout, backoff y jitter;
- MQTT o HTTP, con contrato y servicio receptor;
- lectura válida/inválida y calidad temporal explícitas;
- configuración persistente y cola finita;
- deduplicación y confirmación de almacenamiento remoto;
- diagnóstico y pruebas de caída, reinicio y recuperación.

No necesitas implementar HTTP y MQTT simultáneamente. Elige uno y justifica sus requisitos. BLE, batería y OTA se incorporan cuando forman parte del alcance; documenta su decisión.

## 2. Arquitectura
El sensor entrega una lectura al módulo de adquisición. El nodo valida, identifica y persiste el registro; un módulo de transporte envía pendientes al servicio. El servicio deduplica, almacena y confirma por ID. El dashboard consulta datos guardados y muestra su edad/calidad.

| Responsabilidad | Entrada | Salida / evidencia |
|---|---|---|
| Adquisición | sensor o simulador | lectura y calidad |
| Registro | lectura validada | ID estable y persistencia comprobada |
| Conectividad | estado de red/servicio | intentos acotados y diagnóstico |
| Sincronización | pendientes | ACK por ID y backlog |
| Servicio | registro | fila única durable y ACK |
| Visualización | datos guardados | valor, unidad, fecha y calidad |

Completa [PLANTILLA.md](PLANTILLA.md) antes del montaje. Reutiliza la [arquitectura IoT](../unidad13-arquitectura-iot/) y la [cola offline](../unidad16-registro-sincronizacion/).

## 3. Hardware y configuración
Registra chip, placa, sensor, tensión, interfaz, GPIO, resistencias necesarias y alimentación. Comprueba pinout y compatibilidad de 3.3 V. No asumas que un módulo alimentado a 5 V tiene señales compatibles.

Fija versiones de core y bibliotecas. Documenta particiones y espacio para configuración/cola. Publica una plantilla sin secretos y explica cómo proporcionar credenciales localmente.

## 4. Contrato de telemetría
Ejemplo de registro simulado, no una medición real:

```json
{
  "schema_version": 1,
  "device_id": "nodo-lab-01",
  "record_id": "nodo-lab-01:arranque-unico:42",
  "sequence": 42,
  "measured_at": null,
  "time_quality": "unknown",
  "source": "simulated",
  "measurement": {
    "name": "temperature",
    "value": 24.6,
    "unit": "degC",
    "quality": "valid"
  }
}
```

Define tamaño máximo, rangos acordes al sensor, campos obligatorios y formato UTC cuando haya hora fiable. Para una lectura inválida utiliza value null y quality apropiada; no inventes 0 ni -999. Un rango físicamente posible no garantiza exactitud o calibración.

El texto arranque-unico ilustra el contrato: la implementación debe generar una identidad de arranque no reutilizada o usar otra estrategia estable. Mantén record_id en cada reenvío.

En MQTT separa telemetría, estado y confirmaciones por nodo; en HTTP define endpoint, método y respuesta. El ACK de aplicación debe identificar el registro almacenado. Ni publish aceptado ni un 200 sin cuerpo contractual bastan para demostrar persistencia.

## 5. Construcción por etapas
### Etapa A — Medición local
Implementa una lectura simulada periódica y luego el sensor. Muestra valor, calidad y edad. Avanza cuando el muestreo funcione sin red.

### Etapa B — Contrato y receptor
Valida el JSON en el servicio. Envía un registro y verifica una fila guardada. Reenvía el mismo ID: debe seguir existiendo una sola fila y recibirse confirmación.

### Etapa C — Conectividad
Añade conexión y reintentos acotados. Mide el peor tiempo de llamada y confirma que el muestreo continúa durante caídas.

### Etapa D — Persistencia
Carga configuración validada. Guarda registros antes del intento de envío si deben sobrevivir a reinicios. Define capacidad, recuperación de escrituras incompletas y descarte.

### Etapa E — Sincronización
Envía lotes pequeños y confirma por ID. Pierde un ACK y reinicia entre almacenamiento remoto y confirmación local; el reenvío debe deduplicarse.

### Etapa F — Dashboard y diagnóstico
Muestra último dato, edad, calidad, disponibilidad y pendientes. Un dashboard que sigue mostrando el último valor no demuestra que el nodo siga midiendo.

### Etapa G — Prueba integrada
Ejecuta la matriz siguiente y conserva resultados reales. Ajusta el diseño ante un criterio incumplido antes de añadir extensiones.

## 6. Criterios de aceptación
Perfil de laboratorio sugerido: muestreo cada 2 s, transmisión por lotes cada 10 s, cola de al menos 200 registros y caída controlada de 5 min. Ajusta el muestreo si el sensor necesita más tiempo.

Antes de probar fija el hueco máximo tolerable de adquisición, timeout, lote máximo, capacidad real y plazo de vaciado. Una cola de 200 registros cubre 150 muestras de esa caída, pero debes medir bytes y sobrecarga.

| Prueba | Resultado requerido |
|---|---|
| Operación normal | registros válidos, unidad y fuente visibles |
| Sin Wi-Fi 5 min | muestreo continúa dentro del límite; pendientes aumentan |
| Wi-Fi activo, servicio caído | diagnóstico de servicio, sin reiniciar por rutina |
| Lectura inválida | calidad explícita; no se presenta como dato válido |
| ACK perdido | reenvío con mismo ID; una sola fila remota |
| Reinicio con pendientes | recupera registros completos persistidos |
| Cola llena | aplica política y contabiliza pérdida |
| Recuperación | vaciado acotado sin desatender nuevas lecturas |
| Fallos simultáneos | sensor y red conservan diagnósticos independientes |

Registra producidos, persistidos, únicos remotos, pendientes, rechazados y descartados. Explica cada diferencia; no presentes pérdida cero si no la mediste.

## 7. Observabilidad y seguridad
Reporta versión, origen del dato, último éxito, motivo de reset, backlog y descartes. No imprimas secretos. Protege el transporte y limita permisos por dispositivo según la [Unidad 18](../unidad18-seguridad/).

## 8. Evidencias y reproducibilidad
Entrega enlaces al repositorio, esquema de montaje, contrato y resultados. El README debe permitir configurar servicio, compilar, cargar y probar con las versiones declaradas. Añade una demostración breve de operación, caída y recuperación, identificando qué es simulado y qué fue probado físicamente.

Si utilizaste IA, declara herramienta, uso y comprobaciones realizadas. Conserva autoría y licencias de bibliotecas y código reutilizado.

## 9. Reto y autoevaluación
Añade tres nodos con identidades distintas y provoca una caída común. Evalúa jitter, deduplicación y velocidad de recuperación.

¿Dónde se confirma durabilidad? ¿Cómo sabes que el dato es reciente? ¿Qué sucede al llenarse? ¿Qué parte funciona sin servicio?

## 10. Checklist
- [ ] Hardware y versiones reproducibles.
- [ ] Sensor/simulador diferenciados.
- [ ] Contrato y ACK por ID.
- [ ] Cola finita y pérdida contabilizada.
- [ ] Muestreo independiente de red.
- [ ] Caída, reinicio y deduplicación comprobados.
- [ ] Evidencias y limitaciones explícitas.

[Anterior: energía](../unidad20-energia/) · [Siguiente: control remoto](../unidad22-proyecto-control/) · [Índice](../README.md)


---

## Continuar el curso

- **Unidad anterior:** [Unidad 20 — Consumo energético y deep sleep](../unidad20-energia/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 22 — Proyecto: control remoto](../unidad22-proyecto-control/README.md)
