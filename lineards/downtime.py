# Kattis - downtime
'''
    Find maximum number of overlapping intervals in O(n) time
'''
import sys
import math

n, k = map(int, sys.stdin.readline().split())

head = 0
ans = 0
q = []

for _ in range(n):
    t = int(sys.stdin.readline())

    while (head < len(q) and q[head] + 1000 <= t):
        head += 1

    q.append(t)
    ans = max(ans, len(q) - head)

print(math.ceil(ans / k))