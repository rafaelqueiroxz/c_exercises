/*
	Name: PassagemParametro.cpp
	Author: Rafael A. Queiroz
	Date: 26/08/26 10:22
	Description: Programa para realizar a troca de valores entre variáveis
				 demonstrando o conceito de passagem de parâmentros tanto 
				 por CÓPIA quanto por REFERÊNCIA
*/


// Seção de importação
#include <stdio.h>

//Seção de prototipação
void trocar(int *, int *);

main() {
	
	int a, b;
	
	a = 5; // hard code -> permanece sempre o mesmo valor, independente de quantas vezes o sistema rodar. Ao contrário de um número digitado pelo usuário, por exemplo.
	b = 10;
	
	printf("A: %d" , a);
	printf("\nB: %d" , b);
	
	trocar(&a, &b); // Invoke para trocar
	
	printf("\n\nA: %d" , a);
	printf("\nB: %d" , b);
	
	
}

// Função para realizar a troca de valores entre as duas variáveis
void trocar(int *a, int *b) {
	
	int aux = 0;
	aux = *a;
	*a = *b;
	*b = aux;
	
}

