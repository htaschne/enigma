#include <stdio.h>
#include <string.h>

#define MAX 50

char G[MAX][MAX];

void imprime() {
  for( int i = 0; i < MAX; i++ ) {
    for( int j = 0; j < MAX; j++ )
      printf( "%c", G[i][j] );
    printf( "\n" );
  }
}

typedef struct {
  int x, y, stp;
} Trip;

Trip Stack[2000];
int Ssize = 0;

void push( int x, int y, int stp ) {
  Stack[Ssize].x = x;
  Stack[Ssize].y = y;
  Stack[Ssize++].stp = stp;
}

void pop( int *x, int *y, int *stp ) {
  (*x) = Stack[--Ssize].x;
  (*y) = Stack[Ssize].y;
  (*stp) = Stack[Ssize].stp;
}

void explore( int x, int y ) {

  int passos = 0;

  while ( 1 ) {

    G[y][x] = '.';

    char ch;
    scanf( "%c", &ch );
    printf( "%c", ch );

    switch ( ch ) {
      case ')':
        pop( &x, &y, &passos );
        break;
      case '|':
        pop( &x, &y, &passos );
      case '^':
      case '(':
        push( x, y, passos );
        break;
      case 'S': G[y + 1][x] = '-'; y += 2; break;
      case 'N': G[y - 1][x] = '-'; y -= 2; break;
      case 'W': G[y][x - 1] = '|'; x -= 2; break;
      case 'E': G[y][x + 1] = '|'; x += 2; break;
      case '$': puts(""); return;
    }
  }
}

int main() {
  memset(G, '#', MAX*MAX);
  explore( MAX / 2, MAX / 2 );
  imprime();
}
