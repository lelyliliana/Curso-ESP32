# Diseño de un servicio BLE

## Identificación
- Chip, placa, core y biblioteca:
- Nombre anunciado (sin secretos):
- UUID propio del servicio:
- Peripheral/central y servidor/cliente GATT:
- Máximo de clientes y política de autorización:

## Contrato
| Característica | UUID | Operaciones | Formato y unidad | Tamaño máximo | Permiso |
|---|---|---|---|---:|---|
| temperature | | read / notify | lectura + calidad + secuencia | | lectura autorizada |
| humidity | | read / notify | lectura + calidad | | lectura autorizada |
| threshold | | read / write | versión + ID + umbral | | configuración autorizada |
| status | | read / notify | ID + resultado + valor aplicado | | lectura autorizada |

Define codificación, orden de bytes si utilizas binario, rangos y representación de lectura inválida. Para UUID estándar cumple el formato estándar; para contratos propios asigna UUID propios.

## Flujo de escritura
- Validación y respuesta ante formato inválido:
- Cola de peticiones y rechazo cuando está llena:
- Cuándo se aplica y cuándo se persiste:
- Cómo se confirma al móvil:
- Qué hacer con una petición repetida:
- Qué hacer si el móvil se desconecta antes del resultado:

## Notificaciones
- Intervalo y condiciones:
- Suscripción/CCCD:
- MTU y fragmentación si aplica:
- Secuencia y recuperación de datos perdidos:
- Comportamiento con varios clientes:

## Acceso
- Ventana de configuración y acción física:
- Emparejamiento, cifrado y protección requerida:
- Bonding, revocación y cambio de propietario:
- Datos que nunca aparecen en advertising ni logs:

## Evidencia
Registra lectura válida, escritura válida, escritura rechazada, desconexión y reconexión. Conserva el valor aplicado ante una petición inválida.

[Volver a la unidad](README.md)
