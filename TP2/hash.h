#ifndef HASH_H
#define HASH_H

#include "arvore.h"
#include "arvoresbb.h"
#include "aluno.h"

typedef struct Hash{
	Arvore **hash;
	ArvoreSBB **hashSBB;
	int tam;
	int nElem;
}Hash;

int funcaoHash(int matricula); //Criar a função hash
Hash* criaHash(int n);
void apagaHash(Hash *h);
void insereNaHash(Hash *h, Aluno *x);
Aluno* obtemDaHash(Hash *h, int x);
Aluno* obtemDaHashSBB(Hash *h, int x);
void imprime(Hash *h);
void imprimeSBB(Hash *h, char *saida);
int obtemNumElem(Hash *h);

#endif
