/*
	Name: DeterminanteMatriz.c
	Author: Rafael A. Queiroz
	Date: 23/09/26
	Description: 	Faça um programa que seja capaz de calcular o 
                    Determinante de uma matriz quadrada de ordem 3, 
                    por meio de uma função chamada "calcularDeterminante( )" 
                    e retornar esse valor para a função que originou 
                    o processamento, a "main( )". Após esse retorno, 
                    o valor deve ser passado para uma outra função chamada 
                    "analisarDeterminante( )" que deverá emitir as seguintes 
                    mensagens:

                    Determinante POSITIVO cujo valor é igual a XX.X
                    ou
                    Determinante NEGATIVO cujo valor é igual a XX.X

                    Obs: Utilize a Regra de Sarrus para o cálculo do 
                    determinante e lembre-se que o número encontrado é um dado 
                    do tipo REAL, ou seja, float.
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
float calcularDeterminante(float mat[3][3]);
void analisarDeterminante(float);

main() {
    float mat[3][3] = {2, 1, 1, 3, 1, 2, 1, -1, 0};

    analisarDeterminante(calcularDeterminante(mat));
}

float calcularDeterminante(float mat[3][3]) {

    float dp1 = 0.0;
    float dp2 = 0.0;
    float dp3 = 0.0;
    float ds1 = 0.0;
    float ds2 = 0.0;
    float ds3 = 0.0;

    float x = 0.0;
    float y = 0.0;

    float detMat = 0.0;

    float matCalculo[3][5];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == 3) {
                matCalculo[i][j] = mat[i][0];
            } else if (j == 4) {
                matCalculo[i][j] = mat[i][1];
            } else {
                matCalculo[i][j] = mat[i][j];
            }
        }
    }

    dp1 = matCalculo[0][0] * matCalculo[1][1] * matCalculo[2][2];
    dp2 = matCalculo[0][1] * matCalculo[1][2] * matCalculo[2][3];
    dp3 = matCalculo[0][2] * matCalculo[1][3] * matCalculo[2][4];

    ds1 = matCalculo[0][4] * matCalculo[1][3] * matCalculo[2][2];
    ds2 = matCalculo[0][3] * matCalculo[1][2] * matCalculo[2][1];
    ds3 = matCalculo[0][2] * matCalculo[1][1] * matCalculo[2][0];

    x = dp1 + dp2 + dp3;
    y = ds1 + ds2 + ds3;

    detMat = x - y;

    return detMat;

}

void analisarDeterminante(float detMat) {

    if (detMat < 0) {
        printf("Determinante NEGATIVO cujo o valor eh igual a %.1f.", detMat);
    } else {
        printf("Determinante POSITIVO cujo o valor eh igual a %.1f.", detMat);
    }

}

