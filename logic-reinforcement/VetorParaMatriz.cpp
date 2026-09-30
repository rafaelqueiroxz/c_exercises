/*
	Name: VetorParaMatriz.cpp
	Author: Rafael A. Queiroz
	Date: 30/09/26 11:38
	Description: 	Fazer um programa que carregue um vetor
					com 25 elementos inteiros, passe-o para
					uma função e, a partir dai, faça uma carga
					em uma matriz quadrada. Depois imprima o vetor 
					em uma função e a matriz em outra;
*/

// Seção de importação
#include <stdio.h>

// Seção de Prototipação
void carregarMatriz(int *, int [5][5]);
void imprimirVetor(int *);
void imprimirMatriz(int [][5]);

main() {
	
	int vet[25] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
	int mat[5][5];
	
	carregarMatriz(vet, mat);
	imprimirVetor(vet);
	imprimirMatriz(mat);
	
	
}

void carregarMatriz(int vet[], int mat[][5]) {
	
	int z = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			mat[i][j] = vet[z];
			z++;
		}
	}
	
}

void imprimirVetor(int vet[]) {
	
	printf("\nConteudo do Vetor: \n");
	printf("|");
	for (int i = 0; i < 25; i++) {
		printf(" %d |", vet[i]);
	}
	
}

void imprimirMatriz(int mat[][5]) {
	
	printf("\n\nConteudo da Matriz: \n");
	
	for (int i = 0; i < 5; i++) {
		printf("|");
		for (int j = 0; j < 5; j++) {
			printf(" %d |", mat[i][j]);
		}
		printf("\n");
	}
	
}
