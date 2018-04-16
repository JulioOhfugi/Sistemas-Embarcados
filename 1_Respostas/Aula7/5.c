#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


 void contrl_c(){
     printf("Processo terminado!\n");
     exit(1);
 }

void chamar_comando(){
    system("ps");
    alarm(1);
}

int main()
{
    

    signal(SIGALRM, chamar_comando);
    signal(SIGINT, contrl_c);
    alarm(1);
    while(1);
    return 0;
}
