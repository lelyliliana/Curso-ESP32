# Unidad 00 — Preparación, seguridad y placa ESP32

## Qué aprenderás
Identificar exactamente tu ESP32, preparar el entorno y evitar dos errores comunes: copiar un pinout de otra placa y aplicar 5 V a GPIO de 3.3 V.

## Requisito recomendado

Completa primero el [Curso de Arduino](https://github.com/lelyliliana/Curso-Arduino).

Aquí no repetiremos desde cero Ley de Ohm, GPIO, ADC, PWM, millis o buses: estudiaremos cómo cambian al trabajar con ESP32 e IoT.

# 1. ESP32 no es una placa única

ESP32 es una familia/ecosistema.

Puedes encontrar variantes como ESP32, S2, S3, C3, C6 y placas de desarrollo construidas alrededor de módulos diferentes.

Pueden cambiar:
- arquitectura/núcleos;
- Wi‑Fi/Bluetooth;
- USB;
- número de GPIO;
- ADC;
- periféricos;
- pinout;
- restricciones.

Nunca uses “pinout ESP32” como si fuera universal.

# 2. Identidad de tu hardware

Registra:
- familia/chip;
- módulo;
- placa;
- revisión cuando importe;
- chip USB‑serial si existe;
- documentación oficial/fabricante.

Una foto de Internet de una placa parecida no es documentación suficiente.

# 3. Lógica de 3.3 V

Los GPIO ESP32 trabajan típicamente con lógica de 3.3 V.

**No apliques 5 V directamente a un GPIO** salvo que la documentación exacta indique tolerancia.

Un módulo alimentado a 5 V puede tener una salida de 5 V: verifica por separado alimentación y nivel lógico.

# 4. Alimentación

Una placa de desarrollo puede aceptar USB y ofrecer pines 5V/VIN/3V3 según diseño.

No asumas:
- qué pin es entrada/salida de potencia;
- cuánta corriente entrega el regulador;
- que puedes alimentar motores/servos;
- que dos fuentes pueden conectarse simultáneamente.

Consulta esquema/documentación.

# 5. USB

Según placa puede existir:
- USB‑UART externo;
- USB nativo;
- ambos.

Esto afecta puerto, drivers, modo de carga y diagnóstico.

# 6. Entorno

Con Arduino IDE:
1. instala soporte ESP32 apropiado;
2. selecciona placa exacta o perfil compatible documentado;
3. selecciona puerto;
4. compila;
5. carga un ejemplo mínimo;
6. abre Serial.

Las APIs pueden cambiar entre versiones del core. Registra la versión usada.

# 7. Boot y carga

Algunas placas entran automáticamente al bootloader; otras situaciones pueden requerir BOOT/RESET.

Además, dispositivos conectados a ciertos GPIO pueden impedir un arranque normal.

Antes de culpar al IDE, prueba la placa sin periféricos externos.

# 8. Credenciales

Nunca publiques:
- SSID/clave;
- tokens;
- claves privadas;
- secretos de API.

Los ejemplos usan placeholders.

Lee [CHECKLIST.md](CHECKLIST.md); la estrategia específica de Wi‑Fi se profundiza en Unidad 06.

# 9. Diagnóstico inicial

Con placa sola:
- compila;
- carga;
- Serial;
- reinicia;
- identifica mensajes de boot;
- confirma estabilidad.

Esto crea una línea base antes de añadir hardware.

# 10. Seguridad física

Se mantienen las reglas de Arduino:
- cablear desenergizado;
- GPIO no es potencia;
- motores/relés con etapa apropiada;
- no trabajar directamente con red eléctrica;
- verificar polaridad/niveles.

# 11. Ficha técnica

Crea una ficha de tu placa con:
- foto/modelo;
- pinout;
- alimentación;
- GPIO seguros para tus prácticas;
- buses;
- ADC;
- PWM;
- Wi‑Fi/BLE;
- USB;
- restricciones de arranque;
- enlaces fuente.

# 12. Errores frecuentes
- copiar pinout de otra ESP32;
- 5 V a GPIO;
- confundir pin 5V con lógica 5 V;
- placa genérica seleccionada sin comprobar;
- periféricos conectados durante diagnóstico de boot;
- credenciales en Git.

# 13. Reto
Entrega la ficha técnica y explica tres diferencias entre tu placa y otra familia ESP32.

# 14. Autoevaluación
1. ¿ESP32 es una sola placa?
2. ¿GPIO tolera 5 V por defecto?
3. ¿VCC del módulo determina su salida lógica?
4. ¿USB siempre funciona igual?
5. ¿Por qué probar placa sola?
6. ¿Qué versión debes registrar?

# 15. Checklist
- [ ] Hardware exacto identificado.
- [ ] Pinout fiable.
- [ ] 3.3 V respetado.
- [ ] Core/placa/puerto.
- [ ] Baseline sin periféricos.
- [ ] Sin secretos.

Continúa con arquitectura y GPIO.
