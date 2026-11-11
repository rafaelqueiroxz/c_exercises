/*
	Name: NomeMusical.cpp
	Author: Rafael A. Queiroz
	Date: 11/11/26 10:30
	Description: 	Programa para armazenar um nome e
					tocar o som equivalente
*/

// Seção de importação
#include <windows.h>
#include <stdio.h>

main() {
	
	char nome[30];
	int i;
	
	printf("Digite seu nome: ");
	gets(nome);
	
	printf("\nConteudo do vetor: \n|");
	while(true) {
		for (i = 0; nome[i] != '\0'; i++) {
			printf("%c|", nome[i]);
			Beep(nome[i]*10, 200);
		}
		printf("\n|");
	}
}
