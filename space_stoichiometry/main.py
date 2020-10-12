
# https://adventofcode.com/2019/day/14

import sys

from collections import defaultdict
from typing import DefaultDict, List, Tuple

filename: str = "1.in" if len(sys.argv) == 1 else sys.argv[1]

recipe: DefaultDict[str, List] = defaultdict(list)

for line in open(filename).readlines():
    pre, pos = line.rstrip().split(" => ")
    if ',' in pre:
        rcp: List[Tuple[int, str]] = []
        ingredients: List[str] = pre.split(", ")
        for ing in ingredients:
            amount, ingredient = ing.split(" ")
            rcp.append((int(amount), ingredient))
        recipe[pos] = rcp

def cost(target: str) -> int:
    '''
    "the cost of something is the sum of the cost of it's parts"
    really high level: cost(target) = sum([cost(ing) for ing in recipe[target]])

    pseudo-code:

    total_cost: int = 0
    for ing in recipe[target]:
        total_cost += cost(ing)

    return total_cost
    '''

    # not sure if this is the base case
    if target not in recipe.keys():
        return

    total_cost: int = 0
    for ing in recipe[target]:
        total_cost += cost(ing)

    return total_cost

print(cost("FUEL"))

