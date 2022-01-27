# UVa - 11565 Simple Equations
"""
    Iterative Complete Search
    O(N) solution
"""
import sys


def is_valid(x, y, z):
    global A, B, C

    is_distinct = x != y and y != z and x != z
    cond1 = x + y + z == A
    cond2 = x * y * z == B
    cond3 = x * x + y * y + z * z == C

    return is_distinct and cond1 and cond2 and cond3


N = int(input())

for _ in range(N):
    (A, B, C) = map(int, input().split())

    solution = False
    for x in range(-22, 22):
        if solution:
            break
        for y in range(-58, 58):
            z = A - (x + y)
            if is_valid(x, y, z):
                print(x, y, z)
                solution = True
                break

    if not solution:
        print("No solution.")
