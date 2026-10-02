# Checklist OTA

## Antes
- [ ] Chip, flash, core/SDK y bootloader registrados.
- [ ] Partición destino suficiente y esquema compatible.
- [ ] Firmware previo válido y recuperación física preparada.
- [ ] Servidor autorizado y TLS validado.
- [ ] Integridad y autenticidad de manifiesto/imagen verificadas.
- [ ] Destino, versión y requisitos compatibles.
- [ ] Energía suficiente y salidas seguras.
- [ ] Timeout, cancelación y tamaño máximo.
- [ ] Migración compatible con rollback.
- [ ] Rollback/anti-rollback comprendidos según configuración.

## Durante
- [ ] Etapa y progreso observables sin secretos.
- [ ] Control local conserva sus límites.
- [ ] Descarga incompleta no activa una imagen inválida.
- [ ] Verificación precede a selección de arranque.

## Después
- [ ] Nueva versión reportada.
- [ ] Configuración y pendientes recuperados.
- [ ] Autoprueba acotada ejecutada.
- [ ] Imagen confirmada solo tras cumplir criterios.
- [ ] Fallo de autoprueba conduce a recuperación configurada.
- [ ] Firmware previo entiende datos tras recuperación.
- [ ] Distribución detenida si el grupo de prueba falla.

## Evidencias
| Caso | Etapa | Firmware al recuperar | Datos conservados | Resultado |
|---|---|---|---|---|
| Actualización válida | | | | |
| Descarga interrumpida | | | | |
| Imagen incompatible | | | | |
| Autoprueba fallida | | | | |
| Corte de energía controlado | | | | |

No marques rollback como probado si tu bootloader/configuración no lo habilita.

[Volver a la unidad](README.md)
