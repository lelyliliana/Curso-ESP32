# Plantilla — Presupuesto energético

## Montaje y medición
- Chip/placa, core y firmware:
- Fuente, batería, tensión y capacidad útil:
- Punto de medición (batería o carga):
- Instrumento, rango y capacidad de observar picos:
- Regulador, LED, USB y sensores alimentados:
- Temperatura y condiciones de red:

## Fases sin solapamiento
| Fase | Corriente (mA) | Duración (s) | I × t (mA·s) | Medida o estimada |
|---|---:|---:|---:|---|
| Arranque/recuperación | | | | |
| Estabilización/medición | | | | |
| Persistencia | | | | |
| Conexión/transmisión | | | | |
| Preparación de sueño | | | | |
| Sueño | | | | |
| Total | | | | |

- Tiempo del ciclo = suma de duraciones:
- Corriente promedio = suma de I × t / tiempo del ciclo:
- Capacidad útil medida/estimada y margen:
- Autonomía aproximada = mAh útiles / mA promedio:
- Si cambian tensiones: cálculo en Wh y eficiencia:
- Pico de corriente y capacidad de la fuente:

## Políticas
- Frecuencia de medición y transmisión:
- Presupuesto máximo de conexión:
- Comportamiento sin servicio:
- Persistencia/cola antes de dormir:
- Configuración de despertar compatible con chip:
- Estado de salidas y periféricos:
- Recuperación tras corte de energía:
- Restricción durante OTA/autoprueba:

## Comparación
| Escenario | Tiempo activo | Consumo medio | Pendientes / pérdidas | Observación |
|---|---:|---:|---|---|
| Red disponible | | | | |
| Red caída | | | | |
| Backlog al reconectar | | | | |
| Sensor en estabilización | | | | |

La autonomía calculada es una estimación con supuestos. Valídala en el sistema completo; no uses consumo del chip como si fuera consumo de la placa.

[Volver a la unidad](README.md)
