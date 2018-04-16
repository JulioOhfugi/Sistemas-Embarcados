#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>



int main(int argc, char **argv){

    pid_t child_pid_1;
    int fd[2];

    pipe(fd);
    child_pid_1 = fork();
    
    printf("Processo filho: ");
    printf("\n");

    if(child_pid_1 == 0){
        printf("filho_1 %d e v_global %d", (int) getpid(),v_global); 
        Incrementa_Variavel_Global(getpid());      
    }

    else{
        child_pid_2 = fork();
        if(child_pid_2 == 0){
            printf("filho_2 %d e v_global %d", (int) getpid(),v_global);
            Incrementa_Variavel_Global(getpid());      
        }

        else{
            
            child_pid_3 = fork();
            if(child_pid_3 == 0){
                printf("filho_3 %d e v_global %d", (int) getpid(),v_global);
                Incrementa_Variavel_Global(getpid());      
            }
        
        }
    }

  
    
    return 0;
}
