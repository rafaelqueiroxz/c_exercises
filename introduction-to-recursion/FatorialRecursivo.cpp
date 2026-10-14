/*
	Name: FatorialRecursivo.cpp
	Author: Rafael A. Queiroz
	Date: 14/10/26 12:08
	Description: 	Execute o cálculo do fatorial de um
					número por meio de uma função recursiva.
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
int imprimirFatorial(int);

main() {
	
	int numero;
	
	printf("Entre com o valor que sera calculado o fatorial: ");
	scanf("%d", &numero);
	
	printf("\n%d! = ", numero);
	
	printf("%d\n", imprimirFatorial(numero));
	
}

int imprimirFatorial(int numero) {
	
	if (numero == 1) {
		printf("%d = ", numero);
		return 1;
	}
	
	printf("%d x ", numero);
	return numero * imprimirFatorial(numero-1);
}
