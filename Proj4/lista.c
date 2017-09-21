#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct nodo{
	int chave;
	char info[50];
};

struct lista{
	int numeroElementos;
	celula vec[50];
};


Lista *aloca(){

	Lista *L = (Lista*)malloc(sizeof(Lista));
	return L;
};

void definir(Lista *L){

	L->numeroElementos = 0;
	L->vec[0].chave = 0;
	strcpy(L->vec[0].info,"\0");
};

void inserir(Lista *L, int chave, char *info){

	if (L->numeroElementos == 50) printf("Lista cheia!\n");
	else{
		if (L->numeroElementos == 0){
			
			L->vec[0].chave = chave;
			strcpy(L->vec[0].info,info);
			L->numeroElementos++;
		}
		else{
			L->vec[L->numeroElementos].chave = chave;
			strcpy(L->vec[L->numeroElementos].info,info);
			L->numeroElementos++;
		}
	}
};

int localizar(int chaveProcura, Lista *L){

	int i;

	for (i = 0; i < L->numeroElementos; i++){
		if (L->vec[i].chave == chaveProcura) return i+1;
	}

	return 0;
};

void print_lista(Lista *L){

	int i;

	if(L->numeroElementos == 1){
		printf("1 membro da lista:%d\n",L->vec[0].chave);
		printf("1 membro da lista:%s\n",L->vec[0].info);
		printf("\n");
	}
	else{
		for (i = 0; i <= (L->numeroElementos)-1; i++){
			printf("%d membro da lista:%d\n",i+1,L->vec[i].chave);
			printf("%d membro da lista:%s\n",i+1,L->vec[i].info);
			printf("\n");
		}
	}
};

int remover(int p, Lista *L){

	int i;

	if (p < 0 || p > L->numeroElementos) return 0;
	for (i = 0; i < L->numeroElementos-1; i++){
		L->vec[p+i].chave = L->vec[p+i+1].chave;
		strcpy(L->vec[p+i].info,L->vec[p+i+1].info);
	}
	L->numeroElementos--;
};

int tamanho(Lista *L){
	return L->numeroElementos;
};

void apagar_lista(Lista *L){

	int i;
	for (i = 0; i < L->numeroElementos; ++i){
		strcpy(L->vec[i].info,"\0");
		L->vec[i].chave = 0;
	}
	L->numeroElementos = 0;
};

void destruir_lista(Lista *L){
	free(L);
};

Lista *copia(Lista *L){

	int i;

	Lista *listaCopia = aloca();
	definir(listaCopia);

	listaCopia->numeroElementos = L->numeroElementos;
	for (i = 0; i < L->numeroElementos; i++){
		listaCopia->vec[i].chave = L->vec[i].chave;
		strcpy(listaCopia->vec[i].info,L->vec[i].info);
	}

	return(listaCopia);
};

