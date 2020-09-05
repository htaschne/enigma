#include <stdio.h>

#define MAX 20

#define max(a, b)                                                              \
  ({                                                                           \
    __typeof__(a) _a = (a);                                                    \
    __typeof__(b) _b = (b);                                                    \
    _a > _b ? _a : _b;                                                         \
  })

char G[MAX][MAX];

void clean() {
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
      G[i][j] = '#';
}

void imprime() {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      printf("%c", G[i][j]);
    }
    printf("\n");
  }
}

int achafecha(char str[], int pos, int pip[], int *contpip) {
  int prof = 0;
  while (pos++) {
    if (str[pos] == ')' && prof == 0)
      return pos;
    if (str[pos] == ')')
      prof--;
    if (str[pos] == '(')
      prof++;
    if (str[pos] == '|' && prof == 0) {
      pip[*contpip] = pos;
      (*contpip)++;
    }
  }
  return -1;
}

int best = 0;
int cria_grafo(char *str, int pos, int x, int y, int passos) {
  best = max(best, passos);
  G[y][x] = '.';
  int pipes[1000] = {};
  // printf("Pos: %d, %d: %d\n", x, y, passos);
  switch (str[pos]) {
  case '^':
    // printf( "Comeceiiii :) \n" );
    cria_grafo(str, pos + 1, x, y, 0);
    break;
  case ')':
    cria_grafo(str, pos + 1, x, y, passos);
    break;
  case '(': {
    int totpipes = 1;
    pipes[0] = pos;
    int end_pos = achafecha(str, pos + 1, pipes, &totpipes);
    for (int i = 0; i < totpipes; ++i)
      cria_grafo(str, pipes[i] + 1, x, y, passos);
    break;
  }
  case '|': {
    int totpipes = 0;
    int end_pos = achafecha(str, pos, pipes, &totpipes);
    cria_grafo(str, end_pos + 1, x, y, passos);
    break;
  }
  case 'S':
    cria_grafo(str, pos + 1, x, y + 2, passos + 1);
    G[y + 1][x] = '-';
    break;
  case 'N':
    cria_grafo(str, pos + 1, x, y - 2, passos + 1);
    G[y - 1][x] = '-';
    break;
  case 'W':
    cria_grafo(str, pos + 1, x - 2, y, passos + 1);
    G[y][x - 1] = '|';
    break;
  case 'E':
    cria_grafo(str, pos + 1, x + 2, y, passos + 1);
    G[y][x + 1] = '|';
    break;
  case '$':
    // printf("acabamos uhulL :)\n");
    break;
  }
  return -1;
}

int main() {
  char ch, str[20000] = {};
  int len = 0;
  while (1 == scanf("%c", &ch))
    str[len++] = ch;
  // printf("Li e tem %d  :D \n", len);
  clean();

  cria_grafo(str, 0, MAX / 2, MAX / 2, 0);
  printf("%d\n", best);
  imprime();
}
