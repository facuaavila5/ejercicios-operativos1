/*
💻 Ejercicio 7: “Múltiples hijos + SIGCHLD”

Descripción:
El padre crea varios hijos. Cada hijo termina después de un tiempo aleatorio (con sleep(rand()%5)), y el padre los limpia automáticamente con el handler.

Pistas:

Usa signal(SIGCHLD, handler).

Dentro del handler, usar while (waitpid(-1, NULL, WNOHANG) > 0); para limpiar varios hijos de una sola vez.
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void handler(int);

int main(void) {
    srand(time(NULL)); // seed generator
    signal(SIGCHLD, handler);

    for(int i = 0; i < 5; i++) {
        pid_t pid = fork();
        if(pid == 0) {
            printf("Soy el proceso hijo de id: %d, iniciando tarea!\n", getpid());
            sleep(rand()%5 + 2);
            printf("Proceso hijo de id: %d, tarea finalizada!\n", getpid());
            sleep(2);
            exit(0);
        }
        else {
            sleep(1);
        }
    }
    
    for(int i = 0; i < 5; i++) {
        pause(); // Espera por cada signal del hijo que fallece
    }
    printf("Ya se me murieron todos mis hijos, finalizando ejecucion...\n");
}

void handler(int sig) {
    printf("Soy el proceso padre. Limpiando proceso hijo...\n");
    wait(NULL); // Limpia el ultimo hijo muerto
}