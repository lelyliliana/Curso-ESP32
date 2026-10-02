# Plantilla — Proyecto final ESP32/IoT

## 1. Problema y usuario
- Necesidad concreta y usuario:
- Evidencia del problema:
- Objetivo verificable:
- Función local y función remota:

## 2. Alcance y requisitos
| Requisito | Criterio medible | Estado (diseñado/implementado/simulado/probado) | Evidencia |
|---|---|---|---|
| Función principal | | | |
| Tiempo de respuesta / edad de datos | | | |
| Operación degradada | | | |
| Recuperación | | | |
| Seguridad | | | |
| Energía / mantenimiento | | | |

- Exclusiones y razón:
- Casos no aplicables y justificación:

## 3. Arquitectura de extremo a extremo
- Diagrama de telemetría:
- Diagrama de comandos/resultados, si aplica:
- Responsabilidades del nodo y del servicio:
- Decisiones edge/servicio:
- Dependencias externas y sus fallos:

## 4. Hardware y entorno
- Chip/placa y documentación oficial:
- Sensores, interfaces, unidades y tiempo de estabilización:
- Actuadores, driver y realimentación:
- Alimentación, tensión, corriente y picos:
- Core/SDK, bibliotecas, herramientas y particiones:

| GPIO | Función | Tensión / nivel activo | Restricción verificada | Estado al arrancar |
|---|---|---|---|---|
| | | | | |

## 5. Conectividad y protocolos
- Wi-Fi/BLE y razón:
- HTTP/MQTT/otro y razón:
- Topics/endpoints y métodos:
- Timeout, backoff, jitter y periodo estable:
- Duración máxima observada de llamadas:
- Función que continúa sin red:

## 6. Contratos y tiempo
- Versión, campos, tipos, unidades, rangos y tamaño:
- device_id, record_id / command_id:
- ID estable y política tras reinicio:
- Calidad de medición y lectura inválida:
- Hora UTC, calidad temporal y reloj desconocido:
- Orden, duplicados, vigencia y concurrencia:
- ACK de aplicación y resultado físico/software:

## 7. Persistencia y funcionamiento offline
- Clasificación RAM/configuración/historial:
- Tipos, versiones, valores seguros y migración:
- Capacidad en registros y bytes:
- Duración offline objetivo:
- Persistencia antes de envío:
- Deduplicación remota y confirmación durable:
- Política de cola llena y cuarentena:
- Recuperación de escritura incompleta/compactación:
- Pérdida posible y cómo se cuenta:

## 8. Estados y control
- Estados independientes por capa:
- Estado global derivado:
- Prioridad local/remota:
- Salida segura durante reset, desconexión y sueño:
- Datos caducados y pérdida de supervisión:
- Límites de seguridad locales:
- Reconciliación después de reinicio:

## 9. Seguridad
| Activo | Amenaza | Impacto | Control | Prueba |
|---|---|---|---|---|
| | | | | |

- Provisioning, credenciales por nodo y revocación:
- Secretos fuera de Git/capturas/logs:
- Transporte y validación de identidad:
- Autorización por operación/topic:
- Validación, repetición y límites de peticiones:
- Servicios expuestos:
- Acceso físico, datos y retención:

## 10. Actualización y energía
- Método de actualización y justificación:
- OTA implementada/diseñada/no requerida y razón:
- Autenticidad, particiones, autoprueba y recuperación:
- Compatibilidad de datos con vuelta de versión:
- Alimentación y consumo medido/estimado:
- Modo de operación y tiempo activo:
- Presupuesto máximo de conexión:
- Decisión sobre deep sleep y disponibilidad:
- Punto de medición, unidades y supuestos de autonomía:

## 11. Observabilidad
- Versión, uptime/reset/despertar:
- Último éxito por capa y estado:
- Edad/calidad de datos:
- Backlog, rechazos, descartes y reintentos:
- Estado de comando / actualización:
- Logs sin secretos:

## 12. Plan y resultados de pruebas
| Caso | Versión / condiciones | Estímulo y duración | Esperado medible | Obtenido | Evidencia |
|---|---|---|---|---|---|
| Hardware/local | | | | | |
| Normal conectado | | | | | |
| Sin Wi-Fi | | | | | |
| Sin servicio | | | | | |
| Sensor inválido, si aplica | | | | | |
| Mensaje inválido/no autorizado | | | | | |
| Duplicado / confirmación perdida | | | | | |
| Reinicio | | | | | |
| Cola llena, si aplica | | | | | |
| Recuperación | | | | | |
| Fallos simultáneos | | | | | |
| Energía / mantenimiento | | | | | |

## 13. Análisis y limitaciones
- Criterios cumplidos/incumplidos:
- Conteos de datos y pérdidas:
- Peor latencia observada y recuperación:
- Pruebas físicas, simuladas y pendientes:
- Límites de sensor/red/almacenamiento/seguridad:
- Conclusiones respaldadas por evidencia:

## 14. Reproducibilidad y autoría
- Repositorio y commit:
- Montaje y dependencias:
- Configuración sin secretos:
- Compilación, carga, servicio y ejecución:
- Cómo repetir una prueba normal y una de fallo:
- Demostración y resultados:
- Contribuciones:
- Uso de IA y verificaciones:
- Fuentes, autoría y licencias:

[Guía](README.md) · [Checklist](CHECKLIST.md) · [Rúbrica](RUBRICA.md)
