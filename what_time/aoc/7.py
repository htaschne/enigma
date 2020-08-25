import sys

from collections import defaultdict

all_pre = set()
all_pos = set()
edges = defaultdict(list)
incoming = defaultdict(list)

def main():
  global L
  filename = sys.argv[1] if len(sys.argv) > 1 else '7.1'
  for line in open(filename).readlines():
    pre = line.rstrip().split(' ')[1]
    pos = line.rstrip().split(' ')[7]
    all_pre.add(pre)
    all_pos.add(pos)
    edges[pre].append(pos)
    incoming[pos].append(pre)

  # Toposort
  L = []
  S = (all_pre - all_pos)

  while len(S) != 0:
    n = S.pop()
    L.append(n)

    for m in edges[n]:
      print(m, edges[n])
      edges[n].remove(m)
      incoming[m].remove(n)
      if len(incoming[m]) == 0:
        S.add(m)

  print(L)

if __name__ == '__main__':
  main()
