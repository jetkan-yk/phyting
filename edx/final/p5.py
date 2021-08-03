from collections import Counter


def uniqueValues(aDict):
    """
    aDict: a dictionary
    returns: a sorted list of keys that map to unique aDict values, empty list if none
    """
    count = Counter(aDict.values())
    return sorted([key for key in aDict if count[aDict[key]] == 1])


aDict = {1: 1, 3: 2, 6: 0, 7: 0, 8: 4, 10: 0}
print(uniqueValues(aDict))
aDict = {1: 1, 2: 1, 3: 1}
print(uniqueValues(aDict))
