/*
	Name: AmplitudeTermica.c
	Author: Rafael A. Queiroz
	Date: 24/09/26
	Description: 	Escreva um programa que leia 7 valores reais representando 
                    as temperaturas registradas ao longo de um dia, dentro de 
                    uma função chamada lerTemperaturas( ). Em seguida, 
                    passe esse vetor como parâmetro para uma função chamada 
                    calcularAmplitudeTermica( ), que deverá identificar a 
                    maior e a menor temperatura do vetor e retornar a diferença 
                    entre elas (amplitude). Por fim, o valor retornado deve ser 
                    passado para uma terceira função, classificarClima( ), que 
                    deverá exibir uma das mensagens abaixo, conforme o valor da amplitude:

                    - Amplitude até 5.0 → "Clima estável"
                    - Amplitude entre 5.1 e 10.0 → "Clima variável"
                    - Amplitude acima de 10.0 → "Clima instável"

                    Obs: o valor da amplitude deve ser exibido junto com a mensagem, 
                    arredondado para uma casa decimal.
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
void lerTemperaturas();
float calcularAmplitudeTermica(float *);
void classificarClima(float);


int main() {
    
    lerTemperaturas();

    return 0;

}

void lerTemperaturas() {

    float temperaturas[7];

    for (int i = 0; i < 7; i++) {
        printf("Digite a temperatura de hoje as %dh00: ", (i+1)*3);
        scanf("%f", &temperaturas[i]);
    }

    classificarClima(calcularAmplitudeTermica(temperaturas));

}

float calcularAmplitudeTermica(float temperaturas[]) {

    float tempMax = temperaturas[0];
    float tempMin = temperaturas[0];

    for (int i = 1; i < 7; i++) {
        if (tempMax < temperaturas[i]) {
            tempMax = temperaturas[i];
        } else if (tempMin > temperaturas[i]) {
            tempMin = temperaturas[i];
        }
    }

    float amplitude = 0.0;

    if (tempMax < 0 && tempMin < 0) {
        amplitude = tempMin - tempMax;
    } else {
        amplitude = tempMax - tempMin;
    }

    return amplitude;

}

void classificarClima(float amplitude) {

    if (amplitude <= 5.0) {
        printf("\nClima estavel.");
    } else if (amplitude <= 10.0) {
        printf("\nClima variavel.");
    } else {
        printf("\nClima instável.");
    }


}
