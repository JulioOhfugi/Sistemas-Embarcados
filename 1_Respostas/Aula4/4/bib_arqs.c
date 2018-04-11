#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"


int tam_arq_texto(char *nome_arquivo){

    int i=0;
    FILE *fp;
    char *nome = nome_arquivo;
    char letra;
    fp = fopen( nome, "r");

    while((letra=getc(fp)) != EOF){
        i++;
    }

    fclose(fp);

	return i;
}
