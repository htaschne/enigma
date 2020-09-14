#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pula(int pos, int cont, char* s, int size) {
  while (cont) {
    pos++;
    if (pos == size) pos = 0;
    if (s[pos] != '+') cont--;
  }
  return pos;
}

int simula(char *in, int len, int jump, int count) {
  int pos = 0;
  int vivos = len;
  while (count > 0) {
    pos = pula(pos, (jump+1)%vivos, in, len);
    if ( in[pos] == '0' ) return 0;
    in[pos] = '+';
    count--;
    vivos--;
    pos = pula(pos, 1, in, len);
  }
  return jump;
}

int main() {
  // parsing the input.
  char *buf = (char*) malloc(sizeof(char) * 255);
  gets(buf);
  int size = strlen(buf);
  char *in = (char*) malloc(sizeof(char) * size);
  memcpy(in, buf, size);
  free(buf);

  // try all values for jumps, returns the first possible solution (smallest jump).
  // not sure if it halts.
  int res, jump = 0, ones = 0;
  for (int i = 0; i < size; ++i) if (in[i] == '1') ones++;
  char *current = (char*) malloc(sizeof(char) * size);
  do {
    memcpy(current, in, size);
    res = simula(current, size, jump, ones);
    jump++;
  } while (res == 0);

  printf("%d\n", res);
}
