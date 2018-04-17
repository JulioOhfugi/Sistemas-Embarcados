#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile long int media[4];


void* funcao1(void* v)
{
	long int *vetor = (long int *) v;
    media[0]= 0;
    for( int k=0; k<12500; k++){
        media[0]=media[0]+vetor[k];
        }
    media[0] = (media[0]/12500);
	return NULL;
}


void* funcao2(void* v)
{
	long int *vetor = (long int *) v;
    media[1]= 0;
    for( int l=12500; l<25000; l++){
            media[1] = media[1] + vetor[l];
    }
    media[1] = (media[1]/12500);
	return NULL;
}


void* funcao3(void* v)
{
	long int *vetor = (long int *) v;
    media[2]= 0;
    for( int m=25000; m<37500; m++){
        media[2] = media[2] + vetor[m];
    }
     media[2] = (media[2]/12500);
	return NULL;
}


void* funcao4(void* v)
{
	long int *vetor = (long int *) v;
    media[3]= 0;
    for( int n=37500; n<50000; n++){
       media[3] = media[3] + vetor[n];
    }
    media[3] = (media[3]/12500);
	return NULL;
}






int main ()
{
	pthread_t thread_id1;
    pthread_t thread_id2;
    pthread_t thread_id3;
    pthread_t thread_id4;

    long int v[50000];

    long int media2=0;
    long int media1=0;


	for(int i=0;i<50000;i++){
	    v[i] = random();
	}

    for(int j=0; j<50000; j++){
       media1 = v[j] + media1;
    }

    media1 = (media1/50000);
	
    printf("Busca completa no vetor v[50000] -> Media : %ld\n", media1);

    pthread_create(&thread_id1, NULL, &funcao1, v);
    pthread_create(&thread_id2, NULL, &funcao2, v);
    pthread_create(&thread_id3, NULL, &funcao3, v);
    pthread_create(&thread_id4, NULL, &funcao4, v);
	

	pthread_join(thread_id4,NULL);
	pthread_join(thread_id3,NULL);
	pthread_join(thread_id2,NULL);
	pthread_join(thread_id1,NULL);

    for(int i=0; i<4; i++){
       media2 = media[i] + media2;
    }

    media2 = (media2/4);


    printf("Entre as quatro treads -> Media : %ld\n", media2);
	
	printf("Terminando programa\n");

	return 0;
}












