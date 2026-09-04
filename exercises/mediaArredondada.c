/*
	Name: mediaArredondada.c
	Author: Rafael A. Queiroz
	Date: 04/09/26
	Description: 	Engendre um programa que leia 10 números reais em uma função
                    chamada "carregarVetor", após a carga, passe esse vetor para uma
                    função chamada "calcularMedia", após isso, passe para uma terceira
                    função chamada "exibirMediaArredondada" que deverá receber o valor
                    apurado pela segunda função e mostrar o valor da média arredondado.
*/

// Seção de importação
#include <stdio.h>
#include <math.h>

// Seção de prototipação
void carregarVetor(float *);
float calcularMedia(float *);
void exibirMediaArredondada(float);


int main()
{
    float array[10];

    printf("Carregue o vetor de 10 posicoes com valores reais\n");
    carregarVetor(array);
    exibirMediaArredondada(calcularMedia(array));

}

void carregarVetor(float array[]) {

    for (int i = 0; i < 10; i++) {

        printf("Digite o %do valor: ", i+1);
        scanf("%f", &array[i]);

    }

}

float calcularMedia(float array[]) {
    float media = 0.0;
    for (int i = 0; i < 10; i++) {
        media += array[i];
    }
    media /= 10;

    return media;
}

void exibirMediaArredondada(float media) {
    int mediaArredondada = (int)round(media);
    printf("A média arredondada dos valores inseridos no vetor eh %d", mediaArredondada);
}