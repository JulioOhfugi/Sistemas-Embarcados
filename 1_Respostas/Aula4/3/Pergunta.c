#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){


    FILE *fp;
    fp = fopen("Eu.txt", "w");

   fprintf(fp, "Nome: %s \n ", argv[1]);
   fprintf(fp, "Idade: %d \n ", argc);
   fclose(fp);


	return 0;
}

