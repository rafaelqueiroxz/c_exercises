/*
	Name: Exercicio5.cpp
	Author: Rafael A. Queiroz
	Date: 25/11/26 11:53
	Description: 	Escreva uma função que receba um vetor, seu tamanho
					e um numero x, retornando quantas vezes o numero x
					aparece no vetor
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
int contarX(int, int *, int);

main() {
	
	int tamanho = 0;
	printf("Digite o tamanho do vetor que sera criado: ");
	scanf("%d", &tamanho);
	printf("\n");
	
	int vetor[tamanho];
	for (int i = 0; i < tamanho; i++) {
		printf("Digite o elemento da posicao %d do vetor: ", i);
		scanf("%d", &vetor[i]);
	}
	
	int x = 0;
	printf("\nDigite o numero que deseja rastrear no vetor: ");
	scanf("%d", &x);
	
	int ocorrenciaX = contarX(tamanho, vetor, x);
	
	printf("O numero %d aparece %d vezes no vetor!", x, ocorrenciaX);
	
}

int contarX(int tamanho, int vetor[], int x) {
	int ocorrenciaX = 0;
	for (int i = 0; i < tamanho; i++) {
		if (vetor[i] == x) {
			ocorrenciaX++;
		}
	}
	return ocorrenciaX;
}
