/*

    Name: SomaBordaMeio.c
    Author: Rafael A. Queiroz
    Date: 24/11/2026

    Description:    Escreva um programa que faça a carga de uma matriz quadrada 
                    de ordem 4, com elementos fornecidos pelo usuário, e que 
                    essa estrutura seja passada como parâmetro para uma função 
                    chamada compararRegioes( ). Essa função deve calcular 
                    separadamente a soma dos elementos que compõem a borda da 
                    matriz (primeira e última linha, primeira e última coluna) 
                    e a soma dos elementos que compõem o centro da matriz (os 
                    elementos internos, que não pertencem à borda), apontando 
                    qual das duas regiões possui a maior soma.
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
void compararRegioes(int[][4]);

int main() {
    
    int matriz[4][4];
    printf("Soma de borda e centro. Qual eh maior?\n\n");

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Digite o elemento [%d][%d] da matriz: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    compararRegioes(matriz);


}

void compararRegioes(int matriz[][4]) {

    int somaBorda = 0;
    int somaMeio = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i > 0 && i < 3 && j > 0 && j < 3) {
                somaMeio += matriz[i][j];
            } else {
                somaBorda += matriz[i][j];
            }
        }
    }

    if (somaMeio == somaBorda) {
        printf("\nA soma da borda eh igual a soma do meio! Ambas totalizam %d", somaMeio);
    } else if (somaMeio > somaBorda) {
        printf("\nA soma do meio (%d) eh maior que a soma da borda (%d)!", somaMeio, somaBorda);
    } else {
        printf("\nA soma da borda (%d) eh maior que a soma do meio (%d)!", somaBorda, somaMeio);
    }

}
