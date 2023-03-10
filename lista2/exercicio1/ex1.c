#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int comprimento, largura;
    int filho_pid, status;

    // Lê as dimensões do terreno do usuário
    printf("Digite o comprimento do terreno: ");
    scanf("%d", &comprimento);

    printf("Digite a largura do terreno: ");
    scanf("%d", &largura);

    // Cria um novo processo
    filho_pid = fork();
    printf("%d", filho_pid);

    if (filho_pid == 0) {
        // Processo filho calcula a área do terreno
        int area = comprimento * largura;

        // Exibe a área do terreno na tela
        printf("Área do terreno: %d\n", area);
    } else if (filho_pid > 0) {
        // Processo pai calcula o perímetro do terreno
        int perimetro = 2 * (comprimento + largura);

        // Exibe o perímetro do terreno na tela
        printf("Perímetro do terreno: %d\n", perimetro);

        // Aguarda o processo filho finalizar
        wait(&status);
    } else {
        // Erro na criação do processo filho
        printf("Erro na criação do processo filho!\n");
        exit(1);
    }

    return 1;
}