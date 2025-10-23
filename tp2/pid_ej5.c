/*
💻 Ejercicio 5: “Terminar hijo con SIGTERM”

Descripción:
El padre crea un hijo que entra en un bucle infinito. Luego de 5 segundos, el padre lo termina con SIGTERM.

Pistas:

Usa sleep(5) en el padre.

Usa signal(SIGTERM, handler) en el hijo para despedirse.

El padre hace kill(pid, SIGTERM).
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void sigterm_handler(int sig);

int main(void) {
    pid_t pid = fork();

    if(pid == 0) {
        signal(SIGTERM, sigterm_handler);
        while(1) {

        }
    }
    else {
        sleep(5);
        kill(pid, SIGTERM);
        wait(NULL);
        sleep(1);
        printf("Mi proceso hijo de id: %d ha muerto, finalizando ejecucion...\n", pid);
    }

    return 0;
}

void sigterm_handler(int sig) {
    printf("Soy el proceso hijo de id %d, llegó mi muerte...\n", getpid());
    exit(0);
}
