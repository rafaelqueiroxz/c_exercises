/*
	Name: VerificaAnagrama.c
	Author: Rafael A. Queiroz
	Date: 24/09/26
	Description: 	Desenvolva um programa em que seja possível passar 
                    duas palavras (dois vetores de char) para uma 
                    função chamada saoAnagramas( ), que deverá 
                    verificar se a segunda palavra é um anagrama da 
                    primeira, ou seja, se é formada exatamente pelas 
                    mesmas letras, em qualquer ordem, sem letras a mais 
                    ou a menos. A função deve retornar um valor inteiro 
                    (1 para verdadeiro, 0 para falso) para a main( ), 
                    que será responsável por exibir a mensagem final 
                    ao usuário.

                    Exemplo:

                    Entrada 1: "amor"    Entrada 2: "roma"  → Saída: "São anagramas"
                    Entrada 1: "livro"   Entrada 2: "lobo"  → Saída: "Não são anagramas"


                    Obs: desconsidere diferenças entre maiúsculas e minúsculas, 
                    mas não utilize nenhuma função pronta de ordenação de string 
                    da biblioteca padrão — a comparação deve ser feita por contagem 
                    de ocorrências de cada letra.
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
int saoAnagramas(int, char *, char *);
int verificarTamanho(char *, char *);


int main() {
    
    char palavra1[20];
    char palavra2[20];

    printf("Digite a primeira palavra: ");
    scanf("%s", &palavra1);

    printf("Digite a segunda palavra: ");
    scanf("%s", &palavra2);

    int verificacaoAnagrama = saoAnagramas(verificarTamanho(palavra1, palavra2), palavra1, palavra2);

    if (verificacaoAnagrama == 0) {
        printf("\nAs palavras digitadas NAO sao um anagrama uma da outra.");
    } else {
        printf("\nAs palavras digitadas sao um anagrama uma da outra.");
    }

    return 0;

}

int verificarTamanho(char palavra1[], char palavra2[2]) {

    int tamanho1 = 0;
    int tamanho2 = 0;
    int tamanho = 0;

    int i = 0;
    while(palavra1[i] != '\0') {
        i++;
        tamanho1++;
    }

    i = 0;
    while(palavra2[i] != '\0') {
        i++;
        tamanho2++;
    }

    if (tamanho1 != tamanho2) {
        tamanho = 0;
    } else {
        tamanho = tamanho1;
    }

    return tamanho;

}

int saoAnagramas(int tamanho, char palavra1[], char palavra2[]) {

    if (tamanho == 0) {
        return 0;
    } else {
        int contPalavra1 = 0;
        int contPalavra2 = tamanho-1;

        while(contPalavra1 < contPalavra2) {
            if (palavra1[contPalavra1] != palavra2[contPalavra2]) {
                return 0;
            } else {
                contPalavra1++;
                contPalavra2--;
            }
        }

        return 1;
    }

}