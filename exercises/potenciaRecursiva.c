/*
	Name: PotenciaRecursiva.c
	Author: Rafael A. Queiroz
	Date: 19/10/26
	Description: 	Potenciação x^k
                    Enunciado: Implemente uma função recursiva que receba 
                    dois números inteiros x e k (com k ≥ 0) e calcule o valor 
                    de x^k utilizando apenas multiplicações (sem usar funções
                    prontas como pow()). 
                    
                    Caso base: Se k = 0, retorne 1.
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
void calcularPotenciaIgualHomem(int, int);

// Variáveis Globais
int resultado = 1;

int main(){

    int x = 0;
    int k = 0;

    printf("Digite o valor de x e k (x^k)\n");
    printf("x: ");
    scanf("%d", &x);
    printf("k: ");
    scanf("%d", &k);

    calcularPotenciaIgualHomem(x, k);

}

void calcularPotenciaIgualHomem(int x, int k) {

    if (k == 0) {
        printf("x^k = %d", resultado);
    } else {
        resultado *= x;
        calcularPotenciaIgualHomem(x, --k);
    }

}