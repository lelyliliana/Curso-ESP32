# Unidad 01 — Arquitectura, GPIO y elección de pines

## Qué aprenderás
Elegir GPIO a partir de la documentación real de tu chip/placa y comprender por qué un pin físicamente expuesto puede no ser apropiado para cualquier función.

# 1. Del Arduino clásico al ESP32

ESP32 integra, según familia:
- CPU más potente;
- Wi‑Fi;
- Bluetooth/BLE en variantes compatibles;
- ADC;
- PWM;
- UART;
- I²C;
- SPI;
- timers;
- watchdogs;
- memoria/periféricos avanzados.

Más capacidad también significa más restricciones e interacciones.

# 2. GPIO no equivalentes

Un pin puede ser:
- entrada/salida general;
- solo entrada en ciertas variantes;
- conectado a flash/PSRAM;
- strapping/arranque;
- USB/JTAG;
- no expuesto;
- reservado por la placa.

Consulta **chip + módulo + placa**.

# 3. Strapping/boot pins

Algunos GPIO se muestrean durante reset para decidir configuración de arranque.

Un sensor/pull-up/pull-down externo puede cambiar ese nivel e impedir el boot.

No significa que nunca puedan usarse: significa que debes entender la restricción y estado durante reset.

# 4. Flash/PSRAM

Pines usados internamente por memoria pueden no estar disponibles aunque aparezcan en diagramas genéricos del chip.

La placa/módulo concreto manda.

# 5. 3.3 V

La entrada no debe superar los límites eléctricos especificados.

Para señales de 5 V usa una adaptación apropiada:
- divisor cuando eléctricamente/protocolo sea válido;
- level shifter;
- transceptor.

No uses un divisor indiscriminadamente para buses bidireccionales o señales rápidas.

# 6. Drive y carga

GPIO controla señales/cargas pequeñas dentro de especificación.

No conectes motores, servos, relés o tiras LED directamente.

La mayor potencia de CPU del ESP32 no aumenta mágicamente la potencia segura del GPIO.

# 7. Pull-up/pull-down

ESP32 ofrece resistencias internas según pin/periférico/familia.

No asumas que todos los pines tienen exactamente las mismas capacidades.

# 8. Buses flexibles

En muchas variantes/periféricos existe flexibilidad para asignar señales a diferentes GPIO mediante matriz de IO u otros mecanismos.

Pero algunas señales/pines tienen restricciones o rendimiento especial.

“Se puede mapear” no significa “cualquier pin es igual de bueno”.

# 9. Planificación

Usa [PLANTILLA_PINES.md](PLANTILLA_PINES.md).

Para cada función registra:
- GPIO;
- dirección;
- periférico;
- nivel;
- estado durante boot;
- restricción;
- fuente documental.

# 10. Conflictos

Antes de cablear detecta:
- mismo pin para dos funciones;
- pin de boot con carga externa;
- bus compartido;
- timer/periférico compartido;
- pin reservado.

# 11. Práctica guiada

Planifica:
- LED;
- pulsador;
- ADC;
- I²C;
- UART.

No conectes todavía. Justifica cada pin con documentación.

# 12. Errores frecuentes
- todos los GPIO iguales;
- pin visible = libre;
- ignorar boot;
- divisor para cualquier señal;
- motor directo;
- copiar pinout de otra familia;
- asignar primero y documentar después.

# 13. Reto
Crea dos planes de pines válidos para tu placa y explica ventajas/conflictos de cada uno.

# 14. Autoevaluación
1. ¿Qué es strapping pin?
2. ¿Pin del chip = disponible en placa?
3. ¿Divisor sirve para todo?
4. ¿GPIO ESP32 da más potencia por ser más rápido?
5. ¿Por qué planificar antes?
6. ¿Qué documentar por pin?

# 15. Checklist
- [ ] GPIO justificados.
- [ ] Boot revisado.
- [ ] Niveles compatibles.
- [ ] Sin cargas de potencia.
- [ ] Conflictos detectados.

Continúa con primer programa.
