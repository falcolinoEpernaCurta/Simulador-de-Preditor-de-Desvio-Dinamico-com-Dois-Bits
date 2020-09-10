/*
 * Autor: Pedrolino
 * Criado: 07.09.2020  19.23.59
 */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>


#define STRONGLY_NOT_TAKEN "  oOOOOOOOOOOOOOOOo    /                  \\ ( STRONGLY NOT TAKEN ) \\                  /   oOOOOOOOOOOOOOOOOo  "
#define WEAKLY_NOT_TAKEN "  oOOOOOOOOOOOOOOo   /                \\ ( WEAKLY NOT TAKEN ) \\                /   oOOOOOOOOOOOOOOo  "
#define WEAKLY_TAKEN "  oOOOOOOOOOOo   /            \\ ( WEAKLY TAKEN ) \\            /   oOOOOOOOOOOo  "
#define STRONGLY_TAKEN "  oOOOOOOOOOOOOo   /              \\ ( STRONGLY TAKEN ) \\              /   oOOOOOOOOOOOOo  "


#define TAKEN_BOX "=============|   TAKEN   |============="
#define NOT_TAKEN_BOX "=============| NOT TAKEN |============="

#define TAKEN_ARROW "     1    --------->"
#define NOT_TAKEN_ARROW "<---------    0     "

#define INF_TAKEN_ARROW "--------------|            |V           1|             |             |           --- "
#define INF_NOT_TAKEN_ARROW "--------------|            ||0           V|             |             ---           "


#define TAKEN 1
#define NOT_TAKEN 0

void show(char *s, int posY, int posX, int n, int m){
	int i, j;
	for (i=0; i < n; i++){
		for (j=0; j < m; j++){
			mvaddch(posY + i, posX + j, s[i*m + j]);
		}
	}
}


void body(int count, int total, int nMisspredict, int result){
	int iniX = 8;
	int iniY = 10;

	mvprintw(1, 1, "Arquitetura e Organizacao de Computadores - UFPR - 2-bit counter branch predictior");



	/* STRONGLY NOT TAKEN STATE */
	if (count == 0 && result == NOT_TAKEN) attron(COLOR_PAIR(1));
	show(INF_NOT_TAKEN_ARROW, iniY - 3, iniX - 4, 6, 14);	
	if (count == 0 && result == NOT_TAKEN) attroff(COLOR_PAIR(1));
	
	if (count == 0) attron(COLOR_PAIR(1));
	show(STRONGLY_NOT_TAKEN, iniY,iniX, 5, 22);
	if (count == 0) attroff(COLOR_PAIR(1));

	if (count == 0 && result == TAKEN) attron(COLOR_PAIR(1));
	show(TAKEN_ARROW, iniY, iniX + 22 + 1, 2, 10);
	if (count == 0 && result == TAKEN) attroff(COLOR_PAIR(1));


	/* WEAKLY NOT TAKEN STATE*/
	if (count == 1) attron(COLOR_PAIR(1));
	show(WEAKLY_NOT_TAKEN, iniY, iniX + 22 + 10 + 1, 5, 20);
	if (count == 1) attroff(COLOR_PAIR(1));


	if (count == 1 && result == NOT_TAKEN) attron(COLOR_PAIR(1));
	show(NOT_TAKEN_ARROW, iniY + 3, iniX + 22 + 1, 2, 10);
	if (count == 1 && result == NOT_TAKEN) attroff(COLOR_PAIR(1));
	
	if (count == 1 && result == TAKEN) attron(COLOR_PAIR(1));
	show(TAKEN_ARROW, iniY, iniX + 22 +20 + 1*10+ 1, 2, 10);
	if (count == 1 && result == TAKEN) attroff(COLOR_PAIR(1));
	
	

	/* WEAKLY TAKEN STATE */
	if (count == 2 && result == NOT_TAKEN) attron(COLOR_PAIR(1));
	show(NOT_TAKEN_ARROW, iniY + 3, iniX + 22 +20 + 1*10 + 1, 2, 10);
	if (count == 2 && result == NOT_TAKEN) attroff(COLOR_PAIR(1));
	
	if (count == 2) attron(COLOR_PAIR(1));
	show(WEAKLY_TAKEN, iniY, iniX + 22 +20 + 2*10 + 1, 5, 16);
	if (count == 2) attroff(COLOR_PAIR(1));


	if (count == 2 && result == TAKEN) attron(COLOR_PAIR(1));
	show(TAKEN_ARROW, iniY, iniX + 22 +20 + 16+ 2*10+ 1, 2, 10);
	if (count == 2 && result == TAKEN) attroff(COLOR_PAIR(1));
	
	
	/* STRONGLY TAKEN STATE */
	if (count == 3 && result == NOT_TAKEN) attron(COLOR_PAIR(1));
	show(NOT_TAKEN_ARROW, iniY + 3, iniX + 22 +20+16 + 2*10 + 1, 2, 10);
	if (count == 3 && result == NOT_TAKEN) attroff(COLOR_PAIR(1));
	
	if (count == 3 && result == TAKEN) attron(COLOR_PAIR(1));
	show(INF_TAKEN_ARROW, iniY-3, iniX + 22 + 20 + 16 + 18/2 + 3*10, 6, 14);	
	if (count == 3 && result == TAKEN) attroff(COLOR_PAIR(1));
	
	if (count == 3) attron(COLOR_PAIR(1));
	show(STRONGLY_TAKEN, iniY, iniX + 22 + 20 + 16+ 3*10 + 1, 5, 18);
	if (count == 3) attroff(COLOR_PAIR(1));


	/* GUESS */
	mvprintw(iniY + 9, iniX -3, "*GUESS*");
	if (count < 2)
		show(NOT_TAKEN_BOX, iniY +10 , iniX -3, 3, 13);
	else 
		show(TAKEN_BOX, iniY +10 , iniX -3, 3, 13);

	/* RESULT */
	mvprintw(iniY + 9, iniX -3 + 13 +2 + 5 , "*RESULT*");
	if (result == TAKEN)
		show(TAKEN_BOX, iniY +10 , iniX + 13 + 2, 3, 13);
	else
		show(NOT_TAKEN_BOX, iniY +10 , iniX + 13 + 2, 3, 13);
	
	/* TOTAL */
	mvprintw(iniY + 15, iniX -3, "#TOTAL = %d", total);

	/* N. MISSPREDICTION */
	mvprintw(iniY + 15, iniX -3 + 15, "#N. MISSPREDICTION = %d", nMisspredict);
	mvprintw(iniY + 17, iniX -3, "MISSRATE = %f", total == 0 ? (total) : (((float)nMisspredict)/total));
	

	/* ESCOLHER ESTADO INICAL*/
	mvprintw(iniY + 18, iniX - 3, "PRESSIONE I PARA REINICIAR A SIMULACAO EM OUTRO ESTADO INICIAL");
	
//	mvprintw(iniY + 19, iniX - 3, "PRESSIONE F PARA A OPCAO FOR LOOP()");
	

	mvprintw(iniY + 20, iniX -3, "PRESSIONE S PARA SAIR");
	mvprintw(iniY + 21, iniX -3, "PRESSIONE QUALQUER TECLA PARA MODIFICAR OS ESTADOS");
}

void back_end(int *count, int *total, int *nMisspredict, int i){

	*total += 1; 
	
 	int predict;             
	if (*count < 2)
		predict = NOT_TAKEN;
	else
		predict = TAKEN;

        if (i != predict)
		*nMisspredict += 1;

        if (i == TAKEN)
		*count = (*count == 3) ? (3) : (*count + 1);
	else
		*count = (*count == 0) ? (0) : (*count - 1);

}

int main(){ 
	initscr();	
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	srand(time(0));


        int count = 0;
        int nMisspredict = 0;
	int total = 0;
        while (1){
                int i = rand() % 2 ;
		clear();
		body(count, total, nMisspredict, i);
		back_end(&count, &total, &nMisspredict, i);

		int c = getch();
		if (c == 'I' || c == 'i'){
			c = getch();
			if (c < '0'){
				count = 0;
			}else if (c > '3'){
				count = 3;
			}else {
				count = c - '0';
			}
			total = 0;
			nMisspredict = 0;
			body(count, total, nMisspredict, i);
		}/*else if (c == 'F' || c == 'f'){
			mvprintw(0 + 23, 3 - 3, "DIGITE QUANTAS ITERACOES SERAO EXECUTADAS");
			long long n;
			scanw("%d", &n);
			attron(COLOR_PAIR(1));
			mvprintw(0 , 0, "dhsajkhdjkahsdkjhak %d", n);
			attroff(COLOR_PAIR(1));
			
			for (i=0; i <= n; i++){
				clear();
				body(count, total, nMisspredict, i != n);
				back_end(&count, &total, &nMisspredict, i != n);
			}


		
		}*/else if (c == 'S' || c == 's'){
			endwin();
			exit(0);
		}
	}
	

	return 0;
}

