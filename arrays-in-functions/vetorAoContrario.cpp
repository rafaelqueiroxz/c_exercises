/*
	Name: vetorAoContrario.cpp
	Author: Rafael A. Queiroz
	Date: 02/09/26 11:22
	Description: 	Escreva um programa que leia uma cadeia de caracteres,
					armazene em um vetor e passe para uma função chamada
					"imprimirContrario" que deverá exibir a sequencia de 
					caracteres do fim para o começo.
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
void imprimirContrario(char *);

main() {
	
	char palavra[30];
	
	printf("Digite a paravra que sera invertida: ");
	gets(palavra);
	
	imprimirContrario(palavra);
	
}

void imprimirContrario(char *P) {
	
	printf("\nA palavra %s ao contrario eh ", P);
	
	for(int i = 30-1; i >= 0; i--) {
		printf("%c", P[i]); 
	}
	
}
