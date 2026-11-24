/*

    Name: GerandoCodigo.c
    Author: Rafael A. Queiroz
    Date: 24/11/2026

    Description:    Crie uma função chamada gerarCodigoProduto( ) 
                    que recebe dois vetores como parâmetro: um 
                    vetor de char contendo o prefixo do produto 
                    (3 letras) e um vetor de inteiros contendo 3 
                    dígitos numéricos. Essa função deve intercalar 
                    os elementos dos dois vetores, alternando uma 
                    letra e um dígito, formando um novo vetor de 
                    char (o código final do produto). Esse novo 
                    vetor deve ser passado para uma outra função, 
                    chamada exibirCodigo( ), responsável apenas por 
                    imprimi-lo na tela.
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
void gerarCodigoProduto(char *, int *, char *, int);
void exibirCodigo(char *);

int main() {

    char prefixo[3];
    int digitos[3];

    printf("Digite o prefixo do produto com 3 digitos: ");
    scanf("%c %c %c", &prefixo[0], &prefixo[1], &prefixo[2]);

    printf("Digite o codigo numerico de 3 digitos (de espaco entre um numero e outro): ");
    scanf("%d %d %d", &digitos[0], &digitos[1], &digitos[2]);

    char codigoProduto[6];

    gerarCodigoProduto(prefixo, digitos, codigoProduto, 6);

    exibirCodigo(codigoProduto);

}

void gerarCodigoProduto(char prefixo[], int digitos[], char codigoProduto[], int tamanho) {

    int contadorPrefixo = 0;
    int contadorDigitos = 0;

    for (int i = 0; i < tamanho; i++) {

        if (i % 2 == 0) {
            codigoProduto[i] = prefixo[contadorPrefixo];
            contadorPrefixo++;
        } else {
            codigoProduto[i] = digitos[contadorDigitos] + '0';
            contadorDigitos++;
        }

    }

}

void exibirCodigo(char codigoProduto[]) {
    printf("\nCodigo gerado: %s\n", codigoProduto);
}

