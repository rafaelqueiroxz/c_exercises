/*
	Name: verificaPalindromo.c
	Author: Rafael A. Queiroz
	Date: 04/09/26
	Description: 	Desenvolva um programa em que seja possível passar uma frase para
                    uma função e verificar se a sequência de caracteres é um palíndromo
                    ou não. 
                    
                    Exemplo: ovo, arara, renner são palíndromos.
*/

// Seção de importação
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Seção de prototipação
void verificarPalindromo(char *);
int calcularTamanhoPalavra(char *);

int main()
{
    
    char palavra[11]; // Maior palindromo da lingua portuguesa é "omissíssimo", com 11 caracteres.

    printf("Digite uma palavra e verificaremos se ela eh um palindromo ou nao: ");
    scanf("%s", palavra);
    verificarPalindromo(palavra);        

}

int calcularTamanhoPalavra(char palavra[]) {
    int i = 0;
    int tamanho = 1;
    while(palavra[i] != '\0') {
        i++;
        tamanho++;
    }

    return tamanho;
}

void verificarPalindromo(char palavra[]) {

    int tamanho = calcularTamanhoPalavra(palavra);
    char palavraAoContrario[tamanho];

    for(int i = 0; i < tamanho; i++) {
        if (i == (tamanho-1)) {
            palavraAoContrario[i] = '\0';
        } else {
            palavraAoContrario[i] = palavra[abs(i-(tamanho-2))];
        }
        
    }

    int cont = 0;
    for (int i = 0; i < tamanho; i++) {
        if (palavraAoContrario[i] == palavra[i]) {
            cont++;
        }
    }

    if (cont == tamanho) {
        printf("\nA palavra digitada eh um palindromo");
    } else {
        printf("\nA palavra digitada nao eh um palindromo");
    }

}