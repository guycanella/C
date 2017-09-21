
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include "functions.h"


int main(){

	int vec[5] = {1,2,3,4,5};
	double vec2[5] = {1.3,2.5,3.8,4.7,5.0}, *vec3, **mx4, **fmx, *fvec;
	vec3 = zeros(5);
	mx4 = zeros_mx(5,5);
	fmx = fill_mx_rand(6,6);
	fvec = fill_rand(3);

	print_vec(vec3,5,"l");
	print_vec(fvec,3,"l");
	print_mx(mx4,5,5);
	print_mx(fmx,6,6);

	printf("Somatório de inteiros = %d\n",sum(vec,5));
	printf("Média de inteiros = %lf\n",mean(vec,5));
	printf("Somatório de pontos flutuantes = %.1lf\n",sum_db(vec2,5));
	printf("Média de pontos flutuantes = %lf\n",mean_db(vec2,5));
	printf("Produtório de inteiros = %d\n",prod(vec,5));
	printf("Produtório de pontos flutuantes = %.3lf\n",prod_db(vec2,5));

	free(vec3);
	free(mx4);
	free(fmx);
	free(fvec);
	return 0;
}
