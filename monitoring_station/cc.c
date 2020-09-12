#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define TRUE 1

char G[MAX][MAX];

int isFora(int lin, int col) {
	if (lin < 0 || lin >= MAX) return 1;
	if (col < 0 || col >= MAX) return 1;
	return 0;
}

void killTodoMundo(char GG[MAX][MAX], int lin, int col, int var_lin, int var_col) {
	while (TRUE) { // <-- Ver o #define ||quem disse q n tem boolean em C
		lin += var_lin;
		col += var_col;
		if (isFora(lin, col)) return;
		GG[lin][col] = '.';
	}
}

/*
	 para largura = 1 a ???
	 para lin = y - largura até y + largura
	 para col = x - largura até x + largura
	 se lin, col tá fora da matriz -> continue;
	 vê quem tá em ( lin, col )
	 e mata os que se ve depois dele
	 */

int station(char GG[MAX][MAX], int lin, int col) { 
	int resposta = 0;
	for (int larg = 1; larg < MAX; larg++) { // conrado tem quase certeza disso. Isso!
		for(int l = lin - larg; l <= lin + larg; l++ ) {
			for(int c = col - larg; c <= col + larg; c++) {
				if ( isFora(l,c) ) continue;
				if ( GG[l][c] == '#') {
					resposta++;
					killTodoMundo(GG, lin, col, l - lin, c - col); // caaaalma calma calma calma para
				}
			}
		}
	}
	return resposta;
}

int main() {
	// lendo o input :)
	for (int lin = 0; lin < MAX; ++lin)
		for (int col = 0; col < MAX; ++col)
			scanf("%c", &(G[lin][col]));


	int best,x,y = 0; 
	for (int lin = 0; lin < MAX; ++lin) {
		for (int col = 0; col < MAX; ++col) {
			if(G[lin][col] != '#') continue;

			char GG[MAX][MAX];
			memcpy(GG, G, MAX*MAX*sizeof(char));

			int current = station(GG, lin, col);

			if (current > best){
				best = current;
				x = col;
				y = lin;

			}
		}
	}

	/*

		 A -> (3,1) | (6,2) | (9,3)  -> ( +3, +1 )   ( dx, dy )
		 B -> (3,2) | (6,4) | (9,6)  -> ( +3, +2 )   

		 012345678j9
		 0#.........
		 1...AX..... 
		 2...B..a.x. 
		 3.EDCG....a
		 4..F.c.b...
		 5.....c....
		 6..efd.c.gb
		 7.......c..
		 8....f...c.
		 9...e..d..c

*/

}
