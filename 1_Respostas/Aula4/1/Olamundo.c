#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){

    FILE *fp;
    fp = fopen("ola_mundo.txt", "w");

   fputs("Ola Mundo!", fp);
   fclose(fp);


	return 0;
}

