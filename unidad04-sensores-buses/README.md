# Unidad 04 — Sensores, I²C y SPI en ESP32

## Qué aprenderás
Integrar periféricos respetando 3.3 V, asignación de pines, pull-ups, direcciones y concurrencia con otros subsistemas.

# 1. Mantén el método de Arduino

```text
modelo → datasheet → alimentación → niveles
→ interfaz → biblioteca → ejemplo mínimo
→ validar → integrar
```

ESP32 no elimina ninguna de esas etapas.

# 2. I²C

Muchas placas permiten configurar SDA/SCL en GPIO seleccionados, pero:
- evita pines restringidos;
- verifica API/core;
- comprueba pull-ups;
- comprueba niveles.

# 3. Pull-ups

Un módulo I²C puede incluir resistencias hacia su VCC.

Si alimentas un breakout a 5 V, sus pull-ups podrían llevar SDA/SCL a 5 V dependiendo del diseño.

**No conectes hasta revisar el esquema/módulo.**

# 4. Varias pull-ups

Módulos en paralelo reducen la resistencia equivalente.

Inventaría cuáles tienen pull-ups y calcula/estima el conjunto cuando el bus crece.

# 5. Dirección

Usa [PRACTICA_I2C.md](PRACTICA_I2C.md) para inventario.

Un scanner detecta ACK/dirección; no valida precisión del sensor.

# 6. SPI

ESP32 puede disponer de varios controladores/buses según familia.

Algunas señales se pueden remapear, pero no asumas que todos los buses/pines son equivalentes.

# 7. Chip Select

Cada dispositivo SPI suele tener CS independiente.

Define estado seguro de CS durante boot para evitar selección accidental cuando importe.

# 8. Frecuencia

ESP32 puede operar buses rápidamente, pero el límite real incluye:
- periférico;
- cableado;
- level shifter;
- protoboard;
- capacitancia;
- biblioteca.

Más MHz no es automáticamente mejor.

# 9. Bibliotecas bloqueantes

Una biblioteca puede tardar milisegundos o más en una operación.

En un nodo conectado, mide si afecta:
- Wi‑Fi;
- tareas;
- watchdog;
- frecuencia de muestreo.

# 10. Compartir bus

Dos bibliotecas pueden configurar el mismo bus de formas distintas.

Cuando integres, documenta:
- bus;
- pines;
- frecuencia;
- dirección/CS.

# 11. Alimentación

Wi‑Fi + pantalla + sensores aumenta consumo y ruido.

Si un sensor falla solo cuando transmite, investiga alimentación/EMI además del software.

# 12. Práctica guiada

Integra dos I²C:
1. inventario;
2. scanner;
3. uno por uno;
4. juntos;
5. activa Wi‑Fi más adelante y compara estabilidad.

# 13. Errores frecuentes
- breakout 5 V conectado sin revisar pull-ups;
- scanner = sensor correcto;
- máxima frecuencia SPI;
- pines elegidos sin boot review;
- biblioteca bloqueante ignorada;
- fallos con Wi‑Fi atribuidos solo al código.

# 14. Reto
Dos sensores I²C + periférico SPI con tabla de buses, niveles y recursos.

# 15. Autoevaluación
1. ¿Pull-up a 5 V puede ser problema?
2. ¿Scanner valida medición?
3. ¿SPI rápido siempre mejor?
4. ¿CS importa en boot?
5. ¿Biblioteca puede bloquear?
6. ¿Wi‑Fi puede revelar alimentación débil?

# 16. Checklist
- [ ] Niveles.
- [ ] Pull-ups.
- [ ] Direcciones/CS.
- [ ] Pines válidos.
- [ ] Frecuencia razonable.
- [ ] Integración observada.

Continúa con interrupciones y tareas.
