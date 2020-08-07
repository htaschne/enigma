
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct parent {
  char *name;
  int64_t lands;
  struct parent *sons;
} parent;

// sometimes i miss c++:
// parent* find-root(set<parent> &sons, set<parent> &parents) {
//   for (auto &p : parents)
//     if (sons.count(p) == 0)
//       return p;
//   return NULL; // could not find.
// }


int main() {
  int64_t n;
  scanf("%lld", &n);
  //printf("%lld\n", n);

  char p[256]; char f[256]; int64_t l; // 256 is a bet.
  while (scanf("%s %s %lld", p, f, &l) != EOF) {
    printf("%s %ld\n", p, strlen(p));
    //printf("%s %s %lld\n", p, f, l);
  }

  // parent *root = find-root(...);
  // assert(root != NULL);

  // int64_t best = 0;
  // char *name[] = {};
  // explore(raiz, n, &best, name);

  // printf("%s: %lld\n", best, name);
}

