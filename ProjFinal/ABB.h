#define bool int
#define true 1
#define false 0

/*
        PROGRAMA DE UM DICIONÁRIO DO TIPO MAPA DESENVOLVIDO POR:

        GUILHERME ARANTES CANELLA   |   N USP: 9284000
        FELIPE MARABOLI             |   N USP: 8657306

        DISCIPLINA: ESTRUTURA DE DADOS
        PROF: RICARDO J. G. B. CAMPELLO
*/

/*
    Sistema de uma árvore ABB:
        Uma arvore contem um Nodo que contem um tipo_elem, ou seja,
        Arvore > Nodo > tipo_elem

*/

// DEFINE O REGISTRO TIPO_ELEM QUE IRÁ CONTER OS CAMPOS CHAVE E INFO
typedef struct {
    char chave[30];
    char info[30];

}tipo_elem;

// DEFINE O REGISTRO DO NODO QUE CONTEM TRES PONTEIROS, UM PARA O FILHO ESQUERDO, UM PARA O FILHO DIREITO E 
// OUTRO PARA O PAI
typedef struct nodo Nodo;

// DEFINE O REGISTRO ARVORE QUE IRA CONTEM OS NODOS
typedef struct arvore Arvore;

// FUNÇÃO QUE INICIALIZA UMA ÁRVORE
Arvore *createTree();

// FUNÇÃO QUE INICIALIZA UM NODO
Nodo *createNodo(tipo_elem x, Nodo *p, Arvore *T);

// FUNÇÃO QUE CRIA UM NODO CORRESPONDENTE AO FILHO DIREITO
Nodo *createRightNodo(tipo_elem x, Nodo *p, Arvore *T);

// FUNÇÃO QUE CRIA UM NODO CORRESPONDENTE AO FILHO ESQUERDO
Nodo *createLeftNodo(tipo_elem x, Nodo *p, Arvore *T);

// FUNÇÃO QUE CRIA UM NODO NULO
Nodo *createNodoNulo();

// FUNÇÃO QUE CRIA UM ELEMENTO NULO E RETORNA ESSE ELEMENTO
tipo_elem createElementoNulo();

// FUNÇÃO QUE RETORNA A RAIZ DA ÁRVORE
Nodo *root(Arvore *T);

// FUNÇÃO QUE APONTA O PONTEIRO RAIZ DA ÁRVORE T PARA NULL
void pointRootNull(Arvore *T);

// FUNÇÃO QUE APONTA O PONTEIRO RAIZ DA ÁRVORE T PARA O NODO P
void pointRootTo(Arvore *T, Nodo *p);

// FUNÇÃO QUE RETORNA O NÚMERO DE NODOS DA ÁRVORE
int size(Arvore *T);

// FUNÃO QUE VERIFICA SE A ÁRVORE ESTÁ VAZIA OU NÃO
bool isEmpty(Arvore *T);

// FUNÇÃO QUE INCREMENTA O NÚMERO DE NODOS DA ÁRVORE
void incrementTree(Arvore *T);

// FUNÇÃO QUE DECREMENTA O NÚMERO DE NODOS DA ÁRVORE
void decrementTree(Arvore *T);

// FUNÇÃO QUE RETORNA O FILHO DIREITO DO NODO P
Nodo *rightChild(Nodo *p);

// FUNÇÃO QUE RETORNA O FILHO ESQUERDO DO NODO P
Nodo *leftChild(Nodo *p);

// FUNÇÃO QUE RETORNA O PAI DO NODO P
Nodo *parent(Nodo *p);

// VERIFICA SE O NODO P É UM NODO INTERNO
bool isInternal(Nodo *p);

// VERIFICA SE O NODO P É UM NODO EXTERNO
bool isExternal(Nodo *p);

bool isSemiExternal(Nodo *p);

// VERIFICA SE O NODO P É O FILHO ESQUERDO
bool isLeftChild(Nodo *p);

// VERIFICA SE O NODO P É O FILHO DIREITO
bool isRightChild(Nodo *p);

// VERIFICA SE O NODO P É A RAIZ DA ÁRVORE
bool isRoot(Arvore *T, Nodo *p);

// RETORNA O ELEMENTO DO NODO P
tipo_elem elem(Nodo *p);

// FUNÇÃO DE BUSCA AUXILIAR QUE RETORNA UM NODO; PODE RETORNA NULO 
Nodo *searchAux(tipo_elem k, Nodo *p, Arvore *T);

// FUNÇÃO DE PROCURA QUE AUXILIA NA FUNÇÃO 'SEARCH'; RETORNA UM PONTEIRO PARA NODO
Nodo *searchAux2(char *k, Nodo *p, Arvore *T);

// FUNÇÃO QUE PRINTA NA TELA O ELEMENTO DO NODO P
void visit(Nodo *p);

// FUNÇÃO QUE LISTA TODOS OS NOMES DO DICIONÁRIOS, COMEÇANDO PELO MENOR NOME DE ACORDO COM O PERCURSO 
// INTER-FIXADO
void inOrder(Nodo *p);

// FUNÇÃO QUE INSERE O ELEMENTO X NO NODO P
void changeElem(tipo_elem x, Nodo *p);

// FUNCÃO QUE SEGUE OS NODOS DA ÁRVORE PASSANDO PELOS MEMBROS DA ESQUERDA
Nodo *goToLeft(Nodo *p);

// FUNCÃO QUE SEGUE OS NODOS DA ÁRVORE PASSANDO PELOS MEMBROS DA DIREITA
Nodo *goToRight(Nodo *p);

// FUNÇÃO QUE PROCURA UM SUBSTITUTO AO P, PARA ADICIONA-LO NA POSIÇÃO DE P
Nodo *findSubstitute(Arvore *T, Nodo *p);

// REMOVE UM NODO QUE SEJA SEMI-EXTERNO E NÃO SEJA RAIZ
void removeAboveExternal(Nodo *p);

// REMOVE UM NODO QUE SEJA SEMI-EXTERNO E SEJA RAIZ
void removeAboveExternalForRoot(Arvore *T,Nodo *p);

// REMOVE QUALQUER NODO QUE SEJA EXTERNO
void removeExternal(Nodo *p);

