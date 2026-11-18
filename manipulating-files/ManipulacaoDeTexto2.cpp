/*
	Name: ManipulacaoDeTexto2.cpp
	Author: Rafael A. Queiroz
	Date: 18/11/26 08:56
	Description: 	Programa para manipular um arquivo texto já existente!
*/

#include <stdio.h>
#define MAX_LINHA 128

int main() {
	
	FILE *file = fopen("alunos.txt", "r"); // r = parametro de leitura
	
	if (file == NULL) {
		perror("Erro ao abrir o arquivo!");
		return 1;
	}
	
	char line[MAX_LINHA];
	
	while(fgets(line, sizeof(line), file) != NULL) {
		printf("%s", line);
	}
	
	//for (int i = 0; line[i] != '\0'; i++) {
	//	printf("%c", line[i]);
	//}
	
	fclose(file);
	
}

