/*
	Name: Exercicio4.cpp
	Author: Rafael A. Queiroz
	Date: 25/11/26 11:43
	Description: 	Faça uma função que encontre o maior elemento de um vetor
					de inteiros e outra que encontre o menor.
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
int encontrarMaior(int, int *);
int encontrarMenor(int, int *);

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
	
	int posicaoMaior = encontrarMaior(tamanho, vetor);
	int posicaoMenor = encontrarMenor(tamanho, vetor);
	
	printf("\n\nO maior elemento digitado no vetor foi o numero %d\n", vetor[posicaoMaior]);
	printf("O menor elemento digitado no vetor foi o numero %d\n", vetor[posicaoMenor]);
	
}

int encontrarMaior(int tamanho, int vetor[]) {
	int posicaoMaior = 0;
	for (int i = 1; i < tamanho; i++) {
		if (vetor[posicaoMaior] < vetor[i]) {
			posicaoMaior = i;
		}
	}
	return posicaoMaior;
}

int encontrarMenor(int tamanho, int vetor[]) {
	int posicaoMenor = 0;
	for (int i = 1; i < tamanho; i++) {
		if (vetor[posicaoMenor] > vetor[i]) {
			posicaoMenor = i;
		}
	}
	return posicaoMenor;
}

