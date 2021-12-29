from math import ceil, log


def getIdealNums(low, high):
    max_pow_3 = ceil(log(high) / log(3))
    max_pow_5 = ceil(log(high) / log(5))

    count = 0
    for x in range(max_pow_3 + 1):
        for y in range(max_pow_5 + 1):
            if low <= pow(3, x) * pow(5, y) <= high:
                count += 1

    return count


if __name__ == "__main__":
    low = int(input())
    high = int(input())

    print(getIdealNums(low, high))
