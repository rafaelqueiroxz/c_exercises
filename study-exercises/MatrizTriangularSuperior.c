/*

    Name: MatrizTriangularSuperior.c
    Author: Rafael A. Queiroz
    Date: 24/11/2026

    Description:    Engendre uma solução em código C para analisar uma matriz 
                    quadrada de ordem escolhida pelo usuário, que aponte se ela 
                    é ou não uma Matriz Triangular Superior, ou seja, se todos 
                    os elementos posicionados abaixo da diagonal principal são 
                    iguais a zero, independentemente dos valores acima ou sobre 
                    a diagonal.
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação

void carregarMatriz(int ordem, int[][ordem]);
void verificarTriangularSuperior(int ordem, int[][ordem]);

int main() {
    
    int ordem;

    printf("Digite a ordem da matriz que sera inserida: ");
    scanf("%d", &ordem);

    int matriz[ordem][ordem];

    carregarMatriz(ordem, matriz);
    verificarTriangularSuperior(ordem, matriz);

}

void carregarMatriz(int ordem, int matriz[ordem][ordem]) {

    printf("\n");
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            printf("Digite o elemento [%d][%d] da matriz: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\n");

}

void verificarTriangularSuperior(int ordem, int matriz[ordem][ordem]) {

    int teste = 0;
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            if (j < i) {
                teste += matriz[i][j];
            }
        }
    }

    if (teste == 0) {
        printf("A matriz digitada eh uma matriz triangular superior!");
    } else {
        printf("A matriz digitada NAO eh uma matriz triangular superior!");
    }

}