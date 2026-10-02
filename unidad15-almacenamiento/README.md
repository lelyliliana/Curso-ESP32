# Unidad 15 — Almacenamiento y configuración

## Objetivo
Conservar configuración entre reinicios.

Opciones dependen del entorno y placa:
- preferencias/NVS;
- sistemas de archivos;
- almacenamiento externo.

## Qué guardar
- parámetros;
- calibración;
- identificadores no secretos;
- último estado cuando sea apropiado.

## Escrituras
La memoria flash tiene ciclos limitados. Evita escribir continuamente datos que podrían mantenerse en RAM o agruparse.

## Reto
Guarda un umbral configurable y recupéralo después de reiniciar.
