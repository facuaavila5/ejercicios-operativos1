/*
💻 Ejercicio 9: “Shell con Ctrl+C manejado”

Descripción:
Implementar una shell básica donde Ctrl+C (SIGINT) no mata a la shell, pero sí mata al proceso hijo que se esté ejecutando.

Pistas:

Ignorar SIGINT en el proceso padre (signal(SIGINT, SIG_IGN)).

Restaurar el comportamiento por defecto (SIG_DFL) en el hijo antes de ejecutar execvp().
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 10

int main(void) {
    char cmd[MAX_CMD_LENGTH];

    printf("==============================\n");
    printf("Custom shell by Avila, Facundo\n");
    printf("==============================\n\n");

    while(1) {
        do {
            printf("facundo@avila: ");
            //scanf("%s", cmd);

        } while(cmd == NULL);
        printf("scanned = %s\n", cmd);
    }
    

    return 0;
}