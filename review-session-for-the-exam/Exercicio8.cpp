/*
	Name: Exercicio8.cpp
	Author: Rafael A. Queiroz
	Date: 25/11/26 12:30
	Description: 	Implemente uma função buscarValor que procure um numero inteiro
					em uma matriz 3x3 e informe se ele existe ou nao.
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
int buscarValor(int[][3], int);

main() {
	
	int matriz[3][3];
	printf("Digite os elementos da Matriz de ordem 3\n\n");
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("Digite o elemento [%d][%d] da matriz: ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	int num = 0;
	printf("\nDigite o numero que voce deseja buscar na matriz: ");
	scanf("%d", &num);
	
	int existe = buscarValor(matriz, num);
	
	if (existe == 1) {
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (matriz[i][j] == num) {
					printf("\n\nO numero buscado esta na posicao [%d][%d] da matriz\n", i, j);
				}
			}	
		}	
		
	} else {
		printf("\n\nO numero buscado nao existe na matriz informada.\n");
	}
	
}

int buscarValor(int matriz[][3], int num) {
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (matriz[i][j] == num) {
				return 1;
			}
		}
	}
	return 0;
	
}
