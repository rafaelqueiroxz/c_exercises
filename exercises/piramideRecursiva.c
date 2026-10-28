/*
	Name: PiramideRecursiva.c
	Author: Rafael A. Queiroz
	Date: 19/10/26
	Description: 	void ImprimePiramide(int n);

                    Imprime uma pirâmide conforme o exemplo 
                    abaixo de forma recursiva, sendo o maior 
                    valor n fornecido como argumento. 
                    Ex: Para n = 7, temos:
                    
                    1
                    2 1
                    3 2 1
                    4 3 2 1
                    5 4 3 2 1
                    6 5 4 3 2 1
                    7 6 5 4 3 2 1
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
void imprimePiramide(int);

int main(){

    int n = 0;

    printf("Digite um numero inteiro que sera a base para a construcao da piramide: ");
    scanf("%d", &n);

    printf("\n");
    for (int i = 1; i <= n; i++) {
        imprimePiramide(i);
    }

}

void imprimePiramide(int n) {

    if (n == 1) {
        printf("%d\n", n);
    } else {
        printf("%d", n);
        imprimePiramide(n-1);
    }

}