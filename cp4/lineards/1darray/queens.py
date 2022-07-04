import sys


def main():
    inputs = sys.stdin.readlines()

    N = int(inputs[0])
    queens = [tuple(map(int, xy.split())) for xy in inputs[1:]]

    row = [False] * N
    col = [False] * N
    left = [False] * (N * 2)
    right = [False] * (N * 2)
    success = True

    for x, y in queens:
        if row[x] or col[y] or left[x - y] or right[x + y]:
            success = False
        else:
            row[x] = col[y] = left[x - y] = right[x + y] = True

    print("CORRECT") if success else print("INCORRECT")


if __name__ == "__main__":
    main()
