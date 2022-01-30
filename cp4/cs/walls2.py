"""2^n, TLE"""

import sys
from math import sqrt


def countBits(x):
    return bin(x).count("1")


def canReach(cranes):
    return all(any(dist(wall, crane) <= r for crane in cranes) for wall in walls)


def dist(a, b):
    x1, y1 = a
    x2, y2 = b

    return sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)


if __name__ == "__main__":
    inputs = [map(int, row.split()) for row in sys.stdin.readlines()]
    outputs = []

    # Process inputs
    l, w, n, r = inputs[0]
    walls = [(-l / 2, 0), (l / 2, 0), (0, -w / 2), (0, w / 2)]
    cranes = [tuple(row) for row in inputs[1:]]

    # Sort bitmasks by increasing number of set bits
    bitmask = [i for i in range(1, (1 << n))]
    bitmask.sort(key=lambda x: countBits(x))

    for mask in bitmask:
        if countBits(mask) > 4:
            break

        # Select cranes according to bitmask
        selected_cranes = []
        for i in range(n):
            if mask & (1 << i):
                selected_cranes.append(cranes[i])

        # Check if can reach all walls
        if canReach(selected_cranes):
            print(countBits(mask))
            exit(0)

    print("Impossible")
