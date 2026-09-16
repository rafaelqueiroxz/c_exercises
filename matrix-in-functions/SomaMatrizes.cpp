/*
	Name: SomaMatrizes.cpp
	Author: Rafael A. Queiroz
	Date: 16/09/26 11:48
	Description: 	Escrever um código em que seja possivel realizar
					a soma de duas matrizes quadradas de mesma ordem.
					As matrizes devem ser carregadas na função main()
					e passadas para uma função chamada somarMatrizes()
					que deverá realizar a soma. Em uma função separada,
					deverão ser impressas as duas matrizes (MatA e MatB)
					e também a matriz soma (MatSoma).
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
void somarMatrizes(int [][3], int [][3]);
void imprimirMatrizes(int [][3], int [][3]);

main() {
	

	int MatA[3][3] = {{3, 6, 2}, {1, 4, 9}, {5, 6, 7}};
	int MatB[3][3] = {{2, 1, 9}, {5, 3, 7}, {8, 2, 6}};
	
	imprimirMatrizes(MatA, MatB);
	somarMatrizes(MatA, MatB);
	
	
}

void somarMatrizes(int MatA[][3], int MatB[][3]) {
	
	printf("\nMatriz Soma: \n");
	for(int i = 0; i < 3; i++) {
		printf("| ");
		for(int j = 0; j < 3; j++) {
			printf("%d | ", MatA[i][j] + MatB[i][j]);
		}
		printf("\n");
	}
	
	
}

void imprimirMatrizes(int MatA[][3], int MatB[][3]) {
	
	printf("Matriz A: \n");
	for(int i = 0; i < 3; i++) {
		printf("| ");
		for(int j = 0; j < 3; j++) {
			printf("%d | ", MatA[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMatriz B: \n");
	for(int i = 0; i < 3; i++) {
		printf("| ");
		for(int j = 0; j < 3; j++) {
			printf("%d | ", MatB[i][j]);
		}
		printf("\n");
	}
	
	
}
