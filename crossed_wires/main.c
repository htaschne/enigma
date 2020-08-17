#include <stdio.h>

#define MAX 50000

int Mat[MAX][MAX] = {};

int abs(int a) { return a > 0 ? a : -a; }

int dist(int posX, int posY) {
  return abs(posX - MAX/2) + abs(posY - MAX/2);
}

int main() {
  int posX = MAX/2, posY = MAX/2, qtd;
  char dir;
  int passos = 0;
  while ( 2 == scanf("%c%d,", &dir, &qtd) ) {
    while (qtd--) {
      passos++;
      switch (dir) {
        case 'R': if (Mat[++posX][posY] == 0) Mat[posX][posY] = passos; break;
        case 'U': if (Mat[posX][++posY] == 0) Mat[posX][posY] = passos; break;
        case 'L': if (Mat[--posX][posY] == 0) Mat[posX][posY] = passos; break;
        case 'D': if (Mat[posX][--posY] == 0) Mat[posX][posY] = passos; break;
      }
    }
  }

  int min = 2 * MAX;
  posX = posY = MAX/2;
  passos = 0;
  while ( 2 == scanf("%c%d,", &dir, &qtd) ) {
    while (qtd--) {
      passos++;
      switch (dir) {
        case 'R': if ( Mat[++posX][posY] != 0 && min > passos + Mat[posX][posY]) min = passos + Mat[posX][posY]; break;
        case 'U': if ( Mat[posX][++posY] != 0 && min > passos + Mat[posX][posY]) min = passos + Mat[posX][posY]; break;
        case 'L': if ( Mat[--posX][posY] != 0 && min > passos + Mat[posX][posY]) min = passos + Mat[posX][posY]; break;
        case 'D': if ( Mat[posX][--posY] != 0 && min > passos + Mat[posX][posY]) min = passos + Mat[posX][posY]; break;
      }
    }
  }
  printf("%d\n", min);

}
