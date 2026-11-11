/*
	Name: Teclado.cpp
	Author: Rafael A. Queiroz
	Date: 11/11/26 10:16
	Description: 	Programa para simular sons de um teclado
*/

// Seção de importação
#include <windows.h>
#include <stdio.h>
#include <conio.h>

main() {
	
	int tecla;
	
	while(true) {
		tecla = getch();
		Beep(tecla*10, 100);
		// printf("\nTecla pressionada: %c - %d", tecla, tecla);
	}
	
}
