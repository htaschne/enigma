#include <cstdio>
#include <vector>
#include <set>
#include <map>

#define MAX 500

using namespace std;

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
    // printf( "%c", ch );

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
      case '$': /*puts("");*/ return;
    }
  }
}

int main() {
  memset(G, '#', MAX*MAX);
  explore( MAX / 2, MAX / 2 );

  auto portas = [&](int px, int py) {
    vector<pair<int, int>> pp;
    if (G[py][px+1] == '|') pp.push_back(make_pair(px+2, py));
    if (G[py][px-1] == '|') pp.push_back(make_pair(px-2, py));
    if (G[py+1][px] == '-') pp.push_back(make_pair(px, py+2));
    if (G[py-1][px] == '-') pp.push_back(make_pair(px, py-2));
    return pp;
  };

  // bfs
  set<pair<int, int>> seen;
  vector<pair<int, int>> Q = portas(MAX/2, MAX/2);
  int depth = 0;

  map<pair<int, int>, int> dist;

  while (!Q.empty()) {
    depth++;
    vector<pair<int, int>> new_Q;
    for (auto n : Q) {
      if (seen.count(n))
        continue;

      seen.insert(n);
      dist[n] = depth;

      auto possiveis_caminhos = portas(n.first, n.second);
      for (auto &pc : possiveis_caminhos) new_Q.push_back(pc);
    }
    Q.swap(new_Q);
  }
  printf("%d\n", --depth);

  // part II
  int resp = 0; for (auto [k,v] : dist) if (v >= 1000) resp++;
  printf("%d\n", resp);
}
