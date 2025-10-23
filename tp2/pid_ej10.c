/*
💻 Ejercicio 10: “Shell con procesos en background”

Descripción:
Permitir ejecutar comandos con & al final (como sleep 5 &) que no bloqueen la shell.

Pistas:

Si el comando termina con &, no hagas wait() en el padre.

Instalar signal(SIGCHLD, handler) para limpiar los hijos terminados.
*/