/*
	Name: RecursaoI.cpp
	Author: Rafael A. Queiroz
	Date: 14/10/26 11:13
	Description: 	Programa para demonstrar a utilização
					da função para chamadas recursivas
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
void funcao1();
void linha(int);
void lerNum();

// Variáveis Globais
int contador = 0;

main() {
	
	// funcao1();
	/* int quantidade = 0;
	
	printf("Qual a quantidade de caracteres para desenhar a linha? ");
	scanf("%d", &quantidade);
	
	linha(quantidade); */
	
	lerNum();
	
}

// Função recursiva
void funcao1() {
	
	if (contador == 30) {
		return;
	}
	
	printf("-");
	contador++;
	printf("%d", contador);
	funcao1();
	
	lerNum();
	
}

void linha(int quantidade) {
	
	if (quantidade == 0) {
		return;
	}
	
	printf("-");
	linha(--quantidade); // invoke recursivo
	
}

void lerNum() {
	
	int num;
	printf("Digite um numero: ");
	scanf("%d", &num);
	
	if (num == 99) {
		return;
	}
	
	lerNum();
	
}
