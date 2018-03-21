#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){

    char nome[30];
    int idade;

    printf("Digite seu nome: ");
    scanf("%s", nome);
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    FILE *fp;
    fp = fopen("Eu.txt", "w");

   fprintf(fp, "Nome: %s ", nome);
   fprintf(fp, "Idade: %d", idade);
   fclose(fp);


	return 0;
}

