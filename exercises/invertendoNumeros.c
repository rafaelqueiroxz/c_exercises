/*
	Name: invertendoNumeros.c
	Author: Rafael A. Queiroz
	Date: 04/09/26
	Description: 	(Desafio) Faça um programa em que seja lido um número inteiro, 
                    passá-lo para uma função que deverá imprimir este número ao 
                    contrário. O número NÃO deve ser armazenado em um vetor. 
                    
                    Entrada: 29845
                    Saída: 54892
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
void imprimirAoContrario(int);

int main()
{
    int numeroInicial = 0;

    printf("Digite o numero que sera invertido: ");
    scanf("%d", &numeroInicial);

    imprimirAoContrario(numeroInicial);

}

void imprimirAoContrario(int numeroInicial) {

    int i = 0;

    printf("\nNumero invertido: ");

    while(numeroInicial != 0) {
        printf("%d", (numeroInicial % 10));
        numeroInicial /= 10;
    }

}

