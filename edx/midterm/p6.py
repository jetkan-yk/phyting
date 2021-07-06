def flatten(aList):
    """
    aList: a list
    Returns a copy of aList, which is a flattened version of aList
    """
    res = []
    helper(aList, res)
    return res


def helper(aList, res):
    if not isinstance(aList, list):
        return res.append(aList)
    for x in aList:
        helper(x, res)


print(flatten([[1, "a", ["cat"], 2], [[[3]], "dog"], 4, 5]))
