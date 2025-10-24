/*
💻 Ejercicio 9: “Shell con Ctrl+C manejado”

Descripción:
Implementar una shell básica donde Ctrl+C (SIGINT) no mata a la shell, pero sí mata al proceso hijo que se esté ejecutando.

Pistas:

Ignorar SIGINT en el proceso padre (signal(SIGINT, SIG_IGN)).

Restaurar el comportamiento por defecto (SIG_DFL) en el hijo antes de ejecutar execvp().
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define MAX_CMD_LENGTH 64
#define MAX_WORDS 10

int cli_interface(void);
int scan_command(char command[], char *[]);

void handler(int sig) {
    printf("\nRecibí Ctrl+C, adios...\n");
    exit(0);
}

int main(void) {
    char user_input[MAX_CMD_LENGTH];
    char *words_scanned[MAX_WORDS];

    printf("==============================\n");
    printf("Custom shell by Facundo Avila\n");
    printf("==============================\n\n");
    signal(SIGINT, SIG_IGN); // Ignore Ctrl + C signal

    while(1) {
        do {
            printf("facundo@avila: ");
            //scanf("%s", cmd);
            fgets(user_input, MAX_CMD_LENGTH, stdin);
        } while(user_input == NULL || user_input[0] == '\n'); // Avoid scanning \n
        
        pid_t pid = fork();
        if(pid == 0) {
            signal(SIGINT, handler);
            scan_command(user_input, words_scanned);
            execvp(words_scanned[0], words_scanned); // TODO: if word != command, print "command not found"
            // if command is valid, skip lines from here
            printf("zsh: command not found: %s\n", words_scanned[0]); 
            exit(0);
        }
        else {
            wait(NULL);
        }
        
    }
    
    return 0;
}

/*
 * Scans user input, skipping leading spaces, then iterates through whole array
 * until it finds a space. When a space is found, it stores the memory address of
 * the next char in an array of char pointers, so then I can use that array to
 * scan word by word the user input.
 */

int scan_command(char command[], char *words[]) {
    if(command == NULL) {
        perror("Command is NULL!\n");
        return 1;
    }

    // Replace \n char added by fgets() function to \0
    int cmd_len = strlen(command);
    if(command[cmd_len - 1] == '\n') {
        command[cmd_len - 1] = '\0';
    }

    int j = 0;
    // Skip leading spaces
    while(command[j] == ' ') {
        j++;
    }

    words[0] = &command[j]; // Store pointer to first word
    int k = 1; // Iterator for words array

    for(int i = j + 1; command[i] != '\0'; i++) {
        // Check if next char is a space or \0 too to avoid multiple spaces
        if((command[i] == ' ') && (command[i + 1] != ' ') && (command[i + 1] != '\0')) {
            command[i] = '\0';
            words[k] = (char *)&command[i + 1];
            k++;
        }
    }

    words[k] = NULL;

    return 0;
}
