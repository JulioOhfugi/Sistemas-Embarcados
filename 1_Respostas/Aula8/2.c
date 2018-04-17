#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile long int maior[4];


void* funcao1(void* v)
{
	long int *vetor = (long int *) v;
    maior[0]= vetor[0];
    for( int k=0; k<12500; k++){
        if(maior[0] < vetor[k]){
            maior[0] = vetor[k];
        }
    }
	return NULL;
}


void* funcao2(void* v)
{
	long int *vetor = (long int *) v;
    maior[1]= vetor[0];
    for( int l=12500; l<25000; l++){
        if(maior[1] < vetor[l]){
            maior[1] = vetor[l];
        }
    }
	return NULL;
}


void* funcao3(void* v)
{
	long int *vetor = (long int *) v;
    maior[2]= vetor[0];
    for( int m=25000; m<37500; m++){
        if(maior[2] < vetor[m]){
            maior[2] = vetor[m];
        }
    }
	return NULL;
}


void* funcao4(void* v)
{
	long int *vetor = (long int *) v;
    maior[3]= vetor[0];
    for( int n=37500; n<50000; n++){
        if(maior[3] < vetor[n]){
            maior[3] = vetor[n];
        }
    }
	return NULL;
}






int main ()
{
	pthread_t thread_id1;
    pthread_t thread_id2;
    pthread_t thread_id3;
    pthread_t thread_id4;

    long int v[50000];

    long int maior1=0;
    long int maior2=0;



	for(int i=0;i<50000;i++){
	    v[i] = random();
	}

    for(int j=0; j<50000; j++){
        if(maior1<v[j]){
            maior1 = v[j];
        }

    }
	
    printf("Busca completa no vetor v[50000] -> Maior : %ld\n", maior1);

    pthread_create(&thread_id1, NULL, &funcao1, v);
    pthread_create(&thread_id2, NULL, &funcao2, v);
    pthread_create(&thread_id3, NULL, &funcao3, v);
    pthread_create(&thread_id4, NULL, &funcao4, v);
	

	pthread_join(thread_id4,NULL);
	pthread_join(thread_id3,NULL);
	pthread_join(thread_id2,NULL);
	pthread_join(thread_id1,NULL);

    for(int i=0; i<4; i++){
        if(maior2<maior[i]){
            maior2 = maior[i];
        }

    }




    printf("Entre as quatro treads -> Maior : %ld\n", maior2);
	
	printf("Terminando programa\n");

	return 0;
}












