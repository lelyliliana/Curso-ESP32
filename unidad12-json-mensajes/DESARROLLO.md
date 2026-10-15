# Validar el significado de un documento JSON

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [contrato_json](ejemplos/contrato_json/contrato_json.ino). Abre el código completo mientras sigues el recorrido.

## 1. JSON correcto no significa dato aceptable

El programa no usa red ni sensor: prueba cuatro textos controlados en setup. Esto permite estudiar contrato sin mezclar fallos de transporte. El primer texto tiene nodo01 y temperatura numérica 23.5; los otros introducen un tipo incorrecto, un valor fuera de rango y sintaxis incompleta.

| Entrada | Sintaxis | Contrato esperado |
|---|---|---|
| nodo01 y 23.5 numérico | Válida | Aceptado |
| nodo01 y "23.5" como cadena | Válida | Rechazado |
| nodo01 y 999 | Válida | Rechazado por rango |
| Llave sin completar | Inválida | Rechazado antes de interpretar datos |

El JSON transmitido debe conservar comillas de claves y cadenas. En código C++, las comillas internas se escapan para que pertenezcan al texto, no para enviar caracteres adicionales al receptor.

## 2. Sigue el orden de comprobación

Primero deserializeJson intenta construir el documento. Después exige objeto, dos campos, nodo de texto con valor nodo01 y temperatura compatible con número. Solo si todo eso pasa obtiene t y comprueba que sea finita y esté entre -40 y 125.

El orden evita usar un valor convertido por defecto para un campo ausente. Convertir automáticamente "23.5" también podría ocultar un productor que dejó de respetar su contrato. Validar exige decidir qué se acepta, no solo conseguir una conversión posible.

## 3. Unidades y procedencia

La clave temperatura_c declara Celsius. El rango ayuda a detectar datos incompatibles, pero no mide calibración ni conexión del sensor. Un valor ficticio de 23.5 también pasa. Debes conservar procedencia en otro campo o contexto cuando compares fuentes reales y simuladas.

El contrato de esta unidad tiene exactamente dos campos. No es el mismo del nodo ambiental posterior, que incluye humedad y uptime. Los ejemplos responden a objetivos distintos; no envíes el payload de una unidad al validador de otra suponiendo compatibilidad automática.

## 4. Versiona con cambios en ambos extremos

Para añadir schema_version=1 hay que modificar documento, cantidad de campos exigida, validación de tipo/valor y pruebas de rechazo. Si añades solo el campo al emisor, el validador actual lo rechazará por exceso de campos. Elige explícitamente si convivirán dos versiones o si ambos extremos se actualizarán juntos.

## 5. Ensayo por una diferencia

En una copia cambia nodo01 por otro nodo y predice rechazo. Restaura y elimina la temperatura; vuelve a comparar. Finalmente añade un campo extra. Cada prueba debe explicar qué condición falla primero. Leer ACEPTADO no es demostrar precisión: solo demuestra que ese texto cumplió este contrato.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las soluciones](SOLUCIONES.md) · [Volver a la unidad](README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2012%20%E2%80%94%20Dise%C3%B1o%20de%20mensajes%20y%20JSON%20del%20curso%20ESP32%20e%20Internet%20de%20las%20Cosas%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-ESP32%2Ftree%2Fmain%2Funidad12-json-mensajes%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
