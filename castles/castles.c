
#include <stdio.h>   // printf scanf
#include <string.h>  // memcpy
#include <stdlib.h>  // malloc free exit
#include <assert.h>  // assert


//#define DEBUG

void dfs(int *C, int *best, int* used, int* castles, int *edges, int depth, int castle) {
  if (*best < depth) { *best = depth; }
#ifdef DEBUG
  printf("%d: ", castle);
  for (int i = 0; i < *C; ++i)
    printf("%d ", used[i]);
  printf("\n");
#endif


  int *next_castles = (int*) malloc(sizeof(int) * (*C));
  memcpy(next_castles, castles, sizeof(int) * (*C));
#ifdef DEBUG
  for (int i = 0; i < *C; ++i)
    assert(next_castles[i] == castles[i]);
#endif

  int cost = 0;
  for (int i = 0; i < *C; ++i) {
    if (edges[*C*castle + i] && castle != i) {
      if (next_castles[castle] - ((2*next_castles[i]) + 50) >= 0 && used[i] == 0) {
        cost = (2*next_castles[i]) + 50;
        int prev = next_castles[castle];
        next_castles[castle] -= cost;
        used[i] = 1;
        dfs(C, best, used, next_castles, edges, depth + 1, next_castles[i]);
        next_castles[castle] += cost; // reset for next iteration
        used[i] = 0;
        assert(next_castles[castle] == prev);
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
#ifdef DEBUG
  printf("%d %d %d\n", S, C, E);
#endif
  C++;

  /// SAVE EACH CASTLE'S ARMY. i.e: castle[0] = 144 (or S);
  int *castles = (int*) malloc(sizeof(int) * C);
  castles[0] = S;
  int castle_id; int army;
  for (int i = 0; i < C; ++i) {
    scanf("%d %d", &castle_id, &army);
    castles[castle_id] = army;
#ifdef DEBUG
    printf("%d %d\n", castle_id, army);
#endif
  }

  /// READING POSSIBLE PATHS (EDGES).
  int departure; int arrivals;
  int *edges = calloc(C*C, sizeof(edges[0]));
  for (int i = 0; i < E; ++i) {
    scanf("%d %d", &departure, &arrivals);
    edges[C*departure + arrivals]++;
    edges[C*arrivals + departure]++;
#ifdef DEBUG
    printf("[%d][%d] = %d\n", departure, arrivals, edges[C*departure + arrivals]);
#endif
  }
#ifdef DEBUG
  // assert edges are all cool with the right value.
  for (int i = 0; i < C; ++i) {
    for (int j = 0; j < C; ++j) {
      if (edges[C*i + j] == 1) {
        printf("%d -> %d\n", i, j);
      }
    }
  }
#endif

  int *used = calloc(C, sizeof(int));
  dfs(&C, &best, used, castles, edges, 0, 0);
  printf("best: %d\n", best);
}

