/*
	Name: QuadradoMagico.c
	Author: Rafael A. Queiroz
	Date: 23/09/26
	Description: 	(Desafio) Engendre uma solução em código C para analisar 
                    uma matriz quadrada de ordem escolhida pelo usuário, que 
                    aponte se os elementos presentes na matriz constituem ou 
                    não um Quadrado Mágico, ou seja, a soma de qualquer uma das
                    linhas, ou colunas ou diagonais, possuem exatamente sempre 
                    o mesmo valor, veja:  
                    
                    Exemplo:    2 9 4
                                7 5 3
                                6 1 8

                    Obs 1: Na matriz exemplo acima, a soma dos elementos sempre 
                    dará o valor 15, em qualquer linha, coluna ou diagonal. 
                    Obs 2: Os dados devem ser inseridos por meio de uma função 
                    chamada "carregarMatriz( )" e a análise se é ou não um 
                    Quadrado Mágico, em uma outra função chamada 
                    "analisarQuadradoMagico( )" que deverá receber a matriz como
                    parâmetro.

*/

// Seção de importação
#include <stdio.h>

// Variáveis Globais
int n = 0;

// Seção de prototipação
void carregarMatriz(int mat[n][n]);
void analisarQuadradoMagico(int mat[n][n]);

int main() {

    printf("Insira a ordem da Matriz que será gerada: ");
    scanf("%d", &n);

    int mat[n][n];
    
    carregarMatriz(mat);
    analisarQuadradoMagico(mat);

}

void carregarMatriz(int mat[n][n]) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Digite o valor correspondente a Matriz[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

}

void analisarQuadradoMagico(int mat[n][n]) {

    int linhas[n];
    int colunas[n];
    int diagonais[2] = {0, 0};

    for (int i = 0; i < n; i++) {
        linhas[i] = 0;
        colunas[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            linhas[i] += mat[i][j];
            colunas[j] += mat[i][j];
        }

        diagonais[0] += mat[i][i];
        diagonais[1] += mat[i][n-1-i];

    }

    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (linhas[i] == colunas[i] && linhas[i] == diagonais[0] && linhas[i] == diagonais[1]) {
            cont++;
        }
    }

    if (cont != n) {
        printf("\nA matriz inserida NAO eh um Quadrado Magico!");
    } else {
        printf("\nA matriz inserida EH um Quadrado Magico!");
    }
    

}
