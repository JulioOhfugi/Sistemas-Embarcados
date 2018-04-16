
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char **argv){

    pid_t filho;
    int i;

    filho = fork();

    for(i=1;i<=argc;i++){  
     
    if(filho == 0){
       execvp(argv[i]);
      
    }


    }
    
   
    

    
    return 0;
}
