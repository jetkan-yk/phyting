# Kattis - Bungee Builder
'''
O(N) Sliding window solution pseudocode

Create 2 pointers h1, h2
Iterate h1 := 0 -> n-1:
    Iterate h2 := h1 + 1 -> n-1:
        If h1 <= h2:
            a bridge is formed, 
            ans := max(ans, h1 - min_h)
            h1 := h2
            min_h := h1
        Else:
            min_h := min(min_h, h2)
Repeat above for reversed mountain order
'''
import sys


def compute(arr):
    h1 = ans = 0
    min_h = arr[h1]
    for h2 in range(1, len(arr)):
        if arr[h1] <= arr[h2]:  # a bridge is formed
            ans = max(ans, arr[h1] - min_h)
            h1 = h2
            min_h = arr[h1]
        else:
            min_h = min(min_h, arr[h2])
    return ans


n = int(input())
arr = list(map(int, sys.stdin.readline().split()))

print(max(compute(arr), compute(arr[::-1])))