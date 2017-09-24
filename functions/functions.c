
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/*
 *	SIMPLE AND COMPLEX FUNCTIONS BUILT IN C
 *
 *		produced by Guilherme Canella
 *
 *
 *
 *
 *	Function: sum
 *		- a function that sum all elements in the array.
 *		The array must be an array of integers.
 *
 *	Arguments:
 *		- an array of integers
 *		- an integer that means the size of the array
 *
 *	Return:
 *		- the sum of all elements of the array
 *
*/
int sum(int array[], int n){
	int soma=0;
	for(int i=0; i<n; i++){
		soma = soma + array[i];
	}
	return soma;
}

/*
 *	Function: sum_db
 *		- a function that sum all elements in the array.
 *		The array must be an array of doubles.
 *
 *	Arguments:
 *		- an array of floats
 *		- an integer that means the size of the array
 *
 *	Return:
 *		- the sum of all elements of the array. A float number
 *
*/
double sum_db(double array[], int n){
	double soma=0.0;
	for(int i=0; i<n; i++){
		soma = soma + array[i];
	}
	return soma;
}

/*
 *	Function: prod
 *		- a function that multiply all elements in the array.
 *		The array must be an array of integers.
 *
 *	Arguments:
 *		- an array of integers
 *		- an integer that means the size of the array
 *
 *	Return:
 *		- the multiplication of all elements of the array.
 *
*/
int prod(int array[], int n){
	int factor=1;
	for(int i=0; i<n; i++){
		factor = factor*array[i];
	}
	return factor;
}

/*
 *	Function: prod_db
 *		- a function that multiply all elements in the array.
 *		The array must be an array of doubles.
 *
 *	Arguments:
 *		- an array of floats
 *		- an integer that means the size of the array
 *
 *	Return:
 *		- the multiplication of all elements of the array.
 *
*/
double prod_db(double array[], int n){
	double factor=1.0;
	for(int i=0; i<n; i++){
		factor = factor*array[i];
	}
	return factor;
}

/*
 *	Function: mean
 *		- a function that calculate the mean value of an array.
 *		The array must be an array of integers.
 *
 *	Arguments:
 *		- an array of integers
 *		- an integer that means the size of the array
 *
 *	Return:
 *		- the sum of all elements of the array.
 *
 *  Requirements:
 *  	- function sum
*/
double mean(int array[], int n){
	return (double) sum(array,n)/n;
}

/*
 *	Function: mean_db
 *		- a function that calculate the mean value of an array.
 *		The array must be an array of doubles.
 *
 *	Arguments:
 *		- an array of floats
 *		- an integer that means the size of the array
 *
 *	Return:
 *		- the sum of all elements of the array.
 *
 *  Requirements:
 *  	- function sum_db
 *
*/
double mean_db(double array[], int n){
	return sum_db(array,n)/n;
}

/*
 *	Function: fact
 *		- a function that calculate the factorial of a number
 *
 *	Arguments:
 *		- an integer
 *
 *	Return:
 *		- the factorial of the argument. It returns a float number
 *
*/
double fact(int count){
	int i;
	double ACM;
	ACM=1;

	for (i=1; i<=count; i++){
		ACM = ACM*i;
	}
	return ACM;
}

/*
 *	Function: allocate_mx
 *		- a function that allocate dynamically a matrix
 *
 *	Arguments:
 *		- 1th: an integer that means the number of rows of the matrix
 *		- 2th: an integer that means the number of columns of the matrix
 *
 *	Return:
 *		- a double pointer for the matrix
 *
*/
double **allocate_mx(int lin, int col){

	int i;
	double **matriz;
	matriz = (double**) malloc(lin * sizeof (double*));

	for (i=0; i<lin; i++){
		 matriz[i] = (double*) malloc(col * sizeof (double));
	}

	return matriz;
}

/*
 *	Function: allocate_vec
 *		- a function that allocate dynamically an array
 *
 *	Arguments:
 *		- an integer that means the number of elements in an array
 *
 *	Return:
 *		- a pointer for the array
 *
*/
double *allocate_vec(int cell){
	double *vec;

	vec = (double*) malloc(cell * sizeof(double));

	return vec;
}

/*
 *	Function: zeros
 *		- a function that initiate dynamically an array of zeros
 *
 *	Arguments:
 *		- an integer that means the number of elements in an array
 *
 *	Return:
 *		- a pointer for the array
 *
 *  Requirements:
 *  	- function allocate_vec
*/
double *zeros(int cell){
	int i;
	double *array = allocate_vec(cell);
	for(int i=0; i<cell; i++){
		array[i] = 0.0;
	}
	return array;
}

/*
 *	Function: zeros_mx
 *		- a function that initiate dynamically a matrix of zeros
 *
 *	Arguments:
 *		- 1th: an integer that means the number of rows of the matrix
 *		- 2th: an integer that means the number of columns of the matrix
 *
 *	Return:
 *		- a double pointer for the matrix
 *
 *  Requirements:
 *  	- function allocate_mx
*/
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

/*
 *	Function: ones
 *		- a function that initiate dynamically an array of ones
 *
 *	Arguments:
 *		- an integer that means the number of elements in an array
 *
 *	Return:
 *		- a pointer for the array
 *
 *  Requirements:
 *  	- function allocate_vec
*/
double *ones(int cell){
	int i;
	double *array = allocate_vec(cell);
	for(int i=0; i<cell; i++){
		array[i] = 1.0;
	}
	return array;
}

/*
 *	Function: ones_mx
 *		- a function that initiate dynamically a matrix of ones
 *
 *	Arguments:
 *		- 1th: an integer that means the number of rows of the matrix
 *		- 2th: an integer that means the number of columns of the matrix
 *
 *	Return:
 *		- a double pointer for the matrix
 *
 *  Requirements:
 *  	- function allocate_mx
*/
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

/*
 *	Function: fill_mx
 *		- a function that initiate dynamically a matrix where all the 
 *		elements are equal to the first argument
 *
 *	Arguments:
 *		- 1th: an integer that means the element that will fill the matrix
 *		- 2th: an integer that means the number of rows of the matrix
 *		- 3th: an integer that means the number of columns of the matrix
 *
 *	Return:
 *		- a double pointer for the matrix
 *
 *  Requirements:
 *  	- function allocate_mx
*/
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

/*
 *	Function: fill
 *		- a function that initiate dynamically an array where all the 
 *		elements are equal to the first argument
 *
 *	Arguments:
 *		- 1th: an integer that means the element that will fill the array
 *		- 2th: an integer that means the number of elements of the array
 *
 *	Return:
 *		- a pointer for the array
 *
 *  Requirements:
 *  	- function allocate_vec
*/
double *fill(int n, int cell){
	int i;
	double m = (double) n;
	double *array = allocate_vec(cell);
	for(int i=0; i<cell; i++){
		array[i] = m;
	}
	return array;
}

/*
 *	Function: fill_rand
 *		- a function that initiate dynamically an array where all the 
 *		elements are random numbers between 0 and 1
 *
 *	Arguments:
 *		- 1th: an integer that means the number of elements of the array
 *
 *	Return:
 *		- a pointer for the array
 *
 *  Requirements:
 *  	- function allocate_vec
 *  	- library time.h
*/
double *fill_rand(int cell){
	srand(clock());
	int i;
	double *array = allocate_vec(cell);
	for(int i=0; i<cell; i++){
		array[i] = rand()/(double)RAND_MAX;
	}
	return array;
}

/*
 *	Function: fill_mx_rand
 *		- a function that initiate dynamically a matrix where all the 
 *		elements are random numbers between 0 and 1
 *
 *	Arguments:
 *		- 1th: an integer that means the number of rows of the matrix
 *		- 2th: an integer that means the number of columns of the matrix
 *
 *	Return:
 *		- a double pointer for the matrix
 *
 *  Requirements:
 *  	- function allocate_mx
 *  	- library time.h
*/
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

/*
 *	Function: range
 *		- a function that gives a double number between the values  
 *		min and max as arguments
 *
 *	Arguments:
 *		- 1th: an integer that means the minimum number in the interval
 *		- 2th: an integer that means the maximun number in the interval
 *
 *	Return:
 *		- a double number
 *
 *  Requirements:
 *  	- library time.h
*/
double range(int min, int max){
	srand(clock());
	double scale = rand()/(double)RAND_MAX;
	return (min + scale*(max - min));
}

/*
 *	Function: fill_vec_range
 *		- a function that gives an array of double numbers, which numbers   
 *		are random in interval of min and max 
 *
 *	Arguments:
 *		- 1th: an integer that means the minimum number in the interval
 *		- 2th: an integer that means the maximun number in the interval
 *		- 3th: an integer that means the size of the array
 *
 *	Return:
 *		- a double pointer of the array
 *
 *  Requirements:
 *  	- function allocate_vec
 *  	- function range
 *  	- library time.h
*/
double *fill_vec_range(int min, int max, int cell){
	double *vec = allocate_vec(cell);
	for(int i=0; i<cell; i++){
		vec[i] = range(min,max);
	}
	return vec;
}

/*
 *	Function: fill_vec_range
 *		- a function that gives a matrix of double numbers, which numbers   
 *		are random in interval of min and max 
 *
 *	Arguments:
 *		- 1th: an integer that means the minimum number in the interval
 *		- 2th: an integer that means the maximun number in the interval
 *		- 3th: an integer that means the number of rows of the matrix
 *		- 4th: an integer that means the number of columns of the matrix
 *
 *	Return:
 *		- a double pointer of the array
 *
 *  Requirements:
 *  	- function allocate_mx
 *  	- function range
 *  	- library time.h
*/
double **fill_mx_range(int min, int max, int lin, int col){
	double **array = allocate_mx(lin,col);
	for(int i=0; i<lin; i++){
		for(int j=0; j<col; j++){
			array[i][j] = range(min,max);
		}
	}
	return array;
}

/*
 *	Function: print_vec
 *		- a function that prints out the array in the different modes:
 *		the mode in line "l" or the mode in block "b"
 *
 *	Arguments:
 *		- 1th: a pointer for the array
 *		- 2th: an integer that means the size of the array
 *		- 3th: a char that means the mode to print the array
 *
 *	Return:
 *		- no return
 *
*/
void print_vec(double *array, int cell, char *mode){
	if(strncmp(mode,"b",1)){
		for(int i=0; i<cell; i++){
			printf("%.2lf ",array[i]);
		}
		printf("\n");
	}else{
		for(int i=0; i<cell; i++){
			printf("%.2lf\n",array[i]);
		}
	}
}

/*
 *	Function: print_mx
 *		- a function that prints out a matrix 
 *
 *	Arguments:
 *		- 1th: a double pointer for the matrix
 *		- 2th: an integer that means the number of rows of the matrix
 *		- 3th: an integer that means the number of columns of the matrix
 *
 *	Return:
 *		- no return
 *
*/
void print_mx(double **mx, int lin, int col){
	for(int i=0; i<lin; i++){
		for(int j=0; j<col; j++){
			printf("%.2lf ",mx[i][j]);
		}
		printf("\n");
	}
}

/*
 *	Function: trace
 *		- a function that calculates the trace of a matrix.
 *		The matrix must be a square matrix and fill with integers
 *
 *	Arguments:
 *		- 1th: a double pointer for the matrix
 *		- 2th: an integer that means the size of the matrix
 *
 *	Return:
 *		- no return
 *
*/
int trace(int **array, int n){
	int soma=0;
	for(int i=0; i<n; i++){
		soma = soma + array[i][i];
	}
	return soma;
}

/*
 *	Function: trace_db
 *		- a function that calculates the trace of a matrix.
 *		The matrix must be a square matrix and fill with doubles.
 *
 *	Arguments:
 *		- 1th: a double pointer for the matrix
 *		- 2th: an integer that means the size of the matrix
 *
 *	Return:
 *		- no return
 *
*/
double trace_db(double **array, int n){
	double soma=0;
	for(int i=0; i<n; i++){
		soma = soma + array[i][i];
	}
	return soma;
}

/*
 *	Function: bubble_sort
 *		- a function that sorts in ascending order an array
 *		of integers, using the 'bubble sort' algorithm.
 *
 *	Arguments:
 *		- 1th: a pointer for the array
 *		- 2th: an integer that means the size of the array
 *
 *	Return:
 *		- no return
 *
*/
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

/*
 *	Function: bubble_sort_db
 *		- a function that sorts in ascending order an array
 *		of doubles, using the 'bubble sort' algorithm.
 *
 *	Arguments:
 *		- 1th: a pointer for the array
 *		- 2th: an integer that means the size of the array
 *
 *	Return:
 *		- no return
 *
*/
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

/*
 *	Function: insertion_sort
 *		- a function that sorts in ascending order an array
 *		of integers, using the 'insertion sort' algorithm.
 *
 *	Arguments:
 *		- 1th: a pointer for the array
 *		- 2th: an integer that means the size of the array
 *
 *	Return:
 *		- no return
 *
*/
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

/*
 *	Function: insertion_sort_db
 *		- a function that sorts in ascending order an array
 *		of doubles, using the 'insertion sort' algorithm.
 *
 *	Arguments:
 *		- 1th: a pointer for the array
 *		- 2th: an integer that means the size of the array
 *
 *	Return:
 *		- no return
 *
*/
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

/*
 *	Function: selection_sort
 *		- a function that sorts in ascending order an array
 *		of integers, using the 'selection sort' algorithm.
 *
 *	Arguments:
 *		- 1th: a pointer for the array
 *		- 2th: an integer that means the size of the array
 *
 *	Return:
 *		- no return
 *
*/
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

/*
 *	Function: selection_sort_db
 *		- a function that sorts in ascending order an array
 *		of doubles, using the 'selection sort' algorithm.
 *
 *	Arguments:
 *		- 1th: a pointer for the array
 *		- 2th: an integer that means the size of the array
 *
 *	Return:
 *		- no return
 *
*/
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

int partition(double *array, int start, int end){
	int pivot = array[start];
	int i = start;
	int j = end-1;
	double aux;

	while(1){
		do i++; while(array[i] < pivot);
		do j--; while(array[j] > pivot);
		if(i >= j) return j;
		aux = array[i];
		array[i] = array[j];
		array[j] = aux;
	}
}

/*
 *	Function: quick_sort_db
 *		- a function that sorts in ascending order an array
 *		of doubles, using the 'quick sort' algorithm.
 *
 *	Arguments:
 *		- 1th: a pointer for the array
 *		- 2th: an integer that means the first position of the array
 *		- 3th: an integer that means the last position of the array
 *
 *	Return:
 *		- no return
 *
*/
void quick_sort_db(double *array, int start, int end){
	if(start < end){
		int q = partition(array,start,end);
		quick_sort_db(array,start,q);
		quick_sort_db(array,q+1,end);
	}
}













