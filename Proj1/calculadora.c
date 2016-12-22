#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
	%%%% Calculadora de matrizes e operações lógicas %%%

	Nome: Guilherme Arantes Canella
	Prof.: Dr. Ricardo Campello - ICMC
	Disciplina: Introdução à Programação SCC0121 - 2015
*/

double **aloca(int lin, int col);

double **soma_matriz(double **matrizA, double **matrizB, int lin, int col);

double **sub_matriz(double **matrizA, double **matrizB, int lin, int col);

void imprime(FILE *x, double **matriz, int lin, int col);

double **mult_matriz(double **matrizA, double **matrizB, int lin_a, int col_a, int col_b);

double det_triangular(double **matriz, int lin_a, int count);

double fatorial(int count);

void main(void){

// ---------------------------------- DECLARAÇÃO DE VARIÁVEIS --------------------------------------------------------------------------------------------


	int i, j, c, r, P1, K1, lin, col, res, leitura, lin_a, col_a, lin_b, col_b, ent, count, flag=1;
	char ch, objeto, operacao;
	FILE *arq;
	double ACM, aux, aux2, *vecA, *vecB, **matrizA, **matrizB, **MR;

// ---------------------------------- ABERTURA DO LOOPING DE LEITURA --------------------------------------------------------------------------------------

	arq = fopen("dados.txt","w");

// ---------------------------------- ABERTURA DO ARQUIVO DE TEXTO ----------------------------------------------------------------------------------------


	for (i=1; i>0; i++){  // FOR EXTERNO
		if (arq == NULL){
			printf("Erro, não foi possível abrir o arquivo.\n");
			exit(0);
		}

		//fprintf(arq, "Teste %d:\n", i);
		scanf(" %c",&objeto);

		if (objeto == 'M'){

			fprintf(arq,"Teste %d:\n",i);
			scanf(" %c",&operacao);
			if ((operacao == '+') || (operacao == '-') || (operacao == '*')){

				scanf(" %d %d",&lin_a,&col_a);

				matrizA = aloca(lin_a,col_a);
				for (lin=0; lin<lin_a; lin++){
					for (col=0; col<col_a; col++){
						scanf("%lf",&matrizA[lin][col]);
					}
				}

				scanf(" %d %d",&lin_b,&col_b);

				matrizB = aloca(lin_b,col_b);
				for (lin=0; lin<lin_b; lin++){
					for (col=0; col<col_b; col++){
						scanf("%lf",&matrizB[lin][col]);
					}
				}

				if ((operacao == '+') || (operacao == '-')){

					if ((lin_a == lin_b) && (col_a == col_b)){
						if (operacao == '+'){
							imprime(arq,soma_matriz(matrizA,matrizB,lin_a,col_a),lin_a,col_a);
							free(matrizA);
							free(matrizB);
						}
						else if (operacao == '-'){
							imprime(arq,sub_matriz(matrizA,matrizB,lin_a,col_a),lin_a,col_a);
							free(matrizA);
							free(matrizB);
						}
						else{
							fprintf(arq, "Operacao invalida para o(s) operando(s) dado(s).\n");
							free(matrizA);
							free(matrizB);
						}
					}
					else{
						fprintf(arq, "Operacao invalida para o(s) operando(s) dado(s).\n");
						free(matrizA);
						free(matrizB);
					}
				}
				else if (operacao == '*'){

					if (col_a == lin_b){
						imprime(arq,mult_matriz(matrizA,matrizB,lin_a,col_a,col_b),lin_a,col_b);
						free(matrizA);
						free(matrizB);
					}
					else if ((lin_a == 1) && (col_a == 1) || (lin_b == 1) && (col_b == 1)){
						if (lin_a == 1){
							MR = (double**)malloc(lin_b*sizeof(double*));
							for (i=0; i<lin_b; i++){
								MR[i] = (double*)malloc(col_b*sizeof(double));
							}

							for (i=0; i<lin_b; i++){
								for (j=0; j<col_b; j++){
									MR[i][j] = matrizA[0][0]*matrizB[i][j];
								}
							}
							imprime(arq,MR,lin_b,col_b);
							free(matrizA);
							free(matrizB);
						}
						else if (lin_b == 1){
							MR = (double**)malloc(lin_a*sizeof(double*));
							for (i=0; i<lin_a; i++){
								MR[i] = (double*)malloc(col_a*sizeof(double));
							}

							for (i=0; i<lin_a; i++){
								for (j=0; j<col_a; j++){
									MR[i][j] = matrizB[0][0]*matrizA[i][j];
								}
							}
							imprime(arq,MR,lin_a,col_a);
							free(matrizA);
							free(matrizB);
						}
					}
					else{
						fprintf(arq, "Operacao invalida para o(s) operando(s) dado(s).\n");
						free(matrizA);
						free(matrizB);
					}
				}
				else{
					fprintf(arq, "Operacao invalida para o(s) operando(s) dado(s).\n");
					free(matrizA);
					free(matrizB);
				}
			}
			else if (operacao == 'O'){

				scanf(" %d",&col_a);
				vecA = (double*)malloc(col_a * sizeof(double));
				for (i=0; i<col_a; i++){
					scanf("%lf",&vecA[i]);
				}

				scanf(" %d",&col_b);
				vecB = (double*) malloc(col_b * sizeof(double));
				for (i=0; i<col_b; i++){
					scanf("%lf",&vecB[i]);
				}

				if (col_a == col_b){
					ACM=0;
					for (j=0; j<col_a; j++){
						ACM = ACM + vecA[j]*vecB[j];
					}
					if (ACM == 0){
						fprintf(arq,"1\n");
						free(vecA);
						free(vecB);
					}
					else{
						fprintf(arq,"0\n");
						free(vecA);
						free(vecB);
					}
				}
				else{
					fprintf(arq, "Operacao invalida para o(s) operando(s) dado(s).\n");
					free(vecA);
					free(vecB);
				}				
			}
			else if (operacao == 'D'){

				scanf(" %d %d",&lin_a,&col_a);
				matrizA = aloca(lin_a,col_a);
				if (lin_a == col_a){

// -------------------------------------- LE A MATRIZ PARA CALCULAR O DETERMINANTE ----------------------------------------------------------------------------

					for (i=0; i<lin_a; i++){
						for (j=0; j<lin_a; j++){
							scanf("%lf",&matrizA[i][j]);
						}
					}

// ------------------------------------- CONFERE SE NÃO HÁ LINHAS E COLUNAS NULAS ------------------------------------------------------------------------------

					for (i=0; i<lin_a; i++){
						ACM=0;
						for (j=0; j<lin_a; j++){
							ACM = ACM + matrizA[i][j];
						}
						if (ACM == 0){
							fprintf(arq,"0\n");
							free(matrizA);
							goto fim;
						}
					}

					for (j=0; j<lin_a; j++){
						ACM=0;
						for (i=0; i<lin_a; i++){
							ACM = ACM + matrizA[i][j];
						}
						if (ACM == 0){
							fprintf(arq,"0\n");
							free(matrizA);
							goto fim;
						}
					}

// ---------------------------------------- VERIFICA SE EXISTEM LINHAS PROPORCIONAIS ----------------------------------------------------------------------------

					aux2=0;
					ent=0;
					for (col=0; col<lin_a-1; col++){
						for (i=1; i<lin_a-col; i++){
							for (j=0; j<lin_a; j++){
								if (aux2 == 0){
									if (matrizA[col][j] == 0) break;
									else{
										aux2 = matrizA[col+i][j]/matrizA[col][j];
										aux = matrizA[col+i][j]/matrizA[col][j];
									}
								}
								else{
									aux = matrizA[col+i][j]/matrizA[col][j];
									if (aux == aux2) ent++;
								}
							}
							if (ent >= lin_a-1){
								fprintf(arq,"0\n");
								free(matrizA);
								goto fim;
							}
							aux2=0;
							ent=0;
						}
					}

// -------------------------------------- VERIFICA SE EXISTEM COLUNAS PROPORCIONAIS ----------------------------------------------------------------------------

					aux2=0;
					ent=0;
					for (col=0; col<lin_a-1; col++){
						for (i=1; i<lin_a; i++){
							for (j=0; j<lin_a-col; j++){
								if (aux2 == 0){
									if (matrizA[j][col] == 0) break;
									else{
										aux2 = matrizA[j][col+i]/matrizA[j][col];
										aux = matrizA[j][col+i]/matrizA[j][col];
									}
								}
								else{
									aux = matrizA[j][col+i]/matrizA[j][col];
 									if (aux == aux2) ent++;
								}
							}
							if (ent >= lin_a-1){
								fprintf(arq,"0\n");
								free(matrizA);
								goto fim;
							}
							aux2=0;
							ent=0;
						}
					}
// --------------------------------------------- ORGANIZA AS LINHAS PARA QUE A DIAG. PRINC. SEJA NAO NULA ---------------------------------------------------------

					ACM=1;
					for (i=0; i<lin_a; i++){
						ACM = ACM*matrizA[i][i];
					}
					count=0;
					while(1){

						ACM=1;
						for (i=0; i<lin_a; i++){
							if (matrizA[i][i] == 0){
								for (j=0; j<lin_a; j++){
									if (i == lin_a-1){
										aux = matrizA[i][j];
										matrizA[i][j] = matrizA[i-i][j];
										matrizA[i-i][j] = aux;
									}
									else{
										aux = matrizA[i][j];
										matrizA[i][j] = matrizA[i+1][j];
										matrizA[i+1][j] = aux;
									}
								}
								count++;
								if (count == fatorial(100)){
									fprintf(arq,"0\n");
									fprintf(arq,"0\n");
									free(matrizA);
									goto fim;
								}
							}
						}

						for (i=0; i<lin_a; i++){
							ACM = ACM*matrizA[i][i];
						}
						if (ACM !=0){
							break;
						}
					} 
// ---------------------------------------------- CALCULO DO DETERMINANTE USANDO A FUNCAO DET_TRIANGULAR -----------------------------------------------------------

					fprintf(arq,"%lf\n",det_triangular(matrizA,lin_a,count));
					free(matrizA);

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
				}
				else{
					fprintf(arq, "Operacao invalida para o(s) operando(s) dado(s).\n");
					free(matrizA);
				}
			}
			else fprintf(arq, "Operacao invalida para o(s) operando(s) dado(s).\n");
		}
		else if (objeto == 'L'){

// ----------------------------------------------- OPERACOES COM PORTAS LOGICAS ----------------------------------------------------------------------------------
			fprintf(arq,"Teste %d:\n",i);
			scanf(" %c",&operacao);
			if (operacao == 'X'){

				scanf("%d %d",&P1,&K1);
				fprintf(arq, "%d\n", P1^K1);
			}
			else if (operacao == 'N'){

				scanf(" %d %d",&P1,&K1);
				fprintf(arq, "%d\n", !(P1 & K1));
			}
			else if (operacao == 'R'){

				scanf(" %d %d",&P1,&K1);
				fprintf(arq, "%d\n", !(P1 | K1));
			}
                        else{
				fprintf(arq, "Operacao invalida para o(s) operando(s) dado(s).\n");
			}
		}
		else if (objeto == 'F'){
			flag=0;
			break;
		}
		else{
			fprintf(arq, "Operacao invalida para o(s) operando(s) dado(s).\n");
		}
		if (flag == 0) break;
		fim:;
		
	}

	fclose(arq);

// ---------------------------------------------- FIM DOS CÁLCULOS E ESCRITA NO ARQUIVO --------------------------------------------------------------------
// ---------------------------------------------- LEITURA DO ARQUIVO ---------------------------------------------------------------------------------------

	arq = fopen("dados.txt","a+");
		if (arq == NULL){

			printf("Erro, não foi possível abrir o arquivo.\n");
			exit(0);
		}
		else while( (ch=fgetc(arq)) != EOF ) putchar(ch);

	fclose(arq);
// ------------------------------------------------- FIM DO PROGRAMA ----------------------------------------------------------------------------------------
}

double **aloca(int lin, int col){

        int i;
		double **matriz;
        matriz = (double**) malloc(lin * sizeof (double*));
        for (i=0; i<lin; i++){

                matriz[i] = (double*) malloc(col * sizeof (double));
        }

        return matriz;
}

double **mult_matriz(double **matrizA, double **matrizB, int lin_a, int col_a, int col_b){

        int i, j, l, k;
	double **MR, ACM;
        ACM=0;
        MR = (double**)malloc(lin_a * sizeof(double*));
        for (l=0; l<lin_a; l++){
                MR[l] = (double*)malloc(col_b * sizeof(double));
        }
        for (i=0; i<=lin_a-1; i++){
                for (j=0; j<=col_b-1; j++){
                        for (k=0; k<=col_a-1; k++){
                                ACM = ACM + (matrizA[i][k]*matrizB[k][j]);
                        }
                        MR[i][j] = ACM;
                        ACM=0;
                }
        }
        return MR;
}

double **soma_matriz(double **matrizA, double **matrizB, int lin, int col){

        int i, j;
        double **matrizR; 
	matrizR = aloca(lin,col);
        for (i=0; i<lin; i++){
                for (j=0; j<col; j++){

                        matrizR[i][j] = matrizA[i][j] + matrizB[i][j];
                }
        }
        return matrizR;
}

double **sub_matriz(double **matrizA, double **matrizB, int lin, int col){

        int i, j;
        double **matrizR;
	matrizR  = aloca(lin,col);
        for (i=0; i<lin; i++){
                for (j=0; j<col; j++){

                        matrizR[i][j] = matrizA[i][j] - matrizB[i][j];
                }
        }
        return matrizR;
}

void imprime(FILE *x, double **matriz, int lin, int col){

        int i, j;
        for (i=0; i<lin; i++){
                for (j=0; j<col; j++){

                        fprintf(x,"%.1f ",matriz[i][j]);
                }
                fprintf(x,"\n");
        }
}

double det_triangular(double **matriz, int lin_a, int count){

	double *vecA, beta, res, det;
	int col, i, k, j, sinal, c;

	vecA = (double*) malloc(lin_a * sizeof(double));
	for (col=0; col<lin_a; col++){
		for (i=1; i<lin_a; i++){

			k = col+i;
			if (k == lin_a) break;
			else{
				beta = matriz[col+i][col]/matriz[col][col];
				beta = (-1)*beta;
				for (j=0; j<lin_a; j++){
					vecA[j] = beta*matriz[col][j];
					matriz[col+i][j] = matriz[col+i][j] + vecA[j];
                                }
                        }
                }
        }
     
 
	res=1;
	for (i=0; i<lin_a; i++){
		res = res*matriz[i][i];
	}

	sinal = pow(-1,count);
	det = sinal*res;
	return det;
}

double fatorial(int count){

	int i;
	double ACM;

	ACM=1;

	for (i=1; i<=count; i++){
		ACM = ACM*i;
	}

	return ACM;
}
