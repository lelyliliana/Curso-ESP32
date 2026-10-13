# Soluciones razonadas del laboratorio 22

[Volver al laboratorio](LABORATORIO.md)

1. No: reporta software_output, sin sensor de realimentación.
2. Podría renovarse al reconectar; nunca publiques retained en command.
3. Mide y documenta; si necesitas garantía estricta utiliza protección independiente.

## Qué entregar

Explica la predicción, conserva la entrada o modificación exacta y compara resultado esperado y observado. Para hardware registra GPIO y alimentación; para red registra códigos/estado sin credenciales. Cuando un experimento dependa del ambiente, una respuesta textual no sustituye la medición.

## Criterio de avance

El mando local bloquea ON y mantiene OFF. Tras liberar se requiere nuevo comando; vencimiento vuelve OFF.

## Límite que debes poder explicar

No incluye command_id/expiración UTC ni registro de autoridad por emisor; son extensiones del proyecto, no promesas.

Un fallo detectado y explicado tiene valor formativo; no lo conviertas en éxito por cambiar el objetivo después de ejecutar. Para el proyecto conserva también intentos, pérdidas y condiciones que no pudiste reproducir.
