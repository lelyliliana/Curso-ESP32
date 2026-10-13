# Laboratorios progresivos ESP32

[Entorno y montaje](../docs/ENTORNO.md) · [Servicios HTTP/MQTT](servicios/README.md) · [Registro de evidencias](../docs/EVIDENCIAS.md) · [Volver al curso](../README.md)

Cada unidad contiene un sketch independiente: se abre en Arduino IDE por el archivo cuyo nombre coincide con la carpeta. Sigue los pasos de su laboratorio y consulta las soluciones después de intentar. No necesitas usar 24 dispositivos ni montar todos los periféricos a la vez.

|Unidad|Laboratorio|Comprobación|
|---|---|---|
|00|[preparacion](../unidad00-preparacion/LABORATORIO.md)|[Soluciones](../unidad00-preparacion/SOLUCIONES.md)|
|01|[arquitectura-gpio](../unidad01-arquitectura-gpio/LABORATORIO.md)|[Soluciones](../unidad01-arquitectura-gpio/SOLUCIONES.md)|
|02|[primer-programa](../unidad02-primer-programa/LABORATORIO.md)|[Soluciones](../unidad02-primer-programa/SOLUCIONES.md)|
|03|[io-adc-pwm](../unidad03-io-adc-pwm/LABORATORIO.md)|[Soluciones](../unidad03-io-adc-pwm/SOLUCIONES.md)|
|04|[sensores-buses](../unidad04-sensores-buses/LABORATORIO.md)|[Soluciones](../unidad04-sensores-buses/SOLUCIONES.md)|
|05|[interrupciones-tareas](../unidad05-interrupciones-tareas/LABORATORIO.md)|[Soluciones](../unidad05-interrupciones-tareas/SOLUCIONES.md)|
|06|[wifi](../unidad06-wifi/LABORATORIO.md)|[Soluciones](../unidad06-wifi/SOLUCIONES.md)|
|07|[cliente-http](../unidad07-cliente-http/LABORATORIO.md)|[Soluciones](../unidad07-cliente-http/SOLUCIONES.md)|
|08|[servidor-web](../unidad08-servidor-web/LABORATORIO.md)|[Soluciones](../unidad08-servidor-web/SOLUCIONES.md)|
|09|[api-rest](../unidad09-api-rest/LABORATORIO.md)|[Soluciones](../unidad09-api-rest/SOLUCIONES.md)|
|10|[mqtt](../unidad10-mqtt/LABORATORIO.md)|[Soluciones](../unidad10-mqtt/SOLUCIONES.md)|
|11|[telemetria-control](../unidad11-telemetria-control/LABORATORIO.md)|[Soluciones](../unidad11-telemetria-control/SOLUCIONES.md)|
|12|[json-mensajes](../unidad12-json-mensajes/LABORATORIO.md)|[Soluciones](../unidad12-json-mensajes/SOLUCIONES.md)|
|13|[arquitectura-iot](../unidad13-arquitectura-iot/LABORATORIO.md)|[Soluciones](../unidad13-arquitectura-iot/SOLUCIONES.md)|
|14|[ble](../unidad14-ble/LABORATORIO.md)|[Soluciones](../unidad14-ble/SOLUCIONES.md)|
|15|[almacenamiento](../unidad15-almacenamiento/LABORATORIO.md)|[Soluciones](../unidad15-almacenamiento/SOLUCIONES.md)|
|16|[registro-sincronizacion](../unidad16-registro-sincronizacion/LABORATORIO.md)|[Soluciones](../unidad16-registro-sincronizacion/SOLUCIONES.md)|
|17|[fallos-reconexion](../unidad17-fallos-reconexion/LABORATORIO.md)|[Soluciones](../unidad17-fallos-reconexion/SOLUCIONES.md)|
|18|[seguridad](../unidad18-seguridad/LABORATORIO.md)|[Soluciones](../unidad18-seguridad/SOLUCIONES.md)|
|19|[ota](../unidad19-ota/LABORATORIO.md)|[Soluciones](../unidad19-ota/SOLUCIONES.md)|
|20|[energia](../unidad20-energia/LABORATORIO.md)|[Soluciones](../unidad20-energia/SOLUCIONES.md)|
|21|[proyecto-nodo-iot](../unidad21-proyecto-nodo-iot/LABORATORIO.md)|[Soluciones](../unidad21-proyecto-nodo-iot/SOLUCIONES.md)|
|22|[proyecto-control](../unidad22-proyecto-control/LABORATORIO.md)|[Soluciones](../unidad22-proyecto-control/SOLUCIONES.md)|
|23|[proyecto-final](../unidad23-proyecto-final/LABORATORIO.md)|[Soluciones](../unidad23-proyecto-final/SOLUCIONES.md)|

Las unidades12,13 y17 permiten aprender sin servicios de red;13 y17 son simulaciones declaradas.18 requiere CA/endpoint autorizado,19 una placa con particiones OTA y20 verificación energética propia. Las bases21–23 no prometen funciones avanzadas que no implementan: conserva los límites y la rúbrica del proyecto.

## Navegación y resultados

El sketch de cada unidad se registra en catalogo.json. scripts/compilar.py comprueba compilación; no carga ni controla dispositivos. docs/VERIFICACION.md registra verificaciones realizadas y casos físicos pendientes.
