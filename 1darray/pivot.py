# Kattis - pivot
'''
    Classic static range min/max query problem
'''
import sys

n = int(input())
arr = list(map(int, sys.stdin.readline().split()))
left_max = [None] * n
right_min = [None] * n

for i in range(n):
    if i == 0:
        left_max[0] = arr[0]
        right_min[n - 1] = arr[n - 1]
    else:
        left_max[i] = max(left_max[i - 1], arr[i])
        right_min[n - i - 1] = min(right_min[n - i], arr[n - i - 1])

ans = 0
for i in range(n):
    if left_max[i] == right_min[i]:
        ans += 1

print(ans)