# Unidad 12 — JSON y contratos de mensajes

**[Desarrollo paso a paso: Validar el significado de un documento JSON](DESARROLLO.md)**. Sigue el código, las tablas y el experimento antes de resolver la práctica.

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/esp32/)

## Qué aprenderás
Diseñar payloads versionados, limitados y validables, distinguiendo ausencia, null, dato inválido y error.

# 1. JSON es formato, no contrato

```json
{"x":"hola"}
```

es JSON válido, pero puede ser inválido para tu sistema.

El contrato define significado, tipos, rangos y obligatoriedad.

# 2. Contrato

Usa [CONTRATO_MENSAJES.md](CONTRATO_MENSAJES.md).

Por campo documenta:
- nombre;
- tipo;
- unidad;
- obligatorio;
- rango;
- significado;
- ejemplo.

# 3. Unidades

```json
{"temperatureC":25.4}
```

es menos ambiguo que un nombre sin unidad cuando no existe otro contrato claro.

# 4. Dato inválido

Puedes usar, según contrato:
- value null + valid false;
- campo omitido bajo reglas;
- objeto de error/calidad.

No uses 0 o -999 como sentinel por costumbre: pueden confundirse con datos.

# 5. Timestamp

Define:
- origen del tiempo;
- formato;
- zona;
- comportamiento sin sincronización.

Uptime no es hora de calendario.

No inventes timestamp real si el dispositivo no conoce la hora.

# 6. Device ID

Debe ser estable y evitar revelar información innecesaria.

No uses una MAC pública por costumbre si un identificador configurado/aleatorio satisface el requisito.

# 7. Versionado

```json
{"version":1}
```

Una versión desconocida debe rechazarse o manejarse mediante compatibilidad explícita.

No intentes adivinar el esquema.

# 8. Memoria

Define tamaño máximo de payload y capacidad de parseo.

Una entrada remota no debe provocar reservas ilimitadas en un microcontrolador.

# 9. Tipos

JSON distingue number, string, boolean, null, array y object.

Si el contrato exige boolean, no aceptes automáticamente el string "true" solo porque podrías convertirlo.

# 10. Rangos

Después de validar tipo, valida semántica.

Por ejemplo, un PWM o una temperatura deben caer dentro del rango definido por el contrato/aplicación.

Parsear correctamente no demuestra que el valor sea aceptable.

# 11. Evolución

Añadir un campo opcional suele ser menos disruptivo que renombrar/eliminar uno obligatorio.

Piensa en consumidores antiguos.

# 12. Seguridad

No incluyas passwords, tokens o claves privadas en telemetría.

Trata mensajes entrantes como no confiables.

# 13. Práctica guiada

Prueba:
- JSON correcto;
- sintaxis inválida;
- campo faltante;
- tipo incorrecto;
- rango;
- versión desconocida;
- payload demasiado grande.

# 14. Errores frecuentes
- JSON válido = comando válido;
- sentinel -999;
- timestamp sin reloj;
- MAC como ID universal;
- coerciones automáticas;
- buffer ilimitado;
- romper esquema sin versión.

# 15. Reto
Diseña telemetría y comando v1 con tabla de campos y diez casos de validación.

# 16. Autoevaluación
1. ¿JSON define semántica?
2. ¿Cómo representar inválido?
3. ¿Uptime es hora?
4. ¿Por qué versionar?
5. ¿Parseo = validación?
6. ¿Qué limitar por memoria?

# 17. Checklist
- [ ] Contrato.
- [ ] Unidades.
- [ ] Validez explícita.
- [ ] Versión.
- [ ] Tipos y rangos.
- [ ] Tamaño limitado.

Continúa con arquitectura IoT.


---


## Laboratorio ejecutable de referencia

Esta unidad incluye [programa completo y práctica paso a paso](LABORATORIO.md), [soluciones razonadas](SOLUCIONES.md) y [registro de evidencias](../docs/EVIDENCIAS.md).

**Objetivo de la práctica:** Distinguir datos numéricos de textos y rechazar mensajes incompletos.

**Alcance:** Contrato pequeño autónomo; el proyecto ambiental tiene además humedad y uptime y valida según su propio esquema.

## Continuar el curso

- **Unidad anterior:** [Unidad 11 — Telemetría, control y operación degradada](../unidad11-telemetria-control/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 13 — Arquitectura de un sistema IoT](../unidad13-arquitectura-iot/README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2012%20%E2%80%94%20Dise%C3%B1o%20de%20mensajes%20y%20JSON%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad12-json-mensajes%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
