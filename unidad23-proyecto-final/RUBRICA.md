# Rúbrica técnica — Proyecto final ESP32/IoT

Total sugerido: **100 puntos**. Sirve para evaluación y autoevaluación.

## Criterios y evidencia
| Criterio | Máximo | Evidencia para cumplimiento completo |
|---|---:|---|
| Problema, alcance y arquitectura | 10 | usuario y objetivo verificable; flujos y responsabilidades; decisiones justificadas |
| Hardware, GPIO y alimentación | 10 | chip/placa, conexiones, niveles, fuente y estado de arranque verificados |
| Conectividad y protocolos | 15 | canal reproducible, tiempos acotados y semántica del protocolo aplicada |
| Diseño de mensajes/API | 10 | contrato versionado y validado; unidades/calidad; IDs y resultados según alcance |
| Manejo de fallos y reconexión | 15 | fallos por capa y simultáneos; timeout/backoff/jitter; recuperación observable |
| Seguridad y credenciales | 10 | amenazas, secretos protegidos de publicación, permisos y revocación; rechazo probado |
| Persistencia/funcionamiento degradado | 10 | política offline implementada y probada; recuperación, capacidad y pérdidas explicadas |
| Energía/actualización | 5 | alimentación/consumo y estrategia de actualización; OTA/sueño implementados cuando lo exige el alcance |
| Pruebas | 10 | matriz con condiciones, esperado medible, obtenido y evidencias de operación y fallo |
| Documentación y reproducibilidad | 5 | montaje, versiones, configuración sin secretos, ejecución, resultados, límites y autoría |
| **Total** | **100** | |

## Niveles de desempeño
Para cada fila utiliza un factor y multiplícalo por su máximo:

| Nivel | Factor | Regla |
|---|---:|---|
| Completo | 1,00 | criterio y evidencia completos dentro del alcance; resultados coherentes |
| Mayormente logrado | 0,75 | función/evidencia principal presente; omisiones menores sin invalidar la conclusión |
| Parcial | 0,50 | implementación o pruebas incompletas; faltan casos relevantes |
| Incipiente | 0,25 | descripción o demostración aislada sin verificar el criterio central |
| Ausente | 0,00 | sin evidencia o afirmación incompatible con resultados |

Ejemplo: manejo de fallos parcialmente logrado obtiene 15 × 0,50 = 7,50 puntos. Suma los diez criterios y redondea el total a dos decimales.

## Aplicabilidad
El alcance se acuerda antes de evaluar. Un proyecto de monitoreo no necesita actuador; evalúa contratos de datos en lugar de inventar control. Una alimentación USB no elimina la evaluación energética.

Si OTA o deep sleep no corresponden, la fila de energía/actualización conserva sus 5 puntos: exige justificación, alimentación documentada y método de actualización/recuperación. Si esas funciones son requisitos declarados, solo describirlas no equivale a implementarlas.

Si no existe cola offline por decisión justificada, evalúa la política degradada, el destino de lecturas no enviadas y su prueba. No otorgues cumplimiento completo a una promesa de persistencia que no se ejecutó.

## Calidad de evidencia
- Un diseño conceptual puede explicar decisiones; no demuestra implementación.
- Una simulación debe identificarse y no sustituye pruebas eléctricas del montaje.
- Una prueba normal no demuestra recuperación.
- Código escrito no demuestra compilación ni funcionamiento físico.
- publish, ACK de broker o GPIO escrito no prueban por sí solos almacenamiento remoto o efecto físico.
- Un criterio no probado debe quedar pendiente, no marcado como exitoso.

No ejecutes montajes eléctricamente incompatibles para obtener evidencia: corrige primero y registra el caso como pendiente. Una credencial publicada requiere revocación/rotación; borrarla del último archivo no basta para considerar resuelto el control.

## Registro de evaluación
| Criterio | Máximo | Factor | Puntos | Evidencia / observación |
|---|---:|---:|---:|---|
| Problema y arquitectura | 10 | | | |
| Hardware | 10 | | | |
| Conectividad | 15 | | | |
| Mensajes/API | 10 | | | |
| Fallos/reconexión | 15 | | | |
| Seguridad | 10 | | | |
| Persistencia/degradación | 10 | | | |
| Energía/actualización | 5 | | | |
| Pruebas | 10 | | | |
| Documentación | 5 | | | |
| **Total** | **100** | | | |

[Guía](README.md) · [Plantilla](PLANTILLA_PROYECTO.md) · [Checklist](CHECKLIST.md)
