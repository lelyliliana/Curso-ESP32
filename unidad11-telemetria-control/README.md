# Unidad 11 — Telemetría, control y operación degradada

**[Desarrollo paso a paso: Separar orden, estado y vencimiento en MQTT](DESARROLLO.md)**. Sigue el código, las tablas y el experimento antes de resolver la práctica.

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/esp32/)

## Qué aprenderás
Publicar mediciones, recibir comandos validados y mantener función local aunque Wi‑Fi o broker fallen.

# 1. Dos caminos

```text
sensor → estado local → telemetría → broker
broker → comando → validación → lógica local → actuador
```

El broker no debería saltarse las reglas locales de seguridad.

# 2. Telemetría

Define:
- variable;
- unidad;
- frecuencia;
- timestamp si aporta;
- calidad/validez;
- deviceId;
- versión del mensaje.

No publiques datos inválidos como si fueran normales.

# 3. Control

Antes de accionar:
1. topic esperado;
2. payload parseable;
3. versión;
4. comando permitido;
5. tipo/rango;
6. estado local permite acción;
7. autorización/identidad cuando corresponda.

# 4. Idempotencia

Prefiere:

```json
{"command":"setOutput","enabled":true}
```

sobre un comando `toggle` cuando los duplicados/reintentos puedan ocurrir.

# 5. Confirmación

No confundas:
- comando recibido;
- comando aceptado;
- salida ordenada;
- efecto físico confirmado.

Si no tienes sensor de realimentación, solo puedes afirmar hasta donde realmente observas.

# 6. Estado reportado

Después de una orden, publica estado actual:

```text
command → validate → apply → state
```

Esto ayuda a consumidores a no asumir que publicar un comando equivale a ejecución.

# 7. Reconexión

Usa [MAQUINA_ESTADOS.md](MAQUINA_ESTADOS.md).

El nodo puede estar:
- sin Wi‑Fi;
- sin broker;
- operativo;
- degradado;
- con sensor en error.

Los estados pueden coexistir en dimensiones distintas; diseña el modelo con claridad.

# 8. Operación degradada

Sin broker:
- sigue midiendo;
- controla localmente si es seguro;
- registra datos si existe almacenamiento;
- reintenta con backoff.

No bloquees esperando MQTT.

# 9. Datos pendientes

Si guardas telemetría offline, no publiques una avalancha sin control al reconectar.

Define:
- tamaño máximo;
- orden;
- política de descarte;
- ritmo de sincronización.

Se profundiza en Unidad 16.

# 10. Comandos antiguos

Tras reconectar, un comando retenido o encolado puede ser obsoleto.

Incluye cuando corresponda:
- timestamp;
- id;
- expiración;
- versión.

No ejecutes ciegamente cualquier comando recibido.

# 11. Fail-safe

Una pérdida de red no debe dejar un actuador en un estado peligroso indefinidamente.

La política depende del proceso:
- mantener;
- apagar;
- volver a local;
- timeout de comando.

Defínela explícitamente.

# 12. Práctica guiada

Nodo:
1. publica sensor;
2. recibe setOutput;
3. valida;
4. publica estado;
5. apaga broker;
6. sigue midiendo;
7. recupera broker.

# 13. Errores frecuentes
- comando = efecto físico confirmado;
- toggle con duplicados;
- bloquear sin broker;
- backlog infinito;
- comando antiguo ejecutado;
- seguridad dependiente de nube.

# 14. Reto
Nodo que funcione 10 min sin broker, mantenga control local y recupere telemetría con política limitada.

# 15. Autoevaluación
1. ¿Qué validar en comando?
2. ¿Set vs toggle?
3. ¿ACK significa efecto físico?
4. ¿Qué hace modo degradado?
5. ¿Backlog ilimitado?
6. ¿Qué hacer con comando antiguo?

# 16. Checklist
- [ ] Telemetría válida.
- [ ] Comandos validados.
- [ ] Estado reportado.
- [ ] Degradación.
- [ ] Recuperación.
- [ ] Fail-safe.

Continúa con JSON.


---


## Laboratorio ejecutable de referencia

Esta unidad incluye [programa completo y práctica paso a paso](LABORATORIO.md), [soluciones razonadas](SOLUCIONES.md) y [registro de evidencias](../docs/EVIDENCIAS.md).

**Objetivo de la práctica:** Controlar un LED con comandos idempotentes y vencimiento local.

**Alcance:** ON/OFF es salida software sin realimentación. No detecta comando antiguo ni implementa ACL por nodo por sí solo.

## Continuar el curso

- **Unidad anterior:** [Unidad 10 — MQTT: publish/subscribe y diseño de topics](../unidad10-mqtt/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 12 — JSON y contratos de mensajes](../unidad12-json-mensajes/README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2011%20%E2%80%94%20Telemetr%C3%ADa%20y%20control%20con%20MQTT%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad11-telemetria-control%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
