# Unidad 15 — Almacenamiento y configuración

## Qué aprenderás
Conservar parámetros entre reinicios y distinguir configuración, estado temporal y registros históricos, con validación y recuperación.

## 1. Elegir dónde guardar
| Medio | Uso habitual | Límite que debes diseñar |
|---|---|---|
| RAM | lectura actual y estado temporal | se pierde al reiniciar |
| Preferences / NVS | pequeños parámetros clave-valor | capacidad, tipos y desgaste |
| Sistema de archivos en flash | archivos y registros limitados | partición, integridad y montaje |
| microSD / almacenamiento externo | volúmenes mayores | extracción, energía y fallos de escritura |

Preferences es la interfaz Arduino-ESP32 a NVS. No es una base de datos de telemetría ilimitada. La tabla de particiones reparte espacio entre aplicación, OTA y almacenamiento.

## 2. Qué merece persistencia
Guarda umbrales, calibración e identidad según el requisito. Una lectura reciente puede quedar en RAM; el historial pendiente necesita otra política. No restaures automáticamente un actuador al último estado si ese estado resulta inseguro al arrancar.

Completa [ESTRATEGIA.md](ESTRATEGIA.md). Define valor por defecto, rango, versión del esquema y comportamiento ante datos desconocidos.

## 3. Cargar, validar y aplicar
La secuencia es leer, validar y aplicar. Que una clave exista no demuestra que tenga el tipo esperado ni un valor válido. Si la configuración es incompatible, conserva evidencia y usa un modo seguro; no borres toda NVS como solución normal.

Los valores por defecto deben ser seguros para el montaje. Una migración transforma explícitamente un esquema conocido; un firmware antiguo no debe sobrescribir datos de una versión de esquema que no entiende.

## 4. Ejemplo de un único parámetro
Este sketch Arduino-ESP32 demuestra un umbral no secreto. Cambia solo GUARDAR_CAMBIO y NUEVO_UMBRAL para la práctica. No instala una interfaz de configuración remota.

```cpp
#include <Arduino.h>
#include <Preferences.h>
#include <math.h>

Preferences prefs;
constexpr float UMBRAL_DEFECTO = 30.0f;
constexpr bool GUARDAR_CAMBIO = false;
constexpr float NUEVO_UMBRAL = 32.0f;

bool valido(float x) {
  return isfinite(x) && x >= 0.0f && x <= 60.0f;
}

void setup() {
  Serial.begin(115200);
  if (!prefs.begin("curso", false)) {
    Serial.println("NVS no disponible: usar modo seguro");
    return;
  }
  float umbral = prefs.getFloat("umbral", UMBRAL_DEFECTO);
  if (!valido(umbral)) {
    Serial.println("Valor invalido: usar defecto sin borrar evidencia");
    umbral = UMBRAL_DEFECTO;
  }
  if (GUARDAR_CAMBIO && valido(NUEVO_UMBRAL) &&
      NUEVO_UMBRAL != umbral) {
    const size_t escritos = prefs.putFloat("umbral", NUEVO_UMBRAL);
    if (escritos == sizeof(float)) {
      umbral = NUEVO_UMBRAL;
      Serial.println("Cambio persistido");
    } else {
      Serial.println("No se confirmo escritura; conservar estado seguro");
    }
  }
  prefs.end();
  Serial.printf("Umbral aplicado: %.2f\n", umbral);
}

void loop() {
  // La aplicacion local utiliza el umbral validado.
}
```

Validación del material: API contrastada con documentación oficial; compilación y prueba física pendientes en la placa y versión elegidas.

El ejemplo asume un namespace de laboratorio y una clave float. Para una configuración real comprueba también tipo y versión antes de cargar. Un retorno de escritura correcto no convierte varias escrituras independientes en una transacción.

## 5. Escrituras y cortes de energía
Escribe ante un cambio aceptado, no en cada loop. Agrupa cambios, limita frecuencia y registra errores. Wear levelling reduce desgaste, pero no vuelve infinita la vida de la flash.

Para campos relacionados evita mezclar mitad de una configuración antigua y mitad de una nueva. Diseña un registro versionado único o un esquema de dos copias con generación, validación y activación; verifica las garantías del almacenamiento elegido. Un checksum detecta corrupción accidental, no autentica datos.

No habilites formateo automático al fallar el montaje de un sistema de archivos: podría destruir registros recuperables. El restablecimiento de fábrica debe ser una operación explícita con alcance definido.

## 6. Secretos
Separar secretos del código evita publicarlos, pero no los cifra en la flash. NVS sin cifrado no es una caja fuerte. Evalúa cifrado de almacenamiento, acceso físico y provisioning en la [Unidad 18](../unidad18-seguridad/).

## 7. Práctica guiada
1. Registra placa, core y partición usada. Compila el ejemplo con guardado desactivado.
2. Arranca y comprueba el valor por defecto.
3. Habilita un cambio válido y verifica el resultado de escritura.
4. Deshabilita el guardado, vuelve a cargar y reinicia: debe recuperar el cambio.
5. Solicita un valor fuera del rango: no debe persistirse.
6. Diseña cómo detectar una clave con tipo incorrecto y un esquema incompatible.
7. En un montaje de laboratorio sin actuadores, prueba reinicios durante cambios y registra la configuración recuperada.

No borres la flash entre los pasos de persistencia: borrar durante la carga invalidaría la prueba.

## 8. Diagnóstico y errores
| Síntoma | Comprobar |
|---|---|
| Siempre vuelve al defecto | namespace, clave, borrado durante carga, resultado de put |
| NVS no abre | partición, espacio, errores del entorno |
| Datos incoherentes | tipo, esquema, validación y actualizaciones parciales |
| Registros desaparecidos | formateo, política de borrado y partición seleccionada |

## 9. Reto y autoevaluación
Diseña una configuración con umbral, intervalo y versión, que sobreviva a reinicios sin aceptar campos incompatibles. Explica cómo migrarla y cómo volver al firmware anterior.

¿Por qué no guardar cada lectura en NVS? ¿Qué confirma put? ¿Qué ocurre si falla la lectura? ¿Guardar un secreto implica cifrarlo?

## 10. Checklist
- [ ] Clasificación RAM/persistencia.
- [ ] Valores seguros y rangos.
- [ ] Tipos y esquema comprobados.
- [ ] Resultado de escritura observado.
- [ ] Desgaste y capacidad considerados.
- [ ] Recuperación sin borrado automático.

## Referencias oficiales
- [Preferences](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/preferences.html).
- [NVS](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/storage/nvs_flash.html).

[Anterior: BLE](../unidad14-ble/) · [Siguiente: sincronización](../unidad16-registro-sincronizacion/) · [Índice](../README.md)
