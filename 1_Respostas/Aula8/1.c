#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile int i;

void* print(void* unused)
{
	//int *numeros = (int *) i;
	
	while(1){
		printf("%d\n",i);
		sleep(1);
        if(i==10){
            printf("%d\n",i);
            break;
        }
	}

	return NULL;
}

int main ()
{
	pthread_t thread_id1;
	
	pthread_create(&thread_id1, NULL, &print, NULL);

	for(i=1;i<10;i++){
		sleep(1);
	}
	
	sleep(1);
	printf("Terminando programa\n");

	return 0;
}












