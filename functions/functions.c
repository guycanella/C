
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int sum(int array[], int n){
	int soma=0;
	for(int i=0; i<n; i++){
		soma = soma + array[i];
	}
	return soma;
}

double sum_db(double array[], int n){
	double soma=0.0;
	for(int i=0; i<n; i++){
		soma = soma + array[i];
	}
	return soma;
}

int prod(int array[], int n){
	int factor=1;
	for(int i=0; i<n; i++){
		factor = factor*array[i];
	}
	return factor;
}

double prod_db(double array[], int n){
	double factor=1.0;
	for(int i=0; i<n; i++){
		factor = factor*array[i];
	}
	return factor;
}

double mean(int array[], int n){
	return (double) sum(array,n)/n;
}

double mean_db(double array[], int n){
	return sum_db(array,n)/n;
}

double fact(int count){
	int i;
	double ACM;
	ACM=1;

	for (i=1; i<=count; i++){
		ACM = ACM*i;
	}
	return ACM;
}

double **allocate_mx(int lin, int col){

	int i;
	double **matriz;
	matriz = (double**) malloc(lin * sizeof (double*));

	for (i=0; i<lin; i++){
		 matriz[i] = (double*) malloc(col * sizeof (double));
	}

	return matriz;
}

double *allocate_vec(int cell){
	double *vec;

	vec = (double*) malloc(cell * sizeof(double));

	return vec;
}

double *zeros(int cell){
	int i;
	double *array = allocate_vec(cell);
	for(int i=0; i<cell; i++){
		array[i] = 0.0;
	}
	return array;
}

double **zeros_mx(int lin, int col){
	int i;
	double **matrix = allocate_mx(lin,col);
	for(int i=0; i<lin; i++){
		for(int j=0; j<col; j++){
			matrix[i][j] = 0.0;
		}
	}
	return matrix;
}

double *ones(int cell){
	int i;
	double *array = allocate_vec(cell);
	for(int i=0; i<cell; i++){
		array[i] = 1.0;
	}
	return array;
}

double **ones_mx(int lin, int col){
	int i;
	double **matrix = allocate_mx(lin,col);
	for(int i=0; i<lin; i++){
		for(int j=0; j<col; j++){
			matrix[i][j] = 1.0;
		}
	}
	return matrix;
}

double **fill_mx(int n, int lin, int col){
	int i;
	double m = (double) n;
	double **matrix = allocate_mx(lin,col);
	for(int i=0; i<lin; i++){
		for(int j=0; j<col; j++){
			matrix[i][j] = m;
		}
	}
	return matrix;
}


double *fill(int n, int cell){
	int i;
	double m = (double) n;
	double *array = allocate_vec(cell);
	for(int i=0; i<cell; i++){
		array[i] = m;
	}
	return array;
}

double *fill_rand(int cell){
	srand(clock());
	int i;
	double *array = allocate_vec(cell);
	for(int i=0; i<cell; i++){
		array[i] = rand()/(double)RAND_MAX;
	}
	return array;
}

double **fill_mx_rand(int lin, int col){
	srand(clock());
	int i;
	double **matrix = allocate_mx(lin,col);
	for(int i=0; i<lin; i++){
		for(int j=0; j<col; j++){
			matrix[i][j] = rand()/(double)RAND_MAX;
		}
	}
	return matrix;
}

void print_vec(double *array, int cell, char *mode){
	if(mode == "l"){
		for(int i=0; i<cell; i++){
			printf("%.2lf ",array[i]);
		}
		printf("\n");
	}else if(mode == "b"){
		for(int i=0; i<cell; i++){
			printf("%.2lf\n",array[i]);
		}
	}
}

void print_mx(double **mx, int lin, int col){
	for(int i=0; i<lin; i++){
		for(int j=0; j<col; j++){
			printf("%.2lf ",mx[i][j]);
		}
		printf("\n");
	}
}

int trace(int **array, int n){
	int soma=0;
	for(int i=0; i<n; i++){
		soma = soma + array[i][i];
	}
	return soma;
}

double trace_db(double **array, int n){
	double soma=0;
	for(int i=0; i<n; i++){
		soma = soma + array[i][i];
	}
	return soma;
}

void bubble_sort(int *array, int n){
	int temp;

	for(int i=0; i<n; i++){
		int flag = 0;
		for(int j=0; j<n-i-1; j++){
			if(array[j] > array[j+1]){
				temp			= array[j];
				array[j]		= array[j+1];
				array[j+1]	= temp;
				flag=1;
			}
		}
		if(!flag) break;
	}
}

void bubble_sort_db(double *array, int n){
	double temp;

	for(int i=0; i<n; i++){
		int flag = 0;
		for(int j=0; j<n-i-1; j++){
			if(array[j] > array[j+1]){
				temp			= array[j];
				array[j]		= array[j+1];
				array[j+1]	= temp;
				flag=1;
			}
		}
		if(!flag) break;
	}
}

void insertion_sort(int *array, int n){
	int j, key;

	for(int i=0; i<n; i++){
		key = array[i];
		j = i-1;
		while(j >= 0 && key < array[j]){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	}
}

void insertion_sort_db(double *array, int n){
	int j;
	double key;

	for(int i=0; i<n; i++){
		key = array[i];
		j = i-1;
		while(j >= 0 && key < array[j]){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	}
}

void selection_sort(int *array, int n){
	int min, temp;

	for(int i=0; i<n-1; i++){
		min = i;
		for(int j=i+1; j<n; j++){
			if(array[j] < array[min]){
				min = j;
			}
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}

void selection_sort_db(double *array, int n){
	double temp;
	int min;

	for(int i=0; i<n-1; i++){
		min = i;
		for(int j=i+1; j<n; j++){
			if(array[j] < array[min]){
				min = j;
			}
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}
