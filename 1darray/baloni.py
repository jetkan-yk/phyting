# Kattis - baloni
'''
    Initialize large 1D array
'''
import sys

n = int(input())
arr = list(map(int, sys.stdin.readline().split()))
ans = 0
arrow = [0] * (max(arr) + 1)

for i in arr:
    if arrow[i] == 0: ans += 1
    else: arrow[i] -= 1

    arrow[i - 1] += 1

print(ans)