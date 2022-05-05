import sys

from collections import Counter


def react(root: str, dec: dict[str, str]) -> int:
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

    return sum(current.values())


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

    expanded_length = react(root, dec)
    print("len:", expanded_length)


if __name__ == '__main__':
    main()
