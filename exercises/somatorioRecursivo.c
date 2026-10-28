/*
	Name: SomatorioRecursivo.c
	Author: Rafael A. Queiroz
	Date: 19/10/26
	Description: 	Escreva Somatório de 1 a N

                    Crie uma função recursiva que receba um número 
                    inteiro positivo N e calcule o somatório de todos 
                    os números de 1 até N (1+2+3+...+N)

                    Se N = 1, retorne 1 (ou 0 se N = 0).
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
int somatorio(int);

// Variáveis Globais
int resultado = 0;

int main(){

    int n = 0;

    printf("Entre com o numero inteiro: ");
    scanf("%d", &n);

    int sum = somatorio(n);

    printf("\nO resultado do somatorio de 0 a %d eh %d", n, sum);

}

int somatorio(int n) {

    if (n == 0) {
        return resultado;
    } else {
        resultado += n;
        somatorio(n-1);
    }

}