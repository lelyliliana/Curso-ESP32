# Unidad 05 — Interrupciones, temporización y tareas

**[Desarrollo paso a paso: Distinguir interrupción, tarea y dato compartido](DESARROLLO.md)**. Sigue el código, las tablas y el experimento antes de resolver la práctica.

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/esp32/)

## Qué aprenderás
Elegir entre loop cooperativo, interrupciones y tareas, evitando condiciones de carrera y trabajo inseguro dentro de una ISR.

# 1. Empieza simple

Antes de crear una tarea pregunta:

> ¿millis() + máquina de estados resuelve el problema?

Si sí, probablemente es el diseño más fácil de depurar.

Concurrencia es una herramienta, no un indicador de calidad.

# 2. Interrupción

Una ISR responde a un evento de hardware con baja latencia.

Debe hacer lo mínimo necesario:
- marcar bandera;
- incrementar contador simple de forma segura;
- capturar información mínima.

El trabajo pesado se procesa fuera.

# 3. Evita en ISR

Según plataforma/API:
- delay;
- Serial complejo;
- red;
- asignación dinámica;
- operaciones largas;
- APIs no seguras en contexto ISR.

Consulta documentación del core para atributos/restricciones específicos.

# 4. Datos compartidos

Una variable usada por ISR y código normal requiere considerar:
- visibilidad;
- atomicidad;
- exclusión crítica.

`volatile` puede ser necesario para ciertas variables, pero **no convierte una operación compuesta en atómica ni elimina carreras**.

# 5. Debounce

Un pulsador puede generar múltiples interrupciones por rebote.

No intentes resolver lógica extensa dentro de la ISR.

Captura evento/tiempo y valida fuera.

# 6. FreeRTOS

Arduino‑ESP32 se apoya en FreeRTOS en muchas configuraciones.

Conceptos:
- task;
- scheduler;
- priority;
- queue;
- semaphore/mutex;
- notification.

No necesitas usar directamente todos para una aplicación normal.

# 7. Tareas

Una tarea tiene stack propio y consume memoria.

Crear muchas tareas aumenta:
- RAM;
- coordinación;
- riesgo de carrera;
- complejidad.

# 8. Prioridades

Una tarea de prioridad alta que nunca cede/bloquea apropiadamente puede impedir progreso de otras y afectar sistema.

No subas prioridad para “hacerla más rápida”.

# 9. Datos entre tareas

Evita compartir variables mutables sin sincronización.

Prefiere mecanismos como:
- queues;
- task notifications;
- mutex para recursos compartidos,
según el problema.

# 10. Mutex no es para ISR arbitrariamente

Las primitivas permitidas desde ISR suelen tener variantes/reglas específicas.

No llames una API de tareas desde ISR sin comprobar que está diseñada para ello.

# 11. Core affinity

Algunas variantes/configuraciones permiten fijar tareas a núcleos.

No fijes tareas por moda ni asumas que todo ESP32 es dual-core.

Primero identifica chip y necesidad.

# 12. Watchdog

Un sistema/tarea que no cede durante demasiado tiempo puede activar watchdog según configuración.

El watchdog es una defensa contra bloqueo, no algo que debas desactivar para ocultar un diseño defectuoso.

# 13. Comparación

Realiza [GUIA.md](GUIA.md):

Diseña el mismo sistema:
- loop cooperativo;
- tareas.

Compara complejidad y requisitos.

# 14. Práctica guiada

Interrupción de pulsador:
1. ISR marca evento;
2. loop procesa;
3. debounce fuera;
4. Serial fuera.

Después crea una tarea solo si puedes justificarla.

# 15. Errores frecuentes
- tarea para cada función;
- Serial/fetch en ISR;
- volatile = thread-safe;
- prioridad alta como solución;
- asumir dual-core;
- desactivar watchdog;
- compartir datos sin mecanismo.

# 16. Reto
Compara un nodo sensor con loop cooperativo y con dos tareas. Elige uno y defiende por qué es suficiente.

# 17. Autoevaluación
1. ¿Cuándo crear tarea?
2. ¿Qué debe hacer ISR?
3. ¿volatile elimina carreras?
4. ¿Qué cuesta una task?
5. ¿Prioridad alta siempre mejor?
6. ¿Todo ESP32 dual-core?
7. ¿Para qué watchdog?

# 18. Checklist
- [ ] Diseño simple primero.
- [ ] ISR breve.
- [ ] Datos sincronizados.
- [ ] Tareas justificadas.
- [ ] Watchdog respetado.

Continúa con Wi‑Fi.


---


## Laboratorio ejecutable de referencia

Esta unidad incluye [programa completo y práctica paso a paso](LABORATORIO.md), [soluciones razonadas](SOLUCIONES.md) y [registro de evidencias](../docs/EVIDENCIAS.md).

**Objetivo de la práctica:** Mantener la interrupción corta y observar rebote.

**Alcance:** No promete un contador de pulsaciones sin rebotes; FreeRTOS multitararea es ampliación de GUIA.md.

## Continuar el curso

- **Unidad anterior:** [Unidad 04 — Sensores, I²C y SPI en ESP32](../unidad04-sensores-buses/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 06 — Wi‑Fi, estados y reconexión](../unidad06-wifi/README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2005%20%E2%80%94%20Interrupciones%2C%20temporizaci%C3%B3n%20y%20tareas%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad05-interrupciones-tareas%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
