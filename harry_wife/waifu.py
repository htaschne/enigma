#!/usr/bin/env python3

import sys


def candidate_scores(k: int, candidates: int) -> list[int]:
    scores = []
    n = k
    for _ in range(candidates):
        scores.append(n)
        next_score = ((n * 87) % 601) + 400
        n = next_score
    return scores


def next_candidate(n: int, k: int) -> int:
    return (2 * n + 3) % k if n % 2 == 0 else (3 * n + 1) % k


def main():
    k = int(sys.argv[1])
    candidates = 10_000
    scores = candidate_scores(k, candidates)

    pos, drinks = 0, 0
    while (next_pos := next_candidate(scores[pos], candidates + 1)) != pos:
        drinks += 1
        scores[pos] += 1
        pos = next_pos
        # print(drinks, pos)

    print(
        "Acabou! Harry casará com a candidata na posição %d da mesa, depois de beber %d tequilas!"
        % (pos, drinks)
    )


if __name__ == "__main__":
    main()
