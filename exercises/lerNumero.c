/*
	Name: lerNumero.c
	Author: Rafael A. Queiroz
	Date: 30/08/26
	Description:    Programa que lê um número inteiro, 
                    passe para uma função e ela dever emitir 
                    uma mensagem informando se o número é 
                    positivo ou negativo ou nulo quando for 
                    igual a zero.
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
void lerNumeroInteiro(int *num);

int main()
{

    int num = 0;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);
    lerNumeroInteiro(&num);

}

void lerNumeroInteiro(int *num) {
    if (*num > 0) {
        printf("\nO numero lido eh positivo!");
    } else if (*num < 0) {
        printf("\nO numero lido eh negativo!");
    } else {
        printf("\nO numero lido eh nulo (=0)!");
    }
}