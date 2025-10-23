/*
Descripción:
El proceso padre crea un hijo y ambos imprimen sus PID.

Pistas:

Usa fork().

En el hijo, imprime su PID y el del padre (getpid(), getppid()).

En el padre, espera al hijo con wait().
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    pid_t pid = fork();
    sleep(2);

    if(pid == 0) {
        // proceso hijo
        printf("Hola, soy el proceso hijo de id: %d, mi proceso padre es: %d\n", getpid(), getppid());
        exit(0);
    }
    else {
        // proceso padre
        int status;
        printf("Esperando a que mi proceso hijo termine la ejecucion...\n");
        pid_t pid_child = wait(&status); 
        // Espero a que termine el p. hijo. el status obtiene informacion de finalizacion del proceso hijo. el wait
        // devuelve el pid del proceso hijo, y ademas lo limpia del registro de procesos (al menos en el handler, aca nose)
        printf("Hola, soy el proceso padre de id: %d, mi ultimo proceso hijo finalizado es: %d\n",getpid(), pid_child);
        printf("Impresion de status: %d", status);
    }

    return 0;
}