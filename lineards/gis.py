# Kattis - greedilyincreasing
import sys

if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, sys.stdin.readline().split()))
    ans = []

    for i in range(n):
        if i == 0 or prev < arr[i]:
            prev = arr[i]
            ans.append(prev)

    print(len(ans))
    print(*ans)