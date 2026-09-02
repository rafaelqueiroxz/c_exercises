/*
	Name: conversorTemperatura.c
	Author: Rafael A. Queiroz
	Date: 30/08/26
	Description:    Desenvolva uma função que receba uma 
                    temperatura emgraus Celsiuse retorne 
                    o valor convertido em Fahrenheit, 
                    considere a seguinte fórmula: 
                    (F = C × 1.8 + 32).
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
float converterParaFahrenheit(float *);

int main()
{

    float tempCelsius = 0.0;

    printf("Digite a temperatura em graus Celsius: ");
    scanf("%f", &tempCelsius);
    printf("\nTemperatura em Fahrenheit: %.2f", converterParaFahrenheit(&tempCelsius));

}

float converterParaFahrenheit(float *tempCelsius) {
    return *tempCelsius * 1.8 + 32;
}