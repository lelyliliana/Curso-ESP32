# Checklist de seguridad básica IoT

- [ ] No hay credenciales reales en Git.
- [ ] Los comandos se validan.
- [ ] Los servicios expuestos son necesarios.
- [ ] TLS/certificados se configuran correctamente cuando aplica.
- [ ] Existe estrategia de actualización.
- [ ] Las credenciales pueden rotarse.
- [ ] Los logs no revelan secretos.
- [ ] El dispositivo tiene un estado seguro ante comando inválido.
- [ ] Se conoce qué datos recopila y transmite.

## Si un secreto se publica
Rótalo. Borrarlo del último commit no garantiza que haya desaparecido de copias o historial.
