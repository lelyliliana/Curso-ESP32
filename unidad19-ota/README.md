# Unidad 19 — Actualizaciones OTA

## Qué aprenderás
Diseñar una actualización de firmware verificable y recuperable, incluyendo primer arranque y compatibilidad de datos.

## 1. OTA es un proceso completo
Descargar un archivo no demuestra que sea firmware autorizado ni que funcione. Una actualización termina cuando la aplicación nueva se valida y su estado queda confirmado.

Distingue OTA de laboratorio en red local y despliegue remoto. Un ejemplo ArduinoOTA no convierte automáticamente un producto en un sistema de actualización segura de flota.

## 2. Placa, particiones y versiones
Registra chip, flash, core/SDK, bootloader y esquema de particiones. Una distribución habitual utiliza dos particiones de aplicación y datos OTA para seleccionar arranque; el tamaño de la imagen debe caber en la partición destino.

No asumas soporte de OTA en cualquier esquema ni rollback activado por defecto. Consulta la configuración real. No sobrescribas la aplicación activa mediante una estrategia improvisada.

## 3. Confianza e integridad
| Control | Qué comprueba |
|---|---|
| TLS validado | identidad del servidor y canal |
| Hash esperado desde origen confiable | integridad del archivo recibido |
| Firma verificada con clave de confianza | autenticidad de la imagen |
| Validación de destino | chip, tamaño y compatibilidad |
| Autoprueba de arranque | funcionamiento básico de la aplicación |

Un hash descargado junto a la imagen desde un origen no confiable puede ser sustituido junto a ella. Un número de versión mayor tampoco demuestra autorización.

Diseña manifiesto con versión, destino, tamaño, hash y requisitos de configuración. Protege su autenticidad y la de la imagen según el mecanismo elegido.

## 4. Máquina de estados
Flujo conceptual, no una implementación de OTA:

```text
IDLE → COMPROBAR → DESCARGAR → VERIFICAR → PREPARAR_ARRANQUE
→ REINICIAR → AUTOPRUEBA → CONFIRMAR
```

Ante fallo de descarga o verificación, conserva el firmware válido. Define timeout, espacio, energía mínima y cancelación. Mantén salidas seguras durante la operación y evita que OTA desatienda límites locales.

## 5. Primer arranque y rollback
Con rollback de ESP-IDF configurado, la aplicación nueva debe comprobar su estado pendiente, ejecutar diagnósticos y confirmar validez mediante el mecanismo previsto. Las API de referencia incluyen esp_ota_mark_app_valid_cancel_rollback y esp_ota_mark_app_invalid_rollback_and_reboot.

Estas API no activan solas una configuración ausente. Bootloader, particiones y SDK deben soportar el flujo. Conserva una imagen previa válida.

La autoprueba debe ser acotada: versión, configuración legible, tareas críticas y periféricos necesarios. Exigir Internet instantáneo para confirmar puede provocar rollback por una caída ajena al firmware; define qué comprobaciones locales y de conectividad requiere realmente el producto.

## 6. Configuración y vuelta de versión
El firmware anterior puede no entender datos migrados por el nuevo. Diseña migración reversible, copia válida o compatibilidad antes de modificar almacenamiento.

Rollback funcional y anti-rollback de seguridad son distintos. Anti-rollback impide versiones por debajo de un nivel de seguridad y puede limitar qué imagen de recuperación resulta válida. No programes eFuses como ejercicio introductorio.

## 7. Energía y fallos
Verifica fuente estable, margen para picos y batería suficiente. Define comportamiento si se corta energía durante descarga, verificación, cambio de arranque o autoprueba.

No prometas recuperación solo por tener dos particiones: prueba cada fase en la configuración real. Mantén una ruta de recuperación física autorizada.

## 8. Despliegue gradual y observabilidad
Actualiza primero un dispositivo de laboratorio, después un grupo reducido y luego la flota. Detén la distribución ante fallos. Registra versión anterior/nueva, etapa, bytes, error, motivo de reset y resultado de validación.

No publiques claves de firma ni credenciales OTA. Una actualización manual autorizada y una actualización automática deben compartir las comprobaciones de seguridad necesarias.

## 9. Práctica guiada
1. Documenta chip, versiones, particiones y recuperación física.
2. Prepara dos firmwares de laboratorio que reporten versiones distintas.
3. Establece criterios de autoprueba y confirmación antes de actualizar.
4. Prueba una actualización válida y verifica versión/configuración después del arranque.
5. Interrumpe la descarga: la imagen válida debe seguir disponible.
6. Prueba imagen incompleta o incompatible: debe rechazarse.
7. Si rollback está configurado, usa una imagen de prueba que falle su autoprueba y verifica retorno.
8. Comprueba que el firmware recuperado entiende los datos persistidos.
9. Completa [CHECKLIST.md](CHECKLIST.md) con resultados.

Estas pruebas requieren recuperación preparada, montaje sin actuadores peligrosos y la implementación OTA elegida. No se proporciona aquí un sketch que simule seguridad sin implementarla.

## 10. Errores frecuentes
- Considerar descarga completa como actualización exitosa.
- Hash sin origen confiable.
- Asumir rollback automático.
- Confirmar imagen antes de autoprueba.
- Migrar datos de forma incompatible con recuperación.
- Actualizar toda la flota a la vez.

## 11. Reto y autoevaluación
Diseña OTA para un nodo con batería y cola offline: decide cuándo actualizar, cómo proteger pendientes y cuándo suspender el despliegue.

¿TLS sustituye la firma? ¿Qué confirma la aplicación? ¿Cómo vuelve de versión con configuración migrada? ¿Qué diferencia hay entre rollback y anti-rollback?

## 12. Checklist
- [ ] Destino, particiones y tamaño comprobados.
- [ ] Origen e imagen autorizados.
- [ ] Energía y timeout definidos.
- [ ] Autoprueba y confirmación.
- [ ] Recuperación realmente probada.
- [ ] Datos compatibles con vuelta de versión.
- [ ] Despliegue gradual y diagnóstico.

## Referencia oficial
[OTA y rollback en ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/system/ota.html).

[Anterior: seguridad](../unidad18-seguridad/) · [Siguiente: energía](../unidad20-energia/) · [Índice](../README.md)
