/*
	Name: ExercicioSomECor.cpp
	Author: Rafael A. Queiroz
	Date: 11/11/26 11:18
	Description: 	
					1) Fazer um programa que entre com nome, idade,
					e altura alternando as cores para
					
					Nome:
					Idade:
					Altura:
					
					Ao final da entrada de cada dado, emitir um som
					de entrada e exibir ao final todos os dados com 
					uma cor diferente da entrada e emitir um outro
					som. 
*/

// Seção de importação
#include <stdio.h>
#include <windows.h>

main() {
	
	char nome[30];
	int idade;
	float altura;
	
	printf("\033[1;30mDigite as suas informacoes a seguir:\n");
	printf("\033[1;33mNome: ");
	gets(nome);
	for (int i = 0; nome[i] != '\0'; i++) {
		int som = (int)nome[i];
		Beep(som*10, 300);
	}
	printf("\033[32mIdade: ");
	scanf("%d", &idade);
	Beep(2450, 1000);
	Beep(430, 1000);
	printf("\033[1;36mAltura: ");
	scanf("%f", &altura);
	Beep(2334.98, 1000);
	Beep(2334.98, 1000);
	Beep(2334.98, 1000);
	
	printf("\033[0;\033[31m\nOla %s! Voce tem %d anos e %.2fm de altura!\n\033[40m", nome, idade, altura);
	Beep(424, 1000);
	
	
}
