# Unidad 13 — Arquitectura de un sistema IoT

## Qué aprenderás
Diseñar el sistema completo desde la medición hasta la decisión del usuario y el camino inverso de control, incluyendo fallos, seguridad, tiempo y energía.

# 1. ESP32 es una pieza

```text
mundo físico
→ sensor
→ ESP32
→ red
→ broker/API
→ procesamiento
→ almacenamiento
→ dashboard/alerta
```

Para control existe además un camino de regreso.

# 2. Edge vs nube

Pregunta qué debe ocurrir localmente:
- validación;
- alarma crítica;
- control seguro;
- filtrado;
- agregación.

Una decisión que debe funcionar sin Internet no debería depender exclusivamente de la nube.

# 3. Muestreo vs transmisión

Puedes medir cada segundo y transmitir cada minuto.

Separarlos permite:
- ahorrar energía;
- reducir red;
- conservar detalle local;
- agrupar.

No transmitas cada lectura solo porque la tienes.

# 4. Fallos por capa

Distingue:
- sensor;
- almacenamiento;
- Wi‑Fi;
- DNS/Internet;
- broker/API;
- autenticación;
- payload;
- backend;
- dashboard.

Cada capa necesita observabilidad y recuperación diferente.

# 5. Estado degradado

Define qué conserva el nodo:
- medir;
- controlar;
- almacenar;
- mostrar;
- reintentar.

La degradación debe estar diseñada, no improvisada cuando falle Internet.

# 6. Cola offline

Decide:
- capacidad;
- persistencia;
- orden;
- descarte;
- sincronización;
- qué ocurre si permanece offline días.

Memoria/flash son finitas.

# 7. Tiempo

Si los datos necesitan timestamp real:
- fuente de hora;
- sincronización;
- deriva;
- arranque sin red;
- zona/UTC.

No confundas millis con reloj de calendario.

# 8. Identidad

Cada nodo necesita identidad para datos/comandos.

Diseña:
- provisioning;
- identificador;
- credenciales;
- revocación.

No clones una misma credencial permanente en todos los dispositivos por comodidad.

# 9. Seguridad

Analiza:
- datos en tránsito;
- autenticación;
- autorización;
- secretos;
- superficie expuesta;
- actualización;
- acceso físico.

La Unidad 18 profundiza.

# 10. Actualización

Un dispositivo desplegado necesitará correcciones.

Planifica desde arquitectura:
- cómo actualizar;
- qué pasa si falla;
- compatibilidad de configuración;
- versión reportada.

# 11. Energía

En batería:
- radio;
- frecuencia de transmisión;
- sensores;
- regulador;
- deep sleep
pueden dominar el presupuesto.

Arquitectura de datos y energía están relacionadas.

# 12. Escalabilidad

Tres nodos y 300 nodos cambian:
- naming;
- credenciales;
- topics;
- observabilidad;
- actualizaciones;
- almacenamiento;
- tormentas de reconexión.

Diseña identificadores/topics sin nombres manuales.

# 13. Observabilidad

Un sistema debe permitir saber:
- versión;
- uptime/reset;
- conectividad;
- última medición;
- errores;
- backlog;
- estado de actualización.

Sin observabilidad, mantenimiento remoto se vuelve adivinanza.

# 14. Plantilla

Completa [PLANTILLA_ARQUITECTURA.md](PLANTILLA_ARQUITECTURA.md).

Dibuja tanto:
- flujo de telemetría;
- flujo de comandos.

# 15. Práctica guiada

Diseña tres nodos ambientales.

Simula:
- Internet fuera 1 h;
- broker fuera;
- sensor inválido;
- reinicio;
- credencial revocada.

Describe qué ocurre en cada capa.

# 16. Errores frecuentes
- nube para control crítico local;
- muestreo = transmisión;
- cola infinita;
- millis como timestamp;
- credencial compartida por flota;
- OTA añadido al final;
- sin observabilidad.

# 17. Reto
Arquitectura completa para 30 nodos que pueda operar degradada y recuperarse sin tormenta de tráfico.

# 18. Autoevaluación
1. ¿Qué debe quedar en edge?
2. ¿Muestreo/transmisión iguales?
3. ¿Qué limita cola offline?
4. ¿Cómo obtiene hora?
5. ¿Una credencial para todos?
6. ¿Por qué observabilidad?
7. ¿Energía afecta arquitectura?

# 19. Checklist
- [ ] Flujo ida/vuelta.
- [ ] Edge/nube.
- [ ] Fallos.
- [ ] Offline.
- [ ] Tiempo.
- [ ] Identidad/seguridad.
- [ ] OTA.
- [ ] Energía.
- [ ] Observabilidad.

Continúa con BLE.
