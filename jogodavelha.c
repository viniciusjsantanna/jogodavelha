#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#define TAM 3


void multiplayer(char tabela[][TAM], char jogador1[], char jogador2[]);
void multiJogar(char tabela[][TAM], char jogador1[], char jogador2[], int jogador);
void nivelFacil(char tabela[][TAM], char jogador[]);
void nivelMedio(char tabela[][TAM], char jogador[]);
int verificarPrimeiroJogador(char jogador1[]);
void jogadaMedioComputador(char tabela[][TAM], int primeiro);
int verificarVitoria(char tabela[][TAM]);
void imprimirTabela(char tabela[][TAM]);
int ataqueComputador(char tabela[][TAM]);
int defesaComputador(char tabela[][TAM]);
void jogadaAleatoria(char tabela[][TAM], int primeiro);
void nivelDificil(char tabela[][TAM], char jogador[]);
void jogadaDificilComputador(char tabela[][TAM], int primeiro, int i);
void jogadaPlanejada(char tabela[][TAM], int primeiro, int i);
void limparTabela(char tabela[][TAM]);


//Posicoes sao dadas como XY da matriz de acordo com cada variavel
typedef struct tabela {
	int posicaoLinha1[TAM];
	int posicaoLinha2[TAM];
	int posicaoLinha3[TAM];
}Tabela;




int main(void)
{
	int op, op2, op3; char jogador1[20], jogador2[20], tabela[TAM][TAM];
	do
	{
		limparTabela(tabela);
		printf("\t\t\t* * * * Jogo da Velha * * * *\n\n");
		printf("1. Novo Jogo!\n");
		printf("2. Continuar Jogo!\n");
		printf("3. Sair!\n");
		printf(">>> ");
		scanf_s("%d", &op);
		switch (op) {
		case 1:
			system("cls");
			printf("\t\t\t* * * * Jogo da Velha * * * *\n\n");
			printf("1. Um Jogador!\n");
			printf("2. Dois Jogadores!\n");
			printf(">>>  ");
			scanf_s("%d", &op2);
			switch (op2)
			{
			case 1:
				system("cls");
				printf("\t\t\t* * * * Jogo da Velha * * * *\n\n");
				printf("Informe o Seu nome: "); fflush(stdin);
				gets_s(jogador1, 20);
				system("cls");
				printf("\t\t\t* * * * Jogo da Velha * * * *\n\n");
				printf("1 - Facil!\n");
				printf("2 - Medio!\n");
				printf("3 - Dificil!\n");
				printf(">>> ");
				scanf_s("%d", &op3);


				system("cls");
				printf("\n\n\n\n\n\n\n\n\t\t\tO jogo iniciara em: ");
				printf("3 ");
				Sleep(1000);
				printf("2 ");
				Sleep(1000);
				printf("1");
				printf(".");
				Sleep(1000);
				printf(".");
				Sleep(1000);
				printf(".");
				Sleep(1000);
				system("cls");


				switch (op3)
				{
				case 1:
					nivelFacil(tabela, jogador1);
					break;
				case 2:
					nivelMedio(tabela, jogador1);
					break;
				case 3:
					nivelDificil(tabela, jogador1);
					break;
				}
				break;
			case 2:
				system("cls");
				printf("\t\t\t* * * * Jogo da Velha * * * *\n\n");
				printf("Informe o nome do jogador 1: "); fflush(stdin);
				gets_s(jogador1, 20); fflush(stdin);
				printf("Informe o nome do jogador 2: "); fflush(stdin);
				gets_s(jogador2, 20); fflush(stdin);
				system("cls");
				printf("\n\n\n\n\n\n\n\n\t\t\tO jogo iniciara em: ");
				printf("3 ");
				Sleep(1000);
				printf("2 ");
				Sleep(1000);
				printf("1");
				printf(".");
				Sleep(1000);
				printf(".");
				Sleep(1000);
				printf(".");
				Sleep(1000);
				system("cls");
				printf("\t\t\t* * * * Jogando * * * *\n\n");
				multiplayer(tabela, jogador1, jogador2);
			default:
				break;
			}
			break;
		}
	} while (op != 3);


	return 0;
}
void multiplayer(char tabela[][TAM], char jogador1[], char jogador2[]) {
	int jogador, primeiro;
	srand((unsigned)time(NULL));
	jogador = rand() % 2;
	//printf("\t\t\t* * * * Jogo da Velha * * * *\n\n");
	if (jogador == 0)
	{
		printf("O jogador que ira iniciar: %s", jogador1);
		Sleep(2000);
		primeiro = 1;
		multiJogar(tabela, jogador1, jogador2, primeiro);
	}
	else
	{
		printf("O jogador que ira iniciar: %s", jogador2);
		Sleep(2000);
		primeiro = 2;
		multiJogar(tabela, jogador1, jogador2, primeiro);
	}
}


void multiJogar(char tabela[][TAM], char jogador1[], char jogador2[], int jogador) {
	int linha, coluna, i = 0, j, k, status, score1 = 0, score2 = 0; char novamente; Tabela* table;
	system("cls");
	do {
		printf("\t\t\t\t* * * * Jogando * * * *\n\n");
		imprimirTabela(tabela);


		while (i <= 8) {


			do {
				if (jogador == 1)
					printf("Vez do Jogador: %s\n", jogador1);
				else
					printf("Vez do Jogador: %s\n", jogador2);


				printf("Informe LINHA/COLUNA para fazer uma jogada!\n");
				do {
					printf("LINHA: ");
					scanf_s("%i", &linha);
				} while (linha < 1 || linha > 3);


				do {
					printf("COLUNA: ");
					scanf_s("%i", &coluna);
				} while (coluna < 1 || coluna > 3);


				if (tabela[linha - 1][coluna - 1] == 'X' || tabela[linha - 1][coluna - 1] == 'O') {
					printf("A posicao ja esta preenchida, Jogue Novamente!\n");
					_getch();
					system("cls");
					printf("\t\t\t\t* * * * Jogando * * * *\n\n");
					imprimirTabela(tabela);
				}




			} while (tabela[linha - 1][coluna - 1] == 'X' || tabela[linha - 1][coluna - 1] == 'O');


			if (jogador == 1) {
				tabela[linha - 1][coluna - 1] = 'O';
				jogador = 2;
			}
			else {
				tabela[linha - 1][coluna - 1] = 'X';
				jogador = 1;
			}
			system("cls");
			printf("\t\t\t* * * * Jogando * * * *\n\n");
			imprimirTabela(tabela);


			status = verificarVitoria(tabela);


			if (status == 1) {
				score1++;
				printf("O jogador %s venceu!\n", jogador1);
				printf("# # # Score # # #\n");
				printf("%s : %d\n", jogador1, score1);
				printf("%s : %d\n", jogador2, score2);
				break;
			}
			if (status == 2) {
				score2++;
				printf("O jogador %s venceu!\n", jogador2);
				printf("# # # Score # # #\n");
				printf("%s : %d\n", jogador1, score1);
				printf("%s : %d\n", jogador2, score2);
				break;
			}
			i++;
		}


		if (i == 9 && status == 0)
			printf("O jogo terminou empatado!\n");
		_getch();
		do {
			printf("Deseja jogar novamente: "); fflush(stdin);
			novamente = toupper(getchar());
		} while (novamente != 'S' && novamente != 'N');
		system("cls");
		if (novamente == 'S') {
			limparTabela(tabela);
			i = 0;
		}
	} while (novamente == 'S');
	if (novamente == 'N')
	{
		table = (Tabela*)malloc(sizeof(Tabela));
		for (k = 0; k < TAM; k++)
		{
			for (j = 0; j < TAM; j++)
			{
				if (k == 0)
				{
					table->posicaoLinha1[j] = tabela[k][j];
				}
				else if (k == 1)
				{
					table->posicaoLinha2[j] = tabela[k][j];
				}
				else {
					table->posicaoLinha3[j] = tabela[k][j];
				}
			}
		}
	}


	system("cls");
}


void nivelFacil(char tabela[][TAM], char jogador[]) {
	int primeiro, linha, coluna, i = 0, score1 = 0, score2 = 0, status; char novamente;
	system("cls");
	do {
		printf("\t\t\t* * * * Jogando * * * *\n\n");


		primeiro = verificarPrimeiroJogador(jogador);
		system("cls");
		printf("\t\t\t* * * * Jogando * * * *\n\n");
		imprimirTabela(tabela);


		while (i <= 8) {
			if (primeiro == 1) {
				do {
					printf("Vez do Jogador %s\n\n", jogador);
					printf("Informe LINHA/COLUNA para fazer uma jogada!\n");
					do {
						printf("LINHA: ");
						scanf_s("%i", &linha);
					} while (linha < 1 || linha > 3);


					do {
						printf("COLUNA: ");
						scanf_s("%i", &coluna);
					} while (coluna < 1 || coluna > 3);


					if (tabela[linha - 1][coluna - 1] == 'X' || tabela[linha - 1][coluna - 1] == 'O') {
						printf("A posicao ja esta preenchida, Jogue Novamente!\n");
						_getch();
						system("cls");
						printf("\t\t\t\t* * * * Jogando * * * *\n\n");
						imprimirTabela(tabela);
					}




				} while (tabela[linha - 1][coluna - 1] == 'X' || tabela[linha - 1][coluna - 1] == 'O');


				tabela[linha - 1][coluna - 1] = 'O';
				primeiro = 2;
			}
			else {
				printf("Vez do Computador!\n\n");
				jogadaAleatoria(tabela, primeiro);
				primeiro = 1;
			}
			system("cls");
			printf("\t\t\t* * * * Jogando * * * *\n\n");
			imprimirTabela(tabela);


			status = verificarVitoria(tabela);
			if (status == 1) {
				score1++;
				printf("O jogador %s venceu!\n", jogador);
				printf("# # # Score # # #\n");
				printf("%s : %d\n", jogador, score1);
				printf("Computador : %d\n", score2);
				break;
			}
			if (status == 2) {
				score2++;
				printf("O Computador venceu!\n");
				printf("# # # Score # # #\n");
				printf("%s : %d\n", jogador, score1);
				printf("Computador : %d\n", score2);
				break;
			}


			i++;
		}
		if (i == 9 && status == 0)
			printf("O jogo terminou empatado!\n");
		_getch();
		do {
			printf("Deseja jogar novamente: "); fflush(stdin);
			novamente = toupper(getchar());
		} while (novamente != 'S' && novamente != 'N');
		system("cls");
		if (novamente == 'S') {
			limparTabela(tabela);
			i = 0;
		}
	} while (novamente == 'S');
	system("cls");
}


void nivelMedio(char tabela[][TAM], char jogador[]) {
	int primeiro, i = 0, linha, coluna, score1 = 0, score2 = 0, status; char novamente;
	system("cls");
	do {
		printf("\t\t\t* * * * Jogando * * * *\n\n");


		primeiro = verificarPrimeiroJogador(jogador);
		system("cls");
		printf("\t\t\t* * * * Jogando * * * *\n\n");
		imprimirTabela(tabela);


		while (i <= 8) {


			if (primeiro == 1) {
				do {
					printf("Vez do Jogador %s\n\n", jogador);
					printf("Informe LINHA/COLUNA para fazer uma jogada!\n");
					do {
						printf("LINHA: ");
						scanf_s("%i", &linha);
					} while (linha < 1 || linha > 3);


					do {
						printf("COLUNA: ");
						scanf_s("%i", &coluna);
					} while (coluna < 1 || coluna > 3);


					if (tabela[linha - 1][coluna - 1] == 'X' || tabela[linha - 1][coluna - 1] == 'O') {
						printf("A posicao ja esta preenchida, Jogue Novamente!\n");
						_getch();
						system("cls");
						printf("\t\t\t\t* * * * Jogando * * * *\n\n");
						imprimirTabela(tabela);
					}




				} while (tabela[linha - 1][coluna - 1] == 'X' || tabela[linha - 1][coluna - 1] == 'O');


				tabela[linha - 1][coluna - 1] = 'O';
				primeiro = 2;
			}
			else {
				printf("Vez do Computador!\n\n");
				jogadaMedioComputador(tabela, primeiro);
				primeiro = 1;
				_getch();
			}
			system("cls");
			printf("\t\t\t* * * * Jogando * * * *\n\n");
			imprimirTabela(tabela);


			status = verificarVitoria(tabela);
			if (status == 1) {
				score1++;
				printf("O jogador %s venceu!\n", jogador);
				printf("# # # Score # # #\n");
				printf("%s : %d\n", jogador, score1);
				printf("Computador : %d\n", score2);
				break;
			}
			if (status == 2) {
				score2++;
				printf("O Computador venceu!\n");
				printf("# # # Score # # #\n");
				printf("%s : %d\n", jogador, score1);
				printf("Computador : %d\n", score2);
				break;
			}


			i++;
		}
		if (i == 9 && status == 0)
			printf("O jogo terminou empatado!\n");
		_getch();
		do {
			printf("Deseja jogar novamente: "); fflush(stdin);
			novamente = toupper(getchar());
		} while (novamente != 'S' && novamente != 'N');
		system("cls");
		if (novamente == 'S') {
			limparTabela(tabela);
			i = 0;
		}
	} while (novamente == 'S');
	system("cls");
}


int verificarPrimeiroJogador(char jogador1[]) {
	int primeiro, jogador;


	srand((unsigned)time(NULL));
	jogador = rand() % 2;


	if (jogador == 0)
	{
		printf("O jogador que ira iniciar: %s", jogador1);
		Sleep(2000);
		primeiro = 1;
		/*jogar(tabela, jogador1, primeiro);*/
	}
	else
	{
		printf("O jogador que ira iniciar: Computador");
		Sleep(2000);
		primeiro = 2;
		/*jogar(tabela, jogador1, , primeiro);*/
	}


	//if (op == 1 && jogador == 1){
	//	printf("\nO jogador 1 começa!\n");
	//	primeiro = 1;
	//}
	//else if (op == 2 && jogador == 0){
	//	printf("\nO jogador 1 começa!\n");
	//	primeiro = 1;
	//}
	//else{
	//	printf("\nO Computador começa!\n");
	//	primeiro = 2;
	//}


	return primeiro;
}


void jogadaMedioComputador(char tabela[][TAM], int primeiro) {
	int status;


	status = ataqueComputador(tabela);


	if (status == -1)
	{
		status = 0;
		status = defesaComputador(tabela);
		if (status == -1)
		{
			jogadaAleatoria(tabela, primeiro);
		}
	}
}


int verificarVitoria(char tabela[][TAM]) {
	int i, j, n, c = 0;
	char letra = 'O';
	int retorno = 1;


	while (c < 2) {
		for (i = 0; i < TAM; i++) { //Verificar linhas
			n = 0;
			for (j = 0; j < TAM; j++) {
				if (tabela[i][j] == letra) {
					n++;
				}
			}
			if (n == 3) {
				return retorno;
			}
		}


		for (j = 0; j < TAM; j++) { //Verificar colunas
			n = 0;
			for (i = 0; i < TAM; i++) {
				if (tabela[i][j] == letra) {
					n++;
				}
			}
			if (n == 3) {
				return retorno;
			}
		}


		n = 0;
		for (i = 0; i < TAM; i++) { //Verificar diagonal princ
			if (tabela[i][i] == letra) {
				n++;
			}
		}
		if (n == 3) {
			return retorno;
		}


		n = 0;
		j = TAM - 1;
		for (i = 0; i < TAM; i++) { //Verificar diagonal sec
			if (tabela[i][j] == letra) {
				n++;
				j--;
			}
		}
		if (n == 3) {
			return retorno;
		}


		c++;
		letra = 'X';
		retorno = 2;
	}




	return 0;
}


void imprimirTabela(char tabela[][TAM]) {
	int i, j;


	printf("\n");
	for (i = 0; i < TAM; i++) {
		printf("\t\t\t\t");
		for (j = 0; j < TAM; j++) {
			printf(" %c ", tabela[i][j]);
			if (j != TAM - 1)
				printf(":");
		}
		printf("\n");
		if (i == 0 || i == 1)
			printf("\t\t\t\t-----------");
		printf("\n");


	}
	printf("\n");
}


int ataqueComputador(char tabela[][TAM])
{
	int i, j, x, o, ln, col, c;


	//Ataque
	for (i = 0; i < TAM; i++) { //possibilidade de ganho por linha
		o = 0;
		x = 0;
		for (j = 0; j < TAM; j++) {
			if (tabela[i][j] == 'X') {
				x++;
			}
			else if (tabela[i][j] == 'O') {
				o++;
			}
			else {
				ln = i;
				col = j;
			}
		}
		if (x == 2 && o == 0) {
			tabela[ln][col] = 'X';
			return 1;
		}
	}


	for (j = 0; j < TAM; j++) { //possibilidade de ganho por coluna
		o = 0;
		x = 0;
		for (i = 0; i < TAM; i++) {
			if (tabela[i][j] == 'X') {
				x++;
			}
			else if (tabela[i][j] == 'O') {
				o++;
			}
			else {
				ln = i;
				col = j;
			}
		}
		if (x == 2 && o == 0) {
			tabela[ln][col] = 'X';
			return 1;
		}
	}


	x = 0;
	ln = 0;
	for (i = 0; i < TAM; i++) { //possibilidade de ganho na diagonal princ
		if (tabela[i][i] == 'X') {
			x++;
		}
		else if (tabela[i][i] == '0') {
			ln = i;
		}
		if (x == 2 && ln != 0) {
			tabela[ln][ln] = 'X';
			return 1;
		}
	}


	o = 0;
	c = TAM - 1;
	ln = 0;
	for (i = 0; i < TAM; i++) { //Possibilidade de ganho na diagonal sec
		if (tabela[i][c] == 'X') {
			x++;
		}
		else if (tabela[i][c] == '0') {
			ln = i;
		}
		if (o == 2 && ln != 0) {
			tabela[ln][ln] = 'X';
			return 1;
		}
		c--;
	}


	return -1;
}


int defesaComputador(char tabela[][TAM])
{
	int i, j, x, o, ln, col, c;
	//Defesa
	for (i = 0; i < TAM; i++) { //possibilidade de perda por linha
		o = 0;
		x = 0;
		for (j = 0; j < TAM; j++) {
			if (tabela[i][j] == 'O') {
				o++;
			}
			else if (tabela[i][j] == 'X') {
				x++;
			}
			else {
				ln = i;
				col = j;
			}
		}
		if (o == 2 && x == 0) {
			tabela[ln][col] = 'X';
			return 1;
		}
	}


	for (j = 0; j < TAM; j++) { //possibilidade de perda por coluna
		o = 0;
		x = 0;
		for (i = 0; i < TAM; i++) {
			if (tabela[i][j] == 'O') {
				o++;
			}
			else if (tabela[i][j] == 'X') {
				x++;
			}
			else {
				ln = i;
				col = j;
			}
		}
		if (o == 2 && x == 0) {
			tabela[ln][col] = 'X';
			return 1;
		}
	}


	o = 0;
	ln = 0;
	for (i = 0; i < TAM; i++) { //possibilidade de perda na diagonal princ
		if (tabela[i][i] == 'O') {
			o++;
		}
		else if (tabela[i][i] == '0') {
			ln = i;
		}
		if (o == 2 && ln != 0) {
			tabela[ln][ln] = 'X';
			return 1;
		}
	}


	ln = 0;
	o = 0;
	c = TAM - 1;
	for (i = 0; i < TAM; i++) { //Possibilidade de perda na diagonal sec
		if (tabela[i][c] == 'O') {
			o++;
		}
		else if (tabela[i][c] == '0') {
			ln = i;
		}
		if (o == 2 && ln != 0) {
			tabela[ln][ln] = 'X';
			return 1;
		}
		c--;
	}


	return -1;
}


void jogadaAleatoria(char tabela[][TAM], int primeiro)
{
	int ln, col;


	do {
		srand((unsigned)time(NULL));
		ln = rand() % 3;
		col = rand() % 3;
	} while (tabela[ln][col] == 'X' || tabela[ln][col] == 'O');


	if (primeiro == 1)
	{
		tabela[ln][col] = 'O';
	}
	else
	{
		tabela[ln][col] = 'X';
	}


}


void nivelDificil(char tabela[][TAM], char jogador[]) {
	int i = 0, primeiro, linha, coluna, score1 = 0, score2 = 0, status; char novamente;
	system("cls");
	do {
		printf("\t\t\t* * * * Jogando * * * *\n\n");


		primeiro = verificarPrimeiroJogador(jogador);
		system("cls");
		printf("\t\t\t* * * * Jogando * * * *\n\n");
		imprimirTabela(tabela);


		while (i <= 8) {


			if (primeiro == 1) {
				do {
					printf("Vez do Jogador %s\n\n", jogador);
					printf("Informe LINHA/COLUNA para fazer uma jogada!\n");
					do {
						printf("LINHA: ");
						scanf_s("%i", &linha);
					} while (linha < 1 || linha > 3);


					do {
						printf("COLUNA: ");
						scanf_s("%i", &coluna);
					} while (coluna < 1 || coluna > 3);


					if (tabela[linha - 1][coluna - 1] == 'X' || tabela[linha - 1][coluna - 1] == 'O') {
						printf("A posicao ja esta preenchida, Jogue Novamente!\n");
						_getch();
						system("cls");
						printf("\t\t\t\t* * * * Jogando * * * *\n\n");
						imprimirTabela(tabela);
					}




				} while (tabela[linha - 1][coluna - 1] == 'X' || tabela[linha - 1][coluna - 1] == 'O');


				tabela[linha - 1][coluna - 1] = 'O';
				primeiro = 2;
			}
			else {
				printf("Vez do Computador!\n\n");
				jogadaDificilComputador(tabela, primeiro, i);
				primeiro = 1;
				_getch();
			}
			system("cls");
			printf("\t\t\t* * * * Jogando * * * *\n\n");
			imprimirTabela(tabela);


			status = verificarVitoria(tabela);
			if (status == 1) {
				score1++;
				printf("O jogador %s venceu!\n", jogador);
				printf("# # # Score # # #\n");
				printf("%s : %d\n", jogador, score1);
				printf("Computador : %d\n", score2);
				break;
			}
			if (status == 2) {
				score2++;
				printf("O Computador venceu!\n");
				printf("# # # Score # # #\n");
				printf("%s : %d\n", jogador, score1);
				printf("Computador : %d\n", score2);
				break;
			}


			i++;
		}
		if (i == 9 && status == 0)
			printf("O jogo terminou empatado!\n");
		_getch();
		do {
			printf("Deseja jogar novamente: "); fflush(stdin);
			novamente = toupper(getchar());
		} while (novamente != 'S' && novamente != 'N');
		system("cls");
		if (novamente == 'S') {
			limparTabela(tabela);
			i = 0;
		}
	} while (novamente == 'S');
	system("cls");
}


void jogadaDificilComputador(char tabela[][TAM], int primeiro, int i) {
	int status;


	status = ataqueComputador(tabela);


	if (status == -1)
	{
		status = 0;
		status = defesaComputador(tabela);
		if (status == -1)
		{
			jogadaPlanejada(tabela, primeiro, i);
		}
	}
}


void jogadaPlanejada(char tabela[][TAM], int primeiro, int i) {
	int ln, col;


	if (i == 0) {
		do {
			ln = rand() % 3;
			col = rand() % 3;
		} while (ln == 1 || col == 1);
		tabela[ln][col] = 'X';
		return;
	}
	else if ((tabela[1][1] != 'X' && tabela[1][1] != 'O')) {
		tabela[1][1] = 'X';
		return;
	}
	else if (tabela[0][0] == 'O' && (tabela[2][2] != 'X' && tabela[2][2] != 'O')) {
		tabela[2][2] = 'X';
		return;
	}
	else if (tabela[2][2] == 'O' && (tabela[0][0] != 'X' && tabela[0][0] != 'O')) {
		tabela[0][0] = 'X';
		return;
	}
	else if (tabela[0][2] == 'O' && (tabela[2][0] != 'X' && tabela[2][0] != 'O')) {
		tabela[2][0] = 'X';
		return;
	}
	else if (tabela[2][0] == 'O' && (tabela[0][2] != 'X' && tabela[0][2] != 'O')) {
		tabela[0][2] = 'X';
		return;
	}
	else if (tabela[1][1] == 'X' || tabela[1][1] == 'O') {


		if ((tabela[0][0] == 'X' || tabela[0][0] == 'O') || (tabela[0][2] == 'X' || tabela[0][2] == 'O') || (tabela[2][0] == 'X' || tabela[2][0] == 'O') || (tabela[2][2] == 'X' || tabela[2][2] == 'O')) {
			do {
				ln = rand() % 3;
				col = rand() % 3;
			} while ((ln == 1 || col == 1) && (tabela[ln][col] == 'X' || tabela[ln][col] == 'O'));
			tabela[ln][col] = 'X';
			return;
		}
		else {
			do {
				ln = rand() % 3;
				col = rand() % 3;
			} while ((ln != 1 && col != 1) && (tabela[ln][col] == 'X' || tabela[ln][col] == 'O'));
			tabela[ln][col] = 'X';
			return;
		}
	}
}


void limparTabela(char tabela[][TAM])
{
	int i, j;
	for (i = 0; i < TAM; i++)
	{
		for (j = 0; j < TAM; j++)
		{
			tabela[i][j] = ' ';
		}
	}
}


















