#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void leArquivo(char *entrada, char *saida, int x){
	FILE *out = fopen(saida, "a");
	char *linha = (char*) malloc(sizeof(char) * 50);
	int contador = 0;
	int mat, i;
	srand((unsigned) time(NULL));
	for(i = 0; i < x; i++){
		FILE *arq = fopen(entrada, "r");

		while(fgets(linha, 50, arq) != NULL){
			if(contador%2 == 0){
				mat = (rand() % 90000) + 10000;
				fprintf(out, "%d\n", mat);
			}else{
				linha[strlen(linha) - 1] = '\0';
				fprintf(out, "%s\n", linha);
			}
			contador++;
		}
		fclose(arq);
	}

	free(linha);
	
	fclose(out);
}


int main(int argc, char *argv[]){

		leArquivo(argv[1], argv[2], atoi(argv[3]));
	return 0;
}
