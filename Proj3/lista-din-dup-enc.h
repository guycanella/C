
//TAD DE LISTA DINAMICA SIMPLESMENTE ENCADEADA
typedef struct list_node Nodo;

// DEFINE O TIPO CELULA
typedef struct tipo_elem Celula;

// DEFINE O TIPO LISTA
typedef struct lista Lista;

// DEFINE UMA CELULA
Celula *aloca_cel(int chave, char *info);

// DEFINE UMA LISTA
Lista *definir();

// INSERE UM ELEMENTO/NODO NA LISTA
Nodo *inserir_frente(Celula *x, Lista *L);

// REMOVE O PRIMEIRO ELEMENTO DA LISTA
Celula *remover_frente(Lista *L);

// INSERE UM ELEMENTO NO FINAL DA LISTA
Nodo *inserir_final(Celula *x, Lista *L);

// REMOVE O ELEMENTO FINAL DA LISTA
Celula *remover_final(Lista *L);

// INSERIR UM ELEMENTO APOS O ELEMENTO P
Nodo *inserir_apos(Nodo *p, Celula *x, Lista *L);