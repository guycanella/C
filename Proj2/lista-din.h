

//TAD DE LISTA DINAMICA SIMPLESMENTE ENCADEADA
typedef struct list_node Nodo;

// DEFINE O TIPO CELULA
typedef struct tipo_elem Celula;

// DEFINE O TIPO LISTA
typedef struct lista Lista;

// DEFINE UMA LISTA DE ANTEMÃO
Lista *definir();

// DEFINE UMA CELULA
Celula *define_cel(int chave, char *info);

//ACESSA OS ELEMENTOS DA CELULA
void *acessa_cel(Celula *x);

// FUNÇÃO QUE INSERE UM ELEMENTO NO COMEÇO DA LISTA E RETORNA UM NODO
Nodo *inserir_frente(Celula *x, Lista *L);

// REMOVE UM ELEMENTO DO COMEÇO DA LISTA
Celula *remover_frente(Lista *L);

// INSERE UM ELEMENTO NO FINAL DA LISTA
Nodo *inserir_final(Celula *x, Lista *L);

// REMOVE UM ELEMENTO DO FINAL DA LISTA
Celula *Remover_final(Lista *L);

// RETORNA UM ELEMENTO
Celula *Elemento(Nodo *pa);

// RETORNA O TAMANHO DA LISTA
int tamanho(Lista *L);

// RETORNA O ELEMENTO
Celula elemento(Nodo *pa);

//RETORNA SE A LISTA ESTÁ VAZIA OU NÃO
void lista_vazia(Lista *L);