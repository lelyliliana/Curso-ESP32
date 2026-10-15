# Dar tiempo a recuperarse sin reintentar sin límite

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [backoff](ejemplos/backoff/backoff.ino). Abre el código completo mientras sigues el recorrido.


**Apoyo para este recorrido:** [protocolos y estados](../docs/RECORRIDOS_PROTOCOLOS.md).

## 1. Empieza por una simulación explícita

Este sketch no abre Wi-Fi ni llama un servidor. Simula intentos fallidos para que puedas seguir una política temporal con Serial. La variable habilitado comienza true; por eso hay intentos sin que primero tengas que escribir f.

Espera comienza en 1000 ms. Después de cada fallo simulado se duplica hasta 16000. El máximo limita el intervalo, no la cantidad total de intentos.

## 2. Deriva la línea temporal

| Intento | Intervalo que aparece en el mensaje | Instante nominal desde inicio |
|---:|---:|---:|
| 1 | 1000 ms | 1000 ms |
| 2 | 2000 ms | 3000 ms |
| 3 | 4000 ms | 7000 ms |
| 4 | 8000 ms | 15000 ms |
| 5 | 16000 ms | 31000 ms |
| 6 | 16000 ms | 47000 ms |

El mensaje imprime el intervalo utilizado antes de duplicarlo. Confundir intervalo con tiempo acumulado produciría predicciones equivocadas.

## 3. Recuperación y nuevo fallo

El carácter r fija espera=1000, intentos=0 y habilitado=false. Detiene intentos hasta una nueva f. El carácter f habilita y toma una marca temporal nueva, pero no reinicia por sí mismo espera ni intentos. Si envías f después de un fallo prolongado sin pasar por r, conserva el intervalo escalado.

Una repetición de f también puede aplazar el siguiente intento al cambiar ultimo. Registra las teclas y tiempos si comparas el comportamiento con la tabla inicial.

## 4. Backoff y timeout resuelven problemas distintos

Backoff decide cuándo volver a empezar una operación. Timeout limita cuánto espera una operación que ya comenzó. Retrasar reintentos no impide que una petición individual bloquee demasiado. En una integración real necesitarías ambas políticas y atención de trabajos locales.

Muchos dispositivos reiniciados juntos pueden repetir el mismo patrón sincronizado. Un jitter acotado introduce variación entre intentos. La referencia todavía no lo implementa.

## 5. Diseña jitter sin superar el máximo

Una propuesta es calcular espera base duplicada con máximo 16000 y seleccionar el retraso real entre la mitad y el total de esa base. Así se conserva un límite superior sin sumarle aleatoriamente otros segundos por encima. Define también mínimo y fuente de aleatoriedad.

Predice rangos de tiempo y comprueba que ninguna muestra los exceda. Probar un generador de retardos no demuestra recuperación de un broker: la operación real y su resultado deben incorporarse después.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las soluciones](SOLUCIONES.md) · [Volver a la unidad](README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2017%20%E2%80%94%20Manejo%20de%20fallos%20y%20reconexi%C3%B3n%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad17-fallos-reconexion%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
