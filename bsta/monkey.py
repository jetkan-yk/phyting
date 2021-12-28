"""
UVa 12032 - The Monkey and the Oiled Bamboo

Input:
2
5
1 6 7 11 13
4
3 9 10 14

Output:
Case 1: 5
Case 2: 6

"""


def can(power, gaps):
    for gap in gaps:
        if power < gap:
            return False
        elif power == gap:
            power = power - 1
    return True


T = int(input())
for i in range(T):
    # Read input
    n = int(input())
    r = list(map(int, input().split(" ")))

    # Calculate gaps
    gaps = [r[0]]
    for j in range(1, n):
        gaps.append(r[j] - r[j - 1])

    # BSTA, min_r = 1, max_r = 10000000
    lo = 1
    hi = 10000000
    # log(10000000) / log(2) = 23.25
    for _ in range(24):
        # Round to floor
        mid = (lo + hi) // 2
        # Look for smaller power
        if can(mid, gaps):
            hi = mid
        # Look for larger power
        else:
            lo = mid

    # Output answer
    print(f"Case {i + 1}: {hi}")
