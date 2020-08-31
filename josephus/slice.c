#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

// this can be optimized by counting one's in the main
// and decrement each time it kills someone
int done(char *str, int *n) {
  for (int i = 0; i < *n; ++i)
    if (str[i] == '1')
      return 0;
  return 1;
}

int simula(char *str, int *n, int k, int jump) {
  if (done(str, n)) return 1;
  int killpos = (k + jump) % (*n);
  if (str[killpos] == '1') {
    // TODO: retirar o killpos da str
    // s = s[:killpos] + s[killpos+1:]
    char *new_str = (char*) malloc(sizeof(char) * (*n) - 1);
    memcpy(new_str, str, killpos - 1);
    memcpy(new_str + killpos, str + killpos, (*n) - killpos);
    free(str);
    n--;
    return simula(new_str, n, (killpos % (*n)), jump);
  }
  return 0;
}

int main() {
  char ch; char* buf = (char*) malloc(sizeof(char) * MAX);
  for (int i = 0; scanf("%c", &ch) != EOF; ++i)
    buf[i] = ch;

  int size = strlen(buf) - 1;
  char *str = malloc(sizeof(char) * size);
  memcpy(str, buf, size);
  free(buf);

  int res = 0; int jump = 0;
  while (!res) {
    jump++;
    res = simula(str, &size, 0, jump);
    printf("partial: %d\n", res);
  }
  printf("result: %d\n", res);
}
