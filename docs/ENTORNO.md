# Entorno reproducible ESP32

[Curso](../README.md) · [Laboratorios](../laboratorios/README.md)

## Referencia concreta

| Componente | Referencia |
|---|---|
| Chip/módulo | ESP32 clásico, ESP32-WROOM-32 |
| Perfil de compilación | ESP32 Dev Module (`esp32:esp32:esp32`) |
| Arduino-ESP32 |3.3.12 |
| ArduinoJson |7.4.2 |
| PubSubClient |2.8.0 |
| Monitor serie |115200 baud |
| Servidor educativo |Python 3.10+ (biblioteca estándar) |
| Broker de práctica |Mosquitto 2.0.22 |

Las versiones fijan una combinación reproducible; no significan que sean las únicas válidas. Instala esas versiones para comparar resultados. S2 no tiene BLE; S3/C3 cambian pines y capacidades: adapta antes de usar. Los ejemplos PWM usan API3.x: `ledcAttach` y `ledcWrite` por pin.

## Paso 1. Identifica y prepara la placa

Lee chip/módulo y pinout del fabricante. Empieza solo con USB de datos. No conectes sensores aún. Descarga ZIP del repositorio o clónalo y extrae a una carpeta personal.

## Paso 2. Instala el soporte de placa

En Arduino IDE abre Preferencias y añade a URLs adicionales del gestor de placas:

```text
https://espressif.github.io/arduino-esp32/package_esp32_index.json
```

Abre gestor de placas, busca **esp32 by Espressif Systems** e instala 3.3.12. Selecciona ESP32 Dev Module únicamente para la referencia clásica compatible; si el fabricante proporciona un perfil exacto, registra cuál utilizas.

## Paso 3. Instala las bibliotecas

En gestor de bibliotecas instala **ArduinoJson 7.4.2** y **PubSubClient 2.8.0**. WiFi, HTTPClient, WebServer, Wire, Preferences, BLE y ArduinoOTA vienen con el core. No instales bibliotecas con nombres similares de otro fabricante para sustituirlas.

## Paso 4. Prueba la identificación

Abre `unidad00-preparacion/ejemplos/identidad/identidad.ino`, selecciona puerto y compila. Carga, abre monitor 115200 y compara el chip. Si falla, sigue diagnóstico de Unidad02 antes de añadir componentes.

## Paso 5. Configura solo tu copia local

Los sketches de red contienen `config_local.example.h`. Cópialo a `config_local.h` en la misma carpeta y completa SSID/clave de 2.4 GHz. Para HTTP/MQTT, LAB_HOST es IP LAN del computador. Mantén el archivo privado: `.gitignore` lo excluye.

El firmware necesita esos datos para conectarse; placeholders permiten compilar pero no conectarse. No imprimas credenciales. Todos los tópicos de referencia comienzan por `curso/nodo01/`; dos dispositivos requieren identidad propia y permisos ajustados.

## Paso 6. Construye un montaje por vez

| Elemento | Conexión de referencia clásica |
|---|---|
| LED |GPIO25 →330Ω →ánodo; cátodo →GND |
| Pulsador |GPIO27 ↔GND, INPUT_PULLUP |
| Potenciómetro10kΩ | extremos3V3/GND, cursor34 |
| SHT31 compatible3.3V |3V3/GND, SDA21, SCL22; dirección0x44 |

Desenergiza antes de cablear. Verifica alimentación y pull-ups de tu módulo SHT31; no todas las placas comerciales tienen el mismo regulador/esquema. El pin34 es entrada ADC1 y no admite salida ni pull-up interno en el ESP32 clásico.

## Verificación opcional con CLI

Para estudiantes que ya usan terminal, instala Arduino CLI y el core/bibliotecas indicados. Abre terminal en raíz:

```text
arduino-cli core update-index --additional-urls https://espressif.github.io/arduino-esp32/package_esp32_index.json
```

```text
arduino-cli core install esp32:esp32@3.3.12 --additional-urls https://espressif.github.io/arduino-esp32/package_esp32_index.json
```

```text
arduino-cli lib install ArduinoJson@7.4.2 PubSubClient@2.8.0
```

Ejecuta `python scripts/compilar.py` (o `python3`/`py -3` según sistema). El script compila los 26 sketches de referencia en carpeta temporal, sin cargar firmware, conectar redes ni leer configuraciones privadas de tu copia.

## Fuentes oficiales

- [Instalación Arduino-ESP32](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html).
- [Migración2.x a3.x](https://docs.espressif.com/projects/arduino-esp32/en/latest/migration_guides/2.x_to_3.0.html).
- [LEDC](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/ledc.html).
- [SHT3x, ficha del fabricante](https://sensirion.com/products/catalog/SHT31-DIS-B).
- [PubSubClient: API y límites](https://pubsubclient.knolleary.net/api).
- [ArduinoJson7](https://arduinojson.org/v7/).

No confundas una compilación correcta con comprobación eléctrica, lectura calibrada o seguridad de un sistema en producción.
