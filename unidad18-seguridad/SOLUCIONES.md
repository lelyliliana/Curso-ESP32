# Soluciones razonadas del laboratorio 18

[Volver al laboratorio](LABORATORIO.md)

1. No: son transportes distintos.
2. Cadena/identidad del servidor bajo esa confianza, no corrección de contenido.
3. Eliminaría verificación y ocultaría un fallo de seguridad.

## Qué entregar

Explica la predicción, conserva la entrada o modificación exacta y compara resultado esperado y observado. Para hardware registra GPIO y alimentación; para red registra códigos/estado sin credenciales. Cuando un experimento dependa del ambiente, una respuesta textual no sustituye la medición.

## Criterio de avance

Sin CA no envía; CA incorrecta falla; correcta puede responder HTTP según contrato del endpoint.

## Límite que debes poder explicar

Requiere endpoint propio y hora NTP; no simula éxito TLS ni da una CA universal.

Un fallo detectado y explicado tiene valor formativo; no lo conviertas en éxito por cambiar el objetivo después de ejecutar. Para el proyecto conserva también intentos, pérdidas y condiciones que no pudiste reproducir.
