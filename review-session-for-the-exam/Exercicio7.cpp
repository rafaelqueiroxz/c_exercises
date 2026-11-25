/*
	Name: Exercicio7.cpp
	Author: Rafael A. Queiroz
	Date: 25/11/26 12:12
	Description: 	Faça uma função que receba uma matriz 4x4
					e retorne o maior valor encontrado nela (e,
					se quiser treinar ponteiros, tambem a sua 
					linha e coluna);
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
void maiorValorMatriz(int[][4]);
void specsMatriz(int, int[][4]);

// Variaveis globais
int specs[3];

main() {
	
	int matriz[4][4];
	printf("Digite os elementos da Matriz de ordem 4\n\n");
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("Digite o elemento [%d][%d] da matriz: ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	maiorValorMatriz(matriz);
	
	printf("\nO maior valor digitado na matriz foi %d na posicao [%d][%d]!", specs[0], specs[1], specs[2]);
	
}

void maiorValorMatriz(int matriz[][4]) {
	int maior = 0;
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (maior < matriz[i][j]) {
				maior = matriz[i][j];
			}
		}
	}
	
	specsMatriz(maior, matriz);
}

void specsMatriz(int maior, int matriz[][4]) {
	specs[0] = maior;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (maior == matriz[i][j]) {
				specs[1] = i;
				specs[2] = j;
			}
		}
	}
}
