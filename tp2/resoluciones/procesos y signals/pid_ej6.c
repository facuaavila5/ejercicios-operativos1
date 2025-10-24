/*
💻 Ejercicio 6: “Evitar zombies”

Descripción:
Crea un hijo que termina solo. El padre no usa wait(), sino un handler de SIGCHLD para limpiar el proceso.

Pistas:

Instalar signal(SIGCHLD, handler).

En el handler, llamar a wait(NULL).
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void children_cleaner(int sig);

int main(void) {
    pid_t pid = fork();
    
    if(pid == 0) {
        sleep(1);
        printf("Realizando tarea 1...\n");
        sleep(4);
        printf("Realizando tarea 2...\n");
        sleep(2);
        printf("Finalizando ejecución...\n");
        sleep(1);
        exit(0);
    }
    else {
        signal(SIGCHLD, children_cleaner);
        pause(); // Espera que le llegue la signal
    }
}

void children_cleaner(int sig) {
    wait(NULL);
    printf("Hijo recolectado (reaped).\n");
}