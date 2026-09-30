/*
	Name: FibonacciClassVersion.cpp
	Date: 30/09/26 10:08
	Description: 	Programa para exibir a sequência de
					Fibonacci com a quantidade de elementos
					fornecida pelo usuário.
*/

// Seção de importação
#include <stdio.h>

// Seção de Prototipação
int *calcularFibonacci(int *, int);
void exibirSequencia(int *, int);
void exibirNumeroDeOuro(int *, int);


main() {
	
	int qtdElementos = 0;
	
	printf("Digite a quantidade de numeros da sequencia que voce deseja ver: ");
	scanf("%d", &qtdElementos);
	
	int fibo[qtdElementos];
	fibo[0] = 1;
	fibo[1] = 1;
	exibirSequencia(calcularFibonacci(fibo, qtdElementos), qtdElementos);
	exibirNumeroDeOuro(fibo, qtdElementos);
	
}

// Função para armazenar a sequencia de fibonacci em um vetor
int *calcularFibonacci(int fibo[], int qtdElementos) {

	int prox = 0;
	
	for (int i = 2 ; i < qtdElementos; i++) {
		
		fibo[i] = fibo[i-1] + fibo[i-2];
	}
	
	return fibo;
	
}

void exibirSequencia(int fibo[], int qtdElementos) {
	printf("\nConteudo do vetor de Fibonacci: \n");
	printf("| ");
	for (int i = 0; i < qtdElementos; i++) {
		printf("%d | ", fibo[i]);
	}
}

void exibirNumeroDeOuro(int fibo[], int qtdElementos) {
	
	printf("\n\nNumeros de Ouro da Sequencia: \n");
	printf("| ");
	for (int i = (qtdElementos-1); i > 0; i--) {
		printf("%.3f | ", (float)fibo[i]/fibo[i-1]);
	}
	
}

