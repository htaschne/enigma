#include <stdio.h>
#include <string.h>

// gcc -O3 main.c && ./a.out < input

int main() {
  int n; // numero de processadores
  scanf("# Proc %d", &n);
  char p1[256], p2[256]; int t1, t2;
  while ( scanf("%s_%d -> %s_%d", &p1, &t1, &p2, &t2) ) {
    printf("%s_%d -> %s_%d\n", p1, t1, p2, t2);
  }

}
