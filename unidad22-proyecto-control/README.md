# Unidad 22 — Proyecto: control remoto

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/esp32/)

## Qué construirás
Un sistema que recibe solicitudes de cambio, valida autorización y vigencia, aplica una salida segura y reporta qué ocurrió.

La práctica inicial utiliza un LED externo con resistencia apropiada. Para motores u otras cargas de baja tensión utiliza una etapa de potencia compatible y alimentación adecuada; un GPIO no alimenta directamente esas cargas. No controles red eléctrica en este proyecto educativo.

Esta unidad guía la implementación: no incluye firmware de control ni servicio remoto completos ya probados.

## 1. Alcance y canal
Elige MQTT, HTTP o BLE según tu escenario. Implementa un canal completo antes de integrar otros. Conserva operación local y establece quién tiene autoridad para cambiar la salida.

El proyecto debe demostrar:
- estado seguro de arranque, desconexión y reinicio;
- identidad/autorización y contrato limitado;
- comandos idempotentes de estado deseado;
- tratamiento de repetición, antigüedad y concurrencia;
- confirmación de aplicación y límites de lo observado;
- control local independiente de Internet;
- registro de decisiones y pruebas de fallos.

Completa [PLANTILLA.md](PLANTILLA.md).

## 2. Solicitud, aplicación y efecto físico
| Estado del proceso | Qué demuestra |
|---|---|
| Recibido | llegó una solicitud |
| Aceptado | pasó autorización y validación |
| Aplicado por software | el programa configuró la salida |
| Verificado físicamente | un sensor/realimentación comprobó el efecto |
| Rechazado / fallido | no se completó según el contrato |

Configurar GPIO no demuestra que un motor giró ni que una válvula abrió. Si no hay realimentación física, el estado debe indicar esa limitación.

## 3. Contrato idempotente
Prefiere “establecer salida encendida” a “alternar salida”. Repetir toggle cambia de nuevo el estado; repetir set true mantiene el mismo objetivo.

Ejemplo ilustrativo, para un sistema cuyo reloj y política de vigencia estén definidos:

```json
{
  "schema_version": 1,
  "device_id": "nodo-lab-01",
  "command_id": "cmd-0042",
  "operation": "set_output",
  "desired_state": true,
  "issued_at": "2026-10-02T20:00:00Z",
  "expires_at": "2026-10-02T20:00:15Z"
}
```

Estas fechas son ejemplos, no comandos ejecutables actuales. Define campos, tipo, tamaño máximo, orden y política ante un reloj desconocido. Si no puedes verificar expiración, rechaza comandos que la requieren o usa un protocolo de sesión/secuencia diseñado; no ignores la vigencia silenciosamente.

Para HTTP, un PUT de estado deseado puede expresar idempotencia. En MQTT separa comando, estado y resultado; en BLE separa escritura aceptada de resultado aplicado. Conserva la misma identidad en reintentos.

## 4. Validaciones y duplicados
La secuencia es autorizar emisor/destino, comprobar formato y límites, verificar vigencia/orden, detectar repetición y aplicar según modo local/remoto.

Un command_id ya procesado debe devolver el resultado conocido sin repetir una acción. Si llega el mismo ID con contenido distinto, recházalo como conflicto.

Define tamaño y duración del registro de deduplicación. Si debe sobrevivir a reinicio, necesita persistencia y recuperación. Para una acción física momentánea, un reinicio entre acción y guardado deja una ambigüedad que QoS 2 no elimina; requiere realimentación o reconciliación específica.

## 5. Estado deseado y estado reportado
El estado reportado debe incluir comando, resultado, salida aplicada y si existe verificación física. Ejemplo:

```json
{
  "schema_version": 1,
  "device_id": "nodo-lab-01",
  "command_id": "cmd-0042",
  "result": "applied",
  "software_output": true,
  "physical_verified": false,
  "mode": "remote"
}
```

Si una protección local impide activar, informa rechazo con motivo. No muestres éxito al usuario solo porque el servicio aceptó su petición.

## 6. Orden, retained y reconexión
Comandos concurrentes o reordenados necesitan una política: autoridad del emisor, secuencia de sesión o revisión esperada. Un ID único detecta duplicados, pero no ordena por sí mismo.

No retengas comandos momentáneos: podrían ejecutarse al reconectar. Un estado deseado retained solo es apropiado con reglas explícitas de autoridad, versión, vigencia y reconciliación. La práctica comienza con comandos no retained.

Al reconectar, reporta estado actual y concilia según política; no reproduzcas ciegamente una cola de órdenes antiguas.

## 7. Modo local y seguridad
Define precedencia entre mando local y remoto. Para el LED de laboratorio puedes fijar: arranque apagado, modo local con prioridad y salida apagada al vencer un plazo sin supervisión remota. Ese comportamiento es una decisión del montaje, no una regla universal para todo actuador.

Un mensaje inválido no debe cambiar la salida válida existente salvo que una política de protección independiente lo exija. Distingue rechazo del comando de activación de una protección.

Las protecciones locales siguen operando durante pérdida de red y actualización. Asegura el estado también durante reset/sueño mediante diseño eléctrico, no solo setup.

## 8. Construcción por etapas
1. Prueba salida y mando local sin red; verifica nivel activo y estado de arranque.
2. Implementa el contrato con solicitudes simuladas y rechazo de formatos inválidos.
3. Integra el canal y autorización.
4. Añade resultados por command_id y lectura del estado actual.
5. Implementa repetición, orden y vigencia.
6. Integra prioridad local y pérdida de supervisión.
7. Añade diagnóstico, reinicio y recuperación.
8. Ejecuta pruebas con LED antes de otra carga compatible.

Mide el tiempo entre solicitud aceptada y salida aplicada. La latencia de servicio/broker no debe detener el control local.

## 9. Pruebas de aceptación
Define antes un límite de respuesta local, timeout de supervisión y ventana de comandos.

| Caso | Resultado requerido |
|---|---|
| Comando autorizado válido | salida correcta y resultado vinculado al ID |
| Tipo/rango/tamaño inválido | rechazo; sin cambio indebido |
| Emisor no autorizado | rechazo; sin acción |
| Mismo ID y contenido | resultado conocido; sin segunda acción |
| Mismo ID, distinto contenido | conflicto observable |
| Comando vencido o reordenado | aplica la política documentada |
| Resultado perdido | reintento seguro o consulta del estado |
| Cambio local + comando remoto | prioridad definida y visible |
| Red/servicio caído | operación local y política de supervisión |
| Reinicio después de aplicar | arranque seguro y reconciliación explícita |
| Reconexión | sin reproducir órdenes antiguas |

Observa físicamente el LED y contrasta con software. No atribuyas verificación física automática al sistema si solo la realizó una persona.

## 10. Evidencias
Entrega contrato, máquina de estados, esquema, versiones y registro de cada prueba. Muestra una solicitud válida, rechazo, repetición, control local y recuperación. Declara IA y fuentes reutilizadas.

## 11. Reto y autoevaluación
Añade un segundo cliente: resuelve cambios simultáneos sin suponer que el último mensaje recibido es siempre la intención correcta.

¿Recibido equivale a aplicado? ¿Un ID ordena comandos? ¿Qué limita retained? ¿Qué demuestra un GPIO escrito? ¿Qué ocurre tras un reinicio ambiguo?

## 12. Checklist
- [ ] Carga de baja tensión y montaje documentado.
- [ ] Estado seguro también durante arranque.
- [ ] Autorización y validación.
- [ ] Idempotencia y conflictos.
- [ ] Orden/vigencia y reconexión.
- [ ] Estado reportado sin falsas confirmaciones físicas.
- [ ] Prioridad local y pruebas.

[Anterior: nodo ambiental](../unidad21-proyecto-nodo-iot/) · [Siguiente: proyecto final](../unidad23-proyecto-final/) · [Índice](../README.md)


---

## Continuar el curso

- **Unidad anterior:** [Unidad 21 — Proyecto: nodo IoT ambiental](../unidad21-proyecto-nodo-iot/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 23 — Proyecto final IoT](../unidad23-proyecto-final/README.md)
