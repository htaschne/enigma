
#include <stdio.h>   // printf scanf
#include <string.h>  // memcpy
#include <stdlib.h>  // malloc free exit
#include <assert.h>  // assert

void dfs(int *C, int *best, int* used, int* castles, int *edges, int depth, int castle) {
  if (*best < depth) { *best = depth; }

  int *next_castles = (int*) malloc(sizeof(int) * (*C));
  memcpy(next_castles, castles, sizeof(int) * (*C));

  int cost = 0;
  int prev = 0;
  for (int i = 0; i < *C; ++i) {
    int has_road = edges[*C*castle + i];
    int enemy_beatable = next_castles[castle] - ((2*next_castles[i]) + 50) >= 0;
    int go_backwards = used[i];
    if (has_road && enemy_beatable && !go_backwards) {
        cost = (2*next_castles[i]) + 50;
        prev = next_castles[castle];
        next_castles[castle] -= cost;
        used[i] = 1;
        dfs(C, best, used, next_castles, edges, depth + 1, next_castles[i]);

        // reset for next iteration
        next_castles[castle] += cost;
        used[i] = 0;
        assert(next_castles[castle] == prev);
    }
  }

  free(next_castles);
}

int main() {
  /// READ KING'S CASTLE'S ATTRIBUTES.
  int S; int C; int E;
  int best = 0;
  scanf("%d %d %d", &S, &C, &E);
  C++;

  /// SAVE EACH CASTLE'S ARMY. i.e: castle[0] = 144 (or S);
  int *castles = (int*) malloc(sizeof(int) * C);
  castles[0] = S;
  int castle_id; int army;
  for (int i = 1; i < C; ++i) {
    scanf("%d %d", &castle_id, &army);
    castles[castle_id] = army;
  }

  /// READING POSSIBLE PATHS (EDGES).
  int departure; int arrivals;
  int *edges = calloc(C*C, sizeof(edges[0]));
  for (int i = 0; i < E; ++i) {
    scanf("%d %d", &departure, &arrivals);
    edges[C*departure + arrivals]++;
    edges[C*arrivals + departure]++;
  }

  int *used = calloc(C, sizeof(int));
  dfs(&C, &best, used, castles, edges, 0, 0);
  printf("best: %d\n", best);
}

