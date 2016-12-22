#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista-din.h"

struct tipo_elem{
	int chave;
	char info[50];
};

struct lista{
	int numeroElementos;
	Nodo *head, *tail;
};

struct list_node{

	Celula *elem;
	struct list_node *lig;
};

Lista *definir(){
	Lista *L = (Lista*)malloc(sizeof(Lista));
	L->numeroElementos = 0;
	L->head = NULL;
	L->tail = NULL;

	return L;
}

void *acessa_cel(Celula *x){
	printf("chave: %d\n",x->chave);
	printf("info: %s\n",x->info);
	printf("\n");
}

Celula *define_cel(int chave, char *info){

	Celula *cel;

	cel = (Celula*)malloc(sizeof(Celula));
	cel->chave = chave;
	strcpy(cel->info,info);

	return cel;
}

Celula *aloca_cel(){

	Celula *cel;

	cel = (Celula*)malloc(sizeof(Celula));

	return cel;
}

Nodo *inserir_frente(Celula *x, Lista *L){

	Nodo *pa = (Nodo*)malloc(sizeof(Nodo));
	pa->elem = x;
	pa->lig = L->head;
	L->head = pa;
	if (L->tail == NULL){
		L->tail = L->head;
	}
	L->numeroElementos++;

	return pa;
}

Celula *remover_frente(Lista *L){
	Celula *x;
	Nodo *pa;
	pa = L->head;
	L->head = pa->lig;
	if (L->head == NULL) L->tail = NULL;

	x = pa->elem;
	free(pa);
	L->numeroElementos--;

	return x;
}

Nodo *inserir_final(Celula *x, Lista *L){
	Nodo *pa = (Nodo*)malloc(sizeof(Nodo));
	pa->elem = x;
	pa->lig = NULL;

	if (L->head == NULL) L->head = pa;
	else (L->tail)->lig = pa;
	L->tail = pa;
	L->numeroElementos++;

	return pa;
}

Celula *remover_final(Lista *L){
	Celula *x;
	Nodo *pa;
	pa = L->head;
	if ((L->head)->lig == NULL){
		L->tail = NULL;
		L->head = NULL;
	}
	else{
		while (pa->lig != L->tail) pa = pa->lig;
		L->tail = pa;
		pa = pa->lig;
		(L->tail)->lig = NULL;
	}

	x = pa->elem;
	free(pa);
	L->numeroElementos--;

	return x;
}

Celula *Elemento(Nodo *pa){
	return (pa->elem);
}

int tamanho(Lista *L){

	return L->numeroElementos;
}

Celula elemento(Nodo *pa){

	return (pa->elem);
}

void lista_vazia(Lista *L){

	if (L->numeroElementos == 0) printf("TRUE\n");
	else printf("FALSE\n");
	
}
