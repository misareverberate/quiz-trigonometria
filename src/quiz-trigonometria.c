#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>
#include<conio.c>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<stdbool.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
/*
Nome: Quiz Educacional de Trigonometria
Author: Matheus Viana de Almeida
Date: 31/05/23 21:35
Description: Um quiz sobre geometria :)
*/
int main() {
	/*	-> Configurações Básicas do Console <-	*/
	SetConsoleIcon(LoadIcon(NULL, "console.ico"));
	SetConsoleTitle("Quiz de Geometria - By Matheus Almeida");
	setlocale(LC_ALL, "ptb");
	/*Variáveis Básica -> Declaração da grande maioria das variáveis utilizadas no programa! */

	/* Variável geral para uso em loops*/
	int inteiroDeLoop;
	/* Variáveis gerais do quiz*/
	char nickname[150];
	int pontuacao = 0;
	int erros = 0;
	bool acertou;
	/*Variáveis do Menu interativo*/
	int selecao;
	int menu = 1;
	char seta[30] = "                    ";
	char vazio[30] = "                     ";
	bool selecionado = false;
	/*	-> Variáveis Sans <-	*/
	/*Diálogos*/
	char dialogueIntroducao1[300] = "É um lindo dia lá fora.|\nOs pássaros cantam,\nas flores desabrocham.|\nEm dias como esses,\ncrianças como você, \nque não sabem trigonometria.|||\nDevem queimar no inferno.";
	char dialogueIntroducao2[200] = "Digo... -devem sofrer na Recuperação!!!|\nBem, |de toda forma já que tá aqui,\ntente sobreviver ao meu quiz-\nOU NÃO.";
	char dialogueNick[250] = "Mas olha só, |o que temos aqui!|\nEntão você realmente decidiu se juntar a mim?|\nMUITO FASCINANTE|, que nem meu cabelo, |éh...|\nEntão tá né|, cada doido com suas loucuras.-\n\nMAS ENTÃO CRIANÇA, QUAL É O SEU NOME HEIN?\n";
	char mautempo[500] = "Então parece que você,\nestá afim de um mal tempo...||\nComo eu,| Sans,| sou um ser benevolente,\nvou lhe explicar as regras:\n\n|1)Lhe será apresentado uma pergunta sobre trigonometria\n2)E você terá 5 alternativas de A a E.\n3)Usando W(Move para cima)e S(Move para baixo),\npra escolher a opção no menu,\nAperte Enter pra responder, antes do tempo acabar.\nSIM TEM UM TEMPO PRA RESPONDER!\nExatos 30 segundos\n\n|Regras explanadas\n-ENTÃO |QUE |OS |JOGOS -COMECEM";

	/*Sprites Sans*/
	int sprite1[15][16] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0},
		{0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0},
		{0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0},
		{0, 15, 15, 0, 0, 0, 15, 15, 15, 15, 0, 0, 0, 15, 15, 0},
		{0, 15, 15, 0, 15, 0, 15, 15, 15, 15, 0, 15, 0, 15, 15, 0},
		{0, 15, 15, 0, 0, 0, 15, 15, 15, 15, 0, 0, 0, 15, 15, 0},
		{0, 0, 15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 15, 0, 0},
		{0, 0, 15, 15, 15, 15, 0, 0, 0, 0, 15, 15, 15, 15, 0, 0},
		{0, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 0},
		{0, 15, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 15, 0},
		{0, 0, 15, 15, 0, 15, 0, 15, 15, 0, 15, 0, 15, 15, 0, 0},
		{0, 0, 0, 15, 15, 0, 0, 0, 0, 0, 0, 15, 15, 0, 0, 0},
		{0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};/*Sprite normal*/
	int sprite2[15][16] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0},
		{0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0},
		{0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0},
		{0, 15, 15, 8, 8, 8, 15, 15, 15, 15, 8, 8, 8, 15, 15, 0},
		{0, 15, 15, 0, 15, 0, 15, 15, 15, 15, 0, 15, 0, 15, 15, 0},
		{0, 15, 15, 0, 0, 0, 15, 15, 15, 15, 0, 0, 0, 15, 15, 0},
		{0, 0, 15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 15, 0, 0},
		{0, 0, 15, 15, 15, 15, 0, 0, 0, 0, 15, 15, 15, 15, 0, 0},
		{0, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 0},
		{0, 15, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 15, 0},
		{0, 0, 15, 15, 0, 15, 0, 15, 15, 0, 15, 0, 15, 15, 0, 0},
		{0, 0, 0, 15, 15, 0, 0, 0, 0, 0, 0, 15, 15, 0, 0, 0},
		{0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};/*Sprite olho abaixado*/

	int sprite3[15][16] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0},
		{0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 3},
		{0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 3, 0},
		{0, 15, 15, 0, 0, 0, 15, 15, 15, 15, 3, 3, 3, 3, 3, 0},
		{0, 15, 15, 0, 0, 0, 15, 15, 15, 15, 3, 6, 3, 3, 15, 0},
		{0, 15, 15, 0, 0, 0, 15, 15, 15, 15, 3, 3, 3, 15, 15, 0},
		{0, 0, 15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 15, 0, 0},
		{0, 0, 15, 15, 15, 15, 0, 0, 0, 0, 15, 15, 15, 15, 0, 0},
		{0, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 0},
		{0, 15, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 15, 0},
		{0, 0, 15, 15, 0, 15, 0, 15, 15, 0, 15, 0, 15, 15, 0, 0},
		{0, 0, 0, 15, 15, 0, 0, 0, 0, 0, 0, 15, 15, 0, 0, 0},
		{0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};/*Sprite modo batalha*/

	/*	-> Variáveis das perguntas do quiz <-	*/
	int numeroDePerguntas = 10;
	typedef struct Pergunta { /* Estrutura das perguntas do quiz*/
		int id;
		char dificuldade[30];
		char pergunta[200];
		char alternativas[5][250];
		int rC; /*resposta Correta*/
	} Pergunta;
	/*Definição das Perguntas*/
	Pergunta p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20;

	/*Configuração das Perguntas do quiz*/

	/* -> Fáceis <- */
	/*Bloco de Perguntas 1*/
	strcpy(p1.pergunta, "Qual é a função trigonométrica que relaciona cateto oposto e hipotenusa em um triângulo retângulo?");
	strcpy(p1.alternativas[0], "Seno");
	strcpy(p1.alternativas[1], "Cosseno");
	strcpy(p1.alternativas[2], "Tangente");
	strcpy(p1.alternativas[3], "Secante");
	strcpy(p1.alternativas[4], "Cossecante");
	strcpy(p1.dificuldade, "Fácil");
	p1.rC = 1;
	/*Bloco de Perguntas 2*/
	strcpy(p2.pergunta, "Qual é a função trigonométrica que é o inverso do seno?");
	strcpy(p2.alternativas[0], "Cosseno");
	strcpy(p2.alternativas[1], "Tangente");
	strcpy(p2.alternativas[2], "Insseno");
	strcpy(p2.alternativas[3], " Cossecante");
	strcpy(p2.alternativas[4], "Seno de Sólitis");
	p2.rC = 4;
	/*Bloco de Perguntas 3*/
	strcpy(p3.pergunta, "Qual é a melhor definição para: hipotenusa?");
	strcpy(p3.alternativas[0], "Menor lado de um triângulo");
	strcpy(p3.alternativas[1], "Lado com um ângulo hipoteno(88,99°)");
	strcpy(p3.alternativas[2], "Maior lado de um polígono retângulo");
	strcpy(p3.alternativas[3], "Lado com um ângulo hipoteno(64,46°)");
	strcpy(p3.alternativas[4], "Maior lado de um triângulo");
	p3.rC = 5;
	/*Bloco de Perguntas 4*/
	strcpy(p4.pergunta, "Quais são as principais funções trigonométricas?");
	strcpy(p4.alternativas[0], "Seno, Cosseno, Tangente");
	strcpy(p4.alternativas[1], "Secante, Insante, Pezóide");
	strcpy(p4.alternativas[2], "Lissente, Hipoteno, Lareto");
	strcpy(p4.alternativas[3], "Seno, Cosseno, Hipotenusa");
	strcpy(p4.alternativas[4], "Tangente, Cosseno, Seno");
	p4.rC = 5;
	/* -> Médias <- */
	/*Bloco de Perguntas 5*/
	strcpy(p5.pergunta, "Num triângulo retângulo, se o cateto oposto é 4 e hipotenusa mede 5, qual o valor do cosseno do ângulo agudo?");
	strcpy(p5.alternativas[0], "0,8");
	strcpy(p5.alternativas[1], "0,6");
	strcpy(p5.alternativas[2], "0,4");
	strcpy(p5.alternativas[3], "0,2");
	strcpy(p5.alternativas[4], "0,0");
	p5.rC = 2;
	/*Bloco de Perguntas 6*/
	strcpy(p6.pergunta, "Um observador a 50 metros de um prédio, mede o ângulo de elevação do topo do prédio e dá 45°. Qual a altura do prédio?");
	strcpy(p6.alternativas[0], "35 metros");
	strcpy(p6.alternativas[1], "95 metros");
	strcpy(p6.alternativas[2], "50 metros");
	strcpy(p6.alternativas[3], "45 metros");
	strcpy(p6.alternativas[4], "100 metros");
	p6.rC = 3;
	/*Bloco de Perguntas 7*/
	strcpy(p7.pergunta, "Um muro tem 8 m de altura. Uma pessoa, distante x metros, mede um ângulo de 30° em relação ao topo do muro. Qual o valor x aproximadamente?");
	strcpy(p7.alternativas[0], "13");
	strcpy(p7.alternativas[1], "14");
	strcpy(p7.alternativas[2], "15");
	strcpy(p7.alternativas[3], "16");
	strcpy(p7.alternativas[4], "17");
	p7.rC = 2;
	/* -> Difíceis <- */
	/*Bloco de Perguntas 8*/
	strcpy(p8.pergunta, "Dado cosX como x+3^2, hipotenusa de tamanho 5 e cateto de tamanho 2,5, qual o valor do outro cateto aproximadamente");
	strcpy(p8.alternativas[0], "5,7");
	strcpy(p8.alternativas[1], "2,97");
	strcpy(p8.alternativas[2], "3,7");
	strcpy(p8.alternativas[3], "4,3");
	strcpy(p8.alternativas[4], "6,9");
	p8.rC = 4;
	/* -> Médias <- */
	/*Bloco de Perguntas 9*/
	strcpy(p9.pergunta, "Num triângulo ABC, ângulo A mede 60°, o lado AC mede 10 u e o lado BC mede 8 u. Calcule o valor da tangente do ângulo B.");
	strcpy(p9.alternativas[0], "raiz de 3/2");
	strcpy(p9.alternativas[1], "2/raiz de 3");
	strcpy(p9.alternativas[2], "raiz de 3/3");
	strcpy(p9.alternativas[3], "2 * raiz de 3/3");
	strcpy(p9.alternativas[4], "3/raiz de 3");
	p9.rC = 3;
	/*Bloco de Perguntas 10*/
	strcpy(p10.pergunta, "Num triângulo ABC, ângulo A mede 30° e o ângulo B mede 60°. Se o lado AB mede 10 u, qual é o valor aproximado do lado BC?");
	strcpy(p10.alternativas[0], "5 u");
	strcpy(p10.alternativas[1], "8,66 u");
	strcpy(p10.alternativas[2], "10 u");
	strcpy(p10.alternativas[3], "17,32 u");
	strcpy(p10.alternativas[4], "20 u");
	p10.rC = 2;

	/*Array de todas as perguntas do quiz*/
	Pergunta PerguntasQuiz[20] = {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20};

	/*	-> Inicialização do Programa <-	 */

	mciSendString("open \"sans voice.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   Quiz de Trigonometria por Matheus Almeida\n\t\t\t\t    Ajuste a tela para melhor experiênica!\n\t\t\t\t    Clique em qualquer tecla para continuar");
	getch();
	system("cls");
	/*Obtém o tamanho da tela do usuário*/
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ci;
	ci.dwSize = 100;
	ci.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &ci);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	COORD position;
	int larguraT = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int alturaT = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	/*Inseção da Logo do Programa - Splash Logo*/
	int logoPosX = (larguraT - 9 - 5) /2;
	int logoPosY = (alturaT - 6) /2;
	position.X = logoPosX;
	position.Y = logoPosY;
	SetConsoleCursorPosition(hConsole, position);
	printf("  /\\_/\\\n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf(" ( o.o )\n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf("  > ^ <   \n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf(" /  |  \\  \n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf("/  | |  \\ \n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf("(___|___) \n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	Sleep(2500);
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	system("cls");
	/*Introdução do quiz*/
	setlocale(LC_ALL, "C");
	/*Sprite Sans*/
	int linha = 1;
	int SansPosX = (larguraT - 16 - 17) /2;
	int SansPosY = 1;
	position.X = SansPosX;
	position.Y = SansPosY;
	int j = 0;
	for(inteiroDeLoop = 0; inteiroDeLoop < 15; inteiroDeLoop++) {
		SetConsoleCursorPosition(hConsole, position);
		for(j = 0; j < 16; j++) {
			textcolor(sprite1[inteiroDeLoop][j]);
			printf("\xDB\xDB");
		}
		position.Y++;
	}
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	textcolor(15);
	mciSendString("play mp3 repeat", NULL, 0, NULL);
	int i ;
	setlocale(LC_ALL, "ptb");
	for (i = 0; i < strlen(dialogueIntroducao1); i++) {
		if (dialogueIntroducao1[i] == '\n') {
			position.Y++;
			Sleep(200);
			SetConsoleCursorPosition(hConsole, position);
		} else if (dialogueIntroducao1[i] == '|') {
			mciSendString("stop mp3", NULL, 0, NULL);
			Sleep(800);
			mciSendString("resume mp3", NULL, 0, NULL);
		} else {
			printf("%c", dialogueIntroducao1[i]);
		}
		Sleep(50);
	}
	mciSendString("stop mp3", NULL, 0, NULL);
	setlocale(LC_ALL, "C");
	Sleep(850);
	system("cls");
	/*Sprite Sans*/
	SansPosX = (larguraT - 16 - 17) /2;
	SansPosY = 1;
	position.X = SansPosX;
	position.Y = SansPosY;
	j = 0;
	for(inteiroDeLoop = 0; inteiroDeLoop < 15; inteiroDeLoop++) {
		SetConsoleCursorPosition(hConsole, position);
		for(j = 0; j < 16; j++) {
			textcolor(sprite2[inteiroDeLoop][j]);
			printf("\xDB\xDB");
		}
		position.Y++;
	}
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	textcolor(15);
	mciSendString("play mp3 repeat", NULL, 0, NULL);
	i = 0;
	setlocale(LC_ALL, "ptb");
	for (i = 0; i < strlen(dialogueIntroducao2); i++) {
		if (dialogueIntroducao2[i] == '\n') {
			position.Y++;
			Sleep(200);
			SetConsoleCursorPosition(hConsole, position);
		} else if (dialogueIntroducao2[i] == '|') {
			mciSendString("stop mp3", NULL, 0, NULL);
			Sleep(800);
			mciSendString("resume mp3", NULL, 0, NULL);
		} else if(dialogueIntroducao2[i] == '-') {
			mciSendString("stop mp3", NULL, 0, NULL);
			Sleep(2000);
			mciSendString("resume mp3", NULL, 0, NULL);
		} else {
			printf("%c", dialogueIntroducao2[i]);
		}
		Sleep(50);
	}
	mciSendString("play mp3", NULL, 0, NULL);
	Sleep(500);
	mciSendString("close mp3", NULL, 0, NULL);
	mciSendString("open \"foideF.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	system("cls");
	/*Transição*/
	mciSendString("play mp3 repeat", NULL, 0, NULL);
	system("color 40");
	Sleep(85);
	system("color F0");
	Sleep(85);
	system("color 40");
	Sleep(85);
	system("color 70");
	Sleep(85);
	system("color 40");
	Sleep(85);
	system("color 7");
	Sleep(85);
	system("color 40");
	Sleep(85);
	system("color 07");
	Sleep(150);
	system("cls");
	mciSendString("close mp3", NULL, 0, NULL);
	mciSendString("open \"Spider Dance.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	mciSendString("play mp3 repeat", NULL, 0, NULL);

	/*TELA INICIAL DO QUIZ - MENU*/
menu:
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	selecionado = false;
	pontuacao = 0;
	setlocale(LC_ALL, "C");
	/*Inserção do título*/
	menu = 1;
	textcolor(5);
	linha = 1;
	while (linha <= alturaT) {
		int coluna = 1;
		while (coluna <= larguraT) {
			if (linha == 1 || linha == alturaT || coluna == 1 || coluna == larguraT || coluna == 2 || coluna == larguraT - 1) {
				printf("\xDB");
			} else {
				printf(" ");
			}
			coluna++;
		}
		if(!(linha == alturaT)) {
			printf("\n");
		}
		linha++;
	}
	int titleL = (int)(larguraT-51)/2;
	int titleA = 3;
	position.X = titleL;
	position.Y = titleA;
	SetConsoleCursorPosition(hConsole, position);
	textcolor(3);
	printf("\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf("\333\333                \333\333\n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf("\333\333                \333\333\n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf("\333\333                \333\333\n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf("\333\333                \333\333   \333\333        \333\333   \333\333   \333\333\333\333\333\333\333\333\n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf("\333\333                \333\333   \333\333        \333\333   \333\333         \333\333\n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf("\333\333                \333\333   \333\333        \333\333   \333\333       \333\333\n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf("\333\333                \333\333   \333\333        \333\333   \333\333     \333\333\n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf("\333\333                \333\333   \333\333        \333\333   \333\333   \333\333\n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf("\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333   \333\333\333\333\333\333\333\333\333\333\333\333   \333\333   \333\333\333\333\333\333\333\333\n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf("\t    \333\333\n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf("\t      \333\333\333\333\n");
	/*Fim da Inserção*/
	/*Impressão do menu interativo na tela*/
	setlocale(LC_ALL, "ptb");
	SetConsoleCursorPosition(hConsole, position);
	printf("                     Iniciar o quiz");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf("                     Créditos");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf("                     Sair");
	position.Y = alturaT - 3;
	position.X = larguraT -(larguraT - 3);
	SetConsoleCursorPosition(hConsole, position);
	printf("Use as teclas W e S do teclado pra subir ou descer no menu, respectivamente. Aperte enter pra selecionar");
	position.Y = alturaT - 2;
	position.X = larguraT -(larguraT - 3);
	SetConsoleCursorPosition(hConsole, position);
	printf("Criador: Matheus Viana de Almeida");
	position.Y = alturaT - 11;
	position.X = larguraT -14;
	SetConsoleCursorPosition(hConsole, position);
	printf("  /\\_/\\\n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf(" ( o.o )\n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf("  > ^ <   \n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf(" /  |  \\  \n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf("/  | |  \\ \n");
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf("(___|___) \n");
	position.Y++;
	gotoxy(titleL, 15);
	/*Fim da impressão*/
	/*Lógica do Menu Interativo*/
	printf("%s", seta);
	textcolor(4);
	printf("%c", 3);
	int c = 0;
	while(selecionado == false) {
		int selecao = getch();
		if(selecao == 87 || selecao == 119) {
			if(menu > 1) {
				gotoxy(titleL, 17-(3-menu));
				printf("%s", vazio);
				menu -=1;

				gotoxy(titleL, 17-(3-menu));
				printf("%s", seta);
				textcolor(4);
				printf("%c", 3);
			}
		} else if(selecao == 83 || selecao == 115) {
			if(menu < 3) {
				gotoxy(titleL, 17-(3-menu));
				printf("                     ");
				menu += 1;
				gotoxy(titleL, 17-(3-menu));
				printf("%s", seta);
				textcolor(4);
				printf("%c", 3);
			}
		}
		if(selecao == 13) {
			selecionado = true;
		}
	}
	textcolor(15);
	switch(menu) {
		case 1:
			system("cls");
			goto quiz;
		case 2:
			system("cls");
			printf("Criador do quiz -> Matheus Viana de Almeida\nOrientador: Sérgio Vieira Costa");
			printf("\nMúsicas(Megalovania, Fallen Down, Efeitos Sonoros) -> Toby Fox\n");
			printf("Músicas(Spider Dance Remix) -> Holder\n");
			printf("\nBaseado no jogo UNDERTALE de Toby Foxy, jogue é muito bom\n");
			printf("\n\nAgradecimentos especiais -> Stack Overflow, melhor site de programação.\n\nMateus Furry, Miguel, Cauã, Cristiano, Renan e Josué pelos Feedbacks.");
			printf("\nPara retornar ao menu, aperte qualquer tecla\n\n");
			getch();
			system("cls");
			goto menu;
		case 3:
			return 0;
			break;
		default:
			printf("\n\nO programa detectou algum erro, por favor reinicie o quiz!!");
			break;
	}
	/*Fim da Lógica*/

	/*Início do Quiz*/
quiz:
	/*Carregamento1*/
	system("cls");
	setlocale(LC_ALL, "ptb");
	position.Y = (alturaT-2) / 2;
	position.X = (larguraT-12) / 2;
	SetConsoleCursorPosition(hConsole, position);
	printf("DETERMINAÇÃO");
	position.Y+=1;
	position.X-=8;
	SetConsoleCursorPosition(hConsole, position);
	setlocale(LC_ALL, "C");
	printf("[                         ]");
	for(i = 0; i < 25; i++) {
		Sleep(475);
		position.X++;
		SetConsoleCursorPosition(hConsole, position);
		textcolor(6);
		printf("%\xDB");
	}
	Sleep(250);
	system("cls");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	int nicknameX = (larguraT - 40) /2;
	int nicknameY = (alturaT - 20) /2;
	position.X = nicknameX;
	position.Y = nicknameY;
	SetConsoleCursorPosition(hConsole, position);
	textcolor(15);
	setlocale(LC_ALL, "ptb");
	for (inteiroDeLoop = 0; inteiroDeLoop < strlen(dialogueNick); inteiroDeLoop++) {
		if (dialogueNick[inteiroDeLoop] == '\n') {
			position.Y++;
			Sleep(200);
			SetConsoleCursorPosition(hConsole, position);
		} else if (dialogueNick[inteiroDeLoop] == '|') {
			Sleep(800);
		} else if(dialogueNick[inteiroDeLoop] == '-') {
			Sleep(2000);
		} else {
			printf("%c", dialogueNick[inteiroDeLoop]);
		}
		Sleep(50);
	}
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	printf("Seu nome: ");
	ci.dwSize = 100;
	ci.bVisible = TRUE;
	SetConsoleCursorInfo(hConsole, &ci);
	scanf("%[^\n]s", nickname);
	system("cls");
	ci.dwSize = 100;
	ci.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &ci);
	/*Fim*/
	setlocale(LC_ALL, "ptb");
	position.Y = (alturaT-2) / 2;
	position.X = (larguraT-12) / 2;
	SetConsoleCursorPosition(hConsole, position);
	printf("DETERMINAÇÃO");
	position.Y+=1;
	position.X-=8;
	SetConsoleCursorPosition(hConsole, position);
	setlocale(LC_ALL, "C");
	printf("[                         ]");
	for(i = 0; i < 25; i++) {
		Sleep(475);
		position.X++;
		SetConsoleCursorPosition(hConsole, position);
		textcolor(6);
		printf("%\xDB");
	}
	Sleep(250);
	system("cls");
	mciSendString("close mp3", NULL, 0, NULL);
	system("cls");
	SansPosX = (larguraT - (larguraT-15))/2;
	SansPosY = 5;
	position.X = SansPosX;
	position.Y = SansPosY;
	j = 0;
	setlocale(LC_ALL, "C");
	for(inteiroDeLoop = 0; inteiroDeLoop < 15; inteiroDeLoop++) {
		SetConsoleCursorPosition(hConsole, position);
		for(j = 0; j < 16; j++) {
			textcolor(sprite1[inteiroDeLoop][j]);
			printf("\xDB\xDB");
		}
		position.Y++;
	}

	position.Y -=15;
	position.X += 35;
	SetConsoleCursorPosition(hConsole, position);
	textcolor(15);
	setlocale(LC_ALL, "ptb");
	for (inteiroDeLoop = 0; inteiroDeLoop < strlen(mautempo); inteiroDeLoop++) {
		if (mautempo[inteiroDeLoop] == '\n') {
			position.Y++;
			Sleep(200);
			SetConsoleCursorPosition(hConsole, position);
		} else if (mautempo[inteiroDeLoop] == '|') {
			Sleep(220);
		} else if(mautempo[inteiroDeLoop] == '-') {
			Sleep(1700);
		} else {
			printf("%c", mautempo[inteiroDeLoop]);
		}
		Sleep(50);
	}
	Sleep(500);
	mciSendString("close mp3", NULL, 0, NULL);
	mciSendString("open \"lazer.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	mciSendString("play mp3 repeat", NULL, 0, NULL);
	system("cls");
	system("color 10");
	Sleep(75);
	system("color 60");
	Sleep(75);
	system("color 10");
	Sleep(75);
	system("color 60");
	Sleep(75);
	system("color 10");
	Sleep(75);
	system("color 60");
	Sleep(75);
	system("color 60");
	Sleep(75);
	system("color 07");
	Sleep(75);
	system("cls");
	mciSendString("close mp3", NULL, 0, NULL);
	mciSendString("open \"Undertale - Megalovania.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	mciSendString("play mp3", NULL, 0, NULL);
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	setlocale(LC_ALL, "C");
	int pl;
	/*LÓGICA DO QUIZ -> PERGUNTA E RESPOSTA*/
	for(inteiroDeLoop = 0; inteiroDeLoop < numeroDePerguntas; inteiroDeLoop++) {
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		selecionado = false;
		int time = 30;
		gotoxy(0,0);
		printf("Tempo: ");
		position.X = larguraT-16;
		position.Y = 0;
		SetConsoleCursorPosition(hConsole, position);
		printf("ACERTOS: %02d/10", pontuacao);
		setlocale(LC_ALL, "C");
		SansPosY = 1;
		SansPosX = (larguraT/2)-16;
		int frasePosX = SansPosX + 33;
		int frasePosY = 5;
		position.X = frasePosX;
		position.Y = frasePosY;
		SetConsoleCursorPosition(hConsole, position);
		printf("IT'S SHOW TIME!");
		position.X = SansPosX;
		position.Y = SansPosY;

		j = 0;
		for(i = 0; i < 15; i++) {
			SetConsoleCursorPosition(hConsole, position);
			for(j = 0; j < 16; j++) {
				textcolor(sprite3[i][j]);
				printf("\xDB\xDB");
			}
			position.Y++;
		}
		position.Y +=2;
		pl = position.Y + 3;
		position.X -= 15;
		setlocale(LC_ALL, "C");
		textcolor(7);
		int altura = (alturaT/2)-7;
		int largura = larguraT-8;
		position.Y-=2;
		position.X = 3;
		SetConsoleCursorPosition(hConsole, position);
		printf("%c", 219);
		for (i = 0; i < largura; i++) {
			printf("%c", 223);
		}
		printf("%c\n", 219);
		position.Y++;
		SetConsoleCursorPosition(hConsole, position);
		for (i = 0; i < altura; i++) {
			printf("%c", 219);
			for (j = 0; j < largura; j++) {
				printf(" ");
			}
			printf("%c\n", 219);
			position.Y++;
			SetConsoleCursorPosition(hConsole, position);
		}
		printf("%c", 219);
		for (i = 0; i < largura; i++) {
			printf("%c", 220);
		}
		printf("%c\n", 219);
		position.Y = pl-4;
		position.X += 2;
		SetConsoleCursorPosition(hConsole, position);
		textcolor(7);
		setlocale(LC_ALL, "ptb");
		printf("%d) - %s", inteiroDeLoop + 1,PerguntasQuiz[inteiroDeLoop].pergunta);
		position.Y+=2;
		position.X += 5;
		int menuPY = position.Y;
		SetConsoleCursorPosition(hConsole, position);
		printf("A) - %s",PerguntasQuiz[inteiroDeLoop].alternativas[0]);
		position.Y++;
		SetConsoleCursorPosition(hConsole, position);
		printf("B) - %s",PerguntasQuiz[inteiroDeLoop].alternativas[1]);
		position.Y++;
		SetConsoleCursorPosition(hConsole, position);
		printf("C) - %s",PerguntasQuiz[inteiroDeLoop].alternativas[2]);
		position.Y++;
		SetConsoleCursorPosition(hConsole, position);
		printf("D) - %s",PerguntasQuiz[inteiroDeLoop].alternativas[3]);
		position.Y++;
		SetConsoleCursorPosition(hConsole, position);
		printf("E) - %s",PerguntasQuiz[inteiroDeLoop].alternativas[4]);

		position.Y = menuPY;
		int menuPX = position.X;
		position.X -= 2;
		SetConsoleCursorPosition(hConsole, position);
		textcolor(4);
		printf("%c", 3);



		clock_t start_time = clock();
		menu = 1;
		while(!selecionado) {

			if(!kbhit()) {
				if(!((clock() - start_time) / CLOCKS_PER_SEC > time)) {
					textcolor(7);
					int tempo_restante = time - ((clock() - start_time) / CLOCKS_PER_SEC);
					position.X = 7;
					position.Y = 0;
					SetConsoleCursorPosition(hConsole, position);
					printf("%02d", tempo_restante);
					if(((clock() - start_time) / CLOCKS_PER_SEC > time - 10)) {
						position.X = frasePosX;
						position.Y = frasePosY;
						SetConsoleCursorPosition(hConsole, position);
						Sleep(500);
						textcolor(7);
						printf("Mais rápido, já vai acabar!    ");
					}
				} else {
					position.X = frasePosX;
					position.Y = frasePosY;
					SetConsoleCursorPosition(hConsole, position);
					Sleep(500);
					textcolor(7);
					printf("Ops, o tempo acabou...");
					position.Y++;
					printf("HORA DA PUNIÇÃO!!");
					Sleep(2500);
					SetConsoleCursorPosition(hConsole, position);
					mciSendString("close mp3", NULL, 0, NULL);
					mciSendString("open \"foideF.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
					system("cls");
					mciSendString("play mp3 repeat", NULL, 0, NULL);
					system("color 40");
					Sleep(85);
					system("color F0");
					Sleep(85);
					system("color 40");
					Sleep(85);
					system("color 70");
					Sleep(85);
					system("color 40");
					Sleep(85);
					system("color 7");
					Sleep(85);
					system("color 40");
					Sleep(85);
					system("color 07");
					Sleep(85);
					erros++;
					system("cls");
					mciSendString("close mp3", NULL, 0, NULL);
					mciSendString("open \"Undertale - Megalovania.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
					mciSendString("play mp3 repeat", NULL, 0, NULL);
					break;
				}
			} else {
				int selecao = getch();
				if(selecao == 87 || selecao == 119) {
					if(menu > 1) {
						gotoxy(menuPX-1, menuPY + (5 - (5 - menu)));
						printf(" ");
						menu -=1;
						gotoxy(menuPX-1, menuPY + menu);
						textcolor(4);
						printf("%c", 3);
					}
				} else if(selecao == 83 || selecao == 115) {
					if(menu < 5) {
						gotoxy(menuPX-1, menuPY + (5 - (5 - menu)));
						printf(" ");
						menu +=1;
						gotoxy(menuPX-1, menuPY + menu);
						textcolor(4);
						printf("%c", 3);
					}
				}
				if(selecao == 13) {
					printf("\n\n\n\n\n");
					if(menu == PerguntasQuiz[inteiroDeLoop].rC) {
						pontuacao++;
						position.X = frasePosX;
						position.Y = frasePosY;
						SetConsoleCursorPosition(hConsole, position);
						Sleep(100);
						textcolor(7);
						printf("Parabéns, você acertou!\n");
						Sleep(1000);
						system("cls");
						system("color 20");
						Sleep(85);
						system("color F0");
						Sleep(85);
						system("color 20");
						Sleep(85);
						system("color 70");
						Sleep(85);
						system("color 20");
						Sleep(85);
						system("color 7");
						Sleep(85);
						system("color 20");
						Sleep(85);
						system("color 07");
						Sleep(150);
						system("cls");
						break;
					} else {
						position.X = frasePosX;
						position.Y = frasePosY;
						SetConsoleCursorPosition(hConsole, position);
						Sleep(100);
						textcolor(7);
						printf("Ala, errou KKKKKKKKK\n");
						position.Y++;
						SetConsoleCursorPosition(hConsole, position);
						printf("HORA DA PUNIÇÃO!!");
						Sleep(1200);
						SetConsoleCursorPosition(hConsole, position);
						mciSendString("close mp3", NULL, 0, NULL);
						mciSendString("open \"foideF.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
						system("cls");
						mciSendString("play mp3 repeat", NULL, 0, NULL);
						system("color 40");
						Sleep(85);
						system("color F0");
						Sleep(85);
						system("color 40");
						Sleep(85);
						system("color 70");
						Sleep(85);
						system("color 40");
						Sleep(85);
						system("color 7");
						Sleep(85);
						system("color 40");
						Sleep(85);
						system("color 07");
						Sleep(85);
						erros++;
						system("cls");
						mciSendString("close mp3", NULL, 0, NULL);
						mciSendString("open \"Undertale - Megalovania.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
						mciSendString("play mp3 repeat", NULL, 0, NULL);
						break;
					}
					selecionado = true;
				}
			}

		}
		Sleep(400);
		system("cls");
	}
	mciSendString("close mp3", NULL, 0, NULL);
	system("cls");
	/*	-> Fim do Quiz <-	*/
	char menssagemFinal[150];
	if(pontuacao >= 10) {
		strcpy(menssagemFinal, "Muito bem! Você é um gênio da trigonometria!!\nSans está orgulhoso de você(supostamente).");
		mciSendString("open \"FallenDown.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	} else if(pontuacao >= 8) {
		mciSendString("open \"feliz.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		strcpy(menssagemFinal, "Vejo que seus conhecimentos trigonométricos estão em dia! Considere revisar um pouco.");
	} else if(pontuacao >= 6) {
		mciSendString("open \"feliz.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		strcpy(menssagemFinal, "Você está seguindo um bom caminho, pratique mais!");
	} else if(pontuacao >= 4) {
		mciSendString("open \"feliz.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		strcpy(menssagemFinal, "Busque conhecimento! Lhe falta estudar mais");
	} else if(pontuacao >= 2) {
		mciSendString("open \"gameover.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		strcpy(menssagemFinal, "Dá pra ver que trigonometria não é seu forte... Faça umas aulas de reforço!");
	} else {
		mciSendString("open \"gameover.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		strcpy(menssagemFinal, "Decepcionante, queime no INFERNO. Quer dizer, considere-se reprovado :(");
	}
	mciSendString("play mp3 repeat", NULL, 0, NULL);
	setlocale(LC_ALL, "C");
	linha = 1;
	while (linha <= alturaT) {
		int coluna = 1;
		while (coluna <= larguraT) {
			if (linha == 1 || linha == alturaT || coluna == 1 || coluna == larguraT || coluna == 2 || coluna == larguraT - 1) {
				printf("\333");
			} else {
				printf(" ");
			}
			coluna++;
		}
		printf("\n");
		linha++;
	}
	setlocale(LC_ALL, "ptb");
	position.X = (larguraT/2) - 35;
	position.Y = alturaT/2;
	SetConsoleCursorPosition(hConsole, position);
	for (inteiroDeLoop = 0; inteiroDeLoop < strlen(menssagemFinal); inteiroDeLoop++) {
		if (menssagemFinal[inteiroDeLoop] == '\n') {
			position.Y++;
			Sleep(200);
			SetConsoleCursorPosition(hConsole, position);
		} else if (menssagemFinal[inteiroDeLoop] == '|') {
			Sleep(800);
		} else if(menssagemFinal[inteiroDeLoop] == '-') {
			Sleep(2000);
		} else {
			printf("%c", menssagemFinal[inteiroDeLoop]);
		}
		Sleep(50);
	}
	position.Y += 1;
	SetConsoleCursorPosition(hConsole, position);
	printf("Então %s, a sua pontuação final é de: %d pontos!", nickname, pontuacao);
	position.Y += 4;
	SetConsoleCursorPosition(hConsole, position);
	printf("Aperte em qualquer lugar para voltar ao menu!");
	getch();
	system("cls");
	goto menu;
	return(0);
}
