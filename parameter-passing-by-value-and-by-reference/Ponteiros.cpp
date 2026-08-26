/*
	Name: Ponteiros.cpp
	Author: Rafael A. Queiroz
	Date: 26/08/26 11:55
	Description: Programa para manipular ponteiros
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação


main() {
	
	/* int a = 555;
		int *ptrA = &a;
		printf("A: %d", a);
		printf("\nConteudo apontado por ptrA: %d", *ptrA);
		printf("\n\nEndereco de A: %p", &a);
		printf("\nEndereco de ptrA: %p", &ptrA); */
		
	short int vetor[20];
	
	for (int i = 0; i < 20; i++) {
		
		printf("%p\n", &vetor[i]);
		
	}
	
}

