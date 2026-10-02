# Unidad 02 — Primer programa y diagnóstico serial

## Objetivo
Comprobar compilación, carga y comunicación serial.

```cpp
void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("ESP32 iniciado");
}

void loop() {
  Serial.println(millis());
  delay(1000);
}
```

El baud rate debe coincidir con el monitor.

## Diagnóstico
Registra arranque, estados y errores. La observabilidad será esencial cuando el dispositivo esté conectado.

## Reto
Imprime un reporte de inicio con tiempo desde arranque y estado de un GPIO seguro de tu placa.
