#ifndef ALUNO_H
#define ALUNO_H

typedef struct Aluno{
	char *nome;
	int chave; //matricula
}Aluno;

Aluno* criaAluno(char *n, int mat);
void apagaAluno(Aluno *a);
void imprimeAluno(Aluno *a, char *saida);

#endif
