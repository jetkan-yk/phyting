def solve(intervals):
    next_intervals = []
    i = 0
    j = 1
    while j < len(intervals):
        _, end1 = intervals[i]
        start2, end2 = intervals[j]

        if end1 < start2 or end1 > end2:
            i = j
        else:
            next_intervals.append((start2, end2))
        j += 1
    return next_intervals


def main():
    tc = int(input())
    for _ in range(tc):
        n = int(input())
        p = [int(x) - 1 for x in input().split()]

        intervals = set()
        start = [-1 for _ in range(n)]
        for idx in range(2 * n):
            x = p[idx]
            if start[x] == -1:
                start[x] = idx
            else:
                intervals.add((start[x], idx))

        intervals = sorted(list(intervals))

        if len(solve(solve(intervals))):
            print("no")
        else:
            print("yes")


if __name__ == "__main__":
    main()
