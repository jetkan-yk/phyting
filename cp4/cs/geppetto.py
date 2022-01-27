from operator import inv
import sys

# Read input
inputs = sys.stdin.readlines()
n, m = map(int, inputs[0].split())
invalid = set()
for i in range(m):
    a, b = map(int, inputs[i + 1].split())
    if a > b:
        a, b = b, a
    invalid.add((a - 1, b - 1))

ways = 0
for mask in range(1 << n):
    add_ways = True
    for a, b in invalid:
        if mask & (1 << a) and mask & (1 << b):
            add_ways = False
            break
    ways += add_ways

print(ways)
