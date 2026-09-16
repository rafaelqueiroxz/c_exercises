/*
	Name: Matriz.cpp
	Author: Rafael A. Queiroz
	Date: 16/09/26 10:40
	Description: 	Programa para manipular matrizes
					dentro de uma função.
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
void exibirMatriz(int [3][3]);

main() {
	
	// int vet[] = {6, 13, 89, 20, 45};
	
	// int mat[3][3]; // Matriz quadrada de ordem 3
	int mat[3][3] = {{7,8,2}, {0,1,4}, {5,6,9}}; // hard code
	
	exibirMatriz(mat);
	
}

void exibirMatriz(int mat[3][3]){
	puts("Conteudo da Matriz: ");
	for(int i = 0; i < 3; i++) {
		printf("| ");
		for(int j = 0; j < 3; j++) {
			printf("%d | ", mat[i][j]);
		}
		printf("\n");
	}
}
