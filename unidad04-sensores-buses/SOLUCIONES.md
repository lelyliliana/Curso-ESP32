# Soluciones desarrolladas de la Unidad 04

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. Escaneo

ACK informa que hubo respuesta en una dirección. No sustituye lectura de datos, comprobación CRC ni identificación de modelo. Separa esas evidencias en el informe.

## 2. Dirección 0x45

Cambia SENSOR solo si ADDR y el módulo real están configurados para ella. Cambiar una constante al azar no mueve eléctricamente la dirección del dispositivo.

## 3. Respuesta incompleta

El programa informa Lectura incompleta y retorna sin convertir. No rellena los bytes faltantes con cero ni publica una temperatura inventada. En la siguiente oportunidad intenta otro ciclo.

## Contraste con SPI

Con puente 23→19 se espera recibir A5. Eso no confirma SHT31 ni un sensor SPI real. La práctica I2C y el retorno SPI deben registrarse como ensayos distintos.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
