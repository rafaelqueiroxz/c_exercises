/*
	Name: MudarCor.cpp
	Author: Rafael A. Queiroz
	Date: 11/11/26 12:03
	Description: 	Projeto para consulta que muda a cor e
					o fundo do texto de acordo com o numero
					digitado
*/

// Seção de importação
#include <stdio.h>
#include <windows.h>
#include <conio.h>

void mudarCor(int cor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, cor);
}

main() {
	
	int cor;
	while(true) {
		cor = getch();
		mudarCor(cor);
		printf("Texto colorido\n");
		mudarCor(7);
		printf("Texto normal\n");
	}
	
}
