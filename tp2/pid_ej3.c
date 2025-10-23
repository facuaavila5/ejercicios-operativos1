/*
 * Ejercicio 3: “Crea varios hijos en paralelo”
 * Descripción:
 * El padre crea N hijos (por ejemplo 5), todos se ejecutan al mismo tiempo, y el padre espera a que terminen todos.
 * Pistas:
 * Usa un bucle for con fork().
 * El padre usa un bucle con wait(NULL) para reapearlos.
 * Los hijos imprimen mensajes diferentes (por ejemplo, “Soy el hijo 1”).
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    for(int i = 0; i < 5; i++) {
        sleep(2);
        pid_t pid = fork();
        if(pid == 0) {
            printf("Soy el proceso hijo numero %d\n", i+1);
            sleep(10);
            printf("Proceso hijo numero %d finalizado.\n", i+1);
            exit(0);
        }
        else {
            printf("Proceso padre genero el hijo %d\n", i+1);
            sleep(1);
        }
    }
    for(int i = 0; i < 5; i++) {
        printf("Proceso padre esperando la muerte del proceso hijo numero %d...\n", i+1);
        wait(NULL);
    }
    printf("Todos los procesos hijos terminaron su ejecución. Finalizando ejecucion...\n");

    return 0;
}