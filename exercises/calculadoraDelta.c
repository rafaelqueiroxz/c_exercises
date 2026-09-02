/*
	Name: calculadoraDelta.c
	Author: Rafael A. Queiroz
	Date: 30/08/26
	Description:    função que receba três valores, 
                    a, b e c, que são os coeficientes 
                    de uma equação do segundo grau 
                    e retorne o valor dodelta, que é 
                    dado por: b² - 4ac
*/

// Seção de importação
#include <stdio.h>
#include <math.h>

// Seção de prototipação
float calcularDelta(float *, float *, float *);

int main()
{

    float a, b, c;
    a = b = c = 0.0;

    printf("Digite o valor de A: ");
    scanf("%f", &a);
    printf("\nDigite o valor de B: ");
    scanf("%f", &b);
    printf("\nDigite o valor de C: ");
    scanf("%f", &c);

    printf("\nO valor de Delta, baseado nos valores registrados para A, B e C, eh: %.2f", calcularDelta(&a, &b, &c));

}

float calcularDelta(float *a, float *b, float *c) {
    return pow(*b, 2) - 4 * *a * *c;
}