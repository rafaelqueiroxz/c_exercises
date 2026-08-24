/*
	Name: contagemFogo.cpp
	Author: Rafael A. Queiroz
	Date: 24/08/26 12:31
	Description: 	IMC obtido por meio da função. 2) Faça um código em C que, por meio de uma função, seja capaz de exibir uma
					contagem regressiva por meio de um laço de repetição. O número deverá ser
					escolhido pelo usuário na função principal, ou seja, o main ( ) e, a partir daí, envie
					para que a função execute a exibição dessa contagem regressiva
*/

// Seção de inicialização
#include <stdio.h>
#include <windows.h>


// Seção de prototipação
void contagem(int);


main() {
	
	int valorContagem = 0;
	
	printf("Quantos segundos tera a sua contagem regressiva? : ");
	scanf("%d", &valorContagem);
	
	contagem(valorContagem);
	
}

void contagem(int valorContagem){
	
	for (int i = valorContagem; i >= 0; i--) {
		printf("%d, ", i);
		Sleep(1000);
	}
	printf("FOGO!");
	
}
