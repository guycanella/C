#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista-din-dup-enc.h"

struct tipo_elem {
	int chave;
	char info[50];
};

struct lista {
	int numeroElementos;
	Nodo *head, *tail;
};

struct list_node {
	Celula *elem;
	struct list_node *lig_next, *lig_prev;
};

Celula *aloca_cel(int chave, char *info){

	Celula *cel; 

	cel = (Celula*)malloc(sizeof(Celula));

	cel->chave = chave;
	strcpy(cel->info,info);

	return cel;
}

Lista *definir(){

	Lista *L;

	L = (Lista*)malloc(sizeof(Lista));
	L->numeroElementos = 0;
	L->head = NULL;
	L->tail = NULL;

	return L;
}

Nodo *inserir_frente(Celula *x, Lista *L){

	Nodo *Pa;

	Pa = (Nodo*)malloc(sizeof(Nodo));
	Pa->elem = x;
	Pa->lig_next = L->head;
	Pa->lig_prev = NULL; /* Mudança */
	L->head = Pa;
	if (L->tail == NULL) L->tail = L->head;
	else ((L->head)->lig_next)->lig_prev = Pa; /* Mudança */
	L->numeroElementos++;

	return Pa;
}

Celula *remover_frente(Lista *L){

	Celula *x;
	Nodo *Pa;

	Pa = L->head;
	L->head = Pa->lig_next;
	if (L->head == NULL) L->tail = NULL;
	else (L->head)->lig_prev = NULL;				/* Única mudança */
	x = Pa->elem;
	free(Pa);
	L->numeroElementos--;

	return x;
}

Nodo *inserir_final(Celula *x, Lista *L){

	Nodo *Pa;

	Pa = malloc(sizeof(Nodo));
	Pa->elem = x;
	Pa->lig_next = NULL;
	Pa->lig_prev = L->tail;							/* Única mudança */
	if (L->head == NULL) L->head = Pa;
	else (L->tail)->lig_next = Pa;
	L->tail = Pa;
	L->numeroElementos++;

	return Pa;
}

Celula *remover_final(Lista *L){

	Celula *x;
	Nodo *Pa;

	Pa = L->tail;
	L->tail = (L->tail)->lig_prev;
	if (L->tail == NULL) L->head = NULL;
	else (L->tail)->lig_next = NULL;
	x = Pa->elem;
	free(Pa);
	L->numeroElementos--;
	
	return x;
}

Nodo *inserir_apos(Nodo *p, Celula *x, Lista *L){

	Nodo *Pa;

	if (p == L->tail) return Inserir_final(x, L);
	else {
		Pa = (Nodo*)malloc(sizeof(Nodo));

		Pa->elem = x;
		Pa->lig_next = p->lig_next;
		Pa->lig_prev = p;
		p->lig_next = Pa;
		(Pa->lig_next)->lig_prev = Pa;
		L->numeroElementos++;
		return Pa;
	}
}


