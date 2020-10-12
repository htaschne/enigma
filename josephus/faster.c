#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool simula(char *str, int size, int knife_position, int *jump, int ones) {
  if (!ones) {
    return true;
  }

  int killpos = (knife_position + *jump) % size;

  if (str[killpos] == '1') {
    // if str were a linked list the remove at index would be O(1)
    // currently it's O(n), where n = len(str)
    char *new_str = (char*) malloc(sizeof(char) * (size-1));
    strncpy(new_str, str, killpos);
    strncpy(((char*)new_str)+killpos, ((char*)str)+killpos+1, size-1-killpos);

    bool ret = simula(new_str, size-1, killpos % (size-1), jump, ones-1);
    free(new_str);
    return ret;
  }

  return false;
}

int main() {
  char *buf = (char*) malloc(sizeof(char) * 255);
  gets(buf);
  int size = strlen(buf);
  char *in = (char*) malloc(sizeof(char) * size);
  memcpy(in, buf, size);
  free(buf);

  int jump = 0, ones = 0;

  for (int i=0;i<size;++i) if (in[i]=='1') ones++;

  bool res = false;
  while (!res) {
    jump++;
    res = simula(in, size, 0, &jump, ones); // knife always start at 0.
  }

  printf("%d\n", --jump);
}
