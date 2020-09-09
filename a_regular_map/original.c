#include <stdio.h>
#define MAX 60

char G[MAX][MAX];

void clean() {
  for( int i = 0; i < MAX; i++ )
    for( int j = 0; j < MAX; j++ )
      G[i][j] = '#';
}

void imprime() {
  for( int i = 0; i < MAX; i++ ) {
    for( int j = 0; j < MAX; j++ )
      printf( "%c", G[i][j] );
    printf( "\n" );
  }
}

int achafecha( char str[], int pos ) {
  int prof = 0;
  while ( pos ) {
    if ( str[pos] == ')' && prof == 0 ) return pos;
    if ( str[pos] == ')' ) prof--;
    if ( str[pos] == '(' ) prof++;
    pos++;
  }
  printf( "Eu nao devia estar aqui\n" );
  return -1;
}

typedef struct {
  int x, y, stp, pos;
} Quad;

Quad Stack[1000];
int Ssize = 0;

int isempty( ) { return Ssize == 0; }

void push( int x, int y, int stp, int pos ) {
  Stack[Ssize].x = x;
  Stack[Ssize].y = y;
  Stack[Ssize].stp = stp;
  Stack[Ssize++].pos = pos;
}

void pop( int *x, int *y, int *stp, int *pos ) {
  (*x) = Stack[--Ssize].x;
  (*y) = Stack[Ssize].y;
  (*stp) = Stack[Ssize].stp;
  (*pos) = Stack[Ssize].pos;
}

int best = 0;

void explore( char *str, int x, int y ) {

  push( x, y, 0, 0 );

  while ( ! isempty( ) ) {

    int pos, passos;
    pop( &x, &y, &passos, &pos );

    G[y][x] = '.';
    printf( "%c", str[pos] );

    switch ( str[pos] ) {
      case '^':
      case '(':
        push( x, y, passos, pos + 1 );
      case ')':
        push( x, y, passos, pos + 1 );
        break;
      case '|':
        push( x, y, passos, pos + 1 );
        push( x, y, passos, achafecha( str, pos ) );
        break;
      case 'S': G[y + 1][x] = '-'; push( x, y + 2, passos + 1, pos + 1 ); break;
      case 'N': G[y - 1][x] = '-'; push( x, y - 2, passos + 1, pos + 1 ); break;
      case 'W': G[y][x - 1] = '|'; push( x - 2, y, passos + 1, pos + 1 ); break;
      case 'E': G[y][x + 1] = '|'; push( x + 2, y, passos + 1, pos + 1 ); break;
      case '$': break;
    }
  }
}

int main() {
  char ch, str[20000] = {};
  int len = 0;
  while ( 1 == scanf( "%c", &ch ) ) str[len++] = ch;
  printf( "Li e tem %d  :D \n", len );
  clean( );

  explore( str, MAX / 2, MAX / 2 );
  imprime();
}
