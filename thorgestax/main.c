
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char   *name;
  int    name_size;
  int    lands;
  struct node *sons;
} node;

node* new_node(char *nn, int ns, int l) {
  node* n = malloc(sizeof(node));
  n->name = nn;
  n->name_size = ns;
  n->lands = l;
  return n;
}

int main() {

  int64_t n;
  scanf("%lld", &n);
  //printf("%lld\n", n);

  char p[256]; char f[256]; int64_t l; // bet the names will fit in 256 chars.
  while (scanf("%s %s %lld", p, f, &l) != EOF) {
    printf("%s %ld\n", p, strlen(p));
    // printf("%s %s %lld\n", p, f, l);
  }

}

