/*
💻 Ejercicio 9: “Shell con Ctrl+C manejado”

Descripción:
Implementar una shell básica donde Ctrl+C (SIGINT) no mata a la shell, pero sí mata al proceso hijo que se esté ejecutando.

Pistas:

Ignorar SIGINT en el proceso padre (signal(SIGINT, SIG_IGN)).

Restaurar el comportamiento por defecto (SIG_DFL) en el hijo antes de ejecutar execvp().
*/