# Unidad 02 — Primer programa, arranque y diagnóstico serial

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

Más adelante, conectividad y tareas requerirán temporización no bloqueante.

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
