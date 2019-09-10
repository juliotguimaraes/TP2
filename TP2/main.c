#include <stdlib.h>
#include <stdio.h>
#include "aluno.h"
#include "hash.h"
#include "arvore.h"
#include "arvoresbb.h"

void leArquivo(char *nome, Hash *h){
	FILE *arq = fopen(nome, "r");
	char info[100];
	char *nome = (char *) malloc(sizeof(char) * 100);
	int mat;
	int i = 0;
	while(fgtes(info, 100, arq) != NULL){
		if(i%2 == 0)
			strcpy(nome, info);
		else{
			strcpy(mat, atoi(info));
			Aluno *a;
			a = criaAluno(nome, mat);
			insereNaHash(h, a);
		}
		i++;
	}
	free(nome);
}

int main(int argc, char *argv[]){
	Hash *hash;
	hash = criaHash(10);
	
	leArquivo(argv[1], hash);

	imprimeSBB(hash, argv[2]);

	apagaHash(hash);

	return 0;

}
