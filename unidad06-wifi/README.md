# Unidad 06 — Wi‑Fi, estados y reconexión

**[Desarrollo paso a paso: Conectarse sin confundir Wi-Fi con servicio disponible](DESARROLLO.md)**. Sigue el código, las tablas y el experimento antes de resolver la práctica.

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/esp32/)

## Qué aprenderás
Conectar un ESP32 sin bloquear el dispositivo, modelar estados de red y diseñar reintentos que no destruyan autonomía local.

# 1. Wi‑Fi es un subsistema

Tu dispositivo tiene responsabilidades aunque Internet no exista:

```text
medir
control local
registrar
interfaz local
transmitir
```

No pongas toda la aplicación dentro de:
```cpp
while (WiFi.status() != WL_CONNECTED) {
}
```

# 2. Credenciales

Ejemplos:

```cpp
const char* ssid = "TU_RED";
const char* password = "TU_CLAVE";
```

Son placeholders.

Lee [SEGURIDAD_CREDENCIALES.md](SEGURIDAD_CREDENCIALES.md).

Un archivo ignorado evita commits accidentales, pero el secreto sigue almacenado en el dispositivo/binario. IoT seguro requiere pensar también en aprovisionamiento y rotación.

# 3. Estados

```text
SIN_CONFIG
SIN_RED
CONECTANDO
CONECTADO
REINTENTO
```

Puedes adaptar nombres, pero evita que “conectando” sea un bucle infinito.

# 4. Conexión inicial

Inicia intento y continúa ejecutando loop.

Comprueba periódicamente:
- status;
- tiempo desde intento;
- timeout de conexión;
- siguiente reintento.

# 5. Reconexión

Una red puede desaparecer por:
- AP reiniciado;
- señal;
- credenciales cambiadas;
- DHCP;
- interferencia.

No reinicies todo el ESP32 ante cada pérdida como estrategia principal.

# 6. Backoff

Si falla repetidamente:

```text
1 s → 2 s → 4 s → 8 s → ...
```

hasta un máximo razonable.

Añadir jitter aleatorio puede evitar que cientos de nodos reconecten exactamente al mismo tiempo.

# 7. Eventos Wi‑Fi

El core ofrece mecanismos/eventos según versión para conocer cambios de conexión/IP.

Úsalos cuando simplifiquen el diseño, pero no hagas trabajo pesado dentro de callbacks del sistema.

# 8. IP no es Internet

Estar asociado al AP y obtener IP no garantiza:
- DNS;
- ruta a Internet;
- servidor disponible;
- broker disponible.

Mantén estados separados.

# 9. RSSI

RSSI puede ayudar a diagnosticar señal, pero no es una medición absoluta de calidad de aplicación.

Una señal aparentemente buena no garantiza que el servicio remoto responda.

# 10. Alimentación

La radio produce picos de consumo.

Si reinicia al conectar:
- revisa fuente;
- cable;
- regulador;
- desacoplo;
- brownout logs.

No aumentes delays esperando arreglar energía.

# 11. Ejemplo

Estudia [wifi_reconexion.ino](ejemplos/wifi_reconexion.ino).

Comprueba si el ejemplo necesita ajustes para tu versión del core.

# 12. Práctica guiada

1. conecta;
2. registra cambio de estados;
3. apaga AP;
4. verifica que sensores siguen;
5. enciende AP;
6. observa recuperación;
7. registra tiempo/intentos.

# 13. Errores frecuentes
- while infinito;
- reboot ante cada pérdida;
- IP = Internet;
- retry cada milisegundo;
- credenciales públicas;
- ignorar picos de radio.

# 14. Reto
Nodo que mida continuamente durante 5 min sin red y recupere Wi‑Fi automáticamente sin perder su función local.

# 15. Autoevaluación
1. ¿Wi‑Fi debe bloquear medición?
2. ¿IP garantiza Internet?
3. ¿Qué es backoff?
4. ¿Para qué jitter?
5. ¿Reboot es reconexión?
6. ¿Por qué radio revela problemas de fuente?

# 16. Checklist
- [ ] Estados de red.
- [ ] Sin bloqueo.
- [ ] Timeout/reintento.
- [ ] Backoff.
- [ ] Función local independiente.
- [ ] Credenciales protegidas.

Continúa con HTTP.


---


## Laboratorio ejecutable de referencia

Esta unidad incluye [programa completo y práctica paso a paso](LABORATORIO.md), [soluciones razonadas](SOLUCIONES.md) y [registro de evidencias](../docs/EVIDENCIAS.md).

**Objetivo de la práctica:** Observar conexión y recuperación sin detener el diagnóstico local.

**Alcance:** setAutoReconnect también puede gestionar intentos; este laboratorio no garantiza el calendario interno del driver.

## Continuar el curso

- **Unidad anterior:** [Unidad 05 — Interrupciones, temporización y tareas](../unidad05-interrupciones-tareas/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 07 — Cliente HTTP y consumo de APIs](../unidad07-cliente-http/README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2006%20%E2%80%94%20Conexi%C3%B3n%20Wi%E2%80%91Fi%20y%20reconexi%C3%B3n%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad06-wifi%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
