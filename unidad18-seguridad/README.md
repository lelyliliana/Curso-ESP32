# Unidad 18 — Credenciales y seguridad básica

## Qué aprenderás
Construir un modelo de amenazas y separar confidencialidad, autenticación, autorización, integridad y seguridad física del control.

## 1. Empieza por el sistema
Enumera activos: credenciales, lecturas, configuración, firmware y actuadores. Identifica entradas: Wi-Fi, BLE, HTTP, MQTT, OTA, serial y acceso físico.

Para cada entrada pregunta quién puede acceder, qué podría modificar y qué impacto tendría. Un nodo de temperatura y uno que acciona una cerradura requieren controles diferentes.

## 2. Modelo de amenazas
| Activo | Amenaza | Impacto | Mitigación | Prueba |
|---|---|---|---|---|
| Credencial MQTT | copia desde Git o logs | suplantación | secretos separados y rotación | buscar exposición y revocar |
| Actuador | comando no autorizado | acción peligrosa | ACL, validación y límites locales | comando ajeno rechazado |
| Firmware | actualización falsificada | control del nodo | autenticidad verificable | imagen no autorizada rechazada |
| Telemetría | modificación/repetición | decisión incorrecta | canal autenticado, ID y calidad temporal | duplicado reconocido |

Completa el modelo para tu montaje, incluyendo acceso físico y cambios de propietario.

## 3. Secretos y provisioning
Un archivo ignorado por Git reduce publicación accidental, pero no cifra el firmware ni la flash. Usa plantillas sin credenciales reales, revisa archivos rastreados y evita secretos en capturas.

.gitignore no elimina un archivo que ya está rastreado. Si se publica una credencial, revócala o rótala; borrarla del último commit no la elimina de copias e historial.

Entrega credenciales por un mecanismo de provisioning autorizado. Asigna credenciales por dispositivo y privilegios mínimos. Define renovación, revocación y recuperación cuando la credencial deja de funcionar.

El identificador del nodo no es un secreto ni prueba identidad. No copies una credencial permanente idéntica a toda la flota.

## 4. TLS y confianza
TLS debe validar cadena de confianza y nombre del servidor; la comprobación temporal de certificados requiere una hora fiable según la biblioteca. Define cómo arranca un nodo sin reloj sincronizado y cómo mantiene confianza al renovar certificados.

El cifrado sin validación de identidad no protege de un servidor impostor. No uses setInsecure ni certificados aceptados indiscriminadamente como solución de despliegue. Si utilizas certificados cliente, considera su almacenamiento, caducidad y revocación.

## 5. Autenticación y autorización
Autenticación responde quién es el cliente; autorización determina qué puede hacer. En MQTT, una ACL debe impedir que un nodo publique comandos o suplante topics de otro. En HTTP, valida permisos para cada operación. CORS es una política del navegador, no autenticación.

Una red local y la cercanía BLE no sustituyen estos controles. Cierra servicios que no utilizas y evita exponer el servidor local mediante port forwarding.

## 6. Validar antes de actuar
Valida versión, campos, tipo, rango, tamaño, ID y expiración. Aplica límites físicos locales aunque el emisor esté autenticado.

Un comando firmado o recibido por TLS puede ser antiguo. Diseña protección frente a repetición: ID, secuencia o expiración con política cuando no existe hora confiable. Un comando rechazado debe producir diagnóstico sin modificar la salida.

Rate limiting, colas acotadas y tamaño máximo también protegen disponibilidad. No permitas que peticiones válidas consuman toda la memoria o tiempo local.

## 7. Datos y logs
Recopila solo datos necesarios. Define retención, destinatarios y acceso. No registres tokens, contraseñas ni claves privadas. Un log de diagnóstico puede incluir ID, tipo de fallo y versión sin exponer el secreto.

## 8. Firmware y acceso físico
TLS protege el transporte; la firma de firmware protege autenticidad de la imagen. Secure Boot verifica software de arranque según la plataforma; cifrado de flash protege información almacenada. Son controles diferentes.

Su soporte y configuración dependen del chip y SDK. La programación de eFuses puede ser irreversible: esta unidad trabaja el diseño y la verificación conceptual, no propone activarlas como práctica introductoria. Consulta la documentación exacta antes de una configuración de producción.

## 9. Práctica guiada
Trabaja exclusivamente en tus dispositivos y servicios de laboratorio.
1. Inventaría activos, interfaces y amenazas.
2. Revisa archivos y logs para detectar secretos; utiliza credenciales de laboratorio.
3. Configura permisos para que nodo A no pueda publicar como nodo B.
4. Prueba un cliente sin autorización: no debe cambiar configuración.
5. Prueba comando fuera de rango, repetido y caducado; verifica estado seguro.
6. Rechaza un servidor con identidad no válida sin desactivar TLS.
7. Revoca una credencial de prueba y verifica modo degradado y reprovisioning.
8. Completa [CHECKLIST.md](CHECKLIST.md) con evidencia, no solo marcas.

## 10. Errores frecuentes
- Confundir secreto fuera de Git con secreto protegido en el dispositivo.
- Autenticación sin ACL.
- TLS sin validación.
- UUID, dirección MAC o device_id como contraseña.
- Un comando autorizado sin límites físicos.
- Actualización sin autenticidad ni recuperación.

## 11. Reto y autoevaluación
Diseña provisioning y rotación para 30 nodos, incluyendo uno perdido y un cambio de propietario.

¿Qué protege TLS? ¿Qué protege una firma? ¿Cómo revocas un solo nodo? ¿Qué pasa si no hay hora fiable? ¿Por qué una ACL no sustituye la validación de rango?

## 12. Checklist
- [ ] Modelo de amenazas.
- [ ] Secretos separados y logs revisados.
- [ ] Identidad y permisos por nodo.
- [ ] Canal y servidor validados.
- [ ] Comandos limitados y protegidos de repetición.
- [ ] Revocación y recuperación probadas.
- [ ] Actualización autenticada diseñada.

## Referencia oficial
[Seguridad de ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/security/security.html).

[Anterior: fallos](../unidad17-fallos-reconexion/) · [Siguiente: OTA](../unidad19-ota/) · [Índice](../README.md)
