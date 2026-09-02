/*
	Name: muitoLouco.cpp
	Author: Rafael A. Queiroz
	Date: 02/09/26 10:26
	Description: 	Programa para manipular
					vetores junto com funções
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
int lerNum();
void imprimirVetor(int *);

main() {
	
	int vet[5];
	
	// Fazer a carga no vetor
	for(int i = 0; i < 5; i++){
		vet[i] = lerNum();
	}
	
	
	imprimirVetor(vet);
	
}

// Função para ler e retornar um número digitado pelo usuário
int lerNum() {
	
	int num = 0;
	printf("Digite um numero : ");
	scanf("%d", &num);
	return num;
	
}

// Função para imprimir o vetor
void imprimirVetor(int *V){
	
	// imprimindo o conteúdo do vetor
	puts("\nConteudo do vetor:");
	printf("|");
	for (int i = 0; i < 5; i++) {
		printf(" %d |", V[i]);
	}
	
}
