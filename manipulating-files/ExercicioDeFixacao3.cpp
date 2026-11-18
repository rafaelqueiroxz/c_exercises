/*
	Name: ExercicioDeFixacao3.cpp 
	Author: Rafael A. Queiroz
	Date: 18/11/26 11:42
	Description: 	3) Elaborar um programa que apresente um menu
					de opções para o usuário perguntando qual
					operação ele deseja realizar:
					
						- Criar um novo arquivo ("w")
						- Alterar um conteúdo já existente ("a")
						- Somente ler o conteúdo gravado em um arquivo ("r")
*/

#include <stdio.h>
#include <string.h>
#include <windows.h>
#define EXTENSAO_TEXTO ".txt"

int main() {
	
	
	FILE *file = NULL;
	
	printf("Escolha a operacao que deseja realizar!\n");
	printf("\nW -> Criar um novo arquivo e gravar um conteudo nele!\n");
	printf("A -> Alterar um conteudo de um arquivo ja existente!\n");
	printf("R -> Somente ler o conteudo de um arquivo existente!\n\n");
	
	printf("Digite a sua escolha aqui: ");
	char escolha = ' ';
	scanf("%c", &escolha);
	
	switch(escolha) {
		
		case 'W':
			printf("\nInsira o nome do arquivo que voce deseja criar: ");
			char nomeArquivo[30];
			scanf("%[^\n]", nomeArquivo);
			file = fopen(strcat(nomeArquivo, EXTENSAO_TEXTO), "w");
			printf("Insira um conteudo para o arquivo criado: ");
			char mensagem[50];
			scanf("%s", mensagem);
			printf("Arquivo criado com sucesso!");
			break;
	}
	
	
}
