# Kattis - baloni
'''
    Initialize large 1D array
'''
import sys

if __name__ == "__main__":
    MAXH = 10**6 + 7
    n = int(input())
    arr = list(map(int, sys.stdin.readline().split()))
    ans = 0
    arrow = [0] * MAXH

    for i in arr:
        if arrow[i] == 0: ans += 1
        else: arrow[i] -= 1

        arrow[i - 1] += 1

    print(ans)