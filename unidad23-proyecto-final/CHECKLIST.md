# Checklist — Proyecto final ESP32/IoT

Marca solo lo respaldado por evidencia. “No aplica” requiere razón y no equivale a una prueba exitosa.

## Alcance
- [ ] Problema, usuario y objetivo verificable.
- [ ] Criterios medibles definidos antes de probar.
- [ ] Implementado, diseñado, simulado y probado diferenciados.
- [ ] Flujo de datos y comandos/resultados cuando corresponda.

## Hardware
- [ ] Chip/placa, GPIO y pinout comprobados.
- [ ] Niveles eléctricos y alimentación compatibles.
- [ ] Driver y carga segura cuando existe actuador.
- [ ] Estado de salidas durante arranque/reset considerado.
- [ ] Versiones, dependencias y particiones documentadas.

## Software y contratos
- [ ] Responsabilidades separadas.
- [ ] Función local sin esperas indefinidas de red.
- [ ] Tiempo de llamadas y respuesta medido.
- [ ] Estados por capa y fallos simultáneos.
- [ ] Tipos, rangos, unidades y tamaño máximo.
- [ ] Calidad de lectura y de tiempo explícitas.
- [ ] IDs, duplicados, orden y vigencia según alcance.
- [ ] Confirmación software/física diferenciada.

## Robustez y persistencia
- [ ] Timeout, backoff con tope y jitter.
- [ ] Política degradada y datos caducados.
- [ ] Configuración validada y recuperación tras reinicio.
- [ ] Capacidad offline y política de descarte/rechazo.
- [ ] ACK de aplicación y deduplicación cuando se requiere entrega durable.
- [ ] Escritura incompleta/compactación y pérdidas consideradas.
- [ ] Recuperación sin tormenta de tráfico.

## Seguridad y mantenimiento
- [ ] Modelo de amenazas y permisos por nodo.
- [ ] Sin secretos en Git, capturas ni logs.
- [ ] Provisioning y revocación.
- [ ] Identidad del servidor/canal validada según protocolo.
- [ ] Mensajes no autorizados o inválidos rechazados.
- [ ] Servicios mínimos y límites de peticiones.
- [ ] Estrategia de actualización documentada.
- [ ] OTA y recuperación probadas si se implementan.
- [ ] Alimentación/consumo y decisión sobre sueño documentados.

## Pruebas y resultados
- [ ] Operación normal.
- [ ] Sin Wi-Fi y sin servicio diferenciados.
- [ ] Sensor inválido cuando existe.
- [ ] Mensaje inválido / no autorizado.
- [ ] Duplicado o confirmación perdida.
- [ ] Reinicio y recuperación.
- [ ] Cola llena cuando existe.
- [ ] Fallos simultáneos.
- [ ] Energía y mantenimiento según alcance.
- [ ] Condiciones, duración, esperado, obtenido y evidencia.
- [ ] Datos perdidos/rechazados explicados.
- [ ] Limitaciones y pruebas pendientes declaradas.

## Reproducibilidad
- [ ] README con montaje, configuración, compilación y carga.
- [ ] Servicio/cliente documentado.
- [ ] Un tercero puede repetir una prueba normal y una de fallo.
- [ ] Demostración enlazada y fuentes/licencias.
- [ ] Uso de IA y contribuciones declarados.

[Guía](README.md) · [Plantilla](PLANTILLA_PROYECTO.md) · [Rúbrica](RUBRICA.md)
