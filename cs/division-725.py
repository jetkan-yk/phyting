# UVa - 725 Division
"""
    Iterative Complete Search with Bit Manipulation
    String formatting
    Scope of possible solution is small enough for CS
    O(N) solution
"""
import sys


def is_valid(top, bottom):
    used = bottom < 10000  # set bit for first 0 digit

    while top:
        used |= 1 << (top % 10)
        top //= 10

    while bottom:
        used |= 1 << (bottom % 10)
        bottom //= 10

    return used == (1 << 10) - 1


inputs = map(int, sys.stdin.read().splitlines())
outputs = []

for N in inputs:
    if N == 0:
        break

    no_solution = True
    for bottom in range(1234, (98765 // N) + 1):
        top = bottom * N

        if is_valid(top, bottom):
            outputs.append("{:05} / {:05} = {}".format(top, bottom, N))
            no_solution = False

    if no_solution:
        outputs.append("There are no solutions for {}.".format(N))
    outputs.append("")

sys.stdout.write("\n".join(outputs))
