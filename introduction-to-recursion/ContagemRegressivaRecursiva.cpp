/*
	Name: ContagemRegressivaRecursiva.cpp
	Author: Rafael A. Queiroz
	Date: 14/10/26 11:45
	Description: 	Crie uma função recursiva capaz de exibir uma
					contagem regressiva com o usuário escolhendo
					o número no main e passando para a recursão.
					Ao final da contagem igual a 0, mostrar a 
					palavra "FOGO!".
*/

// Seção de importação
#include <stdio.h>
#include <windows.h>

// Seção de prototipação
void contagem(int);

main() {
	
	int numContagem = 0;
	
	printf("Digite o numero do qual a contagem regressiva partira: ");
	scanf("%d", &numContagem);
	
	contagem(numContagem);
	
}

// Função recursiva

void contagem(int numContagem) {
	
	if (numContagem == 0) {
		printf("0 FOGO!");
		return;
	}
	
	printf("%d ", numContagem);
	Sleep(1000);
	contagem(--numContagem);
	
}
