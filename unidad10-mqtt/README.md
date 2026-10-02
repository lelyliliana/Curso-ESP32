# Unidad 10 — MQTT: publish/subscribe y diseño de topics

## Qué aprenderás
Comprender broker, sesiones, QoS, retained messages y diseñar topics que separen telemetría, estado y comandos.

# 1. Modelo

```text
publisher → broker → subscriber
```

Los dispositivos no necesitan conocerse directamente; se coordinan mediante topics y broker.

# 2. Topic

Ejemplo:

```text
casa/sala/nodo01/telemetry
casa/sala/nodo01/state
casa/sala/nodo01/command
```

Usa [DISENO_TOPICS.md](DISENO_TOPICS.md).

# 3. Telemetría vs estado vs comando

**Telemetría:** mediciones periódicas/eventos.  
**Estado:** situación actual del nodo.  
**Comando:** intención dirigida al dispositivo.

Separarlos reduce ambigüedad y permisos peligrosamente amplios.

# 4. QoS

Conceptualmente:
- QoS 0: entrega como máximo una vez;
- QoS 1: al menos una vez;
- QoS 2: exactamente una vez a nivel del protocolo MQTT bajo sus reglas, con mayor costo.

QoS no garantiza que tu **acción física** ocurra exactamente una vez.

Con QoS 1 pueden existir duplicados: diseña comandos idempotentes cuando importe.

# 5. Retained

Un mensaje retained hace que nuevos suscriptores reciban el último valor retenido de ese topic.

Útil para cierto estado/configuración.

Peligroso si retienes un comando momentáneo como “ABRIR” y un dispositivo recién conectado lo ejecuta.

Decide por topic.

# 6. Last Will

LWT permite al broker publicar un mensaje si el cliente desaparece de forma no limpia según configuración.

Puede ayudar a indicar disponibilidad:

```text
.../availability = offline
```

y al conectar publicar online.

No es un detector perfecto instantáneo de salud física.

# 7. Sesión

Según versión/configuración MQTT, sesiones persistentes pueden conservar suscripciones/mensajes bajo reglas específicas.

Conoce la biblioteca/broker; no asumas comportamiento al reconectar.

# 8. Wildcards

`+` y `#` permiten suscripciones amplias.

Son útiles para dashboards, pero permisos ACL demasiado amplios pueden exponer/controlar más dispositivos de lo previsto.

# 9. Broker

Puede ser local o remoto.

No publiques un broker sin autenticación/TLS a Internet para “hacer la práctica”.

# 10. Frecuencia

No publiques cada loop.

Define:
- periodo;
- cambio mínimo;
- eventos;
- energía/ancho de banda.

# 11. Payload

MQTT transporta bytes.

JSON es una opción, no parte obligatoria de MQTT.

El contrato de mensajes se trabaja en Unidad 12.

# 12. Práctica guiada

Diseña topics para tres nodos:
- telemetry;
- state;
- command;
- availability.

Decide QoS/retained y justifica cada uno.

# 13. Errores frecuentes
- topic improvisado;
- telemetría/comando mezclados;
- QoS 2 = actuador exactamente una vez;
- retained en comandos momentáneos;
- broker público sin seguridad;
- publicar cada loop.

# 14. Reto
Diseña namespace escalable para 10 nodos y una política básica de quién publica/se suscribe.

# 15. Autoevaluación
1. ¿Qué hace broker?
2. ¿QoS 1 puede duplicar?
3. ¿QoS 2 garantiza acción física única?
4. ¿Retained para qué?
5. ¿Por qué LWT?
6. ¿JSON es obligatorio?

# 16. Checklist
- [ ] Topics jerárquicos.
- [ ] Tipos separados.
- [ ] QoS justificado.
- [ ] Retained consciente.
- [ ] Disponibilidad.
- [ ] Broker no expuesto.

Continúa con telemetría y control.
