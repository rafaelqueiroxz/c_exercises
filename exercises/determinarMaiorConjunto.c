/*
	Name: DeterminarMaiorConjunto.c
	Author: Rafael A. Queiroz
	Date: 23/09/26
	Description: 	Escreva um programa que faça a carga em uma matriz quadrada 
                    de ordem 5, com elementos sendo fornecidos pelo usuário e 
                    que esta estrutura seja passada como parâmetro para uma 
                    função chamada "determinarMaiorConjunto( )" em que deve 
                    ser apontado qual, entre os 6 conjuntos, tem a maior soma 
                    de seus elementos. Considere como conjuntos: DP, DS, Acima 
                    da DP, Abaixo da DP, Acima da DS e Abaixo da DS.
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
int determinarMaiorConjunto(int [5][5]);
int valorDP(int [5][5]);
int valorDS(int [5][5]);
int valorAcimaDP(int [5][5]);
int valorAbaixoDP(int [5][5]);
int valorAcimaDS(int [5][5]);
int valorAbaixoDS(int [5][5]);

main() {
    int mat[5][5];

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("Digite o valor que sera armazenado na Matriz[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    int maiorConjunto = determinarMaiorConjunto(mat);

    switch(maiorConjunto) {
        case 0:
            printf("\nO maior conjunto eh a Diagonal Principal!");
            break;
        case 1:
            printf("\nO maior conjunto eh a Diagonal Secundaria!");
            break;
        case 2:
            printf("\nO maior conjunto eh acima da Diagonal Principal!");
            break;
        case 3:
            printf("\nO maior conjunto eh abaixo da Diagonal Principal!");
            break;
        case 4:
            printf("\nO maior conjunto eh acima da Diagonal Secundaria!");
            break;
        case 5:
            printf("\nO maior conjunto eh abaixo da Diagonal Secundaria!");
            break;
        default:
            printf("Erro");
    }

}


int determinarMaiorConjunto(int mat[5][5]) {

    int valores[6] = {valorDP(mat), valorDS(mat), valorAcimaDP(mat), valorAbaixoDP(mat), valorAcimaDS(mat), valorAbaixoDS(mat)};

    int maior = 0;
    int posicaoMaior = 0;
    for(int i = 0; i < 6; i++) {
        if (maior < valores[i]) {
            maior = valores[i];
            posicaoMaior = i;
        }
    }

    return posicaoMaior;
}

int valorDP(int mat[5][5]) {

    int valorDP = 0;

    for (int i = 0; i < 5; i++) {
        valorDP += mat[i][i];
    }

    return valorDP;

}

int valorDS(int mat[5][5]) {

    int valorDS = 0;

    for (int i = 0; i < 5; i++) {
        valorDS += mat[i][4 - i];
    }

    return valorDS;

}

int valorAcimaDP(int mat[5][5]) {

    int valorAcimaDP = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = i+1; j < 5; j++) {
            valorAcimaDP += mat[i][j];
        }
    }

    return valorAcimaDP;

}

int valorAbaixoDP(int mat[5][5]) {

    int valorAbaixoDP = 0;

    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < i; j++) {
            valorAbaixoDP += mat[i][j];
        }
    }

    return valorAbaixoDP;

}

int valorAcimaDS(int mat[5][5]) {

    int valorAcimaDS = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4-i; j++) {
            valorAcimaDS += mat[i][j];
        }
    }

    return valorAcimaDS;

}

int valorAbaixoDS(int mat[5][5]) {

    int valorAbaixoDS = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 4; (j + i) > 4; j--) {
            valorAbaixoDS += mat[i][j];
        }
    }

    return valorAbaixoDS;

}
