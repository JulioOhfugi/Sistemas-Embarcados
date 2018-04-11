#include <stdio.h>
#include <stdlib.h>



int tam_arq_texto(char *nome_arquivo){

    int i;
    FILE *fp;
    char *nome = nome_arquivo;
    fp = fopen( nome, "r");

    while(getc(fp) != EOF){
        i++;
    }

    fclose(fp);

	return i;
}




int main(int argc, char **argv){

    int tamanho;
    char arquivo[30];

    printf( "Nome do arquivo: ");
    scanf("%s", arquivo);

    tamanho = tam_arq_texto(arquivo);

    printf("Tamanho do arquivo: %d ",tamanho);
    printf("\n");
    

	return 0;
}

