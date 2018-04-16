#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>


int main()
{
    pid_t pid_filho;
    int fd[2];

    pipe(fd);

    pid_filho = fork();
  


   if(pid_filho==0){

     
       char nome[100];
       printf("Filho: Digite o nome do usuario " );
       scanf("%s", nome);
    
       if(write(fd[1], nome, sizeof(nome)) < 0){
           printf("Erro na escrita do pipe \n");
       }
   
   } else {

    char nome[100];
    sleep(1);
    if (read(fd[0], nome, 100) < 0){
            printf("Erro na leitura do pipe\n");
        } else {
            printf("PAI: %s \n", nome);      
        }
      
   }

    return 0;
}
