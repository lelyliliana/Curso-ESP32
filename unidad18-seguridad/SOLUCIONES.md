# Soluciones desarrolladas de la Unidad 18

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. Clave MQTT de Unidad 10

No viaja protegida por TLS en ese ejemplo. El transporte WiFiClient y puerto 1883 no incorporan cifrado TLS; el usuario/contraseña del broker cumplen otra función.

## 2. CA válida

Una cadena aceptada, hostname coincidente y fechas válidas apoyan la identidad del servidor conforme a la confianza configurada. No prueban autorización del dispositivo ni exactitud de una medición.

## 3. setInsecure

Desactiva verificaciones que la práctica intenta comprobar. La respuesta podría llegar, pero dejarías de demostrar confianza en el servidor. Revisa reloj, cadena y hostname antes de cambiar el objetivo del ensayo.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
