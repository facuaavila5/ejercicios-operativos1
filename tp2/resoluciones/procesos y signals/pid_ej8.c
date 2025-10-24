/*
💻 Ejercicio 8: “Ejecutar un comando externo”

Descripción:
El programa pide al usuario un comando, crea un proceso hijo, y en el hijo ejecuta el comando con execvp().
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    char command[24];
    printf("Ingrese el comando a ejecutar, por favor: ");
    scanf("%s",command);
    printf("\nComando invocado: %s\n", command);
    for(int i = 0; i < 3; i++) {
        sleep(1);
        printf("Preparando ejecucion...\n");
    }

    pid_t pid = fork();
    if(pid == 0) {
        execvp(command, NULL); // Por ahora solo comandos sin argumentos!
        sleep(2);
        printf("Comando ejecutado, finalizando...\n");
        exit(0);
    }
    else {
        wait(NULL);
    }
    printf("Finalizando ejecucion...");

    return 0;
}
