/*
	Name: verificaPalindromo.c
	Author: Rafael A. Queiroz / Corrigido pelo professor Alexandre Cassiano
	Date: 04/09/26
	Description: 	Desenvolva um programa em que seja possível passar uma frase para
                    uma função e verificar se a sequência de caracteres é um palíndromo
                    ou não. 
                    
                    Exemplo: ovo, arara, renner são palíndromos.
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
int verificaPalindromo(char *);

int main()
{
    char palavra[50];
    int tamanho;

    tamanho = sizeof(palavra)/sizeof(char); // Calcula o tamanho do vetor

    printf("Digite a palavra ou frase que será verificada: ");
    gets(palavra);

    int teste = verificaPalindromo(palavra);

    if (teste == 1) {
        printf("\nA palavra digitada é um palíndromo!");
    } else {
        printf("\nA palavra digitada não é um palíndromo!");
    }

    
}

// Função para verificar se é um palindromo ou não
int verificaPalindromo(char palavra[]) {

    int dir, esq, i;
    for(i = 0; palavra[i] != '\0'; i++) {
    }

    dir = i-1;
    esq = 0;

    while(dir > esq) {
        if(palavra[esq] != palavra[dir]) {
            return 0; // Falso - não é um palíndromo
        } else {
            esq++;
            dir--;
        }
    }

    return 1; // Verdadeiro - é um palíndromo
}