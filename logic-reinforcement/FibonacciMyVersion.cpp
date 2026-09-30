/*
	Name: FibonacciMyVersion.cpp
	Author: Rafael A. Queiroz
	Date: 30/09/26 09:54
	Description: 	Programa para exibir a sequência de
					Fibonacci com a quantidade de elementos
					fornecida pelo usuário.
*/

// Seção de importação
#include <stdio.h>

// Seção de Prototipação
void exibirSequencia(int);

main() {
	
	int qtdNumeros = 0;
	
	printf("Digite a quantidade de numeros da sequencia que voce deseja ver: ");
	scanf("%d", &qtdNumeros);
	
	exibirSequencia(qtdNumeros);
	
}

void exibirSequencia(int qtdNumeros) {
	
	int anterior = 0;
	int atual = 1;
	int proximo = 0;
	int aux = qtdNumeros;
	
	printf("%d", anterior);
	while((qtdNumeros - 1) > 0) {
		
		if (aux == qtdNumeros) {
			printf(", %d", atual);
			qtdNumeros--;
		} else {
			proximo = atual + anterior;
			printf(", %d", proximo);
			anterior = atual;
			atual = proximo;
			qtdNumeros--;
		}
		
	}
	printf("\n");
	
}
