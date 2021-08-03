from collections import Counter


def largest_odd_times(L):
    """Assumes L is a non-empty list of ints
    Returns the largest element of L that occurs an odd number
    of times in L. If no such element exists, returns None"""
    c = sorted(Counter(L).items(), reverse=True)

    for (key, count) in c:
        if count % 2 == 1:
            return key
    return None


print(largest_odd_times([2, 2, 4, 4]))
print(largest_odd_times([3, 9, 5, 3, 5, 3]))
