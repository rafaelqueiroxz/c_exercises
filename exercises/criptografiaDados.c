/*
	Name: criptografiaDados.c
	Author: Rafael A. Queiroz / Correção do professor Alexandre Cassiano
	Date: 04/09/26
	Description: 	Crie uma função que receba dois vetores, um com seu nome completo
                    e outro com os dados do seu CPF e RG. Nesta função, chamada
                    "merge" deverá misturar os dados dos dois vetores da seguinte forma:
                    
                    Entrada "vetor1": Antonio Gabriel Leme
                    
                    Entrada "vetor2": 09935678224 138456732 (observe quem tem um espaço
                    entre CPF e RG)
                    
                    O novo vetor gerado com o texto "misturado" deverá ser passado para
                    uma outra função que deverá realizar a impressão dele. 
                    
                    Saída vetor "crypto": A0n9t9o3n5i6o7 8G2a2b4r i1e3l8 4L5e6m7e32
*/

// Seção de importação
#include <stdio.h>
#include <string.h>

// Seção de prototipação
void merge(char *, char *); // Função para combinar os dois vetores

int main()
{
    char nome[30];
    char docs[21];

    printf("Digite seu nome completo: "); gets(nome);
    printf("Digite seu CPF e seu RG: "); gets(docs);

    merge(nome, docs);

}

void merge(char nome[], char docs[]) {

    int i,j;
    for(i = 0; nome[i] != '\0'; i++) {
    }

    int tamanho = i + 21; // Tamanho da String + Tamanho do vetor 'docs'
    char crypto[tamanho];

    for(i = 0, j = 0; i < tamanho; i++) {
        if (nome[i] != '\0') {
            crypto[j] = nome[i];
            crypto[j+1] = docs[i];

            j = j + 2;
        }
    }

    for(i = 0; i < tamanho; i++) {
        printf("%c | ", crypto[i]);
    }

}