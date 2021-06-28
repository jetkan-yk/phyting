# UVa - 441 Lotto
"""
    Iterative Complete Search with 6 nested loops
"""
import sys
from itertools import combinations

inputs = sys.stdin.read().splitlines()
outputs = []

for line in inputs:
    if line == "0":
        break

    k = int(line.split()[0])
    S = line.split()[1:]

    for a in range(0, k - 5):
        for b in range(a + 1, k - 4):
            for c in range(b + 1, k - 3):
                for d in range(c + 1, k - 2):
                    for e in range(d + 1, k - 1):
                        for f in range(e + 1, k):
                            outputs.append(
                                " ".join([S[a], S[b], S[c], S[d], S[e], S[f]])
                            )
    outputs.append("")

sys.stdout.write("\n".join(outputs))
