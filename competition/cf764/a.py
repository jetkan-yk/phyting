import sys

tc = int(input())

for _ in range(tc):
    n = int(input())
    a = list(map(int, input().split()))
    minX = min(a)
    maxX = max(a)

    print(maxX - minX)
