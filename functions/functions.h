
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int sum(int array[], int n);

double sum_db(double array[], int n);

int prod(int array[], int n);

double prod_db(double array[], int n);

double mean(int array[], int n);

double mean_db(double array[], int n);

double fact(int count);

double **allocate_mx(int lin, int col);

double *allocate_vec(int cell);

double *zeros(int cell);

double **zeros_mx(int lin, int col);

double *ones(int cell);

double **ones_mx(int lin, int col);

double **fill_mx(int n, int lin, int col);

double *fill(int n, int cell);

double *fill_rand(int cell);

double **fill_mx_rand(int lin, int col);

double range(int min, int max);

double *fill_vec_range(int min, int max, int cell);

double **fill_mx_range(int min, int max, int lin, int col);

void print_vec(double *array, int cell, char *mode);

void print_mx(double **mx, int lin, int col);

int trace(int **array, int n);

double trace_db(double **array, int n);

void bubble_sort(int *array, int n);

void bubble_sort_db(double *array, int n);

void insertion_sort(int *array, int n);

void insertion_sort_db(double *array, int n);

void selection_sort(int *array, int n);

void selection_sort_db(double *array, int n);

void quick_sort(int *array, int start, int end);

void quick_sort_db(double *array, int start, int end);

