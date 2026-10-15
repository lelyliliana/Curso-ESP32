# Soluciones desarrolladas de la Unidad 00

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. Flash frente a ficha

Compara capacidad en las mismas unidades. Si el programa informa 4194304 bytes, equivale a 4 MiB. Una diferencia exige revisar modelo real, configuración y consulta; no se corrige cambiando la etiqueta del resultado.

## 2. Selección de placa

Cambia el modo de compilar y cargar. No añade núcleos, BLE ni memoria al chip. La identidad física debe comprobarse antes de elegir el perfil.

## 3. Monitor sin salida

Registra placa, cable, puerto, perfil, core, velocidad y mensajes de carga. Abre a 115200 y reinicia para repetir setup. La referencia no imprime periódicamente; esperar indefinidamente sin reiniciar no recupera un encabezado ya enviado.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
