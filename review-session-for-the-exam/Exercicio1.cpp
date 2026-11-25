/*
	Name: Exercicio1.cpp
	Author: Rafael A. Queiroz
	Date: 25/11/26 10:06
	Description: 	Programa para manipular um vetor com a
					quantidade de elementos escolhido pelo usuário
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
int verificarNegativo();

main() {
	
	
	printf("Qual a quantidade de elementos que sera armazenada no vetor? ");
	int quantidade = verificarNegativo();
	
	if (quantidade == 0) {
		printf("\nVetor com 0 elementos criado com sucesso!\n");
	} else {
		int vetor[quantidade];
	
		printf("\nDigite %d elementos\n", quantidade);
		
		for (int i = 0; i < quantidade; i++) {
			printf("Elemento %d: ", i+1);
			scanf("%d", &vetor[i]);
		}
		
		printf("\nElementos do vetor\n");
		for (int i = 0; i < quantidade; i++) {
			if (i == 0) {
				printf("| ");
			}
			printf("%d | ", vetor[i]);
		}
		printf("\n");
		
		printf("\nNumeros pares\n");
		for (int i = 0; i < quantidade; i++) {
			if (i == 0) {
				printf("| ");
			}
			if (vetor[i] % 2 == 0) {
				printf("%d | ", vetor[i]);
			}
		}
		
		printf("\n\nNumeros maiores que 10\n");
		for (int i = 0; i < quantidade; i++) {
			if (i == 0) {
				printf("| ");
			}
			if (vetor[i] > 10) {
				printf("%d | ", vetor[i]);
			}
		}
		
		printf("\n\nApenas os numeros que ocupam indices impares\n");
		for (int i = 0; i < quantidade; i++) {
			if (i == 0) {
				printf("| ");
			}
			if (i % 2 != 0) {
				printf("%d | ", vetor[i]);
			}
		}
		
		printf("\n\nConteudo do vetor ao contrario\n");
		for (int i = quantidade-1; i >= 0; i--) {
			if (i == quantidade-1) {
				printf("| ");
			}
			printf("%d | ", vetor[i]);
		}
	}
	printf("\n");
}

int verificarNegativo() {
	
	int quantidade = 0;
	scanf("%d", &quantidade);
	if (quantidade >= 0) {
		return quantidade;
	} else {
		printf("Digite um numero valido (positivo)! ");
		verificarNegativo();
	}
	
}

