# Kattis - baloni
'''
    Use of collections.Counter()
'''
import sys
from collections import Counter

if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, sys.stdin.readline().split()))
    ans = 0
    arrow = Counter()

    for i in arr:
        if arrow[i] == 0: ans += 1
        else: arrow[i] -= 1

        arrow[i - 1] += 1

    print(ans)