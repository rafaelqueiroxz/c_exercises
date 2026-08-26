/*
	Name: TrocaDeValoresComDuasVariaveis.cpp
	Author: Rafael A. Queiroz
	Date: 26/08/26 10:22
	Description: Programa para realizar a troca de valores entre variáveis usando apenas duas variaveis
*/


// Seção de importação
#include <stdio.h>

//Seção de prototipação
void trocar(int *, int *);

main() {
	
	int a, b; // Variáveis locais
	
	a = 5; 
	b = 10;
	
	printf("A: %p" , &a);
	printf("\nB: %p" , &b);
	
	trocar(&a, &b); // Invoke para trocar
	
	printf("\n\nA: %d" , a);
	printf("\nB: %d" , b);
	
	
}

// Função para realizar a troca de valores entre as duas variáveis
void trocar(int *a, int *b) {
	
	
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
	
	printf("\n\nA: %d" , *a);
	printf("\nB: %d" , *b);
	
}

