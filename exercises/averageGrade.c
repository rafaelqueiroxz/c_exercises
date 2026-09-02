/*
	Name: averageGrade.c
	Author: Rafael A. Queiroz
	Date: 30/08/26
	Description:    Um professor, muito legal, fez 3 provas 
                    durante um semestre mas só vai levar em 
                    conta as duas notas mais altas para calcular 
                    a média. Faça uma aplicação em C que peça 
                    o valor das 3 notas, passe para uma função 
                    e mostre como seria a média com essas 3 provas, 
                    a média com as 2 notas mais altas, bem como 
                    sua nota mais alta e sua nota mais baixa.
*/

// Seção de importação
#include <stdio.h>

// Seção de prototipação
void avgOfThree(float, float, float);
float avgOfTwoHigher(float, float, float);
void lowerAndHigher(float, float, float);

int main()
{

    float stGrade, ndGrade, rdGrade;
    stGrade = ndGrade = rdGrade = 0.0;
    

    printf("Enter your grade for each of the exams! ");
    printf("\n1st Grade: ");
    scanf("%f", &stGrade);
    printf("2nd Grade: ");
    scanf("%f", &ndGrade);
    printf("3rd Grade: ");
    scanf("%f", &rdGrade);

    avgOfThree(stGrade, ndGrade, rdGrade);
    printf("\nAverage of two highest grades: %.2f", (avgOfTwoHigher(stGrade, ndGrade, rdGrade)));
    lowerAndHigher(stGrade, ndGrade, rdGrade);
    


}

void avgOfThree(float stGrade, float ndGrade, float rdGrade) {
    printf("\nAverage of three grades: %.2f", ((stGrade + ndGrade + rdGrade)/ 3.0));
}

float avgOfTwoHigher(float stGrade, float ndGrade, float rdGrade) {
    float grade1 = 0.0;
    float grade2 = 0.0;

    if (stGrade < ndGrade && stGrade < rdGrade) {
        grade1 = ndGrade;
        grade2 = rdGrade;
    } else if (ndGrade < stGrade && ndGrade < rdGrade) {
        grade1 = stGrade;
        grade2 = rdGrade;
    } else {
        grade1 = stGrade;
        grade2 = ndGrade;
    }

    return (grade1 + grade2) / 2.0;
}

void lowerAndHigher(float a, float b, float c){
    float higher = 0.0;
    float lower = 0.0;

    higher = (a > b) ? a : b;
    higher = (c > higher) ? c : higher;

    lower = (a < b) ? a : b;
    lower = (c < lower) ? c : lower;

    printf("\nHighest grade: %.2f", higher);
    printf("\nLowest grade: %.2f", lower);
}


