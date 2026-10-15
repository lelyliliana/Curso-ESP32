# Recorridos de protocolos y estados

[Curso](../README.md) · [Soporte de red](LECTURA_RED_MQTT.md) · [Conexiones físicas](ATLAS_CONEXIONES.md)

Cada diagrama muestra responsabilidades que deben comprobarse por separado. Los tiempos nominales describen decisiones del programa, no medidas realizadas con una placa.

## MQTT: publicación, suscripción y disponibilidad

```mermaid
sequenceDiagram
    participant E as ESP32
    participant B as Broker
    participant S as Suscriptor
    E->>B: CONNECT con identidad y Last Will
    B-->>E: CONNACK
    E->>B: availability online retenido
    S->>B: SUBSCRIBE a curso/nodo01/#
    B-->>S: Última disponibilidad retenida
    E->>B: Telemetría QoS0 sin retained
    B-->>S: Telemetría para suscriptor activo
    Note over E,B: Pérdida no limpia de conexión
    B-->>S: offline al detectar la pérdida
```

La publicación de telemetría no lleva confirmación de almacenamiento de aplicación. Un nuevo suscriptor no recibe un histórico de telemetría de este ejemplo. Revisa la Unidad 10 antes de atribuir a retained o QoS una propiedad diferente.

## SHT31: aceptar antes de representar

```mermaid
flowchart TD
    A["Solicitar conversión"] --> B{"¿Transmisión aceptada?"}
    B -->|No| X["Informar diagnóstico"]
    B -->|Sí| C["Esperar al menos 20 ms"]
    C --> D{"¿Llegaron seis bytes?"}
    D -->|No| X
    D -->|Sí| E{"¿Dos CRC válidos?"}
    E -->|No| X
    E -->|Sí| F["Convertir temperatura y humedad"]
    F --> G["Representar o publicar según conexión"]
```

CRC y longitud controlan integridad de la respuesta. No certifican calibración ni la salud completa del módulo. Las llamadas del bus tienen costos y límites propios.

## Reenvío HTTP: respuesta perdida después de guardar

```mermaid
sequenceDiagram
    participant E as ESP32
    participant R as Receptor HTTP
    participant D as SQLite
    E->>R: POST nodo01-7 con contenido estable
    R->>D: Comprobar identidad e insertar
    D-->>R: Transacción confirmada
    R--xE: Respuesta 201 perdida
    Note over E: Conserva el mismo pendiente
    E->>R: Reenvío nodo01-7 con mismo contenido
    R->>D: Consultar registro existente
    D-->>R: Mismo contenido
    R-->>E: 200 y ACK nodo01-7
    Note over E: Intenta limpiar marcador persistente
```

El mensaje local Confirmado informa ACK remoto. La limpieza del marcador también puede fallar. Un contenido distinto con la misma identidad recibe 409 en vez de sobrescribir. La creación de las claves NVS del dispositivo no es una transacción atómica de aplicación.

## BLE: descubrir, leer y volver a leer

```mermaid
flowchart TD
    A["Anuncio con UUID de servicio"] --> B["Cliente descubre el nodo"]
    B --> C["Explora servicio y característica"]
    C --> D{"¿Operación solicitada?"}
    D -->|Lectura| E["Obtiene valor actual de actividad"]
    D -->|Escritura| F["No ofrecida por esta característica"]
    E --> G["Cliente espera y vuelve a leer"]
    G --> E
```

La característica solo READ no envía notificaciones al actualizar setValue. Ver un anuncio no autentica al emisor ni demuestra lectura de una característica.

## Backoff: tiempo de espera tras fallos

| Intento simulado | Intervalo nominal | Tiempo acumulado nominal |
|---:|---:|---:|
| 1 | 1 s | 1 s |
| 2 | 2 s | 3 s |
| 3 | 4 s | 7 s |
| 4 | 8 s | 15 s |
| 5 | 16 s | 31 s |
| 6 | 16 s | 47 s |

La referencia no incluye jitter ni conexión real. Un máximo de intervalo no limita el número total de intentos. `r` reinicia la política y la deshabilita; `f` habilita tomando una marca nueva, sin reiniciar por sí sola el contador ni el intervalo escalado.

## Control local y remoto: condiciones antes de actuar

```mermaid
flowchart TD
    A["Mensaje command"] --> B{"¿Tópico, tamaño y JSON válidos?"}
    B -->|No| X["Conservar salida y plazo previos"]
    B -->|Sí| C{"¿ON con botón pulsado?"}
    C -->|Sí| X
    C -->|No| D["Aplicar estado y renovar plazo local"]
    D --> E["Publicar state"]
    L["Revisión periódica del loop"] --> F{"¿Activo y botón, pérdida o vencimiento?"}
    F -->|Sí| G["Apagar y representar estado"]
    F -->|No| H["Conservar estado"]
```

El diagrama de botón corresponde a unidades 22 y 23; la Unidad 11 no lo incorpora. Una llamada de red puede retrasar atención. No hay comprobación de antigüedad de una orden, realimentación de una carga ni una cota de tiempo certificada.
