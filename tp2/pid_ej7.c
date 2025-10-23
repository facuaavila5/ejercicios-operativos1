/*
💻 Ejercicio 7: “Múltiples hijos + SIGCHLD”

Descripción:
El padre crea varios hijos. Cada hijo termina después de un tiempo aleatorio (con sleep(rand()%5)), y el padre los limpia automáticamente con el handler.

Pistas:

Usa signal(SIGCHLD, handler).

Dentro del handler, usar while (waitpid(-1, NULL, WNOHANG) > 0); para limpiar varios hijos de una sola vez.
*/