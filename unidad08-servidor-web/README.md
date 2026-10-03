# Unidad 08 — Servidor web local en ESP32

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/esp32/)

## Qué aprenderás
Exponer una interfaz de diagnóstico/control en LAN sin confundir un servidor educativo local con un servicio seguro para Internet.

# 1. Arquitectura

Consulta [ARQUITECTURA.md](ARQUITECTURA.md).

```text
navegador → LAN → ESP32
```

El dispositivo atiende solicitudes mientras sigue midiendo/controlando.

# 2. No bloquees

Un servidor implementado con bucles de espera largos puede impedir:
- sensores;
- MQTT;
- watchdog;
- control.

Usa APIs/patrones apropiados del core/biblioteca y mantén handlers breves.

# 3. Separa interfaz y datos

Rutas conceptuales:

```text
/            HTML
/api/status  estado
/api/sensor  dato
/api/output  control
```

La página puede consultar endpoints sin incrustar toda la lógica de control en HTML.

# 4. Estado del sensor

No respondas:

```json
{"temperature":0}
```

si el sensor falló y 0 es un valor válido.

Expresa validez/error.

# 5. Control

Una solicitud de control debe validar:
- método;
- autenticación si existe;
- formato;
- rango;
- estado permitido.

Nunca conviertas directamente un parámetro arbitrario en PWM/pin sin validar.

# 6. Concurrencia

Pueden llegar solicitudes mientras otras tareas usan el mismo estado/hardware.

Diseña acceso coherente; no hagas operaciones largas dentro del handler.

# 7. Tamaño

ESP32 tiene RAM limitada.

Evita generar páginas gigantes con concatenaciones repetidas y respuestas sin límites.

Archivos estáticos/plantillas simples pueden ser mejores según proyecto.

# 8. Seguridad de red

Un ESP32 en LAN **no debe exponerse a Internet mediante port forwarding** como atajo.

Un servicio público requiere arquitectura, autenticación, TLS, actualización y hardening apropiados.

# 9. CORS

Si una web de otro origen llama la API, puede aparecer CORS.

CORS es una política del navegador, no autenticación del dispositivo.

No abras `*` sin entender quién debería consumir el endpoint.

# 10. Estado seguro

Si la red desaparece, la lógica local sigue funcionando.

La interfaz web es una interfaz, no el cerebro obligatorio del dispositivo.

# 11. Práctica guiada

Construye:
- /;
- /api/status;
- /api/sensor.

Después apaga el navegador/red y comprueba que el nodo sigue midiendo.

# 12. Errores frecuentes
- handler bloqueante;
- control sin validar;
- error de sensor = cero;
- HTML gigante en RAM;
- port forwarding;
- CORS = seguridad;
- depender del navegador para control local esencial.

# 13. Reto
Panel local que muestre estado, lectura válida/inválida y permita una acción segura.

# 14. Autoevaluación
1. ¿Servidor puede bloquear loop?
2. ¿UI y datos separados?
3. ¿CORS autentica?
4. ¿Port forwarding recomendado?
5. ¿Qué validar en control?
6. ¿Nodo funciona sin navegador?

# 15. Checklist
- [ ] Handlers breves.
- [ ] Endpoints claros.
- [ ] Datos válidos explícitos.
- [ ] Control validado.
- [ ] LAN no expuesta públicamente.

Continúa con API REST.


---

## Continuar el curso

- **Unidad anterior:** [Unidad 07 — Cliente HTTP y consumo de APIs](../unidad07-cliente-http/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 09 — API HTTP/REST básica en el dispositivo](../unidad09-api-rest/README.md)
