
#include <stdio.h>
#include <string.h>

// HACK: should change dfs's signature and change definition for edges[C][C]
//     -- void dfs(int* castles, int** edges, int run, int castle);
// and castles[C].
#define C 8

int best;
// should edges and castles be copies? or should all runs accounts in the same?
void dfs(int castles[C], int edges[C][C], int run, int castle) {
  if (best < run) { best = run; }
  int cost;
  for (int i = 0; i < C; ++i)
    if (edges[castle][i] && castle != i) {
      //printf("%d: %d - %d\n", castle, i, run);
      if (castles[castle] - ((2*castles[i]) + 50) >= 0) {
        cost = (2*castles[i]) + 50;
        castles[castle] -= cost;
        dfs(castles, edges, run + 1, castles[i]);
      }
    }
}

int main() {
  int S; /*C = 0*/; int E;
  int trash;
  best = 0;
  // scanf("%d %d %d", &S, &C, &E);
  scanf("%d %d %d", &S, &trash, &E);
  // printf("%d %d %d\n", S, C, E); // DEBUG!

  int castles[C];
  castles[0] = S; // account for the king!
  int castle_id; int army;
  for (int i = 0; i < C; ++i) {
    scanf("%d %d", &castle_id, &army);
    castles[castle_id] = army;
    // printf("%d %d\n", castle_id, army); // DEBUG!
  }

  int edges[C][C];
  int departure; int arrivals;
  memset(edges, 0, sizeof(int) * C * C);
  for (int i = 0; i < E; ++i) {
    scanf("%d %d", &departure, &arrivals);
    edges[departure][arrivals]++;
    // printf("[%d][%d] = %d\n", departure, arrivals, edges[departure][arrivals]);
    // DEBUG!
  }

  printf("  0 1 2 3 4 5 6 7 \n");
  //printf("-----------------\n");
  for (int i = 0; i < C; ++i) {
    printf("%d|", i);
    for (int j = 0; j < C; ++j) {
      printf("%d ", edges[i][j]);
    }
    printf("\n");
  }

  dfs(castles, edges, 0, 0);
  // printf("best: %d\n", best);
}

