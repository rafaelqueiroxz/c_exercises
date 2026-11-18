/*
	Name: ManipulacaoDeArquivo1.cpp
	Author: Rafael A. Queiroz
	Date: 18/11/26 09:20
	Description: 	Programa para adicionar texto a um arquivo já existente!
*/

#include <stdio.h>

int main() {
	
	FILE *file = fopen("alunos.txt", "a"); // a -> append = adicionar algo no arquivo já existente
	
	if (file == NULL) {
		perror("Erro ao abrir o arquivo ");
		return 1;
	}
	
	fprintf(file, "\n\n====> Fim do Arquivo");
	fputs("\nAlterado por Rafael Queiroz no dia 18/11/2026\n", file);
	
	printf("Alteracoes realizadas com sucesso!");
	
	fclose(file);
	
}

