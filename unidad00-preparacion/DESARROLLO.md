# Identificar la placa antes de trasladar un programa

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [identidad](ejemplos/identidad/identidad.ino). Abre el código completo mientras sigues el recorrido.

## 1. Tres nombres que no significan lo mismo

ESP32 puede nombrar una familia, un chip, un módulo o una tarjeta de desarrollo. El módulo ESP32-WROOM-32 integra componentes alrededor de un chip clásico; la tarjeta añade alimentación, conexión USB y acceso a terminales. Seleccionar ESP32 Dev Module en el IDE configura herramientas y opciones, pero no cambia el hardware conectado.

Comienza por el nombre impreso en módulo y tarjeta. Contrasta el pinout del fabricante y registra la referencia. No adaptes un programa para S3 o C3 sustituyendo únicamente el nombre de la placa: sus recursos y terminales pueden cambiar.

## 2. Qué consulta el programa

Después de abrir Serial a 115200, espera 500 ms e imprime modelo, revisión y número de núcleos. `ESP.getFlashChipSize()` consulta capacidad de flash y `ESP.getFreeHeap()` memoria dinámica disponible en ese momento. Flash y heap no son la misma memoria.

| Dato | Qué describe | Qué no demuestra |
|---|---|---|
| Modelo | Chip identificado por el entorno | Pinout físico completo de tu tarjeta |
| Revisión | Variante de silicio informada | Compatibilidad de todos los módulos |
| Flash | Capacidad de almacenamiento informada | Espacio libre de la aplicación o RAM |
| Heap libre | Memoria dinámica disponible ahora | Cantidad total de flash |

El número de bytes de flash puede convertirse a MiB dividiendo entre 1048576. No confundas MiB con millones decimales de bytes. El heap puede variar entre programas porque bibliotecas y tareas utilizan memoria.

## 3. setup y loop tienen comportamientos diferentes

El encabezado aparece en `setup`, una vez por arranque. `loop` solo espera un segundo y no repite esas consultas. Si abres tarde el monitor, puedes haber perdido el texto inicial. Reinicia la placa con el monitor preparado y observa. Si ves el encabezado repetirse sin solicitarlo, investiga reinicios; no atribuyas la repetición a la instrucción de espera del loop.

## 4. Un ensayo que aísla el entorno

Primero trabaja solo con USB de datos. Compila, carga y observa como comprobaciones distintas. Conserva perfil, core y monitor utilizados junto al encabezado. Si no hay salida, verifica cable de datos, puerto, velocidad, resultado de carga y momento de apertura antes de conectar un sensor.

No necesitas conocer Git para leer el curso. Descarga y extrae el ZIP; abre el sketch dentro de su carpeta. La carpeta y el `.ino` de referencia comparten nombre. Una copia completa conserva los headers locales que otros programas necesitarán.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las soluciones](SOLUCIONES.md) · [Volver a la unidad](README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2000%20%E2%80%94%20Preparaci%C3%B3n%2C%20seguridad%20y%20placa%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad00-preparacion%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
