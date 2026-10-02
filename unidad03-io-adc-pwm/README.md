# Unidad 03 — GPIO, ADC y PWM en ESP32

## Qué aprenderás
Trasladar los fundamentos de Arduino sin asumir resoluciones, rangos, pines o APIs idénticas entre familias/core ESP32.

# 1. Digital

`pinMode`, `digitalRead` y `digitalWrite` mantienen conceptos familiares bajo Arduino core.

Pero el pin elegido debe haber pasado la revisión de Unidad 01.

# 2. ADC

ESP32 dispone de ADC según familia, pero cambian:
- número de canales;
- resolución/configuración;
- rango útil;
- linealidad;
- atenuación;
- interacción con otros periféricos en ciertas familias/versiones.

No copies “0–4095 = 0–3.3 V” como una ley de medición exacta.

# 3. Counts vs voltios

La lectura cruda no es automáticamente una tensión precisa.

Para medición seria considera:
- referencia/calibración del chip;
- atenuación;
- tolerancia;
- no linealidad;
- ruido;
- rango válido.

Usa APIs de calibración disponibles para tu plataforma cuando el requisito lo exija.

# 4. Wi‑Fi y ADC

En algunas familias ESP32 clásicas existen restricciones conocidas entre determinados ADC/periféricos y Wi‑Fi.

No generalices ni ignores: revisa la documentación de **tu familia/core** antes de seleccionar canal para un nodo conectado.

# 5. Entrada

Nunca excedas límites del GPIO/ADC.

3.3 V nominal de lógica no implica que todo el rango ADC sea lineal/preciso hasta exactamente 3.3 V.

# 6. PWM

ESP32 usa periféricos de PWM (por ejemplo LEDC en familias/cores compatibles).

La API de Arduino ESP32 ha cambiado entre versiones.

Consulta la documentación de la versión instalada en lugar de copiar funciones antiguas sin comprobar.

# 7. Frecuencia y resolución

En PWM existe una relación entre:
- frecuencia;
- resolución;
- recursos de hardware.

No siempre puedes pedir simultáneamente frecuencia extremadamente alta y máxima resolución.

# 8. Duty

PWM sigue siendo pulsos digitales, no un DAC.

Algunas variantes ESP32 pueden incluir DAC real; otras no.

Verifica el chip.

# 9. Servo/motores

PWM de control no alimenta cargas.

Servo/motor siguen requiriendo alimentación/driver adecuados como aprendiste en Arduino.

# 10. Práctica

Realiza [PRACTICA.md](PRACTICA.md).

Caracteriza:
- ADC mínimo/medio/máximo;
- ruido;
- PWM en varias configuraciones;
- comportamiento con radio si aplica a tu hardware.

# 11. Diagnóstico

Si ADC cambia al activar Wi‑Fi:
1. identifica familia/canal;
2. revisa documentación;
3. revisa alimentación/ruido;
4. no concluyas inmediatamente que el sensor falló.

# 12. Errores frecuentes
- 0–4095 universal;
- counts = voltios exactos;
- rango lineal asumido;
- API PWM vieja copiada;
- frecuencia/resolución independientes;
- PWM = DAC;
- olvidar interacción de periféricos.

# 13. Reto
Controla PWM desde una entrada analógica y documenta todas las suposiciones específicas de tu placa/core.

# 14. Autoevaluación
1. ¿ADC ESP32 universal?
2. ¿4095 significa 3.3 V exactos?
3. ¿Wi‑Fi puede influir según familia?
4. ¿LEDC API es inmutable?
5. ¿PWM = DAC?
6. ¿Frecuencia/resolución tienen trade-off?

# 15. Checklist
- [ ] ADC caracterizado.
- [ ] Canal compatible.
- [ ] API core actual.
- [ ] PWM configurado con criterio.
- [ ] Sin extrapolar otra familia.

Continúa con sensores y buses.
