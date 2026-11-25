/*
	Name: Exercicio3.cpp
	Author: Rafael A. Queiroz
	Date: 25/11/26 11:33
	Description: 	Crie uma função que receba um vetor de float e
					seu tamanho n e retorne a média dos valores
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
float calculoMediaVetor(int, float *);

main() {
	
	int tamanho = 0;
	printf("Digite o tamanho do vetor que sera criado: ");
	scanf("%d", &tamanho);
	printf("\n");
	
	float vetor[tamanho];
	for (int i = 0; i < tamanho; i++) {
		printf("Digite o elemento da posicao %d do vetor: ", i);
		scanf("%f", &vetor[i]);
	}
	
	float media = calculoMediaVetor(tamanho, vetor);
	
	printf("\nA media dos valores inseridos no vetor eh %.1f\n", media);
	
}

float calculoMediaVetor(int tamanho, float vetor[]) {
	float media = 0.0;
	for (int i = 0; i < tamanho; i++) {
		media += vetor[i];
	}
	
	return media / tamanho;
}
