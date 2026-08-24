/*
	Name: SomaNumeros.cpp
	Author: Rafael A. Queiroz
	Date: 19/08/26 09:56
	Description: Programa para somar dois numeros por meio de uma função.
*/

#include <stdio.h>
#include <locale.h>
#include <Math.h>

//Sessão de prototipação de funções
int somar(int a, int b);
int subtrair(int a, int b);
int multiplicar(int a, int b);
double dividir(int a, int b);
int calcularPotencia(int a, int b);
int calcularPotenciaJVNutella(int a, int b);
double calcularRaizQuadrada(int a);

main() {
	
	setlocale(LC_ALL,"Portuguese");
	
	int a, b, soma, subtracao, multiplicacao, potencia, potenciaJoaoVitorNutella;
	double  divisao, raizQuadradaA, raizQuadradaSoma;
	
	a = b = soma = subtracao = multiplicacao = potencia = potenciaJoaoVitorNutella = 0;
	divisao = raizQuadradaA = raizQuadradaSoma = 0.0;
	
	printf("Digite o valor de A: ");
	scanf("%d", &a);
	printf("Digite o valor de B: ");
	scanf("%d", &b);
	
	soma = somar(a, b);
	subtracao = subtrair(a, b);
	multiplicacao = multiplicar(a, b);
	divisao = dividir(a, b);
	potencia = calcularPotencia(a, b);
	potenciaJoaoVitorNutella = calcularPotenciaJVNutella(a, b);
	raizQuadradaA = calcularRaizQuadrada(a);
	raizQuadradaSoma = calcularRaizQuadrada(somar(a, b));
	
	printf("\nA soma de %d + %d é igual a %d", a, b, soma);
	printf("\nA subtração de %d - %d é igual a %d", a, b, subtracao);
	printf("\nA multiplicação de %d x %d é igual a %d", a, b, multiplicacao);
	printf("\nA divisão de %d / %d é igual a %.2lf", a, b, divisao);
	printf("\nA potência de %d por %d é igual a %d", a, b, potencia);
	printf("\nA potência de %d por %d (Calculada com o pow da lib Math.h) é igual a %d", a, b, potenciaJoaoVitorNutella);
	printf("\nA raiz quadrada de %d é igual a %.2lf", a, raizQuadradaA);
	printf("\nA raiz quadrada da soma de %d + %d é igual a %.2lf", a, b, raizQuadradaSoma);
		
} //fim do programa

// Função para realizar a soma entre dois números inteiros
int somar(int a, int b) {
	
	int result = 0;
	result = a + b;
	return result;
			
}

int subtrair(int a, int b) {
	
	int result = 0;
	result = a - b;
	return result;
			
}

int multiplicar(int a, int b) {
	
	int result = 0;
	result = a * b;
	return result;
			
}

double dividir(int a, int b) {
	
	double result = 0.0;
	result = (double)a / b;
	return result;
			
}

int calcularPotencia(int a, int b) {
	
	int result = a;
	
	for (int i = 1; i < b; i++) {
		result = result * a;
	}
	
	return result;
	
}

int calcularPotenciaJVNutella(int a, int b){
	
	return pow(a, b);
	
}

double calcularRaizQuadrada(int a) {
	sqrt(a);
}
