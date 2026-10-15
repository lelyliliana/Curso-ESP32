# Guardar una configuración con límites de escritura

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [preferencias](ejemplos/preferencias/preferencias.ino). Abre el código completo mientras sigues el recorrido.

## 1. RAM y NVS conservan cosas diferentes

La variable visitas existe en el programa, pero se obtiene desde NVS mediante Preferences. NVS es almacenamiento no volátil en flash. Puede sobrevivir a reinicios conservando la partición; no equivale a memoria ilimitada ni garantiza supervivencia a un borrado de flash.

`prefs.begin("curso", false)` abre un namespace con escritura habilitada. Ese espacio de nombres separa claves de otras partes de la aplicación. La clave arranques se lee con getUInt y valor predeterminado cero si no existe.

## 2. Sigue dos arranques

| Arranque | Valor leído | Valor solicitado para guardar | Texto anterior |
|---|---:|---:|---:|
| Primero sin clave | 0 | 1 | 0 |
| Segundo con escritura previa correcta | 1 | 2 | 1 |
| Tercero | 2 | 3 | 2 |

La impresión dice Arranque anterior. No es una diferencia de uno accidental: se representa el valor leído antes de incrementar. La referencia comprueba que putUInt devolvió cuatro bytes, acorde al tipo usado.

## 3. No continúes ocultando un fallo

Si abrir NVS falla, setup informa NVS fallo y retorna. El loop solo espera; no hay una cola alternativa oculta. Si la escritura no devuelve cuatro, el texto anuncia FALLO. Que aparezca un contador leído no demuestra que el siguiente valor haya quedado persistido.

`prefs.end` cierra el acceso de esa instancia. No borra la clave. Una nueva llamada begin puede volver a abrir el namespace.

## 4. Escribe cuando cambie el requisito

El ejemplo guarda una vez por arranque, no en cada vuelta de loop. Escribir continuamente un valor sin cambios consume recursos y añade desgaste innecesario. Para una configuración modificable, guarda después de validar un cambio y define cómo informar error.

El contador uint32_t tiene un rango finito. En un sistema de identidad no puedes reciclar números silenciosamente al desbordar; necesitarías política adicional. Aquí se estudia persistencia, no unicidad eterna.

## 5. Borra solo lo que quieres borrar

Para reiniciar esta clave en una copia, abre el mismo namespace con escritura y elimina arranques con remove; comprueba su resultado y reinicia. No uses clear si solo quieres una clave: afectaría todas las de ese namespace. Cambiar el namespace no borra el anterior; simplemente consulta otro espacio.

Registra cuál operación realizaste cuando compares reinicios. Reprogramar con opciones de borrado de flash puede producir un resultado distinto de pulsar RESET.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las soluciones](SOLUCIONES.md) · [Volver a la unidad](README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2015%20%E2%80%94%20Almacenamiento%20y%20configuraci%C3%B3n%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad15-almacenamiento%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
