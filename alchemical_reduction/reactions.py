
from typing import List, Set

def react(polymer: List[str], unit: str = '') -> int:
    # given a polymer it reacts all it's units, possibly making it smaller.
    # also it skips all polymer's units that equal the unit parameter.

    stack: List[str] = []
    for un in polymer:
        if un == unit.upper() or un == unit.lower():
            continue
        if stack == []:
            stack.append(un)
            continue

        # checks if the current unit will react with the top of the stack.
        # either top = X and unit = x (Xx) or top = x and unit = X (xX).
        # otherwise it's false
        top = stack[-1]

        if top != un and (top == un.upper() or top == un.lower()):
            stack.pop()
        else:
            stack.append(un)

    return len(stack)

if __name__ == "__main__":
    import sys
    filename = sys.argv[1] if len(sys.argv) > 2 else "0.in"

    # read the whole line (polymer) into the list
    polymer: List[str] = open(filename).readline().rstrip()

    # part I
    # react the input polymer and compute it's size.
    # to react a polymer is to delete all pairs xX and Xx in it.
    print(react(polymer))

    # Part II
    # generate all polymer's variations by deliting, at each iteration, one of
    # the units type (say all the a's and A's) and find the one with the smallest size.
    reacted: Set[str] = set()
    best: int = len(polymer)  # worst case there's no reaction to be excecuted
    for unit in polymer:
        if not unit in reacted:
            reacted.add(unit)
            best = min(best, react(polymer, unit))
    print(best)
