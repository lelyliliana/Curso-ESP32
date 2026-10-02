# Unidad 07 — Cliente HTTP y consumo de APIs

## Qué aprenderás
Hacer solicitudes con timeout, interpretar HTTP correctamente y separar fallo Wi‑Fi, DNS/TCP/TLS, código HTTP y contenido inválido.

# 1. Capas

```text
Wi‑Fi
→ IP/DNS
→ TCP
→ TLS si HTTPS
→ HTTP
→ cuerpo
→ JSON/datos
```

“No funcionó la API” no identifica la capa.

# 2. Solicitud

La API concreta de cliente depende del core/biblioteca, pero el flujo es:

1. comprobar conectividad apropiada;
2. configurar URL/cliente;
3. timeout;
4. enviar;
5. leer código;
6. procesar cuerpo;
7. cerrar/liberar recursos.

# 3. Código HTTP

Un servidor alcanzable puede responder:
- 2xx éxito;
- 4xx solicitud/autorización;
- 5xx servidor.

No conviertas un 401 o 500 en “sin Internet”.

Usa [GUIA_RESPUESTAS.md](GUIA_RESPUESTAS.md).

# 4. Timeout

Toda operación remota debe tener una política temporal.

Un servidor que nunca responde no debe congelar indefinidamente el control local.

# 5. Content-Type

Si esperas JSON, comprueba el contrato/Content-Type cuando sea relevante.

Un 200 con una página HTML de error/proxy no es tu JSON válido.

# 6. JSON

Parsear correctamente no significa que el contenido sea válido.

Después del parseo valida:
- campos;
- tipos;
- rangos;
- versión.

# 7. Memoria

ESP32 tiene recursos limitados.

Evita:
- descargar respuestas enormes;
- duplicar strings innecesariamente;
- reservar documentos JSON gigantes “por si acaso”.

Diseña límites.

# 8. HTTPS

TLS protege transporte/autenticación del servidor cuando se valida correctamente.

No uses modos inseguros o “aceptar cualquier certificado” como solución permanente.

Debes planificar:
- CA/certificado;
- reloj cuando la validación lo necesite;
- memoria;
- rotación/actualización.

# 9. Tiempo

TLS/certificados y timestamps pueden depender de un reloj razonable.

La sincronización de tiempo se profundizará en arquitectura/robustez; no confundas “Wi‑Fi conectado” con “reloj correcto”.

# 10. Frecuencia

No consultes una API en cada loop.

Define intervalo según:
- necesidad;
- cuota;
- energía;
- carga del servicio.

# 11. Reintentos

Un fallo HTTP no implica reintento inmediato.

Usa backoff y considera semántica del método. Repetir una operación no idempotente puede duplicar efectos.

# 12. Práctica guiada

Prueba de forma controlada:
- éxito;
- host inválido;
- timeout;
- 404;
- 500;
- JSON inválido.

Clasifica cada uno.

# 13. Errores frecuentes
- todo fallo = Wi‑Fi;
- sin timeout;
- 200 = datos válidos;
- TLS inseguro permanente;
- respuesta ilimitada;
- GET cada loop;
- retry ciego de POST.

# 14. Reto
Función cliente que devuelva una categoría de resultado clara y no bloquee indefinidamente la función local del nodo.

# 15. Autoevaluación
1. ¿Wi‑Fi conectado garantiza API?
2. ¿404 es fallo de red?
3. ¿200 garantiza JSON válido?
4. ¿Por qué timeout?
5. ¿TLS sin validación es solución?
6. ¿Retry de POST siempre seguro?

# 16. Checklist
- [ ] Capas distinguidas.
- [ ] Timeout.
- [ ] HTTP interpretado.
- [ ] Datos validados.
- [ ] TLS correcto.
- [ ] Frecuencia razonable.

Continúa con servidor web.
