#include <stdio.h>
#include <vector>
#include <set>

#define MAX 500

using namespace std;

int max_x = 0, max_y = 0, min_x = MAX, min_y = MAX;

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
  max_x = max(x, max_x);
  min_x = max(x, min_x);

  max_y = max(y, max_y);
  min_y = max(y, min_y);

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

vector<pair<int, int>> prox(int px, int py) {
  vector<pair<int, int>> pp;
  if (G[py][px+1] == '|') pp.push_back(make_pair(px+2, py));
  if (G[py][px-1] == '|') pp.push_back(make_pair(px-2, py));
  if (G[py+1][px] == '-') pp.push_back(make_pair(px, py+2));
  if (G[py-1][px] == '-') pp.push_back(make_pair(px, py-2));
  return pp;
}

int bfs(int px, int py) {
  set<pair<int, int>> seen;

  int depth = 0;
  vector<pair<int, int>> Q = prox(px, py);

  while (Q.size() != 0) {
    // printf("%d\n", depth);
    depth++;
    vector<pair<int, int>> new_Q;
    for (auto n : Q) {
      if (seen.count(n))
        continue;
      seen.insert(n);


      auto prx = prox(n.first, n.second);
      for (auto &nn : prx) new_Q.push_back(nn);
    }
    Q = new_Q;
  }
  return depth - 1;
}

int main() {
  memset(G, '#', MAX*MAX);
  explore( MAX / 2, MAX / 2 );
  int resp = bfs( MAX/2, MAX/2 );
  // imprime();
  printf("%d\n", resp);
}
