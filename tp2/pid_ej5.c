/*
💻 Ejercicio 5: “Terminar hijo con SIGTERM”

Descripción:
El padre crea un hijo que entra en un bucle infinito. Luego de 5 segundos, el padre lo termina con SIGTERM.

Pistas:

Usa sleep(5) en el padre.

Usa signal(SIGTERM, handler) en el hijo para despedirse.

El padre hace kill(pid, SIGTERM).
*/