/*
	Name: SomaMatrizesEntradaUsuario.cpp
	Author: Rafael A. Queiroz
	Date: 16/09/26 11:48
	Description: 	Escrever um código em que seja possivel realizar
					a soma de duas matrizes quadradas de mesma ordem.
					As matrizes devem ser carregadas na função main()
					e passadas para uma função chamada somarMatrizes()
					que deverá realizar a soma. Em uma função separada,
					deverão ser impressas as duas matrizes (MatA e MatB)
					e também a matriz soma (MatSoma).
					
					Versão incorreta iniciada no dia 16/09.
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
int *somarMatrizes(int [][column], int [][column]);
void imprimirMatrizes(int [][column], int [][column], int [][column]);

// Variaveis Globais
int line = 0;
int column = 0;
int MatSoma[line][column];

int main() {
	
	printf("Insira a ordem das Matrizes que serao digitadas: ");
	scanf("%d", &line);
	column = line;
	
	int MatA[line][column];
	int MatB[line][column];
	
	printf("\n");
	for(int i = 0; i < line; i++) {
		for(int j = 0; j < column; j++) {
			printf("Digite MatA[%d][%d]: ", i, j);
			scanf("%d", MatA[i][j]);
		}
	}
	
	printf("\n");
	for(int i = 0; i < line; i++) {
		for(int j = 0; j < column; j++) {
			printf("Digite MatB[%d][%d]: ", i, j);
			scanf("%d", MatB[i][j]);
		}
	}
	
	imprimirMatrizes(MatA, MatB, somarMatrizes(MatA, MatB));
	
	
}

int *somarMatrizes(int MatA[][column], int MatB[][column]) {
	
	for(int i = 0; i < line; i++) {
		for(int j = 0; j < column; j++) {
			MatSoma[i][j] = MatA[i][j] + MatB[i][j];
		}
	}
	
	return MatSoma;
	
}

void imprimirMatrizes(int MatA[][column], int MatB[][column], int MatSoma[][column]) {
	
	printf("\nMatriz A: \n");
	for(int i = 0; i < line; i++) {
		printf("| ");
		for(int j = 0; j < column; j++) {
			printf("%d | ", MatA[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMatriz B: \n");
	for(int i = 0; i < line; i++) {
		printf("| ");
		for(int j = 0; j < column; j++) {
			printf("%d | ", MatB[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMatriz Soma: \n");
	for(int i = 0; i < line; i++) {
		printf("| ");
		for(int j = 0; j < column; j++) {
			printf("%d | ", MatSoma[i][j]);
		}
		printf("\n");
	}
	
}
