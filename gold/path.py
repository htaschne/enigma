#!/usr/bin/env python3


import sys

Pos = tuple[int, int]
Grid = dict[Pos, int]


def read_case(filename: str) -> tuple[Grid, int]:
  mine = [
    list(filter(lambda x: x != "",
                line.strip().split(" "))) for line in open(filename)
  ]

  n = int(mine.pop(0)[0]) - 1

  g = {}
  for r, row in enumerate(mine):
    for c, col in enumerate(row):
      if col != "x":
        g[(r, c)] = int(col)

  return g, n


def neighborhood(p: Pos, g: Grid) -> list[Pos]:
  return [
    nxt for nxt in ((p[0] - 1, p[1]), (p[0] - 1, p[1] + 1), (p[0], p[1] + 1))
    if nxt in g
  ]


""" == RECURSIVE IMPLEMENTATION ==

def walk(current: Pos, goal: Pos, g: Grid, acc: int = 0) -> int:
  if current == goal:
    return acc + g[current]

  nb = neighborhood(current, g)
  if len(nb) == 0:
    return 0

  return max([walk(path, goal, g, acc + g[current]) for path in nb])
"""


""" == MEMOIZED RECURSIVE IMPLEMENTATION == """
phts: dict[Pos, int] = {}
def walk(current: Pos, goal: Pos, g: Grid, acc: int = 0) -> int:
  global phts
  if current == goal:
    return g[current] + acc

  if current in phts:
    return phts[current] + acc

  nb = neighborhood(current, g)
  if len(nb) == 0:
    return 0

  phts[current] = max([walk(path, goal, g, g[current]) for path in nb])
  return phts[current] + acc


def main():
  g, n = read_case(sys.argv[1])
  rich_path = walk((n, 0), (0, n), g)
  print(rich_path)


if __name__ == '__main__':
  main()
