#include "ABB.h"


/*
        PROGRAMA DE UM DICIONÁRIO DO TIPO MAPA DESENVOLVIDO POR:

        GUILHERME ARANTES CANELLA   |   N USP: 9284000
        FELIPE MARABOLI             |   N USP: 8657306

        DISCIPLINA: ESTRUTURA DE DADOS
        PROF: RICARDO J. G. B. CAMPELLO
*/


// FUNÇÃO QUE RETORNA O ELEMENTO QUE POSSUI A K PROCURADA
tipo_elem search(char *k, Arvore *T);

// FUNÇÃO QUE INSERE O ELEMENTO X NA ÁRVORE T QUE RETORNA BOOLEANO
bool insert(tipo_elem x, Arvore *T);

// FUNÇÃO QUE SUBSTITUI UM DETERMINANDO ELEMENTO DENTRO DA ÁRVORE PELO ELEMENTO X
bool replace(tipo_elem x, Arvore *T);

// FUNÇÃO QUE REMOVE UM ELEMENTO DA ÁRVORE E RETORNA ELE
tipo_elem remover (char *k, Arvore *T);

// FUNÇÃO QUE LISTA A ÁRVORE EM UM PERCURSO INTER-FIXADO
void listInOrder(Arvore *T);

void desllocNodo(Nodo *p);
