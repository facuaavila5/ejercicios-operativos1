/*
 Ejercicio 4: “Comunicación con señales”
 Descripción:
 El padre crea un hijo. Luego le envía una señal (SIGUSR1) al hijo, y el hijo reacciona con un handler.
 Pistas:
 Instalar signal(SIGUSR1, handler) en el hijo.
 El padre hace kill(pid_hijo, SIGUSR1).
 El handler imprime “Recibí una señal del padre”.
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>