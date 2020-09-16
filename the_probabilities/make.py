#!/usr/bin/env python3

def explore(target):
  global values, G, best, namebest

  if G[target] == []:
    if values[target] > best:
      best = values[target]
      namebest = target
    return

  for child in G[target]:
    values[child] *= values[target]
    explore(child)

if __name__ == '__main__':
  import sys
  filename = '0.in' if len(sys.argv) < 2 else sys.argv[1]

  K = set()
  V = set()
  values = {}
  from collections import defaultdict
  G = defaultdict(list)

  for line in open(filename).readlines():
      tokens = line.rstrip().split(':')
      pre = tokens[0][:-1]
      r = tokens[1][1:].split(' ')
      children = []
      K.add(pre)
      for i in range(0, len(r), 2):
        values[r[i]] = float(r[i+1]) / 100
        children.append(r[i])
        V.add(r[i])
      G[pre] = children

  root = list(K - V)[0]
  values[root] = 100 / 100

  best = 0
  namebest = ''
  explore(root)
  print(f"{namebest}: {best:.2f}")
