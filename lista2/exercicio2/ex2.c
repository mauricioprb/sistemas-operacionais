#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int N = 10; // Número de interações
    pid_t pid[3]; // Array de identificadores de processos

    // Criação dos processos
    for(int i = 0; i < 3; i++) {
        pid[i] = fork();
        if(pid[i] < 0) {
            perror("Erro ao criar processo.");
            exit(1);
        } else if(pid[i] == 0) {
            // Processo filho
            for(int j = 0; j < N; j++) {
                printf("Processo %d: iteração %d\n", i, j);
            }
            exit(0);
        }
    }

    // Espera pelo término dos processos filhos
    int status;
    for(int i = 0; i < 3; i++) {
        waitpid(pid[i], &status, 0);
        if(WIFEXITED(status)) {
            printf("Processo %d finalizou com status %d\n", i, WEXITSTATUS(status));
        } else {
            printf("Processo %d terminou com erro\n", i);
        }
    }

    return 1;
}