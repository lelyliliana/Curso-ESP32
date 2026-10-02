# Unidad 23 — Proyecto final IoT

## Propósito
Diseñar, implementar y evaluar un sistema ESP32 de extremo a extremo, justificando hardware, datos, conectividad, funcionamiento degradado y mantenimiento.

El resultado es un prototipo educativo con evidencias y límites explícitos. La documentación de esta unidad orienta el trabajo; no constituye una implementación completa ni certificación de un producto.

## 1. Elegir un problema acotado
Define usuario, necesidad y una condición verificable de éxito. Puedes abordar monitoreo ambiental, agricultura a baja tensión, dispositivo doméstico local, estación de telemetría, robot conectado, alertas o nodo de ciudad inteligente a escala.

Ejemplo de alcance: medir una variable, conservar hasta 30 minutos de pendientes y recuperar sin duplicados. “Crear una ciudad inteligente” no delimita una prueba ni un prototipo construible.

Puedes integrar el [nodo ambiental](../unidad21-proyecto-nodo-iot/) y el [control remoto](../unidad22-proyecto-control/), o construir otro escenario con complejidad equivalente. Un proyecto solo de monitoreo no necesita añadir un actuador sin utilidad.

## 2. Contrato de alcance
Antes de programar, completa [PLANTILLA_PROYECTO.md](PLANTILLA_PROYECTO.md) y fija:
- función local y función dependiente del servicio;
- entradas, salidas y usuario;
- frecuencia de muestreo y envío;
- tiempo de respuesta y edad máxima de datos;
- capacidad offline y política de pérdida;
- comportamiento ante reinicio y fallos simultáneos;
- controles de acceso y actualización;
- criterios de aceptación con unidades y condiciones.

Declara cada requisito como implementado, diseñado, simulado, probado físicamente o fuera de alcance. No presentes un diseño conceptual como capacidad ejecutada.

## 3. Arquitectura y decisiones
Documenta flujo de telemetría y, si existe, flujo de comandos y resultados. Explica responsabilidades del nodo, red, broker/API, almacenamiento y visualización.

| Decisión | Justificación requerida |
|---|---|
| ESP32 y placa | capacidades, GPIO y restricciones verificadas |
| Wi-Fi / BLE | alcance, disponibilidad y necesidades |
| HTTP / MQTT | interacción, contrato y recuperación |
| Edge / servicio | qué debe continuar sin Internet |
| Persistencia | qué sobrevive y qué puede perderse |
| Energía | fuente, picos, tiempos y modo de operación |
| Actualización | método, confianza y recuperación |

Una biblioteca elegida no reemplaza la explicación del contrato ni del manejo de errores.

## 4. Hardware y seguridad eléctrica
Identifica placa, sensor/actuador, tensiones, GPIO, interfaz, alimentación y etapa de potencia cuando corresponda. Comprueba niveles, pines reservados y estado de salidas durante arranque.

Trabaja con cargas educativas de baja tensión. Documenta restricciones y verifica primero con una carga sencilla. No conectes una carga de potencia directamente al GPIO.

## 5. Software y datos
Separa adquisición, control local, conectividad, transporte, almacenamiento y diagnóstico. Diseña ejecución cooperativa y mide llamadas potencialmente bloqueantes.

Los contratos deben incluir versión, identidad, unidades, calidad, tamaño y rangos. Si no hay hora válida, decláralo. Los registros reenviados conservan ID; los comandos incluyen resultado y reglas de vigencia/concurrencia según el alcance.

Mantén estados independientes por capa. Una red recuperada no elimina un fallo de sensor ni una cola llena.

## 6. Robustez y mantenimiento
Implementa el funcionamiento degradado acordado, timeout, backoff y jitter. Para datos que deben sobrevivir, diseña cola finita, recuperación, deduplicación y ACK de aplicación.

Define provisioning, permisos mínimos, secretos fuera del repositorio y logs, revocación y confianza de transporte. La actualización necesita una estrategia documentada; si implementas OTA, comprueba integridad/autenticidad, autoprueba y recuperación según tu configuración.

Energía se evalúa siempre: aunque uses USB, documenta alimentación y límites. Deep sleep y OTA se implementan cuando el requisito lo justifica. Justificar que no corresponden es válido; omitir toda decisión no lo es.

## 7. Ruta de integración
### Paso 1 — Diseño verificable
Completa problema, arquitectura y criterios. Revisa riesgos del montaje antes de conectar.

### Paso 2 — Función local
Prueba adquisición/control sin red. Documenta calidad, salidas y límites de tiempo.

### Paso 3 — Servicio y contrato
Valida un registro o comando simulado en ambos extremos. Comprueba errores y resultados.

### Paso 4 — Comunicación
Integra transporte y autorización. Mide comportamiento en operación normal y caída.

### Paso 5 — Persistencia y recuperación
Añade configuración y datos pendientes según alcance. Prueba reinicio y repetición.

### Paso 6 — Mantenimiento y energía
Comprueba las decisiones de alimentación, actualización y diagnóstico; implementa las que forman parte del prototipo.

### Paso 7 — Pruebas y revisión
Ejecuta la matriz, corrige fallos y vuelve a probar los casos afectados. Completa [CHECKLIST.md](CHECKLIST.md) y usa [RUBRICA.md](RUBRICA.md) para autoevaluarte.

## 8. Matriz mínima de aceptación
| Caso | Evidencia esperada |
|---|---|
| Normal | función y contrato cumplen límites declarados |
| Wi-Fi ausente | función local/degradada según diseño |
| Servicio ausente con Wi-Fi | diagnóstico distingue la capa |
| Sensor inválido, si existe | dato inválido explícito, sin falsa lectura |
| Mensaje mal formado/no autorizado | rechazo sin cambio indebido |
| Reinicio | configuración, pendientes y salidas según política |
| Recuperación | reintentos/lotes acotados y conciliación |
| Fallos simultáneos | diagnósticos independientes |
| Límite de almacenamiento, si existe | descarte/rechazo contabilizado |
| Duplicado o resultado perdido | comportamiento idempotente/deduplicado |
| Energía y mantenimiento | evidencia acorde a decisiones del alcance |

Para cada caso anota versión, montaje, estímulo, duración, esperado medible, obtenido y enlace a evidencia. Los casos que no aplican requieren una justificación concreta. No marques “probado” un caso descrito pero no ejecutado.

## 9. Resultados y limitaciones
Compara resultado con criterio, incluyendo peor latencia observada, cantidad de datos, pérdidas y tiempos de recuperación. Distingue una muestra pequeña de una garantía general.

Documenta calibración, estabilidad del sensor, alcance inalámbrico, capacidad offline, consumo, seguridad no implementada y limitaciones de control. Una demostración exitosa con red no prueba robustez.

## 10. Entrega reproducible
El repositorio debe contener:
- README con problema, alcance y arquitectura;
- versiones, dependencias, particiones y montaje;
- código y configuración de ejemplo sin secretos;
- instrucciones de compilación, carga, servicio y ejecución;
- contratos, estados y políticas;
- matriz de pruebas con resultados y evidencia;
- limitaciones, autoría, fuentes y licencias.

Añade enlaces a demostración y resultados. Para trabajo colaborativo registra contribuciones y usa el tamaño de equipo definido en tu contexto. Declara uso de IA y explica qué verificaste.

Un tercero debe poder reproducir al menos una prueba normal y una de fallo con el montaje y versiones indicados. No publiques credenciales para facilitar esa reproducción.

## 11. Defensa técnica
Responde:
1. ¿Qué problema resuelve y cómo mediste el éxito?
2. ¿Por qué esta placa y este protocolo?
3. ¿Qué funciona sin red y qué deja de funcionar?
4. ¿Qué puede perderse, duplicarse o llegar tarde?
5. ¿Qué confirma el sistema y qué no puede observar?
6. ¿Cómo recupera configuración y estado tras reinicio?
7. ¿Cómo se revocan accesos y se actualiza?
8. ¿Qué límites físicos, energéticos y técnicos permanecen?

## 12. Cierre del recorrido
IoT exige diseñar la relación entre mundo físico, software y servicios, incluyendo sus fallos. El proyecto demuestra esa relación mediante una implementación acotada, resultados reproducibles y límites reconocidos.

[Anterior: control remoto](../unidad22-proyecto-control/) · [Índice del curso](../README.md)
