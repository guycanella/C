#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main(){
	
	int a, b, c;

	Lista *listaA = aloca(), *listaB;

	definir(listaA);

	inserir(listaA,55,"victor");
	inserir(listaA,40,"german");
	inserir(listaA,120,"lucas");
	inserir(listaA,37,"akio");
	inserir(listaA,90,"gian");
	inserir(listaA,80,"gui");

	print_lista(listaA);
	printf("\n");
	printf("Digite uma chave para a procura da pessoa:\n");
	scanf("%d",&a);
	b = localizar(a,listaA);

	printf("A pessoa se encontra na posição: %d\n",b);
	printf("Digite uma posição para ser removida:\n");
	scanf("%d",&c);

	remover(c-1,listaA);
	print_lista(listaA);
	printf("\n");

	listaB = copia(listaA);

	printf("\n");
	printf("Cópia da lista:\n");
	printf("\n");

	print_lista(listaB);

	return 0;
}
