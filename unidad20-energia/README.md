# Unidad 20 — Consumo energético y deep sleep

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/esp32/)

## Qué aprenderás
Diseñar y medir un ciclo de energía completo, conservando configuración y datos pendientes sin perder seguridad ni confundir sueño con una pausa.

## 1. Medir el sistema completo
El consumo del chip no es el de la placa. Incluye regulador, LED, puente USB, sensores y periféricos que siguen alimentados. La radio puede producir picos que la fuente debe soportar.

Mide en el punto de alimentación del montaje, registrando tensión y condiciones. Un multímetro puede mostrar promedio pero omitir picos breves; el instrumento debe ser adecuado a la pregunta. No conectes un amperímetro directamente entre los terminales de una batería: la medición de corriente va en serie y con rango/protección apropiados.

## 2. Muestreo y transmisión
Medir cada segundo y transmitir cada minuto puede ahorrar radio, pero requiere memoria, agregación y política de pérdida. Dormir 10 minutos impide medir con la CPU durante ese intervalo salvo que diseñes funciones compatibles de bajo consumo.

Un nodo que necesita control inmediato o servidor siempre disponible no encaja sin más con deep sleep. Elige modo según tiempo de respuesta, no solo consumo mínimo.

## 3. Modos de ahorro
| Estrategia | Consecuencia |
|---|---|
| Reducir transmisiones | conserva actividad local con menos uso de radio |
| Modem-sleep / gestión de energía | depende de configuración y conectividad requerida |
| Light-sleep | puede conservar contexto y reanudar ejecución; revisar radio y SDK |
| Deep-sleep | CPU/radio dejan de operar normalmente; despertar inicia un nuevo arranque |

En deep sleep no permanece disponible el servidor Wi-Fi ni el enlace BLE normal. Las fuentes de despertar y dominios retenidos dependen del chip. Comprueba temporizador, GPIO/RTC y restricciones en documentación específica.

## 4. Un nuevo arranque
Tras despertar se ejecuta setup de nuevo. RAM normal no es persistencia. Variables en memoria RTC pueden sobrevivir a determinados ciclos de sueño si están configuradas, pero no sustituyen almacenamiento durable ante pérdida de alimentación.

Registra motivo de despertar y reset. Recupera configuración y pendientes antes de transmitir. Un contador relativo o RTC retenido no crea por sí mismo una hora UTC fiable.

## 5. Ciclo con presupuesto de tiempo
El ciclo es despertar, recuperar, medir, guardar si corresponde, conectar, transmitir un lote y dormir. Cada fase tiene tiempo máximo.

Si no hay red, no gastes toda la batería esperando. Al agotar el presupuesto de conexión conserva pendientes según la Unidad 16 y duerme. Define qué ocurre si almacenamiento falla; dormir sin registrar la pérdida no la resuelve.

Antes de dormir termina operaciones críticas de persistencia, coloca periféricos/salidas en estado seguro y configura una fuente de despertar válida. No duermas en medio de OTA ni antes de completar una validación de arranque requerida.

## 6. Ejemplo mínimo: temporizador
Sketch Arduino-ESP32 para una placa compatible con despertar por temporizador. Demuestra arranque y sueño; no incluye sensor, conexión, sincronización ni estimación de autonomía.

```cpp
#include <Arduino.h>
#include "esp_sleep.h"

void setup() {
  Serial.begin(115200);
  Serial.printf("Causa de despertar: %d\n",
                static_cast<int>(esp_sleep_get_wakeup_cause()));

  constexpr uint64_t INTERVALO_US = 10ULL * 60ULL * 1000000ULL;
  const esp_err_t resultado = esp_sleep_enable_timer_wakeup(INTERVALO_US);
  if (resultado != ESP_OK) {
    Serial.println("No se configuro despertar: permanecer despierto");
    return;
  }
  Serial.println("Entrando en deep sleep");
  Serial.flush();
  esp_deep_sleep_start();
}

void loop() {
  // Solo se alcanza si no se entro en deep sleep.
}
```

Validación del material: API contrastada con documentación oficial; compilación y prueba física pendientes en la placa y versión elegidas.

ULL evita calcular microsegundos con un tipo insuficiente. El temporizador define tiempo dormido: el intervalo total entre mediciones también incluye tiempo activo. Para periodicidad de calendario necesitas otra política.

En ciertas placas el USB se desconecta o el monitor serial pierde mensajes al dormir. Esto no demuestra por sí solo un fallo; comprueba causa de despertar y consumo.

## 7. Presupuesto energético
Para fases sin solapamiento:

```text
I_promedio = suma(I_fase × tiempo_fase) / tiempo_ciclo
autonomia_h ≈ capacidad_util_mAh / I_promedio_mA
```

Ejemplo ilustrativo, no medición de una placa: 5 s a 100 mA y 595 s a 0,1 mA producen aproximadamente 0,933 mA de promedio. Con 1 600 mAh útiles, la estimación ideal sería unas 1 716 h, alrededor de 71,5 días.

No presentes ese número como autonomía del ESP32. Cambian regulador, placa, temperatura, batería, conexión y pérdidas. Si batería y carga tienen tensiones diferentes, compara energía en Wh e incorpora eficiencia, o mide corriente directamente en el lado de la batería.

Completa [PLANTILLA_PRESUPUESTO.md](PLANTILLA_PRESUPUESTO.md). Evita sumar fases solapadas dos veces.

## 8. Sensores, salidas y alimentación
Apagar un sensor puede exigir calentamiento o estabilización al despertar. Verifica que no se realimente por GPIO o buses. Mantén tensión y límites eléctricos del montaje.

Las salidas pueden cambiar o flotar durante sueño/arranque según configuración y chip. Diseña resistencias y estado seguro; comprueba la función real antes de conectar un actuador. Una power bank puede apagarse por consumo demasiado bajo.

## 9. Práctica guiada
1. Mide el montaje despierto y registra qué componentes están alimentados.
2. Ejecuta el ejemplo de temporizador y confirma un nuevo arranque.
3. Mide sueño sin asumir el valor teórico del chip.
4. Añade una medición de sensor y verifica tiempo de estabilización.
5. Añade persistencia y transmisión con presupuesto de tiempo.
6. Prueba sin red: debe guardar o contabilizar pérdida y volver a dormir.
7. Reinicia/corta energía en laboratorio y verifica recuperación de pendientes.
8. Compara ciclos de 1 y 10 minutos, con las mismas condiciones.
9. Registra corriente, duración activa, picos observables y razón de despertar.

## 10. Errores frecuentes
- Prometer autonomía con valores de datasheet del chip.
- Esperar conexión sin límite.
- Suponer que RAM sobrevive a pérdida de energía.
- Dormir mientras persiste o actualiza.
- Olvidar consumo de regulador y sensores.
- Pretender control inmediato con radio dormida.

## 11. Reto y autoevaluación
Diseña un nodo que mide cada 10 minutos y soporta 24 h sin red. Calcula energía, almacenamiento, presupuesto de conexión y tiempo de sincronización. Explica cómo cambia el diseño si requiere recibir comandos en menos de 2 s.

¿setup vuelve a ejecutarse? ¿Qué permanece alimentado? ¿Qué pasa sin red? ¿Qué tiempo incluye el ciclo? ¿Dónde mediste corriente?

## 12. Checklist
- [ ] Consumo del montaje medido.
- [ ] Modo compatible con respuesta requerida.
- [ ] Despertar configurado y comprobado.
- [ ] Persistencia y salidas seguras.
- [ ] Tiempo de conexión limitado.
- [ ] Autonomía estimada con unidades y supuestos.
- [ ] Prueba sin red y recuperación.

## Referencia oficial
[Modos de sueño en ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/system/sleep_modes.html).

[Anterior: OTA](../unidad19-ota/) · [Siguiente: nodo IoT ambiental](../unidad21-proyecto-nodo-iot/) · [Índice](../README.md)


---

## Continuar el curso

- **Unidad anterior:** [Unidad 19 — Actualizaciones OTA](../unidad19-ota/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 21 — Proyecto: nodo IoT ambiental](../unidad21-proyecto-nodo-iot/README.md)
