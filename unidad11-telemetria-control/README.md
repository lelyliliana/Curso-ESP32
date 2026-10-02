# Unidad 11 — Telemetría, control y operación degradada

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
