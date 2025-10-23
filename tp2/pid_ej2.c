/*
 * Ejercicio 2: “Crea 3 hijos secuencialmente”
 *
 * Descripción:
 * El proceso padre crea 3 hijos, uno por uno, y espera a que cada uno termine antes de crear el siguiente.
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    int status;
    for(int i = 0; i < 3; i++) {
        sleep(2);
        pid_t pid = fork();
        if(pid == 0) {
            printf("Soy el proceso hijo %d, moriré inmediatamente...\n", i);
            exit(0);
        }
        else {
            pid_t hijo = wait(&status);
            printf("Soy el padre, maté al proceso de pid: %d\n", hijo);
        }
    }
    printf("Creacion de procesos hijos finalizada, terminando...\n");
    return 0;
}
