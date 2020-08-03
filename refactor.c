
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void dfs(const int *C, int *best, int* castles, int **edges, int depth, int castle) {
  if (*best < depth) { *best = depth; }

  int *next_castles = (int*) malloc(sizeof(int) * *C * *C);
  memcpy(next_castles, castles, sizeof(int) * *C * *C);

  int cost = 0;
  for (int i = 0; i < *C; ++i) {
    if (edges[castle][i] && castle != i) {
      //printf("%d: %d - %d\n", castle, i, depth);
      if (castles[castle] - ((2*castles[i]) + 50) >= 0) {
        cost = (2*castles[i]) + 50;
        castles[castle] -= cost;
        dfs(C, best, next_castles, edges, depth + 1, next_castles[i]);
      }
    }
  }

}

int main() {
  /// READ KING'S CASTLE'S ATTRIBUTES.
  int S; int C; int E;
  int best = 0;
  scanf("%d %d %d", &S, &C, &E);
  // printf("%d %d %d\n", S, C, E);

  /// SAVE EACH CASTLE'S ARMY.
  int *castles = (int*) malloc(sizeof(int) * C);
  castles[0] = S;
  int castle_id; int army;
  for (int i = 0; i < C; ++i) {
    scanf("%d %d", &castle_id, &army);
    castles[castle_id] = army;
    // printf("%d %d\n", castle_id, army);
  }

  /// READING POSSIBLE PATHS (EDGES).
  int **edges = (int**) malloc(sizeof(int) * C * C); // <<< (BUG?)
  int departure; int arrivals;
  memset(edges, 0, sizeof(int) * C * C);
  for (int i = 0; i < E; ++i) {
    scanf("%d %d", &departure, &arrivals);
    edges[departure][arrivals]++;
    // printf("[%d][%d] = %d\n", departure, arrivals, edges[departure][arrivals]);
  }

  /// COMPUTE THE ANSWEAR AND PRINT IT OUT TO STDOUT.
  dfs(&C, &best, castles, edges, 0, 0);
  printf("best: %d\n", best);
}

