/*
	Name: PerfumariaSons.cpp
	Author: Rafael A. Queiroz
	Date: 11/11/26 09:54
	Description: 	Programa para emitir sons necessários
					para chamar a atenção do usuário.
*/

// Seção de importação
#include <windows.h> // Biblioteca para utilizar Beep() e Sleep()
#include <stdio.h>

main() {
	
	int freq, tempo;
	int cont;
	
	freq = 2000;
	tempo = 1000;
	
	for (cont =0; i < 20; i++) {
		
		Beep(freq, tempo);
		freq += 500;
		
	}
	for (cont; cont > 0; cont--) {
		
		Beep(freq, tempo);
		freq -= 500;
		
	}
	
	
	
	
}
