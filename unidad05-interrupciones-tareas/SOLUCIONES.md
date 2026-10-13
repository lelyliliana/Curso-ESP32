# Soluciones razonadas del laboratorio 05

[Volver al laboratorio](LABORATORIO.md)

1. La ISR debe ser breve y evitar operaciones que bloquean.
2. Acepta una entrada estable tras el intervalo, sin delay en ISR.
3. La ISR responde a hardware; una tarea tiene planificación propia.

## Qué entregar

Explica la predicción, conserva la entrada o modificación exacta y compara resultado esperado y observado. Para hardware registra GPIO y alimentación; para red registra códigos/estado sin credenciales. Cuando un experimento dependa del ambiente, una respuesta textual no sustituye la medición.

## Criterio de avance

Flancos puede superar pulsaciones por rebote. La salida serial se realiza en loop, no en la ISR.

## Límite que debes poder explicar

No promete un contador de pulsaciones sin rebotes; FreeRTOS multitararea es ampliación de GUIA.md.

Un fallo detectado y explicado tiene valor formativo; no lo conviertas en éxito por cambiar el objetivo después de ejecutar. Para el proyecto conserva también intentos, pérdidas y condiciones que no pudiste reproducir.

## Tareas y cola

Bloquear el consumidor3s permite llenar la cola de4 elementos. La tarea espera hasta100ms por espacio y luego omite el envío; los huecos deben interpretarse como política de saturación del ejemplo. Copiar por cola no requiere leer una variable compartida sin protección. Restaura el consumidor rápido antes de continuar.
