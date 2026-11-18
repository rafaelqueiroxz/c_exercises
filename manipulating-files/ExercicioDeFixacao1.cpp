/*
	Name: ExercicioDeFixacao1.cpp
	Author: Rafael A. Queiroz
	Date: 18/11/26 10:03
	Description: 	1) Escrever um programa que leia nome,
					idade, peso e altura para 5 pessoas e,
					para cada uma delas calcular e analisar
					seus IMC's gravando os resultados em um
					arquivo texto chamado prontuário.
*/

#include <stdio.h>
#include <windows.h>

void calcularIMC(float, float, FILE *);

int main() {
	
	FILE *file = fopen("prontuario.txt", "w");
	
	if (file == NULL) {
		perror("Erro ao abrir o arquivo!");
		return 1;
	}
	
	fprintf(file, "Prontuario do Hospital Santa Ana - 18/11/2026\n");
	
	char nome[30];
	int idade = 0;
	float peso = 0.0;
	float altura = 0.0;
	
	for (int i = 0; i < 5; i++) {
		
		printf("Entre com os dados do %do paciente\n", i+1);
		printf("Nome: ");
		gets(nome);
		printf("Idade: ");
		scanf("%d", &idade);
		printf("Peso: ");
		scanf("%f", &peso);
		printf("Altura: ");
		scanf("%f", &altura);
		printf("\n");
		
		fprintf(file, "\nPaciente %d:\n", i+1);
		fprintf(file, "Nome: %s\n", nome);
		fprintf(file, "Idade: %d\n", idade);
		fprintf(file, "Peso: %.2f\n", peso);
		fprintf(file, "Altura: %.2f\n", altura);
		
		calcularIMC(peso, altura, file);
		
		fflush(stdin);
	}
	
	printf("Dados salvos com sucesso!");
	
	fclose(file);
	
	
}

void calcularIMC (float peso, float altura, FILE *file) {
		
	
	float imc = peso / (altura * altura);
	
	if (imc < 18.5) {
		fprintf(file, "IMC = %.2f | Baixo peso\n", imc);
	} else if (imc < 25) {
		fprintf(file, "IMC = %.2f | Peso adequado\n", imc);
	} else if (imc < 30) {
		fprintf(file, "IMC = %.2f | Sobrepeso\n", imc);
	} else if (imc < 35) {
		fprintf(file, "IMC = %.2f | Obesidade Grau I\n", imc);
	} else if (imc < 40) {
		fprintf(file, "IMC = %.2f | Obesidade Grau II\n", imc);
	} else {
		fprintf(file, "IMC = %.2f | Obesidade Grau III\n", imc);
	}
	
}
