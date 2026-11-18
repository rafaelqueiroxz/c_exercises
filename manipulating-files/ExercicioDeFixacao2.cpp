/*
	Name: ExercicioDeFixacao2.cpp
	Author: Rafael A. Queiroz
	Date: 18/11/26 10:51
	Description: 	2) Fazer um programa que leia uma frase
					já gravada no arquivo e mostre na tela
					ao contrário, ao final grave esta frase 
					no mesmo arquivo. Arquivo = edf2.txt
*/

#include <stdio.h>
#include <windows.h>
#define MAX_LINHA 128

int main() {
	
	FILE *file = fopen("edf2.txt", "r");
	
	if (file == NULL) {
		perror("Erro ao encontrar o arquivo ");
		return 1;
	}
	
	char line[MAX_LINHA];
	
	printf("Conteudo do arquivo: ");
	while (fgets(line, sizeof(line), file) != NULL) {
		printf("%s", line);
	}
	
	int cont = 0;
	while (line[cont] != '\0') {
		cont++;
	}
	
	char reverse[cont];
	int aux = cont;
	printf("\n\nConteudo invertido: ");
	for (int i = 0; i < aux; i++) {
		reverse[i] = line[--cont];
		Sleep(500);
		printf("%c", reverse[i]);
	}
	
	fclose(file);
	
	file = fopen("edf2.txt", "a");
	
	fprintf(file, "\nConteudo do arquivo invertido: ");
	for (int i = 0; i < aux; i++) {
		fprintf(file, "%c", reverse[i]);
	}
	
	printf("\n\nArquivo atualizado com sucesso!");
}
