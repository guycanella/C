
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include "functions.h"


int main(){

	double *vec = fill_vec_range(1,30,20);
	
	print_vec(vec,20,"l");
	quick_sort_db(vec,0,20);
	printf("\n");
	print_vec(vec,20,"l");
	free(vec);
	return 0;
}
