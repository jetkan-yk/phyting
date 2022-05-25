import math


def main():
    MAX_TIME = 43200
    time = [0] * (MAX_TIME + 1)

    n = int(input())

    for _ in range(n):
        flip, done = map(int, input().split())
        time[done] += 1
        time[done - flip] += 1
        time[done - 2 * flip] += 1

    print(math.ceil(max(time) / 2))


if __name__ == "__main__":
    main()
