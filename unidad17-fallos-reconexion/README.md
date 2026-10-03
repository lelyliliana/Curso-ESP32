# Unidad 17 — Manejo de fallos y reconexión

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/esp32/)

## Qué aprenderás
Detectar fallos por capa, mantener la función local y recuperar servicios sin bucles agresivos ni reinicios como mecanismo normal.

## 1. Un fallo no representa todo el sistema
Wi-Fi conectado no demuestra Internet disponible. Un broker disponible no demuestra que el sensor produzca lecturas válidas. Conserva estados separados para sensor, almacenamiento, red, servicio y actualización.

Una etiqueta global como DEGRADADO resume la situación, pero no debe ocultar sus causas. Pueden coexistir SENSOR_ERROR y SIN_SERVICIO. Deriva el estado general a partir de indicadores independientes.

## 2. Política local
Define qué se mantiene, qué se limita y qué pasa a estado seguro. Un nodo puede medir y almacenar sin broker; un control dependiente de datos remotos puede necesitar detener una acción cuando esos datos caducan.

No mantengas una salida peligrosa usando una lectura antigua como si fuera actual. Anota validez y edad de los datos. Los límites locales de seguridad deben continuar activos durante reconexión y OTA.

## 3. Reconexión cooperativa
Organiza conexión, espera, timeout y siguiente intento como estados. Atiende la aplicación local en cada vuelta. Un diseño sin while de espera todavía puede bloquear si la llamada connect tarda varios segundos; comprueba y limita el tiempo de la API real.

Esquema conceptual:

```text
DESCONECTADO → esperar intervalo
CONECTANDO   → iniciar/intentar con limite de tiempo
DISPONIBLE  → atender servicio y medir salud
FALLO       → clasificar, programar reintento o pedir intervencion
```

Un timeout abandona una operación, no demuestra la causa. Registra capa y código de error.

## 4. Backoff y jitter
Un plan de laboratorio puede usar intervalos base de 1, 2, 4, 8, 16 y 30 s, con tope de 30 s y una variación aleatoria acotada. Limita el contador antes de multiplicar para evitar overflow.

El jitter reparte los intentos de una flota. Usa una fuente aleatoria apropiada y evita la misma secuencia fija en todos los nodos. Reinicia el backoff después de un periodo de conexión estable, no tras una conexión que cae inmediatamente.

Para temporización relativa utiliza diferencias unsigned, por ejemplo:

```cpp
if (static_cast<uint32_t>(millis() - inicioEspera) >= intervaloMs) {
  // Ejecutar un paso acotado; no esperar aqui a que vuelva la red.
}
```

Este fragmento requiere variables uint32_t e intervalos acotados; no es un sketch completo. Evita comparar ingenuamente millis() con una fecha límite sumada, porque el contador vuelve a cero.

## 5. Clasificar para recuperar
| Error | Respuesta |
|---|---|
| Red caída / timeout | reintento limitado y operación local |
| 429 / servicio saturado | respetar espera indicada si aplica y reducir ritmo |
| Credencial rechazada | no insistir agresivamente; pedir reprovisioning |
| Certificado inválido | revisar confianza/hora; conservar validación |
| JSON incompatible | rechazar y conservar diagnóstico |
| Sensor inválido | marcar calidad; reintento específico |
| Almacenamiento lleno | aplicar política de datos, sin borrado general |

HTTP 401 y 403 no se resuelven reiniciando Wi-Fi. Tampoco se corrige TLS usando setInsecure como recuperación normal.

## 6. Watchdog y reinicios
El watchdog ayuda a detectar una ejecución que deja de progresar. No lo alimentes ciegamente para esconder un bloqueo ni lo desactives para que una espera infinita parezca funcionar.

Registra motivo de reset y frecuencia de arranques. Si existe un fallo fatal que requiere reinicio, limita la repetición y diseña un arranque seguro; evita un ciclo que desgaste flash o repita acciones físicas.

## 7. Observabilidad
Conserva último éxito por capa, contador de fallos, próximo intervalo, backlog, heap y motivo de reset. Diferencia conectado de operativo y de recuperado. No imprimas secretos.

Completa [MATRIZ_FALLOS.md](MATRIZ_FALLOS.md), incluyendo fallos simultáneos.

## 8. Práctica guiada
1. Define el periodo de medición y la latencia máxima local tolerable.
2. Desconecta Wi-Fi y verifica que la función local mantiene el criterio.
3. Mantén Wi-Fi y detén el servicio: el diagnóstico debe cambiar de capa.
4. Introduce credencial rechazada, respuesta inválida y sensor sin lectura.
5. Reconecta el servicio: comprueba espera, recuperación y vaciado limitado.
6. Reinicia durante una caída y comprueba configuración, cola y salida segura.
7. Mide el peor tiempo del loop y de las llamadas de conexión, no solo su promedio.
8. Repite con sensor inválido y red caída simultáneamente.

Ejemplo de criterio para un laboratorio sin actuadores: lectura cada segundo, ningún hueco superior a 2 s por reconexión y ningún reintento fuera del calendario definido. Ajusta el criterio antes de probar según tu biblioteca y requisito; si no se cumple, identifica la llamada bloqueante.

## 9. Errores frecuentes
- Un estado único que borra un fallo al resolver otro.
- Reiniciar ante cualquier caída.
- Reintento sin tope ni clasificación.
- Suponer que connect es no bloqueante.
- Ocultar lectura inválida o alimentar watchdog sin progreso.

## 10. Reto y autoevaluación
Diseña el comportamiento de 30 nodos tras volver la energía y el broker. Define escalonamiento, arranque seguro y tasa de sincronización.

¿Por qué red y servicio son estados distintos? ¿Cuándo se reinicia backoff? ¿Qué detecta watchdog? ¿Cómo se mide que la función local continúa?

## 11. Checklist
- [ ] Estados por capa y fallos simultáneos.
- [ ] Límites de espera medidos.
- [ ] Backoff con tope y jitter.
- [ ] Datos caducados tratados.
- [ ] Recuperación local segura.
- [ ] Matriz y evidencias de pruebas.

[Anterior: sincronización](../unidad16-registro-sincronizacion/) · [Siguiente: seguridad](../unidad18-seguridad/) · [Índice](../README.md)


---

## Continuar el curso

- **Unidad anterior:** [Unidad 16 — Registro local y sincronización](../unidad16-registro-sincronizacion/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 18 — Credenciales y seguridad básica](../unidad18-seguridad/README.md)
