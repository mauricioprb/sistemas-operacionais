// Exercício 1
/*
#include <sys/types.h>
#include<unistd.h>
#include<stdio.h>
 
int main() {
       	pid_t procID;
       	procID = fork();
 
 	fork();
	fork();
	
	printf("Processo filho - para o FILHO o fork devolveu %d\n", procID);
             printf("Processo filho - PID = %d\n", getpid());
       if (procID < 0)
       {
             printf("Erro na criação do novo processo\n");
             return -1;
       }
       else if (procID == 0)
            {
             printf("Processo filho - para o FILHO o fork devolveu %d\n", procID);
             printf("Processo filho - PID = %d\n", getpid());
             while(1) {
             	
             }
             return 1;
            }
            else
            {
             printf("Processo Pai - para o PAI o fork devolveu %d\n", procID);
             printf("Processo Pai - PID = %d\n", getpid());
             while(1) {
             	
             }
             return 1;
            }
}
*/

// Exrcício 2
/*
#include <sys/types.h>
#include<unistd.h>
#include<stdio.h>

pid_t wait(int *status);
 
int f1(int x)
{
       printf("x = %d", x);
     
}
 
int main()
{
       pid_t procID;
       procID = fork(); 
 
       if (procID < 0)
       {
             printf("Erro na criacao do novo processo\n");
             return -1;
       }
       else if (procID == 0)
            {
             printf("Processo filho - PID = %d\n", getpid());
             f1(100);
             printf("Filho executou a funcao f1 do Pai...\n");
             while(1){}
             return 1;
            }
            else
            {
              wait(NULL);
              printf("Processo Pai - PID = %d\n", getpid());
             f1(50);
              printf("Pai executou a funcao f1...\n");
              while(1){}
              return 1;
            }
}
*/

//Exercício 3

#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

execl("./main", "0", "0");
 
int main()
{
       pid_t procID;
       procID = fork(); 
 
       if (procID < 0)
       {
             printf("Erro na criacao do novo processo\n");
             return -1;
       }
       else if (procID == 0)
            {
             printf("Processo3.c: Processo filho - PID = %d\n", getpid());
             execl("./processo2", "0", "0");
             exit(0);
             printf("Processo3.c: Filho executou o programa \"processo2.c!\"...\n");
             sleep(3);
             }
            else
            {
              wait(NULL);
              printf("Processo3.c: Processo Pai - PID = %d\n", getpid());
              return 1;
            }
}
