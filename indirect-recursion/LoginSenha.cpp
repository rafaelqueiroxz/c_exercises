/*
	Name: LoginSenha.cpp
	Author: Rafael A. Queiroz
	Date: 28/10/26 10:13
	Description: 	Programa para simular um Login e Senha por meio de 
					Recursividade Indireta
*/

// Seção de importação
#include <stdio.h>
#include <string.h>

// Seção de prototipação
void verLogin();
void verSenha();

// Variáveis Globais
char user[20] = "RafaelBonitao";
int senha = 12344321;
int contador = 1;

main() {
	
	verLogin();
	
}

// Função para verificar o Login do Usuário
void verLogin() {
	
	char login[20];
	printf("Login: ");
	gets(login);
	
	/* if (strcmp(login, user) == 0) {
		verSenha();
	} else {
		verLogin();
	} */
	
	strcmp(login, user) == 0 ? verSenha() : verLogin();
	
}

// Função para a verificação da senha
void verSenha() {
	
	int password;
	printf("Senha: ");
	scanf("%d", &password);
	
	if (password == senha) {
		printf("Login efetuado com sucesso!");
	} else {
		if (contador < 3) {
			contador++;
			verSenha();
		} else {
			contador = 1;
			fflush(stdin);
			verLogin();
		}
	}
	
}

