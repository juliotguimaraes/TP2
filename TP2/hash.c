#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

int funcaoHash(int matricula){
	return (matricula%10);
}

Hash* criaHash(int n){
	Hash *novo = (Hash *) malloc(sizeof(Hash));
	int i;
	novo->tam = n;
	novo->nElem = 0;
	novo->hash = (Arvore **) malloc(sizeof(Arvore*) * n);
	novo->hashSBB = (ArvoreSBB **) malloc(sizeof(ArvoreSBB*) * n);;
	for(i = 0; i < n; i++){
		novo->hash[i] = NULL;
		novo->hashSBB[i] = NULL;
	}
	return novo;
}

void apagaHash(Hash *h){
	int i;
	for(i = 0; i < h->tam; i++){
		if(h->hash[i] != NULL)
			apagaArvore(h->hash[i]);
		if(h->hashSBB[i] != NULL)
			apagaArvoreSBB(h->hashSBB[i]);
	}
	free(h->hash);
	free(h->hashSBB);
	free(h);
}

void insereNaHash(Hash *h, Aluno *x){
	int ind = funcaoHash(x->chave);
	insereElementoSBB(&(h->hashSBB[ind]), x);
	if(h->hash[ind] == NULL){
		Arvore *a = criaArvore(x);
		h->hash[ind] = a;
	}else{
		insereElemento(h->hash[ind], x);
	}
	h->nElem++;
}

Aluno* obtemDaHash(Hash *h, int x){
	int ind = funcaoHash(x);
	return pesquisa(h->hash[ind], x);
}

Aluno* obtemDaHashSBB(Hash *h, int x){
	int ind = funcaoHash(x);
	return pesquisaSBB(h->hashSBB[ind], x);

}

void imprime(Hash *h){
	int i;
	for(i = 0; i < h->tam; i++){
		if(h->hash[i] != NULL){
			printf("%d:\n", i);
			imprimeArvore(h->hash[i]);
		}
	}
}

void imprimeSBB(Hash *h, char *saida){
	int i;
	for(i = 0; i < h->tam; i++){
		if(h->hashSBB[i] != NULL){
			FILE *arq = fopen(saida, "a");
			printf("%d:\n", i);
			fclose(arq);
			imprimeArvoreSBB(h->hashSBB[i], saida);
		}
	}
}

int obtemNumElem(Hash *h){
	return h->nElem;
}
