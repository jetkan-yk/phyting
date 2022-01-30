import sys
from math import sqrt
from functools import reduce

# Check if a coverage bitmask covers all walls
def coverAll(x):
    return x == (1 << 4) - 1


# Calculates the Euclidean distance between two points
def dist(a, b):
    x1, y1 = a
    x2, y2 = b

    return sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)


# Check if the crane can cover the wall
def canCover(crane, wall):
    return dist(crane, wall) <= r


if __name__ == "__main__":
    inputs = [map(int, row.split()) for row in sys.stdin.readlines()]
    outputs = []

    # Process inputs
    l, w, n, r = inputs[0]
    walls = [(-l / 2, 0), (l / 2, 0), (0, -w / 2), (0, w / 2)]
    cranes = [tuple(row) for row in inputs[1:]]

    # Using bitmasks to represent the coverage of each crane
    coverages = [0] * n
    for i in range(n):
        for j in range(4):
            if canCover(cranes[i], walls[j]):
                # Mark the j-th wall of i-th crane as 1
                coverages[i] |= 1 << j

    # Check if there's any wall that cannot be covered by any crane
    allCoverage = reduce(lambda a, b: a | b, coverages)
    if not coverAll(allCoverage):
        print("Impossible")
        exit(0)

    ans = 4
    # Check coverage with only 1 crane
    for i in range(n):
        if coverAll(coverages[i]):
            ans = min(ans, 1)
        # Check coverage with 2 cranes
        for j in range(i + 1, n):
            if coverAll(coverages[i] | coverages[j]):
                ans = min(ans, 2)
            # Check coverage with 3 cranes
            for k in range(j + 1, n):
                if coverAll(coverages[i] | coverages[j] | coverages[k]):
                    ans = min(ans, 3)
    print(ans)
