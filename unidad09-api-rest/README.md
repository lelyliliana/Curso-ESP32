# Unidad 09 — API HTTP/REST básica en el dispositivo

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/esp32/)

## Qué aprenderás
Diseñar un contrato estable para lectura/control, usar métodos/códigos coherentes y validar antes de actuar sobre hardware.

# 1. API antes que código

Define primero [CONTRATO_API.md](CONTRATO_API.md).

El consumidor debe saber:
- rutas;
- métodos;
- cuerpo;
- respuesta;
- errores;
- unidades;
- versión si aplica.

# 2. Recursos

Ejemplo:

```text
GET  /api/status
GET  /api/sensor
POST /api/output
```

No conviertas cada función C++ en un endpoint.

Diseña la API desde el dominio.

# 3. GET

Debe usarse para obtener representación sin producir un cambio físico significativo como efecto esperado.

No uses:
```text
GET /motor/on
```

por comodidad si estás modelando una operación de cambio.

# 4. Escritura

POST/PUT/PATCH pueden expresar cambios según contrato.

La elección exacta depende del modelo; lo importante es consistencia y semántica documentada.

# 5. Status HTTP

Ejemplos conceptuales:
- 200 éxito;
- 201 creado si realmente creas recurso;
- 400 solicitud mal formada;
- 404 recurso/ruta;
- 409 conflicto de estado;
- 422 datos semánticamente inválidos cuando tu stack/contrato lo adopte;
- 500 fallo interno inesperado.

No uses 200 para todo con `{"error":true}`.

# 6. Error del sensor

Si el sensor no responde, decide si:
- endpoint responde estado válido con `valid:false`;
- o representa indisponibilidad mediante otro código.

Documenta el contrato y mantenlo consistente.

# 7. Validación

Para control:
- Content-Type;
- JSON válido;
- campos;
- tipos;
- rango;
- comando permitido;
- estado actual;
- autorización si existe.

# 8. Idempotencia

Si un cliente reintenta por timeout, entiende si repetir la solicitud:
- deja el mismo estado;
- duplica una acción.

`setOutput=true` tiene semántica distinta de `toggleOutput`.

Diseñar comandos idempotentes puede simplificar recuperación.

# 9. Límites

Impón tamaño máximo de cuerpo.

Un microcontrolador no debe aceptar JSON ilimitado.

# 10. Versionado

Si otros clientes dependerán de la API, planifica evolución.

No rompas silenciosamente campos/unidades.

# 11. Seguridad

Una API local tampoco debe confiar en cualquier cliente.

La seguridad completa se profundiza en Unidad 18.

# 12. Práctica guiada

Implementa contrato de:
- estado;
- sensor;
- salida.

Prueba JSON mal formado, campo faltante, tipo incorrecto y rango inválido.

# 13. Errores frecuentes
- endpoint por función;
- GET para cambiar hardware;
- 200 para todos los errores;
- toggle difícil de reintentar;
- cuerpo sin límite;
- actuar antes de validar;
- cambiar contrato sin versión.

# 14. Reto
API con errores consistentes y operación de control segura ante reintento.

# 15. Autoevaluación
1. ¿API se diseña antes?
2. ¿GET debe cambiar actuador?
3. ¿Por qué códigos HTTP?
4. ¿Qué es idempotencia?
5. ¿Toggle es fácil de reintentar?
6. ¿Por qué límite de body?

# 16. Checklist
- [ ] Contrato.
- [ ] Métodos coherentes.
- [ ] Códigos.
- [ ] Validación.
- [ ] Límites.
- [ ] Reintentos considerados.

Continúa con MQTT.


---

## Continuar el curso

- **Unidad anterior:** [Unidad 08 — Servidor web local en ESP32](../unidad08-servidor-web/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 10 — MQTT: publish/subscribe y diseño de topics](../unidad10-mqtt/README.md)
