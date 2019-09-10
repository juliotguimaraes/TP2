#include <stdlib.h>
#include <stdio.h>
#include "arvoresbb.h"

ArvoreSBB* criaArvoreSBB(Aluno *a){
    ArvoreSBB *no = (ArvoreSBB*)malloc(sizeof(struct ArvoreSBB)); 
    no->reg = a; 
    no->esq = NULL; 
    no->dir = NULL; 
    no->esqtipo = SBB_VERTICAL; 
    no->dirtipo = SBB_VERTICAL; 
		return no; 
}

void ee(ArvoreSBB **ptr){
	ArvoreSBB *no = *ptr;
	ArvoreSBB *esq = no->esq;

	no->esq = esq->dir;
	esq->dir = no;
	esq->esqtipo = SBB_VERTICAL;
	no->esqtipo = SBB_VERTICAL;
	*ptr = esq;
}

void dd(ArvoreSBB **ptr){
	ArvoreSBB *no = *ptr;
	ArvoreSBB *dir = no->dir;

	no->dir = dir->esq;
	dir->esq = no;
	dir->dirtipo = SBB_VERTICAL;
	no->dirtipo = SBB_VERTICAL;
	*ptr = dir;
}

void ed(ArvoreSBB **ptr){
	ArvoreSBB *no = *ptr;
	ArvoreSBB *esq = no->esq;
	ArvoreSBB *dir = esq->dir;
	
	esq->dir = dir->esq;
	no->esq = dir->dir;
	dir->esq = esq;
	dir->dir = no;
	esq->dirtipo = SBB_VERTICAL;
	no->esqtipo = SBB_VERTICAL;
	*ptr = dir;

}

void de(ArvoreSBB** ptr){
	ArvoreSBB *no = *ptr;
	ArvoreSBB *dir = no->dir;
	ArvoreSBB *esq = dir->esq;

	no->dir = esq->esq;
	dir->esq = esq->dir;
	esq->esq = no;
	esq->dir = dir;
	dir->esqtipo = SBB_VERTICAL;
	no->dirtipo = SBB_VERTICAL;
	*ptr = esq;

}

void iInsere(Aluno *a, ArvoreSBB** ptr, int *incli, int *fim){
	if(*ptr == NULL){
		iInsereAqui(a, ptr, incli, fim);
	}else if(a->chave < (*ptr)->reg->chave){
		iInsere(a, &((*ptr)->esq), &((*ptr)->esqtipo), fim);
		if(*fim){
			return;
		}
		if((*ptr)->esqtipo == SBB_VERTICAL){
			*fim = TRUE;
		}else if((*ptr)->esq->esqtipo == SBB_HORIZONTAL){
			ee(ptr);
			*incli = SBB_HORIZONTAL;
		}else if((*ptr)->esq->dirtipo == SBB_HORIZONTAL){
			ed(ptr);
			*incli = SBB_HORIZONTAL;
		}
	}else if(a->chave > (*ptr)->reg->chave){
		iInsere(a, &((*ptr)->dir), &((*ptr)->dirtipo), fim);
		if(*fim){
			return;
		}
		if((*ptr)->dirtipo == SBB_VERTICAL){
			*fim = TRUE;
		}else if((*ptr)->dir->dirtipo == SBB_HORIZONTAL){
			dd(ptr);
			*incli = SBB_HORIZONTAL;
		}else if((*ptr)->dir->esqtipo == SBB_HORIZONTAL){
			de(ptr);
			*incli = SBB_HORIZONTAL;
		}
	}else{
		printf("Erro: Aluno já está inserido\n");
		*fim = TRUE;
	}
}

void iInsereAqui(Aluno *a, ArvoreSBB** ptr, int *incli, int *fim){
	ArvoreSBB *no = criaArvoreSBB(a);
	*ptr = no;
	*incli = SBB_HORIZONTAL;
	*fim = FALSE;
}

void insereElementoSBB(ArvoreSBB** t, Aluno *n){
	int fim = FALSE;
	int inclinacao = SBB_VERTICAL;
	iInsere(n, t, &inclinacao, &fim);
}

Arvore* apagaSBB(ArvoreSBB *t, int x){

}

Aluno* pesquisaSBB(ArvoreSBB *t, int x){
	if(t == NULL){
		printf("Aluno procurado nao existe\n");
	}else if(x < t->reg->chave){ //Se o elemento pesquisado é menor do que o elemento, chama a função para a subarvore a esquerda
		pesquisaSBB(t->esq, x);
	}else if(x > t->reg->chave){ //Se o elemento pesquisado é maior do que o elemento, chama a função para a subarvore a direita
		pesquisaSBB(t->dir, x);
	}else{ //Encontrou o aluno
		return t->reg;
	}
	return t->reg;
}

void inicializa(ArvoreSBB **raiz){
	*raiz = NULL;
}

void imprimeArvoreSBB(ArvoreSBB *t, char *saida){
	if(t != NULL){
		imprimeAluno(t->reg, saida);
		imprimeArvoreSBB(t->dir);
		imprimeArvoreSBB(t->esq);
	}
}

void apagaArvoreSBB(ArvoreSBB *t){
	if(t != NULL){
		apagaArvoreSBB(t->esq);
		apagaArvoreSBB(t->dir);
		free(t);
	}
}

