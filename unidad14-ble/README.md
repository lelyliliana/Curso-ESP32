# Unidad 14 — Bluetooth y BLE

## Qué aprenderás
Diseñar un servicio BLE para leer mediciones y configurar un nodo cercano, sin confundir conexión, permiso y confirmación de una acción.

## 1. Antes de comenzar
Identifica chip, placa, versión de Arduino-ESP32 y biblioteca BLE. Bluetooth clásico y BLE son tecnologías distintas; BluetoothSerial no sustituye un servicio GATT. Comprueba capacidades en la documentación del modelo: no todos los ESP32 tienen Bluetooth ni admiten las mismas funciones.

Necesitas una placa compatible, USB y un cliente BLE que permita descubrir servicios, leer, escribir y suscribirse. Usa una lectura simulada para separar problemas de radio y sensor. No conectes un actuador peligroso durante esta práctica.

## 2. Roles y descubrimiento
El peripheral anuncia su presencia; el central escanea e inicia la conexión. En esta práctica ESP32 es peripheral y servidor GATT; el móvil es central y cliente GATT. Son dos pares de roles diferentes, aunque aquí coincidan.

Advertising no significa conexión. Conexión no significa emparejamiento. Descubrir una característica no significa tener autorización para modificarla. El nombre anunciado facilita localizar el nodo, pero no demuestra su identidad.

## 3. Servicio y características
Un servicio agrupa características. Cada característica tiene UUID, propiedades, permisos y formato. Para un servicio propio utiliza UUID de 128 bits; no reutilices un UUID estándar para datos incompatibles.

| Característica | Operación | Contrato |
|---|---|---|
| temperature | read / notify | lectura, unidad, calidad y secuencia |
| humidity | read / notify | lectura y calidad |
| threshold | read / write | configuración validada |
| status | read / notify | configuración aplicada y resultado |

Completa [DISENO_SERVICIO.md](DISENO_SERVICIO.md). Las propiedades indican operaciones disponibles; los permisos y la lógica de aplicación determinan quién puede realizarlas.

## 4. Lecturas y notificaciones
Read solicita el valor actual. Notify envía cambios a un cliente suscrito mediante el descriptor correspondiente, normalmente CCCD. Una conexión abierta no implica suscripción.

Una notificación no tiene confirmación ATT; una indicación sí, pero ninguna demuestra por sí sola que la aplicación procesó el dato o que un actuador actuó. Usa secuencias para detectar pérdidas y una lectura de estado para recuperar la situación actual.

No notifiques en cada vuelta de loop. Define una frecuencia, limita el tamaño y verifica el MTU negociado. No supongas que un documento JSON completo cabe en una sola operación BLE: diseña un mensaje pequeño o un protocolo de fragmentación con límites.

## 5. Escritura y confirmación
Valida longitud, codificación, versión, tipo y rango antes de aceptar un umbral. Con escritura con respuesta puedes conocer el resultado del procedimiento GATT; la persistencia y aplicación del parámetro requieren estado de aplicación explícito.

Ruta de procesamiento conceptual, no un sketch listo para compilar:

```text
callback recibe solicitud limitada
→ valida formato y autorización
→ encola una petición pequeña
→ loop aplica configuración
→ guarda cuando corresponda
→ status informa resultado e ID
```

No hagas escrituras lentas de flash ni esperas de red dentro del callback. Si la cola está llena, rechaza la petición de forma observable. Si otras tareas comparten datos, usa sincronización apropiada; volatile no reemplaza un mecanismo de exclusión.

## 6. Seguridad local
Estar cerca no hace seguro un comando. Define emparejamiento, bonding, cifrado y protección contra intermediarios según el riesgo. Bonding conserva claves para conexiones posteriores; no constituye una autorización de aplicación completa. Just Works no ofrece la misma protección frente a intermediarios que métodos autenticados.

Para configurar credenciales abre una ventana temporal mediante una acción física y un canal autenticado; no incluyas secretos en advertising ni logs. Define cómo revocar un móvil y borrar sus vínculos.

## 7. Práctica guiada
1. Registra modelo, versiones y ejemplo BLE oficial utilizado como base.
2. Anuncia un servicio propio y localízalo desde el cliente. Confirma el UUID.
3. Lee una temperatura simulada y distingue dato válido de sensor sin lectura.
4. Suscríbete y comprueba secuencia e intervalo de notificación.
5. Escribe un umbral válido; verifica estado aplicado y vuelve a leerlo.
6. Envía un valor fuera de rango y un mensaje demasiado largo; el umbral debe mantenerse.
7. Desconecta y reconecta. Comprueba advertising, redescubrimiento y suscripción según tu implementación.
8. Repite con Wi-Fi activo y registra latencia, pérdidas y memoria disponible.

Construye una operación cada vez. Las API concretas y firmas de callbacks dependen de la biblioteca y versión; no mezcles ejemplos Bluedroid y NimBLE sin adaptar su interfaz.

## 8. Diagnóstico
| Síntoma | Comprobar |
|---|---|
| Nodo invisible | compatibilidad, advertising, permisos de escaneo del móvil |
| Conecta pero no muestra servicio | UUID, descubrimiento, caché GATT del cliente |
| Read funciona, notify no | suscripción, CCCD, conexión e intervalo |
| Escritura rechazada | propiedades, permisos, longitud y rango |
| Fallos con Wi-Fi | coexistencia de radio, carga de callbacks, heap y tamaño |

RSSI cambia con distancia, orientación y obstáculos. No es una medida precisa de distancia ni prueba de identidad.

## 9. Errores frecuentes
- Tratar BLE como un puerto serial universal.
- Enviar mensajes sin contrato ni límite.
- Confundir write confirmado con configuración persistida.
- Mantener abierta permanentemente la configuración de secretos.
- Bloquear callbacks o asumir que todas las familias son equivalentes.

## 10. Reto y autoevaluación
Diseña un nodo configurable desde dos móviles: determina quién puede cambiar parámetros, cómo resuelves cambios simultáneos y qué ocurre al perder conexión antes de recibir confirmación.

¿Advertising implica conexión? ¿Qué diferencia hay entre propiedad y permiso? ¿Cómo sabe el usuario qué valor quedó aplicado? ¿Qué conserva bonding?

## 11. Checklist
- [ ] Chip y biblioteca compatibles.
- [ ] UUID y contrato documentados.
- [ ] Suscripción comprobada.
- [ ] Escrituras limitadas y validadas.
- [ ] Estado aplicado observable.
- [ ] Reconexión y autorización comprobadas.

## Referencias oficiales
- [BLE en Arduino-ESP32](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/ble.html).
- [API Bluetooth de ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/bluetooth/index.html).

[Anterior: arquitectura IoT](../unidad13-arquitectura-iot/) · [Siguiente: almacenamiento](../unidad15-almacenamiento/) · [Índice](../README.md)
