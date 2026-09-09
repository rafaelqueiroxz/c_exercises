/*
	Name: media6Notas.cpp
	Author: Rafael A. Queiroz
	Date: 02/09/26 12:09
	Description: 	Elabore um programa que leia 6
					notas de um aluno, armazene em um
					vetor, passe para uma função que 
					calcula a sua média aritmética, 
					apontando se ele foi aprovado ou
					não em uma outra função para tal.
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
float calcularMedia(float *);
void imprimirSituacao(float);

main() {
	
	float notas[6];
	
	printf("Digite os valores correspondentes a suas notas\n");
	for (int i = 0; i < 6; i++){
		printf("%da nota: ", i+1);
		scanf("%f", &notas[i]);
	}
	
	imprimirSituacao(calcularMedia(notas));
	
}

float calcularMedia(float *M){
	float media = 0.0;
	
	for(int i = 0; i < 6; i++){
		media += M[i];
	}
	media /= 6;
	
	return media;
}

void imprimirSituacao(float media){
	
	if(media >= 6.0) {
		printf("\nAprovado! Sua media foi %.2f", media);
	} else if (media >= 4.0) {
		printf("\nExame! Sua media foi %.2f", media);
	} else {
		printf("\nReprovado! Sua media foi %.2f", media);
	}
	
}
