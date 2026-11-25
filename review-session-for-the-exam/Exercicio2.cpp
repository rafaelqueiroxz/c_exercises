/*
	Name: Exercicio2.cpp
	Author: Rafael A. Queiroz
	Date: 25/11/26 10:43
	Description: 	
*/

// Seção de importação
#include <stdio.h>

main() {
	
	int matA[3][3];
	int matB[3][3];
	int matSoma[3][3];
	
	printf("Digite os elemento da Matriz A\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("Elemento [%d][%d]: ", i, j);
			scanf("%d", &matA[i][j]);
		}
	}
	
	printf("\nDigite os elemento da Matriz B\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("Elemento [%d][%d]: ", i, j);
			scanf("%d", &matB[i][j]);
			matSoma[i][j] = matA[i][j] + matB[i][j];
		}
	}
	
	printf("\n\nResultado das Matrizes!\n");
	
	printf("\nMatriz A\n");
	for (int i = 0; i < 3; i++) {
		printf("| ");
		for (int j = 0; j < 3; j++) {
			printf("%d | ", matA[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMatriz B\n");
	for (int i = 0; i < 3; i++) {
		printf("| ");
		for (int j = 0; j < 3; j++) {
			printf("%d | ", matB[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMatriz Soma\n");
	for (int i = 0; i < 3; i++) {
		printf("| ");
		for (int j = 0; j < 3; j++) {
			printf("%d | ", matSoma[i][j]);
		}
		printf("\n");
	}
	
	printf("\nPar = 0 / Impar = 1 (Matriz Soma)\n");
	for (int i = 0; i < 3; i++) {
		printf("| ");
		for (int j = 0; j < 3; j++) {
			if (matSoma[i][j] % 2 == 0) {
				printf("0 | ");
			} else {
				printf("1 | ");
			}
		}
		printf("\n");
	}
	
	printf("\nMatriz Soma ao contrario\n");
	for (int i = 2; i >= 0; i--) {
		printf("| ");
		for (int j = 2; j >= 0; j--) {
			printf("%d | ", matSoma[i][j]);
		}
		printf("\n");
	}
	
}

