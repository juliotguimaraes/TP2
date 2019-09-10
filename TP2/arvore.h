#ifndef ARVORE_H
#define ARVORE_H

#include "aluno.h"

typedef struct Arvore{
	struct Arvore *esq;
	struct Arvore *dir;
	Aluno *reg;
}Arvore;

Arvore* criaArvore(Aluno *a);
Aluno* pesquisa(Arvore *t, int x);
void insereElemento(Arvore *t, Aluno *a);
Arvore* apaga(Arvore *t, int x);
Arvore* achaMenor(Arvore *t);
void imprimeArvore(Arvore *t);
void apagaArvore(Arvore *t);

#endif
