#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista-din.h"

int main(){
	
	Lista *L1 = definir();
	Nodo *nodo1, *nodo2, *nodo3, *nodo4;
	Celula *elem1, *elem2, *elem3, *elem4; 

	elem1 = define_cel(50,"guilherme");
	elem2 = define_cel(37,"carlos");
	elem3 = define_cel(88,"fabio");
	elem4 = define_cel(13,"anderson");
	nodo1 = inserir_frente(elem1,L1);
	nodo2 = inserir_frente(elem2,L1);
	nodo3 = inserir_frente(elem3,L1);
	nodo4 = inserir_frente(elem4,L1);

	mostrarElementosLista(L1);

	return 0;
}
