/*
	Name: criptografiaDados.c
	Author: Rafael A. Queiroz
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

// Seção de prototipação
char merge(char *,char *);
void exibirCrypto(char *);

int main()
{
    char nome[50];
    char cpfRg[30];

    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    printf("Digite seu CPF e o seu RG separando-os por espaco: ");
    fgets(cpfRg, sizeof(cpfRg), stdin);

    exibirCrypto(merge(nome, cpfRg));

}

char merge(char nome[], char cpfRg[]) {

    char crypto[80];

    int cont1 = 0;
    int cont2 = 0;
    while(nome[i] != '\0' && cpfRg[i] != '\0') {
        if (i % 2 == 0 && ) {
            crypto[i] = nome[cont1];
            cont1++;
            i++;
        } else {
            crypto[i] = cpfRg[cont2];
            cont2++;
            i++;
        }
    }

}

