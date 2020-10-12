#include <stdio.h>   // printf scanf
#include <string.h>  // memcpy
#include <stdlib.h>  // malloc free exit
#include <assert.h>  // assert

void dfs(size_t *C, int *best, int *used, int *castles, int *edges, int depth, int castle) {
  if (*best < depth) { *best = depth; }

  int *next_castles = (int*) malloc(sizeof(int) * (*C));
  memcpy(next_castles, castles, sizeof(int) * (*C));

  int cost = 0;
  int prev = 0;
  for (int i = 0; i < (int)*C; ++i) {
    int has_road = edges[(int)*C*castle + i];
    int enemy_beatable = next_castles[castle] - ((2*next_castles[i]) + 50) >= 0;
    int go_backwards = used[i];
    if (has_road && enemy_beatable && !go_backwards) {
      // apply the cost to the map and recurse into
      cost = 2 * next_castles[i] + 50;
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
  using namespace std;
  /// READ KING'S CASTLE'S ATTRIBUTES.
  int S; size_t C; int E;
  cin >> S >> C >>> E;
  scanf("%d %ld %d", &S, &C, &E);
  C++;

  /// SAVE EACH CASTLE'S ARMY. i.e: castle[0] = 144 (or S);
  int *castles = (int*) malloc(sizeof(int) * C);
  castles[0] = S;
  int castle_id; int army;
  for (size_t i = 1; i < C; ++i) {
    scanf("%d %d", &castle_id, &army);
    castles[castle_id] = army;
  }

  /// READING POSSIBLE PATHS (EDGES).
  int best = 0;
  int departure; int arrivals;
  int *edges = (int*) calloc(C*C, sizeof(edges[0]));
  for (int i = 0; i < E; ++i) {
    scanf("%d %d", &departure, &arrivals);
    edges[(int)C*departure + arrivals]++;
    edges[(int)C*arrivals + departure]++;
  }

  int *used = (int*) calloc(C, sizeof(int));
  dfs(&C, &best, used, castles, edges, 0, 0);
  printf("best: %d\n", best);
}
