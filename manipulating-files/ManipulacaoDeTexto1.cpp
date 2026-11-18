/*
	Name: ManipulacaoDeTexto1.cpp
	Author: Rafael A. Queiroz 
	Date: 18/11/26 08:29
	Description: 	Programa para manipulação de arquivos do tipo texto
*/

/*

	A manipulação de arquivos de texto utiliza a biblioteca <stdio.h>
	e um ponteiro do tipo FILE * para realizar as operações de:
	
	- Abertura de arquivo (fopen)
	- Leitura de arquivo (read - "r")
	- Escrita de arquivos (write - "w")
	- Anexar em arquivos (append -"a")
	- Finalização do arquivo (fclose)
	
	Funções:
	
	- fprintf(arquivo, formato, ...) -> escreve um texto formatado, como no printf
	- fputs(string, arquivo) -> escreve uma String no arquivo
	- fputc(character, arquivo) -> escreve um único caractere
	- fclose(arquivo) -> fecha o arquivo de texto

*/

#include <stdio.h>

int main() {
	
	
	FILE *file = fopen("alunos.txt", "w");
	
	if (file == NULL) {
		perror("Erro ao abrir o arquivo!");
		return 1;
	}
	
	float nota = 10.0;
	fprintf(file, "Aluno: %s | Nota: %.2f\n", "Beatriz", nota);
	
	if (nota >= 6.0) {
		fputs("Status: Aprovado\n", file);
	} else {
		fputs("Status: Reprovado\n", file);
	}
	
	printf("Operacao com arquivo realizada com sucesso!");
	
	
}

