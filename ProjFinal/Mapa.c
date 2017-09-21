#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mapa.h"

/*
		PROGRAMA DE UM DICIONÁRIO DO TIPO MAPA DESENVOLVIDO POR:

		GUILHERME ARANTES CANELLA	|	N USP: 9284000
		FELIPE MARABOLI				|	N USP: 8657306

		DISCIPLINA: ESTRUTURA DE DADOS
		PROF: RICARDO J. G. B. CAMPELLO
*/

// FUNÇÃO QUE RETORNA O ELEMENTO QUE POSSUI A K PROCURADA
tipo_elem search(char *k, Arvore *T){

	Nodo *nodoAux;

        if(isEmpty(T)){
		tipo_elem y;
		Nodo *nulo;
		nulo = createNodoNulo();
		y = elem(nulo);
		return y;
	}
	nodoAux = searchAux2(k,root(T),T);
	if(nodoAux == NULL){
            
            tipo_elem y;
            Nodo *nulo;
            nulo = createNodoNulo();
            y = elem(nulo);
            return y;
	}else{
            tipo_elem x;
            x = elem(nodoAux);
            return x;
	}	
};

// FUNÇÃO QUE INSERE O ELEMENTO X NA ÁRVORE T QUE RETORNA BOOLEANO
bool insert(tipo_elem x, Arvore *T){

	Nodo *nodoFinal;

	if(isEmpty(T)){
            createNodo(x,root(T),T);
            incrementTree(T);
            return true;
	}

	nodoFinal = searchAux(x,root(T),T);

	if(nodoFinal == NULL) return false;
	else{
            return true;
        }

};

// FUNÇÃO QUE SUBSTITUI UM DETERMINANDO ELEMENTO DENTRO DA ÁRVORE PELO ELEMENTO X
bool replace(tipo_elem x, Arvore *T){

	Nodo *y;
        
        y = searchAux2(x.chave,root(T),T);
        if (y != NULL){  //se a saida de strcmp for 0 , significa que as chaves sao iguais
            changeElem(x,y);   // copia a info de v em x
            return true;
        }
        else return false;

};

// FUNÇÃO QUE REMOVE UM ELEMENTO DA ÁRVORE E RETORNA ELE
tipo_elem remover(char *k, Arvore *T){
	
    tipo_elem x, p_elem, no_elem;
    Nodo *p, *no;

    p = searchAux2(k,root(T),T);
    
    if(p == NULL){
        x = createElementoNulo();
        return x;
    }else{
        if(p == root(T)){
            if(size(T) == 1){
                x = elem(p);
                pointRootNull(T);
                free(p);
                decrementTree(T);
                return x;
            }else if(isSemiExternal(p)){
                x = elem(p);
                removeAboveExternalForRoot(T,p);
                decrementTree(T);
                return x;
            }else{
                no = goToLeft(rightChild(p));
                x = elem(no);
                p_elem = elem(p);
                changeElem(x,p);
                if(isSemiExternal(no)){
                    removeAboveExternal(no);
                    decrementTree(T);
                    return p_elem;
                }else{
                    removeExternal(no);
                    decrementTree(T);
                    return p_elem;
                }
            }
        }else{
            if(isExternal(p)){
                x = elem(p);
                removeExternal(p);
                decrementTree(T);
                return x;
            }else if(isSemiExternal(p)){
                x = elem(p);
                removeAboveExternal(p);
                decrementTree(T);
                return x;
            }else{
                no = findSubstitute(T,p);
                if(isSemiExternal(no)){
                    p_elem = elem(p);
                    no_elem = elem(no);
                    changeElem(no_elem,p);
                    removeAboveExternal(no);
                    decrementTree(T);
                    return p_elem;
                }else{
                    p_elem = elem(p);
                    no_elem = elem(no);
                    changeElem(no_elem,p);
                    removeExternal(no);
                    decrementTree(T);
                    return p_elem;
                }
            }
        }
    }
};

// FUNÇÃO QUE LISTA AS PALAVRAS DO MAPA EM UM PERCURSO INTER-FIXADO
void listInOrder(Arvore *T){
    
    inOrder(root(T));
};


void desllocNodo(Nodo *p){

    if(p != NULL){
        desllocNodo(leftChild(p));
        desllocNodo(rightChild(p));
        free(p);
    }
};
