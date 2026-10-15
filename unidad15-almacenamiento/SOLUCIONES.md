# Soluciones desarrolladas de la Unidad 15

[Laboratorio](LABORATORIO.md) · [Desarrollo paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta los ejercicios antes de comparar. Identifica qué condición explica cada resultado y qué parte del sistema fue comprobada.

## 1. Namespace diferente

Consulta otro espacio y puede devolver el predeterminado cero porque allí no existe la clave. No demuestra que se haya borrado el namespace curso.

## 2. Reiniciar una clave

Con begin del mismo namespace en modo escritura, usa remove sobre arranques y comprueba retorno. No borres todo el espacio si solo quieres reiniciar el contador. Después la primera lectura vuelve al valor predeterminado.

## 3. NVS no ilimitada

Tiene capacidad finita, costos de escritura y comportamiento de flash. Una cola necesita política de ocupación, pérdida y recuperación; guardar un número no implementa esa estructura.

## Evidencia de la práctica

Registra predicción, modificación exacta, resultado y condiciones en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue dato simulado, prueba de servicio y montaje físico. No incluyas credenciales privadas.
