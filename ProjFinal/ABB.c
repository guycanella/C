#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABB.h"

/*
		PROGRAMA DE UM DICIONÁRIO DO TIPO MAPA DESENVOLVIDO POR:

		GUILHERME ARANTES CANELLA	|	N USP: 9284000
		FELIPE MARABOLI				|	N USP: 8657306

		DISCIPLINA: ESTRUTURA DE DADOS
		PROF: RICARDO J. G. B. CAMPELLO
*/

/*
	Sistema de uma árvore ABB:
		Uma arvore contem um Nodo que contem um tipo_elem, ou seja,
		Arvore > Nodo > tipo_elem

*/

// DEFINE O REGISTRO TIPO_ELEM QUE IRÁ CONTER OS CAMPOS CHAVE E INFO
struct registro_elemento{

	char chave[30];
	char info[30];
};

// DEFINE O REGISTRO DO NODO QUE CONTEM TRES PONTEIROS, UM PARA O FILHO ESQUERDO, UM PARA O FILHO DIREITO E 
// OUTRO PARA O PAI
struct nodo{

	tipo_elem elemento;
	struct nodo *left_son, *right_son;
	struct nodo *father;
};

// DEFINE O REGISTRO ARVORE QUE IRA CONTEM OS NODOS
struct arvore{

	int numeroNodos;
	Nodo *raiz;
};

// FUNÇÃO QUE INICIALIZA UMA ÁRVORE
Arvore *createTree(){

	Arvore *T = (Arvore *)malloc(sizeof(Arvore));
	T->numeroNodos = 0;
	T->raiz = NULL;

	return T;
};

// FUNÇÃO QUE INICIALIZA UM NODO
Nodo *createNodo(tipo_elem x, Nodo *p, Arvore *T){

	Nodo *No = (Nodo*)malloc(sizeof(Nodo));

    if(isEmpty(T)) T->raiz = No;
	No->elemento = x;
	No->father = p;
	No->right_son = NULL;
	No->left_son = NULL;

	return No;
};

// FUNÇÃO QUE CRIA UM NODO NULO
Nodo *createNodoNulo(){

	Nodo *nulo = (Nodo*)malloc(sizeof(Nodo));

	nulo->elemento.chave[0] = '\0';
	nulo->elemento.info[0] = '\0';
	nulo->father = NULL;
	nulo->right_son = NULL;
	nulo->left_son = NULL;

	return nulo;
};

// FUNÇÃO QUE CRIA UM ELEMENTO NULO
tipo_elem createElementoNulo(){

	tipo_elem x;
	x.chave[0] = '\0';
	x.info[0] = '\0';

	return x;
};

// FUNÇÃO QUE CRIA UM NODO CORRESPONDENTE AO FILHO DIREITO
Nodo *createRightNodo(tipo_elem x, Nodo *p, Arvore *T){

	p->right_son = createNodo(x,p,T);

	return p->right_son;
};

// FUNÇÃO QUE CRIA UM NODO CORRESPONDENTE AO FILHO ESQUERDO
Nodo *createLeftNodo(tipo_elem x, Nodo *p, Arvore *T){

	p->left_son = createNodo(x,p,T);

	return p->left_son;
};

// FUNÇÃO QUE RETORNA A RAIZ DA ÁRVORE
Nodo *root(Arvore *T){

	return T->raiz;
};

// FUNÇÃO QUE FAZ A RAIZ DE T APONTAR PARA NULL
void pointRootNull(Arvore *T){

	T->raiz = NULL;
};

// FUNÇÃO QUE APONTA A RAIZ DE T PARA P
void pointRootTo(Arvore *T, Nodo *p){

	T->raiz = p;
};

// FUNÇÃO QUE RETORNA O NÚMERO DE NODOS DA ÁRVORE
int size(Arvore *T){

	return T->numeroNodos;
};

// FUNÃO QUE VERIFICA SE A ÁRVORE ESTÁ VAZIA OU NÃO
bool isEmpty(Arvore *T){

	if(size(T) == 0) return true;
	else return false;
};

// FUNÇÃO QUE INCREMENTA O NÚMERO DE NODOS DA ÁRVORE
void incrementTree(Arvore *T){

	T->numeroNodos++;
};

// FUNÇÃO QUE DECREMENTA O NÚMERO DE NODOS DA ÁRVORE
void decrementTree(Arvore *T){

	if(T->numeroNodos != 0) T->numeroNodos--;
};

// FUNÇÃO QUE RETORNA O FILHO DIREITO DO NODO P
Nodo *rightChild(Nodo *p){

	return p->right_son;
};

// FUNÇÃO QUE RETORNA O FILHO ESQUERDO DO NODO P
Nodo *leftChild(Nodo *p){

	return p->left_son;
};

// FUNÇÃO QUE RETORNA O PAI DO NODO P
Nodo *parent(Nodo *p){

	return p->father;
};

// VERIFICA SE O NODO P É UM NODO INTERNO
bool isInternal(Nodo *p){

	if ((p->left_son != NULL) && (p->right_son != NULL)) return true;
	else return false;
};

// VERIFICA SE O NODO P É UM NODO EXTERNO
bool isExternal(Nodo *p){

	if ((p->left_son == NULL) && (p->right_son == NULL)) return true;
	else return false;
};

// FUNÇÃO QUE VERIFICA SE O NODO P É SEMI-EXTERNO, OU SEJA, SE ELE POSSUI UM DOS FILHOS APONTANDO PARA NULL
bool isSemiExternal(Nodo *p){
    
    if (((p->left_son == NULL) && (p->right_son != NULL)) || ((p->left_son != NULL) && (p->right_son == NULL))){
    	return true;
	}else return false;
};

// VERIFICA SE O NODO P É O FILHO ESQUERDO
bool isLeftChild(Nodo *p){

	if(p == leftChild(parent(p))) return true;
	else return false;
};

// VERIFICA SE O NODO P É O FILHO DIREITO
bool isRightChild(Nodo *p){

	if(p == rightChild(parent(p))) return true;
	else return false;
};

// VERIFICA SE O NODO P É A RAIZ DA ÁRVORE
bool isRoot(Arvore *T, Nodo *p){

	if(root(T) == p) return true;
	else return false;
};

// RETORNA O ELEMENTO DO NODO P
tipo_elem elem(Nodo *p){

	tipo_elem a;
	if(p == NULL){
		
		a.chave[0] = '\0';
		a.info[0] = '\0';
		return a;
	}else{

		strcpy(a.chave,p->elemento.chave);
		strcpy(a.info,p->elemento.info);		
		return a;
	}
};

// FUNÇÃO QUE PROCURA UM ELEMENTO E RETORNA UM PONTEIRO PARA UM NODO (AUXILIA NA FUNÇÃO INSERT)
Nodo *searchAux(tipo_elem k, Nodo *p, Arvore *T){

	tipo_elem x;
	Nodo *nodAux;
	x = elem(p);

	if(strcmp(k.chave,x.chave) > 0){

		if(rightChild(p) == NULL){

			nodAux = createRightNodo(k,p,T);
			incrementTree(T);
			return nodAux;
		}else{

			return searchAux(k,rightChild(p),T);
		}
	}else if(strcmp(k.chave,x.chave) < 0){

		if(leftChild(p) == NULL){

			nodAux = createLeftNodo(k,p,T);
			incrementTree(T);
			return nodAux;
		}else{
			return searchAux(k,leftChild(p),T);
		}
	}else{

		return NULL;
	}
};

// FUNÇÃO DE PROCURA QUE AUXILIA NA FUNÇÃO 'SEARCH' RETORNA UM PONTEIRO PARA NODO
Nodo *searchAux2(char *k, Nodo *p, Arvore *T){

    tipo_elem x;
	x = elem(p);
        
	if(strcmp(k,x.chave) > 0){

		if(rightChild(p) == NULL){

			return NULL;
		}else{
            return searchAux2(k,rightChild(p),T);
		}
	}else if(strcmp(k,x.chave) < 0){

		if(leftChild(p) == NULL){

			return NULL;
		}else{
            return searchAux2(k,leftChild(p),T);
		}
	}else{
            return p;
	}
};

void visit(Nodo *p){
    printf("%s\n",p->elemento.chave);
};

void inOrder(Nodo *p){

    if(p != NULL){
        inOrder(leftChild(p));
        visit(p);
        inOrder(rightChild(p));
    }
};

void changeElem(tipo_elem x, Nodo *p){
    
    p->elemento = x;
};

Nodo *goToLeft(Nodo *p){
    
    if (leftChild(p) == NULL) return p;
    else return goToLeft(leftChild(p));
};

Nodo *goToRight(Nodo *p){
    
    if (rightChild(p) == NULL) return p;
    else return goToRight(rightChild(p));
};

Nodo *findSubstitute(Arvore *T, Nodo *p){
    
    Nodo *no;
    tipo_elem x, p_elem;
    x = elem(root(T));
    p_elem = elem(p);
    
    if(strcmp(p_elem.chave,x.chave) > 0){
        no = goToLeft(rightChild(p));
        return no;
       
    }else{
        no = goToRight(leftChild(p));
        return no;
        
    }
};

void removeAboveExternal(Nodo *p){

	if(isRightChild(p)){
		if(rightChild(p) != NULL){
			parent(p)->right_son = rightChild(p);
			rightChild(p)->father = parent(p);
			free(p);
		}else{
			parent(p)->right_son = leftChild(p);
			leftChild(p)->father = parent(p);
			free(p);
		}
	}else{
		if(rightChild(p) != NULL){
			parent(p)->left_son = rightChild(p);
			rightChild(p)->father = parent(p);
			free(p);
		}else{
			parent(p)->left_son = leftChild(p);
			leftChild(p)->father = parent(p);
			free(p);
		}
	}
};

void removeAboveExternalForRoot(Arvore *T,Nodo *p){

	if(rightChild(p) != NULL){
		pointRootTo(T,rightChild(p));
		rightChild(p)->father = NULL;
		free(p);
	}else{
		pointRootTo(T,leftChild(p));
		leftChild(p)->father = NULL;
		free(p);
	}
};

void removeExternal(Nodo *p){

	if(isLeftChild(p)){
		parent(p)->left_son = NULL;
		free(p);
	}else{
		parent(p)->right_son = NULL;
		free(p);
	}
};

