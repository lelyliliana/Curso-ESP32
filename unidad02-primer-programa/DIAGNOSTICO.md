# Diagnóstico — Compilación, carga y Serial

## No compila
Revisa:
- placa/core seleccionado;
- API disponible en la versión instalada;
- bibliotecas;
- errores de sintaxis.

## Compila pero no carga
Revisa:
- puerto;
- cable;
- driver USB/serial cuando aplique;
- modo de arranque requerido por la placa;
- dispositivo conectado a GPIO que interfiera con arranque.

## Carga pero no veo Serial
- baud rate;
- puerto;
- reinicio;
- tiempo de arranque.

## Regla
Distingue siempre **compilación**, **carga**, **arranque** y **ejecución**. Son etapas diferentes.
