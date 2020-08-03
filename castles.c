
#include <stdio.h>   // printf scanf
#include <string.h>  // memset memcpy
#include <stdlib.h>  // malloc free exit

void dfs(const int *C, int *best, int* castles, int **edges, int depth, int castle) {
  if (*best < depth) { *best = depth; }

  int *next_castles = (int*) malloc(sizeof(int) * (*C) * (*C));
  memcpy(next_castles, castles, sizeof(int) * (*C) * (*C));
  // assert(next_castles == castles);

  int cost = 0;
  for (int i = 0; i < *C; ++i) {
    if (edges[castle][i] && castle != i) {
      if (next_castles[castle] - ((2*next_castles[i]) + 50) >= 0) {
        cost = (2*next_castles[i]) + 50;
        next_castles[castle] -= cost;
        dfs(C, best, next_castles, edges, depth + 1, next_castles[i]);
        next_castles[castle] += cost; // reset for next iteration
      }
    }
  }

  free(next_castles);
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
  int departure; int arrivals;
  int **edges = (int**) malloc(sizeof(int) * C * C); // <<< (BUG?)
  memset(edges, 0, sizeof(int) * C * C);
  // assert edges are all cool.
  for (int i = 0; i < E; ++i) {
    scanf("%d %d", &departure, &arrivals);
    edges[departure][arrivals]++;
    // printf("[%d][%d] = %d\n", departure, arrivals, edges[departure][arrivals]);
  }
  // assert edges are all cool with the right value.

  /// COMPUTE THE ANSWEAR AND PRINT IT OUT TO STDOUT.
  dfs(&C, &best, castles, edges, 0, 0);
  printf("best: %d\n", best);
}

