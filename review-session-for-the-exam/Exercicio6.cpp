/*
	Name: Exercicio6.cpp
	Author: Rafael A. Queiroz
	Date: 25/11/26 11:59
	Description: 	Escreva uma função somaLinha que receba uma matriz 4x4 e o 
					indice de uma linha retornando a soma dos elementos dessa linha.
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
int somaLinha(int[][4], int);

main() {
	
	int matriz[4][4];
	printf("Digite os elementos da Matriz de ordem 4\n\n");
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("Digite o elemento [%d][%d] da matriz: ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	int linha = 0;
	printf("\nDigite a linha da matriz que voce deseja saber a soma dos valores: ");
	scanf("%d", &linha);
	
	printf("\nA soma da linha %d da matriz eh igual a %d", linha, somaLinha(matriz, linha));
	
}

int somaLinha(int matriz[][4], int linha) {
	int somaLinha = 0;
	
	for (int j = 0; j < 4; j++) {
		somaLinha += matriz[linha][j];
	}
	
	return somaLinha;
}
