/*
	Name: calculoIMC.cpp
	Author: Rafael A. Queiroz
	Date: 24/08/26 11:37
	Description: 	Um programa em C que leia os dados de uma pessoa como: nome, peso e
					altura e passe para um função que deverá devolver o cálculo do IMC com uma
					mensagem completa mostrando o nome da pessoa, seu peso e altura e também o
					valor do IMC obtido por meio da função.
*/

// Seção de importação
#include <stdio.h>
#include <Math.h>

// Prototipação de Funções
void calcularIMC(char name[], double weight, double height);

main() {
	
	char name[50];
	double weight = 0.0;
	double height = 0.0;
	
	printf("Entre com seu nome, seu peso e sua altura:");
	printf("\nNome: ");
	scanf("%[^\n]", name);
	printf("Peso: ");
	scanf("%lf", &weight);
	printf("Altura: ");
	scanf("%lf", &height);
	
	calcularIMC(name, weight, height);
	
}

void calcularIMC(char nome[], double peso, double altura) {
	double imc = 0.0;
	imc = peso / pow(altura, 2);
	printf("\nOla %s!\nO peso informado foi de %.2lf kg. Ja a altura inserida foi de %.2lf m. O imc correspondente eh de %.2lf\n", nome, peso, altura, imc);
}

