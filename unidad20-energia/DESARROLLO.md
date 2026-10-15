# Medir un ciclo de sueño sin confundir corriente y energía

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [deep_sleep](ejemplos/deep_sleep/deep_sleep.ino). Abre el código completo mientras sigues el recorrido.

## 1. El despertar vuelve a comenzar setup

La referencia imprime causa de despertar y contador RTC, configura un temporizador de diez segundos y entra en deep sleep. No utiliza Wi-Fi en este ensayo. Después del despertar por temporizador vuelve a ejecutar setup; no continúa después de esp_deep_sleep_start como si solo hubiera esperado en una pausa.

`RTC_DATA_ATTR` coloca arranques en memoria RTC que puede conservarse bajo este tipo de sueño y configuración. No es la misma persistencia que NVS. Un corte de alimentación o un reinicio diferente puede alterar su conservación. Registra la causa reportada antes de interpretar el número.

## 2. Sigue el ciclo completo

| Fase | Trabajo de la referencia |
|---|---|
| Arranque/despertar | Inicializa Serial y espera 500 ms |
| Reporte | Incrementa contador RTC y envía mensajes |
| Preparación | Espera salida Serial y configura despertador |
| Deep sleep | Duerme aproximadamente diez segundos |
| Despertar | Repite setup con la causa correspondiente |

El ciclo total incluye fase activa y arranque. Por eso mensajes separados por más de diez segundos no contradicen una espera de sueño de diez. El reloj millis describe actividad del arranque actual, no una línea temporal global que incluya todos los sueños.

## 3. Conserva unidades al promediar

El ejercicio supone 100 mA durante 1 s y 1 mA durante 10 s. Primero suma carga: `100 × 1 + 1 × 10 = 110 mA·s`. Divide entre los once segundos: corriente media de 10 mA.

Eso no es energía. Para calcularla hace falta conocer tensión y dónde se mide. A tensión constante V, la carga es 0.110 coulomb y la energía del ciclo sería `0.110 × V` joules. Con tensión hipotética de 3.3 V serían 0.363 J. Son valores de un ejemplo, no mediciones de esta placa.

## 4. Chip y tarjeta no consumen lo mismo

Una tarjeta de desarrollo incluye regulador, conversor USB y LED, que pueden seguir consumiendo aunque el chip duerma. Una medición por USB representa el conjunto visto desde esa alimentación y puede incluir pérdidas de conversión. No compares directamente con un valor de ficha del chip aislado.

El instrumento debe resolver cambios temporales y no alterar de manera importante la alimentación. No modifiques a ciegas conexiones para medir corriente: identifica el recorrido y la instrumentación apropiada.

## 5. Integrar radio cambia el presupuesto

Si añades Wi-Fi, debes incluir asociación, publicación y fallos de conexión en la fase activa. Dormir pronto puede reducir tiempo disponible para recibir comandos; una política de control continuo y una de muestreo periódico pueden requerir arquitecturas distintas. No prometas autonomía calculando solo el sueño y omitiendo el trabajo que necesita el sistema.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las soluciones](SOLUCIONES.md) · [Volver a la unidad](README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2020%20%E2%80%94%20Consumo%20energ%C3%A9tico%20y%20deep%20sleep%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad20-energia%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
