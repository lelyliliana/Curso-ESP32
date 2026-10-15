# Construir una arquitectura sin atribuir capacidades simuladas

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [arquitectura_estado](ejemplos/arquitectura_estado/arquitectura_estado.ino). Abre el código completo mientras sigues el recorrido.


**Apoyo para este recorrido:** [protocolos y estados](../docs/RECORRIDOS_PROTOCOLOS.md).

## 1. Lee la advertencia como parte del contrato

El programa imprime Lectura SIMULADA=24 C y no incluye WiFi, Wire ni MQTT. Su finalidad es representar disponibilidad de transporte mientras continúa un trabajo local. Un mensaje disponible no demuestra que un broker esté conectado: lo controla una variable cambiada desde Serial.

Las entradas e y f asignan enlace verdadero o falso. El estado enum class da nombres legibles, pero sus etiquetas no crean los servicios que describen.

## 2. Sigue la evolución temporal

| Suceso | enlace | Estado cuando vence el segundo |
|---|---|---|
| Arranque | false | Pasa de LOCAL a DEGRADADO |
| Carácter e | true | ENLAZADO |
| Carácter f | false | DEGRADADO |
| Sin cambio de entrada | Conserva valor | Repite estado correspondiente |

LOCAL es el valor inicial. La referencia no lo mantiene como un modo autónomo posterior: la asignación periódica elige solo ENLAZADO o DEGRADADO. Si quieres tres estados de operación reales, debes definir condiciones y transiciones para los tres.

## 3. Dos dimensiones no siempre caben en una etiqueta

Disponibilidad de sensor y disponibilidad de transporte son independientes. Puedes tener sensor válido sin red, o red disponible con sensor inválido. Una sola variable enlazado no describe ambas cosas.

Para una extensión, define dos indicadores: calidad de adquisición y disponibilidad de transporte. Construye una tabla de cuatro combinaciones y qué se representa en cada una. Si el dato es inválido, no publiques 24 C como sustitución silenciosa. Un valor simulado debe seguir identificado como tal.

## 4. Ubica componentes en un proyecto concreto

En el nodo de la Unidad 21, Wire y SHT31 adquieren; las fórmulas convierten; ArduinoJson representa; PubSubClient solicita publicación; el broker distribuye y un suscriptor observa. La lectura local puede existir sin que haya publicación exitosa. Una base de datos requiere un consumidor que la guarde; el tópico no la añade automáticamente.

## 5. Convierte un diagrama en una prueba

Dibuja cada responsabilidad y nombra la evidencia que la comprueba. Para adquisición: trama y CRC; para representación: JSON; para transporte: conexión y resultado de publicación; para consumo: recepción por otro cliente. Solo cuando implementes y ejecutes cada componente podrás afirmar una arquitectura completa.

El ejercicio de arquitectura sirve para decidir dónde actuar ante fallos. Una caída del broker no se arregla cambiando el cable SDA; un CRC inválido no se soluciona aumentando el periodo de reconexión Wi-Fi.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las soluciones](SOLUCIONES.md) · [Volver a la unidad](README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2013%20%E2%80%94%20Arquitectura%20de%20un%20sistema%20IoT%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad13-arquitectura-iot%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
