import sys


def countDiff(flag1, flag2):
    result = 0
    for i in range(len(flag1)):
        result += flag1[i] != flag2[i]
    return result


def main():
    inputs = [row.strip() for row in sys.stdin.readlines()]
    n = int(inputs[1])
    flags = [row.split(", ") for row in inputs[2:]]

    # Find maximum changes needed to transform flag i to all other flags
    diff = [0] * n
    for i in range(n):
        for j in range(n):
            diff[i] = max(diff[i], countDiff(flags[i], flags[j]))

    # Print flags with smallest max-changes
    minDiff = min(diff)
    for i in range(n):
        if diff[i] == minDiff:
            print(", ".join(flags[i]))


if __name__ == "__main__":
    main()
