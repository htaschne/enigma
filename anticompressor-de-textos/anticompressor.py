import sys

from collections import Counter


def react(root, dec):
    current = Counter(dec[root])
    while True:
        new = Counter()
        for letter in current:
            if letter in dec:
                for x in dec[letter]:
                    new[x] += current[letter]
            else:
                new[letter] += current[letter]

        if new == current:
            break

        current = new

    return current


def main():
    if len(sys.argv) < 2:
        print(f"usage: python3 {sys.argv[0]} <TEST-CASE>")
        exit(1)

    print(sys.argv[1], end="; ")
    dec = {
        line.strip().split(" ")[0]: line.strip().split(" ")[1]
        for line in open(sys.argv[1]).readlines()
        if len(line.strip().split(" ")) > 1
    }


    departures, arrivals = set(), set()
    for k in dec:
        departures.add(k)
        [arrivals.add(x) for x in list(dec[k])]

    root = list(departures - arrivals)[0]
    print("start:", root, end="; ")

    decompressed = react(root, dec)
    print("len:", sum(decompressed.values()))


main()
