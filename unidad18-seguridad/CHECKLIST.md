# Checklist de seguridad básica IoT

Añade evidencia y resultado para cada control.

- [ ] Modelo de amenazas con activos, interfaces, impacto y mitigación.
- [ ] No hay credenciales reales en archivos rastreados, ejemplos o capturas.
- [ ] Logs y diagnósticos no revelan secretos.
- [ ] Provisioning requiere autorización y tiene alcance definido.
- [ ] Credenciales por nodo, rotación, revocación y cambio de propietario.
- [ ] TLS valida servidor; existe política de hora y renovación de confianza.
- [ ] ACL MQTT / permisos HTTP impiden suplantar otro dispositivo.
- [ ] CORS no se utiliza como autenticación.
- [ ] BLE no acepta cercanía como autorización.
- [ ] Comandos validan tipo, rango, tamaño, ID y vigencia.
- [ ] Peticiones repetidas o inválidas no causan acciones inseguras.
- [ ] Colas, frecuencia de solicitudes y memoria están limitadas.
- [ ] Solo están habilitados servicios necesarios.
- [ ] Se conocen datos, retención y destinatarios.
- [ ] OTA comprueba autenticidad y contempla recuperación.
- [ ] Acceso físico y protección de almacenamiento evaluados según el chip.

## Incidente con credenciales
1. Revocar o rotar el secreto expuesto.
2. Actualizar los dispositivos autorizados.
3. Revisar usos y alcance de la exposición.
4. Corregir la causa de publicación y revisar historial/copias.

Borrar el secreto del último commit no reemplaza la revocación.

## Registro
| Control | Prueba autorizada | Resultado | Acción pendiente |
|---|---|---|---|
| ACL por nodo | A intenta usar topic de B | | |
| Comando inválido | fuera de rango | | |
| Revocación | credencial de laboratorio revocada | | |
| TLS | identidad de servidor incorrecta | | |

[Volver a la unidad](README.md)
