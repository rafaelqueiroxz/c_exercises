/*
	Name: TabuadaRecursiva.cpp
	Author: Rafael A. Queiroz
	Date: 14/10/26 11:57
	Description: 	Escreva um programa que imprima uma tabuada
					de multiplicação por meio de uma função 
					recursiva. O valor é escolhido pelo usuário.
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
void imprimirTabuada(int);

// Variáveis Globais
int cont = 1;

main() {
	
	int tabuada = 0;
	
	printf("Entre com a tabuada que voce deseja saber: ");
	scanf("%d", &tabuada);
	
	printf("\n");
	imprimirTabuada(tabuada);
	
}

void imprimirTabuada(int tabuada) {
	
	if(cont > 10) {
		return;
	}
	
	printf("%d x %d = %d\n", tabuada, cont, (tabuada*cont));
	cont++;
	
	imprimirTabuada(tabuada);
	
	
}
