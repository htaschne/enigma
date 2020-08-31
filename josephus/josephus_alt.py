#!/usr/bin/env python3

import sys

def done(s):
    return '1' not in s

# s=str, k=knife_position, j=jump_size
def sim(s,k,j):
  #print(s,k,j)
  if done(s): return True
  killpos = (k+j) % len(s)
  if s[killpos] == '1':
    s = s[:killpos] + s[killpos+1:]
    return sim(s, killpos % len(s), j)
  else:
    return False

initstr = sys.argv[1]
print(initstr)

j = 0 # comeca jah pulando

res = False
while not res:
  j+=1
  res = sim(initstr, 0, j)

print(j)
