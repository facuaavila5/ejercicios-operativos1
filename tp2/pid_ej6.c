/*
💻 Ejercicio 6: “Evitar zombies”

Descripción:
Crea un hijo que termina solo. El padre no usa wait(), sino un handler de SIGCHLD para limpiar el proceso.

Pistas:

Instalar signal(SIGCHLD, handler).

En el handler, llamar a wait(NULL).
*/