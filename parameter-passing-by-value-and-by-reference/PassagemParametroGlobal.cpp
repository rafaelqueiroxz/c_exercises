/*
	Name: PassagemParametroGlobal.cpp
	Author: Rafael A. Queiroz
	Date: 26/08/26 10:22
	Description: Programa para realizar a troca de valores entre variáveis
				 demonstrando o conceito de passagem de parâmentros tanto 
				 por CÓPIA quanto por REFERÊNCIA
*/


// Seção de importação
#include <stdio.h>

// Seção de prototipação
void trocar();

// Variáveis Globais
int a, b, aux = 77;

main() {
	
	a = 5;
	b = 10;
	
	printf("A: %d" , a);
	printf("\nB: %d" , b);
	
	trocar();
	
	printf("\n\nA: %d" , a);
	printf("\nB: %d" , b);
	printf("\nAux Global: %d", aux);
	
	
}

// Função para realizar a troca de valores entre as duas variáveis
void trocar() {
	
	int aux = 0;
	aux = a;
	a = b;
	b = aux;
	printf("\nAux Local: %d", aux);
	
}

