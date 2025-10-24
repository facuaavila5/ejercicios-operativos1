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


void handler(int sig);

int main(void) {
    pid_t pid = fork();

    if(pid == 0) {
        /*
         * NOTA! ChatGPT recomienda utilizar sigaction() en lugar de signal
         */
        signal(SIGUSR1, handler);
        pause();
        exit(0);
    }
    else {
        sleep(1);
        kill(pid, SIGUSR1);
        printf("Soy el padre. Esperando al proceso hijo...\n");
        wait(NULL);
    }
}

void handler(int sig) {
    printf("Hola, soy el proceso hijo de id: %d, mi papi es: %d\n", getpid(), getppid());
}