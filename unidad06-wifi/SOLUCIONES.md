# Soluciones desarrolladas de la Unidad 06

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. Wi-Fi e Internet

WL_CONNECTED e IP local describen el enlace de red. La salida a Internet y la disponibilidad de un servicio requieren comprobaciones adicionales. Un servidor local puede funcionar aunque no exista acceso externo.

## 2. Clave incorrecta

Se esperan fallos de enlace y continuidad de la tarea local. Registra estados y tiempos sin imprimir la clave. Si el programa se reinicia, investiga ese síntoma por separado.

## 3. Reintento cada 30 s

Cambia el umbral 15000 del header a 30000 en una copia y compara las solicitudes manuales. La reconexión automática del core sigue habilitada: no prometas un único intento exacto cada 30 s. Modificar 2000 en el sketch afecta mensajes, no el intervalo manual de red.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
