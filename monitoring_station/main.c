
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX 24

char G[MAX][MAX];

void imprime(char G[MAX][MAX]) {
	for (int lin = 0; lin < MAX; ++lin){
		for (int col = 0; col < MAX; ++col)
			printf("%c", G[lin][col]);
		printf("\n");
	}
	printf("\n\n");
}

int isFora(int lin, int col) {
	if (lin < 0 || lin >= MAX) return 1;
	if (col < 0 || col >= MAX) return 1;
	return 0;
}

void killTodoMundo(char GG[MAX][MAX], int lin, int col, int var_lin, int var_col) {
	while (true) {
		lin += var_lin;
		col += var_col;
		if (isFora(lin, col)) return;
		if(GG[lin][col]== '#')GG[lin][col] = '@';
	}
}

int mdc(int a, int b) {
	while (b != 0) {
		int tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}

int station(char GG[MAX][MAX], int lin, int col) { 
	int resposta = 0;
	for (int larg = 1; larg < MAX; larg++) {
		for (int l = lin - larg; l <= lin + larg; l++ ) {
			for (int c = col - larg; c <= col + larg; c++) {

				if (isFora(l,c))
					continue;

				if (GG[l][c] == '#' && (l != lin || c != col)) {
					resposta++;
					int dx = c - col;
					int dy = l - lin;
					int mm = mdc(abs(dx), abs(dy));
					dx /= mm;
					dy /= mm;
					// imprime(GG);
					killTodoMundo(GG, lin, col, dy, dx); 
					// imprime(GG);
				}
			}
		}
	}
	return resposta;
}

int main() {
	// lendo o input :)
	int lin = 0, col = 0;
	while (true) {
		char ch;
		if (1 != scanf("%c", &ch)) break;
		switch(ch) {
			case '.':
			case '#': G[lin][col++] = ch;
								if (col == MAX) {
									lin++;
									col = 0;
								}
		}
	}

	if (lin != MAX) {
		printf("Estamos com tamanho errado!");
		printf("%d != %d\n", lin, MAX);
		exit(0);
	}

	int best = 0, x = 0, y = 0;
	for (int lin = 0; lin < MAX; ++lin) {
		for (int col = 0; col < MAX; ++col) {
			if (G[lin][col] != '#') continue;

			char GG[MAX][MAX];
			memcpy(GG, G, MAX*MAX*sizeof(char));

			int current = station(GG, lin, col);
			// printf("%d : (%d,%d)\n", current,col,lin);
			if (current > best){
				best = current;
				x = col;
				y = lin;
			}

		}
	}
	printf("%d : (%d,%d)\n", best, y, x);
}
