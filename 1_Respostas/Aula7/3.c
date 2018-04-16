#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>


int main()
{
    pid_t filho_1;
    pid_t filho_2;
    int fd[2];

   pipe(fd);

   filho_1 = fork();
   sleep(1);     
   if(filho_1==0){

       char buf_filho1[100];
       if(read(fd[0], &buf_filho1, sizeof(int) < 0)){
           printf("Erro na leitura do pipe \n");
       } else {
           strcpy(buf_filho1, "Quando o vento passa, é a bandeira que se move.");
           printf("FILHO1: %s \n", buf_filho1);
       }
   
   } else {

    filho_2 = fork();
    sleep(1);
     if(filho_2==0){

       char buf_filho2[100];
       if(read(fd[0], &buf_filho2, sizeof(int) < 0)){
           printf("Erro na leitura do pipe \n");
       } else {
           strcpy(buf_filho2, "Não, é o vento que se move.");
           printf("FILHO2: %s \n", buf_filho2);
       }

   } 
    else {
        
        sleep(1);

    char buf_pai[100];
    if (write(fd[1], &buf_pai, sizeof(buf_pai)) < 0){
            printf("Erro na escrita do pipe\n");
        } else {
            strcpy( buf_pai,"Os dois se enganam. É a mente dos senhores que se move.");
            printf("PAI: %s \n", buf_pai);
         
        }
      
   }
   }

    return 0;
}
