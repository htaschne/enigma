#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool done(char *str, int size) {
  // def done(s):
  //     return '1' not in s
  for (int i = 0; i < size; ++i) {
    if (str[i] == '1') {
      return false;
    }
  }
  return true;
}

bool simula(char *str, int size, int *jump) {
  // # s=str, k=knife_position, j=jump_size
  // def sim(s,k,j):
  //   #print(s,k,j)
  //   if done(s): return True
  //   killpos = (k+j) % len(s)
  //   else:
  //     return False

  int knife_position = 0;
  if (done(str, size)) {
    return true;
  }

  int killpos = (knife_position + *jump) % size;
  if (str[killpos] == '1') {
    //   if s[killpos] == '1':
    //     s = s[:killpos] + s[killpos+1:]
    //     return sim(s, killpos % len(s), j)

  }

  return false;
}

int main() {
  // initstr = sys.argv[1]
  // print(initstr)
  // 
  // j = 0 # comeca jah pulando
  // 
  // res = False
  // while not res:
  //   j+=1
  //   res = sim(initstr, 0, j)
  // 
  // print(j)

	char *buf = (char*) malloc(sizeof(char) * 255);
	gets(buf);
	int size = strlen(buf);
	char *in = (char*) malloc(sizeof(char) * size);
	memcpy(in, buf, size);
	free(buf);

  int jump = 0;

  bool res = false;
  while (!res) {
    jump++;
    res = simula(in, size, &jump);
  }

  printf("%d\n", jump);
}
