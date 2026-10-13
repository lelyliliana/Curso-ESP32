# Unidad 02 — Primer programa, arranque y diagnóstico serial

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/esp32/)

## Qué aprenderás
Distinguir compilación, carga, boot y ejecución, y usar Serial para diagnosticar una placa ESP32 antes de integrar periféricos.

# 1. Cuatro etapas

```text
compilación → carga → arranque → ejecución
```

Un fallo en cada etapa tiene causas diferentes.

# 2. Programa mínimo

```cpp
void setup() {
  Serial.begin(115200);
  Serial.println("Inicio");
}

void loop() {
  Serial.println("vivo");
  delay(1000);
}
```

El baud elegido debe coincidir con el monitor para tus mensajes.

Los mensajes ROM/boot pueden usar configuraciones propias según chip.

# 3. LED integrado

No asumas que:
- existe;
- está en GPIO 2;
- es activo HIGH.

Consulta tu placa.

Si no existe, empieza solo con Serial.

# 4. Compilación

Problemas:
- core/placa;
- API distinta entre versiones;
- biblioteca;
- sintaxis.

Lee el primer error relevante, no solo la última línea.

# 5. Carga

Problemas:
- cable;
- puerto;
- USB‑UART;
- permisos/driver;
- bootloader;
- velocidad/configuración;
- GPIO externo interfiriendo.

Usa [DIAGNOSTICO.md](DIAGNOSTICO.md).

# 6. Boot

El chip puede cargar correctamente y después no arrancar la aplicación por:
- strapping;
- brownout;
- watchdog/reset;
- crash;
- alimentación.

Los mensajes de arranque/reset son evidencia útil.

# 7. Reset reason

Según core/chip existen APIs/logs para conocer causa de reset.

No memorices una API universal: aprende a buscarla para la versión/familia usada.

# 8. Brownout

Wi‑Fi y otros subsistemas pueden producir picos de consumo.

Una alimentación marginal puede funcionar con Blink y reiniciarse al activar radio.

Eso no significa que Wi‑Fi “tenga un bug”.

# 9. Serial como baseline

Antes de conectar sensores:
- imprime identificación/versión si aporta;
- prueba uptime;
- reinicia varias veces;
- observa estabilidad.

# 10. delay aquí

En este programa mínimo delay es aceptable.

Las prácticas de [temporización y tareas](../unidad05-interrupciones-tareas/) y [conectividad](../unidad06-wifi/) utilizan temporización no bloqueante para mantener la función local.

# 11. Práctica guiada

1. programa mínimo;
2. reinicia;
3. desconecta/reconecta;
4. provoca error de compilación;
5. selecciona configuración incorrecta y observa el tipo de fallo;
6. vuelve a baseline.

# 12. Errores frecuentes
- pantalla vacía = código;
- LED integrado asumido;
- baud único para todo mensaje de boot;
- compila = arranca;
- periféricos conectados durante diagnóstico;
- ignorar alimentación.

# 13. Reto
Crea un sketch de diagnóstico que informe uptime y permita reconocer reinicios sin depender de sensores.

# 14. Autoevaluación
1. ¿Carga y boot son lo mismo?
2. ¿LED integrado universal?
3. ¿Qué puede causar brownout?
4. ¿Por qué placa sola?
5. ¿Serial ayuda en qué etapas?

# 15. Checklist
- [ ] Compila.
- [ ] Carga.
- [ ] Arranca estable.
- [ ] Serial comprensible.
- [ ] Baseline reproducible.

Continúa con E/S, ADC y PWM.


---


## Laboratorio ejecutable de referencia

Esta unidad incluye [programa completo y práctica paso a paso](LABORATORIO.md), [soluciones razonadas](SOLUCIONES.md) y [registro de evidencias](../docs/EVIDENCIAS.md).

**Objetivo de la práctica:** Separar arranque y tarea periódica.

**Alcance:** Sin Wi-Fi ni procesos concurrentes; no demuestra tiempo real estricto.

## Continuar el curso

- **Unidad anterior:** [Unidad 01 — Arquitectura, GPIO y elección de pines](../unidad01-arquitectura-gpio/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 03 — GPIO, ADC y PWM en ESP32](../unidad03-io-adc-pwm/README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2002%20%E2%80%94%20Primer%20programa%20y%20diagn%C3%B3stico%20serial%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad02-primer-programa%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
