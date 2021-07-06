from collections import Counter


def uniqueValues(aDict):
    """
    aDict: a dictionary
    """
    count = Counter(aDict.values())
    return sorted([key for key in aDict if count[aDict[key]] == 1])


aDict = {1: 1, 2: 2, 3: 1, 4: 4, 5: 2}
print(uniqueValues(aDict))
