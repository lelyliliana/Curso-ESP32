# Servicios locales del laboratorio

[Entorno](../../docs/ENTORNO.md) · [Índice de laboratorios](../README.md)

## HTTP con Python (un paso por vez)

Necesitas Python 3.10 o superior, sin dependencias adicionales. Abre una terminal en `laboratorios/servicios`.

1. Ejecuta `python servidor.py` (Windows: `py -3 servidor.py`; macOS/Linux: `python3 servidor.py`).
2. Abre `http://127.0.0.1:8000/medicion`: debe responder un JSON con `source: simulated`. Este valor es fijo para estudiar HTTP, no una lectura ambiental.
3. Detén con Ctrl+C. Identifica la IP LAN del computador en su configuración de red.
4. Inicia con `python servidor.py --host IP_LAN` sustituyendo IP_LAN; permite el puerto 8000 solo en la red privada necesaria. No abras redirecciones en el router.
5. Coloca esa IP en LAB_HOST del archivo local del sketch. ESP32 y computador deben poder comunicarse; una red de invitados con aislamiento puede impedirlo.
6. Repite desde ESP32. El servicio por defecto solo escucha loopback: no es accesible desde otro dispositivo hasta cambiar host.

`/salud` confirma servidor; `/medicion` devuelve un dato simulado; POST `/eventos` recibe nodo/id y opcionalmente valor numérico y header Idempotency-Key. Guarda en SQLite antes de confirmar con `ack`. Repetir identidad/cuerpo conserva una fila; identidad conflictiva devuelve 409. Las filas sobreviven al reinicio si conservas el mismo archivo DB. El modelo admite solo nodo01; para otro nodo cambia contrato y aislamiento de claves.

## Consultar API del ESP32 desde el computador

Desde esta carpeta, sustituye IP_ESP32. Ejecuta cada comando por separado:

```text
python peticion.py http://IP_ESP32/api/led
```

```text
python peticion.py http://IP_ESP32/api/led --activo true
```

```text
python peticion.py http://IP_ESP32/api/led --invalido
```

El segundo aplica ON; el tercero debe mostrar 400 y preservar salida. Cambia el ejecutor Python según tu sistema, sin cambiar los argumentos. No uses esta API HTTP sin autenticación para actuadores reales.

## Broker MQTT con Docker (opcional)

El curso usa Mosquitto 2.0.22 y PubSubClient 2.8.0. Si ya tienes Mosquitto autorizado, conserva su configuración y aplica los mismos tópicos/permisos. Documentación: [Mosquitto](https://mosquitto.org/man/mosquitto-conf-5.html) y [imagen oficial](https://hub.docker.com/_/eclipse-mosquitto).

1. Instala/inicia Docker según tu sistema. Abre terminal en esta carpeta.
2. Crea la contraseña local de `curso` (se solicita de forma interactiva; no la escribas en el historial). En PowerShell usa la forma siguiente; en macOS/Linux sustituye `${PWD}` por `$(pwd)` dentro de las comillas del argumento de volumen si tu shell lo requiere:

```text
docker run --rm -it -v "${PWD}/broker:/mosquitto/config" eclipse-mosquitto:2.0.22 mosquitto_passwd -c /mosquitto/config/passwd curso
```

3. Da al archivo `broker/passwd` permisos de lectura dentro del contenedor; contiene hashes y es privado. En macOS/Linux, `chmod 644 broker/passwd` permite al usuario mosquitto leer el bind mount. La carpeta es solo para laboratorio local.
4. Inicia el broker enlazando exclusivamente IP_LAN de tu computador:

```text
docker run --rm --name leli-mqtt -p IP_LAN:1883:1883 -v "${PWD}/broker:/mosquitto/config:ro" eclipse-mosquitto:2.0.22
```

5. Configura LAB_HOST, LAB_MQTT_USER=curso y LAB_MQTT_PASS en cada sketch de red. No uses dos dispositivos con `leli-nodo01`: cambia clientId y ACL al ampliar.
6. En otra terminal entra al contenedor para usar clientes: `docker exec -it leli-mqtt sh`. Crea un archivo privado de opciones para clientes **dentro del contenedor** con `mkdir -p /tmp/cliente` y `vi /tmp/cliente/mosquitto_sub`. Escribe una línea por opción: `-u curso`, `-P TU_CLAVE_LOCAL`, `-h 127.0.0.1`. Estos archivos locales contienen secretos: no los copies al repositorio.
7. Copia la configuración para el publicador con `cp /tmp/cliente/mosquitto_sub /tmp/cliente/mosquitto_pub` y restringe ambos archivos con `chmod 600 /tmp/cliente/mosquitto_sub /tmp/cliente/mosquitto_pub`. Suscríbete: `XDG_CONFIG_HOME=/tmp/cliente mosquitto_sub -t 'curso/nodo01/#' -v`. Mosquitto 2.0 lee automáticamente su archivo por nombre en XDG_CONFIG_HOME; la asignación indica esa carpeta solo para el comando. No utiliza `-o`, disponible a partir de 2.1.
8. Desde otra shell del mismo contenedor publica un comando: `XDG_CONFIG_HOME=/tmp/cliente mosquitto_pub -t curso/nodo01/command -m '{"activo":true}'`. **No agregues `-r`**: command no se retiene. Las comillas indicadas corresponden a sh, no a PowerShell.
9. Prueba credenciales incorrectas en una copia privada del archivo y conserva el rechazo sin revelar secretos. Detén con Ctrl+C en la terminal principal.

El usuario curso tiene acceso al prefijo nodo01 de esta LAN. No autentica diferentes emisores por separado ni cifra tráfico; son credenciales de práctica. Para entornos reales configura TLS/identidad por nodo y ACL separadas. No expongas1883 a Internet.

## Fallos reproducibles

| Cambio | Capa que debe fallar | Evidencia |
|---|---|---|
| Detener servidor HTTP | servicio | código de transporte, pendiente conservado |
| URL inexistente | contrato/ruta |404, distinto de caída Wi-Fi |
| Contraseña MQTT incorrecta | identidad | rechazo sin comando aplicado |
| Broker detenido | transporte | reconexión; salida segura detectada |
| Quitar sensor con placa desenergizada | adquisición | sensor ausente; no dato inventado |

No ejecutes pruebas eléctricas peligrosas para provocar fallos. Compilación, simulación de servicio y funcionamiento físico se registran por separado.
