# Estrategia de almacenamiento

| Dato | Medio | Frecuencia de escritura | Capacidad | Recuperación |
|---|---|---|---|---|
| Lectura actual | RAM | ninguna en flash | una lectura | volver a medir |
| Umbral | NVS | solo cambios aceptados | un parámetro | validar o usar defecto |
| Configuración relacionada | registro versionado | cambios agrupados | dos generaciones si aplica | seleccionar copia válida |
| Telemetría pendiente | almacenamiento acotado | según muestreo/agrupación | límite explícito | recuperar registros completos |
| Secretos | almacenamiento protegido según amenaza | provisioning/rotación | por dispositivo | revocar y reprovisionar |

## Configuración
- Esquema y versión:
- Tipos, unidades y rangos:
- Valores por defecto seguros:
- Estado ante lectura o escritura fallida:
- Garantías de atomicidad del medio:
- Migración de esquema y compatibilidad al volver de versión:
- Tratamiento de un esquema desconocido, sin sobrescribirlo:

## Integridad y mantenimiento
- Detección de corrupción accidental:
- Autenticidad cuando se requiere:
- Límite de escrituras y agrupación:
- Política ante espacio lleno:
- Diagnóstico sin secretos:
- Restablecimiento explícito: qué borra y qué conserva:

## Prueba
Documenta reinicio normal, valor inválido, tipo incorrecto, falta de espacio y corte durante escritura. No interpretes “clave presente” como “configuración válida”.

[Volver a la unidad](README.md)
