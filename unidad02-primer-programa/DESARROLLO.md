# Reconocer un dispositivo vivo y un reinicio

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [latido](ejemplos/latido/latido.ino). Abre el código completo mientras sigues el recorrido.

## 1. Qué significa un latido

Un mensaje periódico permite observar que el programa recorre una tarea. No demuestra que todos los sensores, red o actuadores funcionen. Aquí solo informa contador y tiempo desde arranque.

`ultimo` conserva cuándo se imprimió; `contador` cuántas veces se cumplió la condición. Son variables globales `uint32_t`, enteros sin signo de 32 bits. Al reiniciar vuelven al valor inicial porque no se guardan en almacenamiento persistente.

## 2. Sigue la primera ejecución

| Tiempo aproximado | contador después de ++ | Mensaje |
|---:|---:|---|
| Arranque | 0 | Todavía ninguno periódico |
| 1000 ms | 1 | latido 1 |
| 2000 ms | 2 | latido 2 |
| 3000 ms | 3 | latido 3 |

`++contador` incrementa antes de usar el valor en printf. `%u` representa entero sin signo. El tiempo mostrado proviene de una consulta a millis próxima a la decisión, no de un instrumento externo.

## 3. Reconoce la continuidad de loop

La condición permite recorrer loop muchas veces antes de imprimir. No hay un delay de un segundo dentro de esa tarea. La resta sin signo sirve para comprobar intervalos a través del retorno del reloj a cero si se conserva el patrón y se atiende con suficiente frecuencia.

`ultimo = millis()` programa desde el momento observado. Si una operación retrasa el recorrido, no recupera automáticamente todos los mensajes que habrían correspondido. Periodicidad nominal y exactitud física son propiedades distintas.

## 4. Añade una tarea independiente

En una copia declara otra marca, inicialmente cero. Evalúa en otro `if` si pasaron 3000 ms y actualiza solo esa marca antes de imprimir su mensaje. No uses `else`: a los 3000 ms nominales podrían corresponder ambos trabajos. Tampoco actualices la marca del latido al atender la tarea nueva.

Primero predice diez segundos de mensajes. Después observa y reinicia. El primer contador vuelve a uno después de la primera espera; conservar el número anterior requeriría persistencia explícita, como en la Unidad 15.

## 5. Diagnostica por tendencias

Un salto o retraso no basta para localizar su causa. Registra las marcas y si hubo cambio de firmware, apertura del monitor o RESET. Un contador que vuelve a valores bajos acompañado por un uptime pequeño sugiere un nuevo arranque. Investiga la causa antes de atribuirla a la red, que este programa ni siquiera utiliza.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las soluciones](SOLUCIONES.md) · [Volver a la unidad](README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2002%20%E2%80%94%20Primer%20programa%20y%20diagn%C3%B3stico%20serial%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad02-primer-programa%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
