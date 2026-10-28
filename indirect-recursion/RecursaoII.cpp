/*
	Name: RecursaoII.cpp
	Author: Rafael A. Queiroz
	Date: 28/10/26 09:59
	Description: 	Programa para demonstrar a Recursividade Indireta
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
void lerNumero();
void analisarNumero(int);

main() {
	
	lerNumero();
	
}

// Função para ler um número
void lerNumero() {
	
	int num;
	printf("Digite um numero: ");
	scanf("%d", &num);
	analisarNumero(num);
	
}

// Função para analisar um número
void analisarNumero(int num) {
	
	if (num == 0) {
		return;
	}
	if (num % 2 == 0) {
		printf("O numero digitado eh par!\n");
	} else {
		printf("O numero digitado eh impar!\n");
	}
	lerNumero();
	
}
